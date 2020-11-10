%{
//#ifndef YYSTYPE_IS_DECLARED
//    #define YYSTYPE_IS_DECLARED 1
//    typedef long YYSTYPE;
//#endif
    #include <stdio.h>
    #include "type.h"
 //   #include "builder.h"
    extern int line_no, syntax_err, current_level;
    extern A_NODE *root;
    extern A_ID *current_id;
    extern A_TYPE *int_type;

    int yyerror();
    int yylex();
    char *yyget_text  (void);
    FILE *yyin;
%}
%start program
%code requires {
    #include "builder.h" 
}
%union {int num; char *str; A_NODE *node;A_TYPE *typet; A_ID *idt; A_SPECIFIER *spect;}
%token <num> INTEGER_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL
%token <num> IDENTIFIER TYPE_IDENTIFIER AUTO_SYM BREAK_SYM CASE_SYM CONTINUE_SYM DEFAULT_SYM DO_SYM ELSE_SYM ENUM_SYM FOR_SYM IF_SYM RETURN_SYM SIZEOF_SYM STATIC_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM
//%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE
%token <num> PPLUS MMINUS ARROW GREAT LESS GREATEQ LESSEQ EQU NEQ AAND OOR PPPOINT LPAR RPAR LLPAR RLPAR LMPAR RMPAR COLON POINT COMMA EXC STAR DIV PER AND PLUS MINUS ASSIGN SEMCOLON SLASH
/*     ++ -- -> > < >= <= == != && || *** ( ) [ ] { } : . , ! * / % & + - = ; / */ 
%type <node> initializer initializer_list statement_list_opt statement_list statement labeled_statement compound_statement expression_statement selection_statement iteration_statement jump_statement for_expression arg_expression_list constant_expression constant_expression_opt expression assignment_expression logical_and_expression logical_or_expression equality_expression relational_expression additive_expression multiplicative_expression cast_expression unary_expression postfix_expression primary_expression expression_opt arg_expression_list_opt
%type <idt> translation_unit external_declaration function_definition declaration_list_opt declaration_list declaration init_declarator_list_opt init_declarator_list init_declarator struct_declaration_list struct_declaration struct_declarator_list struct_declarator enumerator_list enumerator declarator direct_declarator parameter_type_list_opt parameter_type_list parameter_list parameter_declaration 
%type <typet> struct_type_specifier enum_type_specifier pointer abstract_declarator direct_abstract_declarator type_name type_specifier abstract_declarator_opt
%type <num> storage_class_specifier struct_or_union
%type <spect> declaration_specifiers
%%
program
    : translation_unit
    { printf("program:"); root=makeNode(N_PROGRAM,NIL,$1->init,NIL);   checkForwardReference(); }
;
translation_unit
    : external_declaration  {$$=$1;}
    | translation_unit external_declaration {$$=linkDeclaratorList($1,$2);}
;
external_declaration
    : function_definition   {$$=$1;}
    | declaration           {$$=$1;}
;
function_definition
    : declaration_specifiers declarator{ printf("funcdef:1"); $<idt>$ = setFunctionDeclaratorSpecifier($2,$1);printf("funcdefe:");} compound_statement {printf("funcAFTERcmp:");$$=setFunctionDeclaratorBody($<idt>3,$4);}
    | declarator { printf("funcdef2:"); $<idt>$ = setFunctionDeclaratorSpecifier($1,makeSpecifier(int_type,0));printf("funcdefe:");} compound_statement {printf("funcsAFTERcmp:"); $$=setFunctionDeclaratorBody($<idt>2,$3);}
;
declaration_list_opt
    :   {printf("declarationlistoptend:");$$=NIL;}
    |   declaration_list {printf("declistend:");$$=$1;}
    ;
declaration_list
    : declaration   {printf("decst:");$$=$1;}
    | declaration_list declaration  {printf("decst!!:");$$=linkDeclaratorList($1,$2);}
    ;
declaration
    : declaration_specifiers init_declarator_list_opt SEMCOLON {printf("decstn:");$$=setDeclaratorListSpecifier($2,$1); }
    ;    //FIXME:
declaration_specifiers
    : type_specifier        {printf("decspec:");$$=makeSpecifier($1,0);}
    | storage_class_specifier   {printf("decspec:");$$=makeSpecifier(0,$1);}
    | type_specifier declaration_specifiers {printf("decspec:");$$=updateSpecifier($2,$1,0);}
    | storage_class_specifier declaration_specifiers    {printf("decspec:");$$=updateSpecifier($2,0,$1);}
    ;
