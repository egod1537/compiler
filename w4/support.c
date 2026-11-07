#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "support.h"
#include "error.h"

extern char *yytext;

A_TYPE *int_type, *char_type, *void_type, *float_type, *string_type;
A_NODE *root;
A_ID *current_id=NIL;
int syntax_err=0;
int line_no=1;
int current_level=0;

static void *allocate(size_t size)
{
    void *memory=malloc(size);

    if (memory==NIL) {
        report_compiler_error(INTERNAL_ERROR,0,line_no,
                              "memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return memory;
}

A_NODE *makeNode(NODE_NAME n, A_NODE *a, A_NODE *b, A_NODE *c)
{
    A_NODE *m;
    m=(A_NODE *)allocate(sizeof(A_NODE));
    m->name=n;
    m->llink=a;
    m->clink=b;
    m->rlink=c;
    m->type=NIL;
    m->line=line_no;
    m->value=0;
    return m;
}

A_NODE *makeNodeList(NODE_NAME n, A_NODE *a, A_NODE *b)
{
    A_NODE *m,*k;
    k=a;
    while (k->rlink)
        k=k->rlink;
    m=(A_NODE *)allocate(sizeof(A_NODE));
    m->name=k->name;
    m->llink=NIL;
    m->clink=NIL;
    m->rlink=NIL;
    m->type=NIL;
    m->line=line_no;
    m->value=0;
    k->name=n;
    k->llink=b;
    k->rlink=m;
    return a;
}

A_ID *makeIdentifier(char *s)
{
    A_ID *id;
    id=(A_ID *)allocate(sizeof(A_ID));
    id->name=s;
    id->kind=0;
    id->specifier=0;
    id->level=current_level;
    id->address=0;
    id->init=NIL;
    id->type=NIL;
    id->link=NIL;
    id->line=line_no;
    id->value=0;
    id->prev=current_id;
    current_id=id;
    return id;
}

A_ID *makeDummyIdentifier(void)
{
    A_ID *id;
    id=(A_ID *)allocate(sizeof(A_ID));
    id->name="";
    id->kind=0;
    id->specifier=0;
    id->level=current_level;
    id->address=0;
    id->init=NIL;
    id->type=NIL;
    id->link=NIL;
    id->line=line_no;
    id->value=0;
    id->prev=0;
    return id;
}

A_TYPE *makeType(T_KIND k)
{
    A_TYPE *t;
    t=(A_TYPE *)allocate(sizeof(A_TYPE));
    t->kind=k;
    t->size=0;
    t->local_var_size=0;
    t->element_type=NIL;
    t->field=NIL;
    t->expr=NIL;
    t->check=FALSE;
    t->prt=FALSE;
    t->line=line_no;
    return t;
}

A_SPECIFIER *makeSpecifier(A_TYPE *t)
{
    A_SPECIFIER *p;
    p=(A_SPECIFIER *)allocate(sizeof(A_SPECIFIER));
    p->type=t;
    p->stor=S_NULL;
    p->line=line_no;
    return p;
}

A_ID *searchIdentifier(char *s, A_ID *id)
{
    while (id) {
        if (strcmp(id->name,s)==0)
            break;
        id=id->prev;
    }
    return id;
}

A_ID *searchIdentifierAtCurrentLevel(char *s, A_ID *id)
{
    while (id) {
        if (id->level<current_level)
            return NIL;
        if (strcmp(id->name,s)==0)
            break;
        id=id->prev;
    }
    return id;
}

void checkForwardReference(void)
{
    A_ID *id;
    A_TYPE *t;
    id=current_id;
    while (id) {
        if (id->level<current_level)
            break;
        t=id->type;
        if (id->kind==ID_NULL)
            syntax_error(31,id->name);
        else if ((id->kind==ID_STRUCT || id->kind==ID_ENUM) && t->field==NIL)
            syntax_error(32,id->name);
        id=id->prev;
    }
}

void setDefaultSpecifier(A_SPECIFIER *p)
{
    if (p->type==NIL)
        p->type=int_type;
}

A_ID *linkDeclaratorList(A_ID *id1, A_ID *id2)
{
    A_ID *m=id1;
    if (id1==NIL)
        return id2;
    while (m->link)
        m=m->link;
    m->link=id2;
    return id1;
}

A_ID *getIdentifierDeclared(char *s)
{
    A_ID *id;
    id=searchIdentifier(s,current_id);
    if (id==NIL)
        syntax_error(13,s);
    return id;
}

A_TYPE *getTypeOfStructOrEnumRefIdentifier(T_KIND k, char *s, ID_KIND kk)
{
    A_TYPE *t;
    A_ID *id;
    id=searchIdentifier(s,current_id);
    if (id) {
        if (id->kind==kk && id->type->kind==k) {
            return id->type;
        } else {
            syntax_error(11,s);
        }
    }
    t=makeType(k);
    id=makeIdentifier(s);
    id->kind=kk;
    id->type=t;
    return t;
}

A_ID *setDeclaratorKind(A_ID *id, ID_KIND k)
{
    A_ID *a;
    a=searchIdentifierAtCurrentLevel(id->name,id->prev);
    if (a)
        syntax_error(12,id->name);
    id->kind=k;
    return id;
}

A_ID *setDeclaratorType(A_ID *id, A_TYPE *t)
{
    id->type=t;
    return id;
}

A_ID *setDeclaratorElementType(A_ID *id, A_TYPE *t)
{
    A_TYPE *tt;
    if (id->type==NIL)
        id->type=t;
    else {
        tt=id->type;
        while (tt->element_type)
            tt=tt->element_type;
        tt->element_type=t;
    }
    return id;
}

A_ID *setDeclaratorTypeAndKind(A_ID *id, A_TYPE *t, ID_KIND k)
{
    id=setDeclaratorElementType(id,t);
    id=setDeclaratorKind(id,k);
    return id;
}

A_ID *setFunctionDeclaratorSpecifier(A_ID *id, A_SPECIFIER *p)
{
    A_ID *a;
    setDefaultSpecifier(p);
    if (id->type==NIL || id->type->kind!=T_FUNC) {
        syntax_error(21,NIL);
        id=setDeclaratorElementType(id,p->type);
        id->kind=ID_VAR;
        return id;
    } else {
        id=setDeclaratorElementType(id,p->type);
        id->kind=ID_FUNC;
    }
    a=searchIdentifierAtCurrentLevel(id->name,id->prev);
    if (a) {
        if (a->kind!=ID_FUNC || a->type->expr) {
            syntax_error(12,id->name);
        } else {
            if (isNotSameFormalParameters(a->type->field,id->type->field))
                syntax_error(22,id->name);
            if (isNotSameType(a->type->element_type,id->type->element_type))
                syntax_error(26,a->name);
        }
    }
    a=id->type->field;
    while (a) {
        if (strlen(a->name))
            current_id=a;
        else if (a->type &&
                 !(a->type==void_type && a==id->type->field && a->link==NIL))
            syntax_error(23,NIL);
        a=a->link;
    }
    return id;
}

A_ID *setFunctionDeclaratorBody(A_ID *id, A_NODE *n)
{
    if (id==NIL || id->type==NIL || id->type->kind!=T_FUNC)
        return id;
    id->type->expr=n;
    return id;
}

A_ID *setDeclaratorListSpecifier(A_ID *id, A_SPECIFIER *p)
{
    A_ID *a;
    setDefaultSpecifier(p);
    a=id;
    while (a) {
        if (strlen(a->name) && searchIdentifierAtCurrentLevel(a->name,a->prev))
            syntax_error(12,a->name);
        a=setDeclaratorElementType(a,p->type);
        if (a->type->kind==T_FUNC)
            a->kind=ID_FUNC;
        else
            a->kind=ID_VAR;
        a->specifier=S_NULL;
        a=a->link;
    }
    return id;
}

A_ID *setParameterDeclaratorSpecifier(A_ID *id, A_SPECIFIER *p)
{
    if (searchIdentifierAtCurrentLevel(id->name,id->prev))
        syntax_error(12,id->name);
    if (p->type==void_type && id->type==NIL && strlen(id->name)!=0)
        syntax_error(14,NIL);
    setDefaultSpecifier(p);
    id=setDeclaratorElementType(id,p->type);
    id->kind=ID_PARM;
    return id;
}

A_ID *setStructDeclaratorListSpecifier(A_ID *id, A_TYPE *t)
{
    A_ID *a;
    a=id;
    while (a) {
        if (searchIdentifierAtCurrentLevel(a->name,a->prev))
            syntax_error(12,a->name);
        a=setDeclaratorElementType(a,t);
        a->kind=ID_FIELD;
        a=a->link;
    }
    return id;
}

A_TYPE *setTypeNameSpecifier(A_TYPE *t, A_SPECIFIER *p)
{
    setDefaultSpecifier(p);
    t=setTypeElementType(t,p->type);
    return t;
}

A_TYPE *setTypeElementType(A_TYPE *t, A_TYPE *s)
{
    A_TYPE *q;
    if (t==NIL)
        return s;
    q=t;
    while (q->element_type)
        q=q->element_type;
    q->element_type=s;
    return t;
}

A_TYPE *setTypeField(A_TYPE *t, A_ID *n)
{
    t->field=n;
    return t;
}

A_TYPE *setTypeExpr(A_TYPE *t, A_NODE *n)
{
    t->expr=n;
    return t;
}

A_TYPE *setTypeStructOrEnumIdentifier(T_KIND k, char *s, ID_KIND kk)
{
    A_TYPE *t;
    A_ID *id,*a;
    a=searchIdentifierAtCurrentLevel(s,current_id);
    if (a) {
        if (a->kind==kk && a->type->kind==k) {
            if (a->type->field) {
                syntax_error(12,s);
            } else {
                return a->type;
            }
        } else {
            syntax_error(12,s);
        }
    }
    id=makeIdentifier(s);
    t=makeType(k);
    id->type=t;
    id->kind=kk;
    return t;
}

A_TYPE *setTypeAndKindOfDeclarator(A_TYPE *t, ID_KIND k, A_ID *id)
{
    if (searchIdentifierAtCurrentLevel(id->name,id->prev))
        syntax_error(12,id->name);
    id->type=t;
    id->kind=k;
    return t;
}

BOOLEAN isNotSameFormalParameters(A_ID *a, A_ID *b)
{
    if (a==NIL)
        return FALSE;
    while (a) {
        if (b==NIL || isNotSameType(a->type,b->type))
            return TRUE;
        a=a->link;
        b=b->link;
    }
    if (b)
        return TRUE;
    else
        return FALSE;
}

BOOLEAN isNotSameType(A_TYPE *t1, A_TYPE *t2)
{
    if (isPointerOrArrayType(t1) || isPointerOrArrayType(t2))
        return isNotSameType(t1->element_type,t2->element_type);
    else
        return t1!=t2;
}

BOOLEAN isPointerOrArrayType(A_TYPE *t)
{
    return t && (t->kind==T_POINTER || t->kind==T_ARRAY);
}

void initialize(void)
{
    int_type=setTypeAndKindOfDeclarator(makeType(T_ENUM),ID_TYPE,makeIdentifier("int"));
    float_type=setTypeAndKindOfDeclarator(makeType(T_ENUM),ID_TYPE,makeIdentifier("float"));
    char_type=setTypeAndKindOfDeclarator(makeType(T_ENUM),ID_TYPE,makeIdentifier("char"));
    void_type=setTypeAndKindOfDeclarator(makeType(T_VOID),ID_TYPE,makeIdentifier("void"));
    setDeclaratorTypeAndKind(makeIdentifier("double"),float_type,ID_TYPE);
    string_type=setTypeElementType(makeType(T_POINTER),char_type);
    int_type->size=4;       int_type->check=TRUE;
    float_type->size=4;     float_type->check=TRUE;
    char_type->size=1;      char_type->check=TRUE;
    void_type->size=0;      void_type->check=TRUE;
    string_type->size=4;    string_type->check=TRUE;

    setDeclaratorTypeAndKind(
        makeIdentifier("printf"),
        setTypeField(
            setTypeElementType(makeType(T_FUNC),void_type),
            linkDeclaratorList(
                setDeclaratorTypeAndKind(makeDummyIdentifier(),string_type,ID_PARM),
                setDeclaratorKind(makeDummyIdentifier(),ID_PARM))),
        ID_FUNC);

    setDeclaratorTypeAndKind(
        makeIdentifier("scanf"),
        setTypeField(
            setTypeElementType(makeType(T_FUNC),void_type),
            linkDeclaratorList(
                setDeclaratorTypeAndKind(makeDummyIdentifier(),string_type,ID_PARM),
                setDeclaratorKind(makeDummyIdentifier(),ID_PARM))),
        ID_FUNC);

    setDeclaratorTypeAndKind(
        makeIdentifier("malloc"),
        setTypeField(
            setTypeElementType(makeType(T_FUNC),string_type),
            setDeclaratorTypeAndKind(makeDummyIdentifier(),int_type,ID_PARM)),
        ID_FUNC);
}

void syntax_error(int i, const char *s)
{
    syntax_err++;
    switch (i) {
    case 11:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "illegal reference to struct or union identifier '%s'",s);
        break;
    case 12:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "redeclaration of identifier '%s'",s);
        break;
    case 13:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "undefined identifier '%s'",s);
        break;
    case 14:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "illegal type specifier in formal parameter");
        break;
    case 21:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "illegal function declarator");
        break;
    case 22:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "conflicting parameter type in prototype function '%s'",s);
        break;
    case 23:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "empty parameter name");
        break;
    case 26:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "illegal or conflicting return type in function '%s'",s);
        break;
    case 31:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "undefined type for identifier '%s'",s);
        break;
    case 32:
        report_compiler_error(DECLARATION_ERROR,i,line_no,
                              "incomplete forward reference for identifier '%s'",s);
        break;
    default:
        report_compiler_error(INTERNAL_ERROR,i,line_no,
                              "unknown declaration error");
        break;
    }
}
