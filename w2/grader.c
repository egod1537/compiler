#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <process.h>
#include <windows.h>
#else
#include <glob.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

#define PATH_BUFFER_SIZE 4096

struct test_cases {
  char **paths;
  size_t count;
  size_t capacity;
};

static char *copy_string(const char *source) {
  size_t length = strlen(source) + 1;
  char *copy = malloc(length);

  if (copy != NULL) {
    memcpy(copy, source, length);
  }

  return copy;
}

static int add_test_case(struct test_cases *cases, const char *path) {
  if (cases->count == cases->capacity) {
    size_t new_capacity = cases->capacity == 0 ? 16 : cases->capacity * 2;
    char **new_paths = realloc(cases->paths, new_capacity * sizeof(*new_paths));

    if (new_paths == NULL) {
      return 0;
    }

    cases->paths = new_paths;
    cases->capacity = new_capacity;
  }

  cases->paths[cases->count] = copy_string(path);
  if (cases->paths[cases->count] == NULL) {
    return 0;
  }

  ++cases->count;
  return 1;
}

static void free_test_cases(struct test_cases *cases) {
  size_t i;

  for (i = 0; i < cases->count; ++i) {
    free(cases->paths[i]);
  }

  free(cases->paths);
}

static int compare_paths(const void *left, const void *right) {
  const char *const *left_path = left;
  const char *const *right_path = right;
  return strcmp(*left_path, *right_path);
}

