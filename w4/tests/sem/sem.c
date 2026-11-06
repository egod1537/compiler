#include <stdio.h>

void SEM_testMakeType(void);
void SEM_testMakeIdentifier(void);
void SEM_testSearchIdentifier(void);
void SEM_testScope(void);
void SEM_testLinkDeclaratorList(void);
void SEM_testSetTypeElementType(void);
void SEM_testSetDeclaratorElementType(void);
void SEM_testSetTypeExpr(void);
void SEM_testSetTypeField(void);
void SEM_testMakeSpecifier(void);
void SEM_testUpdateSpecifier(void);
void SEM_testSetDefaultSpecifier(void);
void SEM_testInitialize(void);
void SEM_testSetDeclaratorListSpecifier(void);
void SEM_testSetFunctionDeclaratorSpecifier(void);
void SEM_testSetFunctionDeclaratorBody(void);
void SEM_testSetParameterDeclaratorSpecifier(void);

int main(void) {
  SEM_testMakeType();
  SEM_testMakeIdentifier();
  SEM_testSearchIdentifier();
  SEM_testScope();
  SEM_testLinkDeclaratorList();
  SEM_testSetTypeElementType();
  SEM_testSetDeclaratorElementType();
  SEM_testSetTypeExpr();
  SEM_testSetTypeField();
  SEM_testMakeSpecifier();
  SEM_testUpdateSpecifier();
  SEM_testSetDefaultSpecifier();
  SEM_testInitialize();
  SEM_testSetDeclaratorListSpecifier();
  SEM_testSetFunctionDeclaratorSpecifier();
  SEM_testSetFunctionDeclaratorBody();
  SEM_testSetParameterDeclaratorSpecifier();

  printf("testScope passed\n");
  return 0;
}

