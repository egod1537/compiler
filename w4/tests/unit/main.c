#include <stdio.h>

void testMakeType(void);
void testMakeIdentifier(void);
void testSearchIdentifier(void);
void testScope(void);
void testLinkDeclaratorList(void);
void testSetTypeElementType(void);
void testSetDeclaratorElementType(void);
void testSetTypeExpr(void);
void testSetTypeField(void);
void testMakeSpecifier(void);
void testUpdateSpecifier(void);
void testSetDefaultSpecifier(void);
void testInitialize(void);
void testSetDeclaratorListSpecifier(void);
void testSetFunctionDeclaratorSpecifier(void);
void testSetFunctionDeclaratorBody(void);
void testSetParameterDeclaratorSpecifier(void);

int main(void) {
  testMakeType();
  testMakeIdentifier();
  testSearchIdentifier();
  testScope();
  testLinkDeclaratorList();
  testSetTypeElementType();
  testSetDeclaratorElementType();
  testSetTypeExpr();
  testSetTypeField();
  testMakeSpecifier();
  testUpdateSpecifier();
  testSetDefaultSpecifier();
  testInitialize();
  testSetDeclaratorListSpecifier();
  testSetFunctionDeclaratorSpecifier();
  testSetFunctionDeclaratorBody();
  testSetParameterDeclaratorSpecifier();

  printf("testScope passed\n");
  return 0;
}