static int collect_test_cases(struct test_cases *cases) {
#ifdef _WIN32
  WIN32_FIND_DATAA data;
  HANDLE search = FindFirstFileA("tc\\*.in", &data);

  if (search == INVALID_HANDLE_VALUE) {
    return 1;
  }

  do {
    char path[PATH_BUFFER_SIZE];

    if ((data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0) {
      continue;
    }

    if (snprintf(path, sizeof(path), "tc\\%s", data.cFileName) >=
        (int)sizeof(path)) {
      fprintf(stderr, "error: test case path is too long: %s\n", data.cFileName);
      FindClose(search);
      return 0;
    }

    if (!add_test_case(cases, path)) {
      FindClose(search);
      return 0;
    }
  } while (FindNextFileA(search, &data));

  FindClose(search);
#else
  glob_t matches;
  size_t i;
  int result = glob("tc/*.in", 0, NULL, &matches);

  if (result == GLOB_NOMATCH) {
    return 1;
  }
  if (result != 0) {
    return 0;
  }

  for (i = 0; i < matches.gl_pathc; ++i) {
    if (!add_test_case(cases, matches.gl_pathv[i])) {
      globfree(&matches);
      return 0;
    }
  }

  globfree(&matches);
#endif

  qsort(cases->paths, cases->count, sizeof(*cases->paths), compare_paths);
  return 1;
}

static int read_normalized_file(const char *path, unsigned char **contents,
                                size_t *length) {
  FILE *file = fopen(path, "rb");
  unsigned char *buffer;
  size_t capacity = 256;
  size_t input_length = 0;
  size_t output_length = 0;
  size_t i;

  if (file == NULL) {
    return 0;
  }

  buffer = malloc(capacity);
  if (buffer == NULL) {
    fclose(file);
    return 0;
  }

  for (;;) {
    size_t bytes_read;

    if (input_length == capacity) {
      size_t new_capacity = capacity * 2;
      unsigned char *new_buffer = realloc(buffer, new_capacity);

      if (new_buffer == NULL) {
        free(buffer);
        fclose(file);
        return 0;
      }

      buffer = new_buffer;
      capacity = new_capacity;
    }

    bytes_read = fread(buffer + input_length, 1, capacity - input_length, file);
    input_length += bytes_read;

    if (bytes_read == 0) {
      break;
    }
  }

  if (ferror(file)) {
    free(buffer);
    fclose(file);
    return 0;
  }

  fclose(file);

  for (i = 0; i < input_length; ++i) {
    if (buffer[i] == '\r') {
      if (i + 1 < input_length && buffer[i + 1] == '\n') {
        ++i;
      }
      buffer[output_length++] = '\n';
    } else {
      buffer[output_length++] = buffer[i];
    }
  }

  if (output_length > 0 && buffer[output_length - 1] == '\n') {
    --output_length;
  }

  *contents = buffer;
  *length = output_length;
  return 1;
}

static size_t print_visible(const unsigned char *contents, size_t length) {
  size_t i;
  size_t width = 2;

  putchar('\'');
  for (i = 0; i < length; ++i) {
    unsigned char ch = contents[i];

    if (ch == '\n') {
      printf("\\n");
      width += 2;
    } else if (ch == '\t') {
      printf("\\t");
      width += 2;
    } else if (ch == '\\' || ch == '\'') {
      printf("\\%c", ch);
      width += 2;
    } else if (isprint(ch)) {
      putchar(ch);
      ++width;
    } else {
      printf("\\x%02X", ch);
      width += 4;
    }
  }
  putchar('\'');
  return width;
}

static void print_output_field(const unsigned char *contents, size_t length) {
  size_t width = print_visible(contents, length);

  while (width < 7) {
    putchar(' ');
    ++width;
  }
}

static const char *case_name(const char *path) {
  const char *slash = strrchr(path, '/');
  const char *backslash = strrchr(path, '\\');

  if (backslash != NULL && (slash == NULL || backslash > slash)) {
    slash = backslash;
  }

  return slash == NULL ? path : slash + 1;
}

static int exit_code_from_system(int status) {
#ifdef _WIN32
  return status;
#else
  if (status != -1 && WIFEXITED(status)) {
    return WEXITSTATUS(status);
  }
  return status;
#endif
}

int main(void) {
  struct test_cases cases = {NULL, 0, 0};
  char target_path[PATH_BUFFER_SIZE];
  char run_target[PATH_BUFFER_SIZE + 3];
  char actual_path[PATH_BUFFER_SIZE];
  char stderr_path[PATH_BUFFER_SIZE];
  char command[PATH_BUFFER_SIZE * 4];
  const char *compiler = getenv("CC");
  unsigned long process_id;
  long timestamp = (long)time(NULL);
  size_t passed = 0;
  size_t failed = 0;
  size_t i;
  int build_status;

#ifdef _WIN32
  process_id = (unsigned long)_getpid();
#else
  process_id = (unsigned long)getpid();
#endif

  if (compiler == NULL || compiler[0] == '\0') {
    compiler = "gcc";
  }

  if (!collect_test_cases(&cases)) {
    fprintf(stderr, "error: could not read test cases\n");
    free_test_cases(&cases);
    return 2;
  }

  if (cases.count == 0) {
    fprintf(stderr, "error: no .in files found in tc\n");
    free_test_cases(&cases);
    return 2;
  }

#ifdef _WIN32
  snprintf(target_path, sizeof(target_path), ".grader_target_%lu_%ld.exe",
           process_id, timestamp);
  snprintf(run_target, sizeof(run_target), ".\\%s", target_path);
#else
  snprintf(target_path, sizeof(target_path), ".grader_target_%lu_%ld",
           process_id, timestamp);
  snprintf(run_target, sizeof(run_target), "./%s", target_path);
#endif
  snprintf(actual_path, sizeof(actual_path), ".grader_actual_%lu_%ld.tmp",
           process_id, timestamp);
  snprintf(stderr_path, sizeof(stderr_path), ".grader_stderr_%lu_%ld.tmp",
           process_id, timestamp);

  snprintf(command, sizeof(command),
           "%s -std=c17 -Wall -Wextra -Wpedantic main.c -o \"%s\"", compiler,
           target_path);
  build_status = system(command);

  if (build_status != 0) {
    fprintf(stderr, "[BUILD FAILED]\n");
    free_test_cases(&cases);
    remove(target_path);
    return 2;
  }

  for (i = 0; i < cases.count; ++i) {
    const char *input_path = cases.paths[i];
    const char *name = case_name(input_path);
    size_t input_path_length = strlen(input_path);
    size_t name_length = strlen(name) - 3;
    char expected_path[PATH_BUFFER_SIZE];
    unsigned char *expected = NULL;
    unsigned char *actual = NULL;
    unsigned char *error_output = NULL;
    size_t expected_length = 0;
    size_t actual_length = 0;
    size_t error_length = 0;
    int run_status;
    int correct;

    if (snprintf(expected_path, sizeof(expected_path), "%.*s.out",
                 (int)(input_path_length - 3), input_path) >=
        (int)sizeof(expected_path)) {
      printf("[FAIL] %.*s: path is too long\n", (int)name_length, name);
      ++failed;
      continue;
    }

    if (!read_normalized_file(expected_path, &expected, &expected_length)) {
      printf("[FAIL] %.*s: missing or unreadable .out file\n", (int)name_length,
             name);
      ++failed;
      continue;
    }

    snprintf(command, sizeof(command),
             "%s < \"%s\" > \"%s\" 2> \"%s\"", run_target, input_path,
             actual_path, stderr_path);
    run_status = system(command);

    if (!read_normalized_file(actual_path, &actual, &actual_length)) {
      printf("[FAIL] %.*s: could not read program output\n", (int)name_length,
             name);
      free(expected);
      ++failed;
      continue;
    }

    correct = run_status == 0 && expected_length == actual_length &&
              memcmp(expected, actual, expected_length) == 0;

    if (correct) {
      printf("[PASS] expected: ");
      print_output_field(expected, expected_length);
      printf(" | actual: ");
      print_output_field(actual, actual_length);
      printf(" | %.*s\n", (int)name_length, name);
      ++passed;
    } else {
      printf("[FAIL] expected: ");
      print_output_field(expected, expected_length);
      printf(" | actual: ");
      print_output_field(actual, actual_length);
      printf(" | %.*s\n", (int)name_length, name);

      if (run_status != 0) {
        printf("  exit code: %d\n", exit_code_from_system(run_status));
      }

      if (read_normalized_file(stderr_path, &error_output, &error_length) &&
          error_length > 0) {
        printf("  stderr:   ");
        print_visible(error_output, error_length);
        putchar('\n');
      }

      ++failed;
    }

    free(expected);
    free(actual);
    free(error_output);
  }

  remove(target_path);
  remove(actual_path);
  remove(stderr_path);
  free_test_cases(&cases);

  printf("\nResult: %zu/%zu passed, %zu failed\n", passed, passed + failed,
         failed);
  return failed == 0 ? 0 : 1;
}
