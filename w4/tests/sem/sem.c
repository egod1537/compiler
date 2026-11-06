#include <stdio.h>

void SEM_MakeType(void);
void SEM_MakeIdentifier(void);
void SEM_SearchIdentifier(void);
void SEM_Scope(void);
void SEM_LinkDeclaratorList(void);
void SEM_SetTypeElementType(void);
void SEM_SetDeclaratorElementType(void);
void SEM_SetTypeExpr(void);
void SEM_SetTypeField(void);
void SEM_MakeSpecifier(void);
void SEM_UpdateSpecifier(void);
void SEM_SetDefaultSpecifier(void);
void SEM_Initialize(void);
void SEM_SetDeclaratorListSpecifier(void);
void SEM_SetFunctionDeclaratorSpecifier(void);
void SEM_SetFunctionDeclaratorBody(void);
void SEM_SetParameterDeclaratorSpecifier(void);

int main(void) {
  SEM_MakeType();
  SEM_MakeIdentifier();
  SEM_SearchIdentifier();
  SEM_Scope();
  SEM_LinkDeclaratorList();
  SEM_SetTypeElementType();
  SEM_SetDeclaratorElementType();
  SEM_SetTypeExpr();
  SEM_SetTypeField();
  SEM_MakeSpecifier();
  SEM_UpdateSpecifier();
  SEM_SetDefaultSpecifier();
  SEM_Initialize();
  SEM_SetDeclaratorListSpecifier();
  SEM_SetFunctionDeclaratorSpecifier();
  SEM_SetFunctionDeclaratorBody();
  SEM_SetParameterDeclaratorSpecifier();

  printf("testScope passed\n");
  return 0;
}

