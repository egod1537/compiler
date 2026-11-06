#include "../../semantic.h"
#include "../../syntax_tree.h"
#include "ast_assert.h"
#include "ast_runner.h"

#include <stdlib.h>
#include <string.h>

static void AST_runStructTest(void) {
  const char *struct_test = getenv("AST_TEST_STRUCT");

  if (struct_test == NULL)
    return;

  if (strcmp(struct_test, "fields") == 0)
    AST_46_Struct(1);
  else if (strcmp(struct_test, "dot") == 0)
    AST_46_Struct(2);
  else if (strcmp(struct_test, "arrow") == 0)
    AST_46_Struct(3);
  else
    semanticError("Unknown struct test mode");
}

void AST_runDeclarationTests(void) {
  if (getenv("AST_TEST_POINTER") != NULL)
    AST_14_PointerDeclaration();

  if (getenv("AST_TEST_ARRAY_DECL") != NULL)
    AST_23_ArrayDeclaration();

  if (getenv("AST_TEST_FUNCTION_DECL") != NULL)
    AST_59_FunctionDeclarator();

  if (getenv("AST_TEST_FUNCTION_PARAMS") != NULL)
    AST_25_FunctionParameters();

  if (getenv("AST_TEST_FUNCTION_SCOPE") != NULL)
    AST_25_FunctionScope();

  if (getenv("AST_TEST_BLOCK_SHADOWING") != NULL)
    AST_44_BlockShadowing();

  if (getenv("AST_TEST_SIZEOF_TYPE") != NULL)
    AST_51_SizeofType();

  if (getenv("AST_TEST_PROGRAM") != NULL)
    AST_58_Program(program_root);

  AST_runStructTest();
}
