
#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <io.h>
#define ISATTY _isatty
#define FILENO _fileno
#else
#include <unistd.h>
#define ISATTY isatty
#define FILENO fileno
#endif

void logMsg(LogLevel level, const char *fmt, ...) {
  static const char *names[] = {"DEBUG", "INFO", "SUCCESS", "WARNING", "ERROR"};

  static const char *colors[] = {
      "\x1b[36m", // cyan
      "\x1b[32m", // green
      "\x1b[32m", // green
      "\x1b[33m", // yellow
      "\x1b[31m"  // red
  };

  int use_color = ISATTY(FILENO(stderr));

  // NO_COLOR 환경변수로 색상 비활성화
  if (getenv("NO_COLOR") != NULL)
    use_color = 0;

  if (use_color)
    fprintf(stderr, "%s", colors[level]);

  fprintf(stderr, "[%s] ", names[level]);

  if (use_color)
    fprintf(stderr, "\x1b[0m");

  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);

  fprintf(stderr, "\n");
}