storage_class_specifier
    : AUTO_SYM      {$$=S_AUTO;}
    | STATIC_SYM    {$$=S_STATIC;}
    | TYPEDEF_SYM   {$$=S_TYPEDEF;}
    ;
init_declarator_list_opt
    :       {$$=makeDummyIdentifier();}
    | init_declarator_list  {$$=$1;}
    ;
init_declarator_list
    : init_declarator       {$$=$1;}
    | init_declarator_list COMMA init_declarator        {$$=linkDeclaratorList($1,$3);}
    ;
init_declarator
    : declarator     {$$=$1;}
    | declarator ASSIGN initializer { $$=setDeclaratorInit($1,$3);}
    ;
type_specifier
    : struct_type_specifier      {$$=$1;}
    | enum_type_specifier        {$$=$1;}
    | TYPE_IDENTIFIER       {$$=yylval.typet;}  //FIXME: ident 값
    ;
struct_type_specifier
    : struct_or_union IDENTIFIER { $<typet>$ = setTypeStructOrEnumIdentifier($1,yyget_text(),ID_STRUCT); } LMPAR {$<idt>$=current_id; current_level++;} struct_declaration_list RMPAR {checkForwardReference();$$=setTypeField($<typet>3,$6); current_level--; current_id=$<idt>5;}
    | struct_or_union {$<typet>$=makeType($1);} LMPAR {$<idt>$=current_id; current_level++;} struct_declaration_list RMPAR {checkForwardReference(); $<typet>$=setTypeField($<typet>2,$5); current_level--; current_id=$<idt>4;}
    | struct_or_union IDENTIFIER { $$ = getTypeOfStructOrEnumRefIdentifier($1,yyget_text(),ID_STRUCT); }
    ;
struct_or_union
    : STRUCT_SYM    {$$=T_STRUCT;}
    | UNION_SYM     {$$=T_UNION;}
    ;
struct_declaration_list
    : struct_declaration        {$$=$1;}
    | struct_declaration_list struct_declaration    {$$=linkDeclaratorList($1,$2);}
    ;
struct_declaration
    : type_specifier struct_declarator_list SEMCOLON {$$=setStructDeclaratorListSpecifier($2,$1);}
    ;
struct_declarator_list
    : struct_declarator {$$=$1;}
    | struct_declarator_list COMMA struct_declarator {$$=linkDeclaratorList($1,$3);}
    ;
struct_declarator
    : declarator    {$$=$1;}
    ;
enum_type_specifier
    : ENUM_SYM IDENTIFIER {$<typet>$=setTypeStructOrEnumIdentifier(T_ENUM,yyget_text(),ID_ENUM);}LMPAR enumerator_list RMPAR {$$=setTypeField($<typet>3,$5);}
    | ENUM_SYM LMPAR enumerator_list RMPAR  {$$=makeType(T_ENUM);}
    | ENUM_SYM IDENTIFIER   {$$=getTypeOfStructOrEnumRefIdentifier(T_ENUM,yyget_text(),ID_ENUM);}
    ;
enumerator_list
    : enumerator    {$$=$1;}
    | enumerator_list COMMA enumerator  {$$=linkDeclaratorList($1,$3);}
    ;
enumerator
    : IDENTIFIER    {$$=setDeclaratorKind(makeIdentifier(yyget_text()),ID_ENUM_LITERAL);}
    | IDENTIFIER {$<idt>$=setDeclaratorKind(makeIdentifier(yyget_text()),ID_ENUM_LITERAL);}ASSIGN expression {$$=setDeclaratorInit($<idt>2,$4);}
    ;
declarator
    : pointer direct_declarator     {$$=setDeclaratorElementType($2,$1);}
    | direct_declarator     {printf("dec2:");$$=$1;}
    ;
pointer
    : STAR  {$$=makeType(T_POINTER);}
    | STAR pointer  {$$=setTypeElementType($2,makeType(T_POINTER));}
    ;
direct_declarator
    : IDENTIFIER    {$$=makeIdentifier(yyget_text());printf("ddec: %s ",yyget_text());}
    | LPAR declarator RPAR  {$$=$2;}
    | direct_declarator LLPAR constant_expression_opt RLPAR {$$=setDeclaratorElementType($1,setTypeExpr(makeType(T_ARRAY),$3));}
    | direct_declarator LPAR {$<idt>$=current_id; current_level++;} parameter_type_list_opt RPAR {checkForwardReference(); current_id=$<idt>3; current_level--; $<idt>$=setDeclaratorElementType($1,setTypeField(makeType(T_FUNC),$4));}
    ;
constant_expression_opt
    :   {$$=NIL;}
    | constant_expression   {$$=$1;}
    ;
parameter_type_list_opt
    :   {$$=NIL;}
    | parameter_type_list   {$$=$1;}
    ;
parameter_type_list
    : parameter_list    {$$=$1;}
    | parameter_list PPPOINT    {$$=linkDeclaratorList($1,setDeclaratorKind(makeDummyIdentifier(),ID_PARM));}
    ;
parameter_list
    : parameter_declaration {$$=$1;}
    | parameter_list COMMA parameter_declaration    {$$=linkDeclaratorList($1,$3);}
    ;
parameter_declaration
    : declaration_specifiers declarator {$$=setParameterDeclaratorSpecifier($2,$1);}
    | declaration_specifiers abstract_declarator_opt {$$=setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(),$2),$1);}
    ;
abstract_declarator_opt
    :   {$$=NIL;}
    | abstract_declarator   {$$=$1;}
    ;
abstract_declarator
    : pointer   {$$=makeType(T_POINTER);}
    | direct_abstract_declarator    {$$=$1;}
    | pointer direct_abstract_declarator    {$$=setTypeElementType($2,makeType(T_POINTER));}
    ;
direct_abstract_declarator
    : LPAR abstract_declarator RPAR {$$=$2;}
    | LLPAR constant_expression_opt RLPAR   {$$=setTypeExpr(makeType(T_ARRAY),$2);}
    | LPAR parameter_type_list_opt RPAR {$$=setTypeExpr(makeType(T_FUNC),$2->init);}
    | direct_abstract_declarator LLPAR constant_expression_opt RLPAR    {$$=setTypeElementType($1,setTypeExpr(makeType(T_ARRAY),$3));}
    | direct_abstract_declarator LPAR parameter_type_list_opt RPAR      {$$=setTypeElementType($1,setTypeExpr(makeType(T_FUNC),$3->init));}
    ;
initializer
    : constant_expression   {printf("init1:\n");$$=makeNode(N_INIT_LIST_ONE,NIL,$1,NIL);}
    | LMPAR initializer_list RMPAR  {printf("init2:\n");$$=$2;}
    ;
initializer_list
    : initializer       {$$=makeNode(N_INIT_LIST,$1,NIL,makeNode(N_INIT_LIST_NIL,NIL,NIL,NIL));}
    | initializer_list COMMA initializer    {$$=makeNodeList(N_INIT_LIST,$1,$3);}
    ;
statement
    : labeled_statement     {$$=$1;}
    | compound_statement    {$$=$1;}
    | expression_statement  {$$=$1;}
    | selection_statement   {$$=$1;}
    | iteration_statement   {$$=$1;}
    | jump_statement        {$$=$1;}
    ;
labeled_statement
    : CASE_SYM constant_expression COLON statement {$$=makeNode(N_STMT_LABEL_CASE,$2,NIL,$4);}
    | DEFAULT_SYM COLON statement   {$$=makeNode(N_STMT_LABEL_DEFAULT,NIL,$3,NIL);}
    ;
statement_list
    : statement {printf("stlist:"); $$=makeNode(N_STMT_LIST,$1,NIL,makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL));}
    | statement_list statement {$$=makeNodeList(N_STMT_LIST,$1,$2);}
    ;
compound_statement
    : LMPAR {printf("cmpstmt:");$<idt>$=current_id; current_level++;} declaration_list_opt statement_list_opt RMPAR {checkForwardReference(); printf("cmpend:");$$=makeNode(N_STMT_COMPOUND,$3->init,NIL,$4); current_id=$<idt>2; current_level--;}
    ;//FIXME:declaration_list_opt
statement_list_opt
    :   {printf("stmtlist:");$$=makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL);}
    |   statement_list {printf("stmtlist:");$$=$1;}
    ;
expression_statement
    : SEMCOLON  {printf("noexp;");$$=makeNode(N_STMT_EMPTY,NIL,NIL,NIL);}
    | expression SEMCOLON   {printf("exp;");$$=makeNode(N_STMT_EXPRESSION,NIL,$1,NIL);}
    ;
selection_statement
    : IF_SYM LPAR expression RPAR statement {$$=makeNode(N_STMT_IF,$3,NIL,$5);}
    | IF_SYM LPAR expression RPAR statement ELSE_SYM statement {$$=makeNode(N_STMT_IF_ELSE,$3,$5,$7);}
    | SWITCH_SYM LPAR expression RPAR statement     {$$=makeNode(N_STMT_SWITCH,$3,NIL,$5);}
    ;
iteration_statement
    : WHILE_SYM LPAR expression RPAR statement  {$$=makeNode(N_STMT_WHILE,$3,NIL,$5);}
    | DO_SYM statement WHILE_SYM LPAR expression RPAR SEMCOLON {$$=makeNode(N_STMT_DO,$2,NIL,$5);}
    | FOR_SYM LPAR for_expression RPAR statement {$$=makeNode(N_STMT_FOR,$3,NIL,$5);}
    ;
for_expression
    : expression_opt SEMCOLON expression_opt SEMCOLON expression_opt {$$=makeNode(N_FOR_EXP,$1,$3,$5);} 
    ;
expression_opt
    :   {$$=NIL;}
    | expression    {$$=$1;}
    ;
jump_statement
    : RETURN_SYM expression_opt SEMCOLON    {$$=makeNode(N_STMT_RETURN,NIL,$2,NIL);}
    | CONTINUE_SYM SEMCOLON {$$=makeNode(N_STMT_CONTINUE,NIL,NIL,NIL);}
    | BREAK_SYM SEMCOLON    {$$=makeNode(N_STMT_BREAK,NIL,NIL,NIL);}
    ;

primary_expression
    : IDENTIFIER        {printf("priident:");$$=makeNode(N_EXP_IDENT,NIL,NULL,NIL); printf("IDENT: %s\n",yyget_text());}      //TODO: 리터럴 값 넘겨주기?
    | INTEGER_CONSTANT  {printf("priint:");$$=makeNode(N_EXP_INT_CONST,NIL,NULL,NIL);}
    | FLOAT_CONSTANT    {$$=makeNode(N_EXP_FLOAT_CONST,NIL,NULL,NIL);}
    | CHARACTER_CONSTANT{$$=makeNode(N_EXP_CHAR_CONST,NIL,NULL,NIL);}
    | STRING_LITERAL    {$$=makeNode(N_EXP_STRING_LITERAL,NIL,NULL,NIL);}
    | LPAR expression RPAR  {printf("priexp:");$$=$2;}
    ;

postfix_expression
    : primary_expression        {printf("priexp:");$$=$1;}
    | postfix_expression LLPAR expression RLPAR {printf("postexp:");$$=makeNode(N_EXP_ARRAY,$1,NIL,$3);}
    | postfix_expression LPAR arg_expression_list_opt RPAR  {printf("postexp:");$$=makeNode(N_EXP_FUNCTION_CALL,$1,NIL,$3);}
    | postfix_expression POINT IDENTIFIER       {printf("postexp:");$$=makeNode(N_EXP_STRUCT,$1,NIL,NULL);}    //FIXME:
    | postfix_expression ARROW IDENTIFIER       {printf("postexp:");$$=makeNode(N_EXP_ARROW,$1,NIL,NULL);}
    | postfix_expression PPLUS      {printf("postexp:");$$=makeNode(N_EXP_POST_INC,NIL,$1,NIL);}
    | postfix_expression MMINUS     {printf("postexp:");$$=makeNode(N_EXP_POST_DEC,NIL,$1,NIL);}
    ;
arg_expression_list_opt
    :   {$$=makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL);}
    | arg_expression_list {$$=$1;}
    ;
arg_expression_list
    : assignment_expression {$$=makeNode(N_ARG_LIST,$1,NIL,makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL));}
    | arg_expression_list COMMA assignment_expression   {$$=makeNodeList(N_ARG_LIST,$1,$3);}
    ;
unary_expression
    : postfix_expression        {$$=$1;}
    | PPLUS unary_expression    {$$=makeNode(N_EXP_PRE_INC,NIL,$2,NIL);}
    | MMINUS unary_expression   {$$=makeNode(N_EXP_PRE_DEC,NIL,$2,NIL);}
    | AND cast_expression       {$$=makeNode(N_EXP_AMP,NIL,$2,NIL);}
    | STAR cast_expression      {$$=makeNode(N_EXP_STAR,NIL,$2,NIL);}
    | EXC cast_expression       {$$=makeNode(N_EXP_NOT,NIL,$2,NIL);}
    | MINUS cast_expression     {$$=makeNode(N_EXP_MINUS,NIL,$2,NIL);}
    | PLUS cast_expression      {$$=makeNode(N_EXP_PLUS,NIL,$2,NIL);}
    | SIZEOF_SYM unary_expression   {$$=makeNode(N_EXP_SIZE_EXP,NIL,$2,NIL);}
    | SIZEOF_SYM LPAR type_name RPAR    {$$=makeNode(N_EXP_SIZE_TYPE,NIL,$3->expr,NIL);}
    ;
cast_expression
    : unary_expression      {$$=$1;}
    | LPAR type_specifier RPAR cast_expression  {$$=makeNode(N_EXP_CAST,$2->expr,NIL,$4);}
    ;
type_name
    : declaration_specifiers abstract_declarator_opt    {$$=setTypeNameSpecifier($2,$1);}
    ;
multiplicative_expression
    : cast_expression   {$$=$1;}
    | multiplicative_expression STAR cast_expression    {$$=makeNode(N_EXP_MUL,$1,NIL,$3);}
    | multiplicative_expression DIV cast_expression     {$$=makeNode(N_EXP_DIV,$1,NIL,$3);}
    | multiplicative_expression PER cast_expression     {$$=makeNode(N_EXP_MOD,$1,NIL,$3);}
    ;
additive_expression
    : multiplicative_expression {$$=$1;}
    | additive_expression PLUS multiplicative_expression    {$$=makeNode(N_EXP_ADD,$1,NIL,$3);}
    | additive_expression MINUS multiplicative_expression   {$$=makeNode(N_EXP_SUB,$1,NIL,$3);}
    ;
relational_expression
    : additive_expression   {$$=$1;}
    | relational_expression LESS additive_expression    {$$=makeNode(N_EXP_LSS,$1,NIL,$3);}
    | relational_expression GREAT additive_expression   {$$=makeNode(N_EXP_GTR,$1,NIL,$3);}
    | relational_expression LESSEQ additive_expression  {$$=makeNode(N_EXP_LEQ,$1,NIL,$3);}
    | relational_expression GREATEQ additive_expression {$$=makeNode(N_EXP_GEQ,$1,NIL,$3);}
    ;
equality_expression
    : relational_expression     {$$=$1;}
    | equality_expression EQU relational_expression {$$=makeNode(N_EXP_EQL,$1,NIL,$3);}
    | equality_expression NEQ relational_expression {$$=makeNode(N_EXP_NEQ,$1,NIL,$3);}
    ;
//TODO: bitwise or,xor,and expression
logical_and_expression
    : equality_expression   {$$=$1;}
    | logical_and_expression AAND equality_expression   {$$=makeNode(N_EXP_OR,$1,NIL,$3);}
    ;
logical_or_expression
    : logical_and_expression    {$$=$1;}
    | logical_or_expression OOR logical_and_expression  {$$=makeNode(N_EXP_OR,$1,NIL,$3);}
    ;
constant_expression
    : expression    {$$=$1;}
    ;
expression
    : assignment_expression {$$=$1;}
//    | expression COMMA assignment_expression //FIXME:{$$=$1;}
    ;
assignment_expression
    : logical_or_expression     {$$=$1;}
    | unary_expression ASSIGN expression    {printf("assigexp=:");$$=makeNode(N_EXP_ASSIGN,$1,NIL,$3);}
    ;
%%
#include "print.h"
extern char *yytext;
int yyerror(const char *s) {fprintf(stderr,"line %d: %s near '%s'\n",line_no,s,yytext);}
int main(int argc, char *argv[])
{
    if ((yyin = fopen(argv[argc - 1], "r")) == NULL)
    {
        printf("can not open input file: %s\n", argv[argc - 1]);
        return 1;
    }
    initialize();
    printf("init\n");
    yyparse();
    //if (!syntax_err)
    //    print_ast(root);
    printf("Done!\n");
    return 0;
}