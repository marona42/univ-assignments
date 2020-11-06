%{
    //#include "y.tab.h"
    #include <stdio.h>
    #include "type.h"
    extern int line_no, syntax_err,current_level;
    extern A_NODE *root;
    extern A_ID *current_id;
    extern A_TYPE *int_type;

    int yyerror();
    int yylex();
%}
%start program
%token INTEGER_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL
%token IDENTIFIER TYPE_IDENTIFIER AUTO_SYM BREAK_SYM CASE_SYM CONTINUE_SYM DEFAULT_SYM DO_SYM ELSE_SYM ENUM_SYM FOR_SYM IF_SYM RETURN_SYM SIZEOF_SYM STATIC_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM
%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE
%token PPLUS MMINUS ARROW GREAT LESS GREATEQ LESSEQ EQU NEQ AAND OOR PPPOINT LPAR RPAR LLPAR RLPAR LMPAR RMPAR COLON POINT COMMA EXC STAR DIV PER AND PLUS MINUS ASSIGN SEMCOLON SLASH
/*     ++ -- -> > < >= <= == != && || *** ( ) [ ] { } : . , ! * / % & + - = ; / */ 
//%union {A_NODE NODE;}
//%type <NODE> struct_specifier
%%
program
    : translation_unit
    { root=makeNode(N_PROGRAM,NIL,$1,NIL);   checkForwardReference(); }
;
translation_unit
    : external_declaration
    | translation_unit external_declaration
;
external_declaration
    : function_definition
    | declaration
;
function_definition
    : declaration_specifiers declarator { $$ = setFunctionDeclaratorSpecifier($2,$1);} compound_statement {$$=setFunctionDeclaratorBody($3,$4);}
    | declarator { $$ = setFunctionDeclaratorSpecifier($1,makeSpecifier(int_type,0));} compound_statement {$$=setFunctionDeclaratorBody($2,$3);}
;
declaration_list_opt
    :   {$$=NIL;}
    |   declaration_list {$$=$1;}
    ;
declaration_list
    : declaration   {$$=$1;}
    | declaration_list declaration  {$$=linkDeclaratorList($1,$2);}
    ;
declaration
    : declaration_specifiers init_declarator_list_opt SEMCOLON {$$=setDeclaratorListSpecifer($2,$2); }
    ;
declaration_specifiers
    : type_specifier        {$$=makeSpecifier($1,0);}
    | storage_class_specifier   {$$=makeSpecifier(0,$1);}
    | type_specifier declaration_specifiers {$$=updateSpecifier($2,$1,0);}
    | storage_class_specifier declaration_specifiers    {$$=updateSpecifier($2,0,$1);}
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
    | declarator ASSIGN initializer {$$=setDeclaratorInit($1,$3);}
    ;
type_specifier
    : struct_type_specifier      {$$=$1;}
    | enum_type_specifier        {$$=$1;}
    | TYPE_IDENTIFIER       {$$=$1;}
    ;
struct_type_specifier
    : struct_or_union IDENTIFIER { $$ = setTypeStructOrEnumIdentifier($1,$2,ID_STRUCT); } LMPAR {$$=current_id; current_level++;} struct_declaration_list RMPAR {checkForwardReference();$$=setTypeField($3,$6); current_level--; current_id=$5;}
    | struct_or_union {$$=makeType($1);} LMPAR {$$=current_id; current_level++;} struct_declaration_list RMPAR {checkForwardReference(); $$=setTypeField($2,$5); current_level--; current_id=$4;}
    | struct_or_union IDENTIFIER { $$ = getTypeOfStructOrEnumRefIdentifier($1,$2,ID_STRUCT); }
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
    : ENUM_SYM IDENTIFIER {$$=setTypeStructOrEnumIdentifier(T_ENUM,$2,ID_ENUM);}LMPAR enumerator_list RMPAR {$$=setTypeField($3,$5);}
    | ENUM_SYM LMPAR enumerator_list RMPAR  {$$=makeType(T_ENUM);}
    | ENUM_SYM IDENTIFIER   {$$=getTypeOfStructOrEnumRefIdentifier(T_ENUM,$2,ID_ENUM);}
    ;
enumerator_list
    : enumerator    {$$=$1;}
    | enumerator_list COMMA enumerator  {$$=linkDeclaratorList($1,$3);}
    ;
enumerator
    : IDENTIFIER    {$$=setDeclaratorKind(makeIdentifier($1),ID_ENUM_LITERAL);}
    | IDENTIFIER {$$=setDeclaratorKind(makeIdentifier($1),ID_ENUM_LITERAL);}ASSIGN expression {$$=setDeclaratorInit($2,$4);}
    ;
declarator
    : pointer direct_declarator     {$$=setDeclaratorElementType($2,$1);}
    | direct_declarator     {$$=$1;}
    ;
pointer
    : STAR  {$$=makeType(T_POINTER);}
    | STAR pointer  {$$=setTypeElementType($2,makeType(T_POINTER));}
    ;
direct_declarator
    : IDENTIFIER    {$$=makeIdentifier($1);}
    | LPAR declarator RPAR  {$$=$2;}
    | direct_declarator LLPAR constant_expression_opt RLPAR {$$=setDeclaratorElementType($1,setTypeExpr(makeType(T_ARRAY),$3));}
    | direct_declarator LPAR {$$=current_id; current_level++;} parameter_type_list_opt RPAR {checkForwardReference(); current_id=$3; current_level--; $$=setDeclaratorElementType($1,setTypeField(makeType(T_FUNC),$4));}
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
    | LLPAR constant_expression_opt RLPAR   {$$=setTypeExpr(makeType(T_ARRAY,$2);}
    | LPAR parameter_type_list_opt RPAR {$$=setTypeExpr(makeType(T_FUNC),$2);}
    | direct_abstract_declarator LLPAR constant_expression_opt RLPAR    {$$=setTypeElementType($1,setTypeExpr(makeType(T_ARRAY),$3));}
    | direct_abstract_declarator LPAR parameter_type_list_opt RPAR      {$$=setTypeElementType($1,setTypeExpr(makeType(T_FUNC),$3));}
    ;
initializer
    : constant_expression   {$$=makeNode(N_INIT_LIST_ONE,NIL,$1,NIL);}
    | LMPAR initializer_list RMPAR  {$$=$2;}
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
    | DEFAULT_SYM COLON statement   {$$=makeNode(N_STMT_LABEL,DEFAULT,NIL,$3,NIL);}
    ;
statement_list
    : statement {$$=makeNode(N_STMT_LIST,$1,NIL,makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL);}
    | statement_list statement {$$=makeNodeList(N_STMT_LIST,$1,$2);}
    ;
compound_statement
    : LMPAR {$$=current_id; current_level++;} declaration_list_opt statement_list_opt RMPAR {checkForwardReference(); $$=makeNode(N_STMT_COMPOUND,$3,NIL,$4); current_id=$2; current_level--;}
    ;
statement_list_opt
    :   {$$=makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL);}
    |   statement_list {$$=$1;}
    ;
expression_statement
    : SEMCOLON  {$$=makeNode(N_STMT_EMPTY,NIL,NIL,NIL);}
    | expression SEMCOLON   {$$=makeNode(N_STMT_EXPRESSION,NIL,$1,NIL);}
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
    : IDENTIFIER        {$$=makeNode(N_EXP_IDENT,NIL,getIdentifierDeclared($1),NIL);}
    | INTEGER_CONSTANT  {$$=makeNode(N_EXP_INT_CONST,NIL,$1,NIL);}
    | FLOAT_CONSTANT    {$$=makeNode(N_EXP_FLOAT_CONST,NIL,$1,NIL);}
    | CHARACTER_CONSTANT{$$=makeNode(N_EXP_CHAR_CONST,NIL,$1,NIL);}
    | STRING_LITERAL    {$$=makeNode(N_EXP_STRING_LITERAL,NIL,$1,NIL);}
    | LPAR expression RPAR  {$$=$2;}
    ;

postfix_expression
    : primary_expression        {$$=$1;}
    | postfix_expression LLPAR expression RLPAR {$$=makeNode(N_EXP_ARRAY,$1,NIL,$3);}
    | postfix_expression LPAR arg_expression_list_opt RPAR  {$$=makeNode(N_EXP_FUNCTION_CALL,$1,NIL,$3);}
    | postfix_expression POINT IDENTIFIER       {$$=makeNode(N_EXP_STRUCT,$1,NIL,$3);}
    | postfix_expression ARROW IDENTIFIER       {$$=makeNode(N_EXP_ARROW,$1,NIL,$3);}
    | postfix_expression PPLUS      {$$=makeNode(N_EXP_POST_INC,NIL,$1,NIL);}
    | postfix_expression MMINUS     {$$=makeNode(N_EXP_POST_DEC,NIL,$1,NIL);}
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
    | SIZEOF_SYM LPAR type_name RPAR    {$$=makeNode(N_EXP_SIZE_TYPE,NIL,$3,NIL);}
    ;
cast_expression
    : unary_expression      {$$=$1;}
    | LPAR type_specifier RPAR cast_expression  {$$=makeNode(N_EXP_CAST,$2,NIL,$4);}
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
    | unary_expression ASSIGN expression    {$$=makeNode(N_EXP_ASSIGN,$1,NIL,$3);}
    ;
%%
extern char *yytext;
A_ID *makeIdentifier(char *s)
{
    A_ID *id;
    id=malloc(sizeof(A_ID));
    id->name=s;
    id->level=current_level;
    id->prev=current_id;
    id->link=NULL;
    current_level=id;
    line = line_no;
    return id;
}
int yyerror(const char *s) {fprintf(stderr,"line %d: %s near '%s'\n",line_no,s,yytext);}
int main(int argc, char *argv[])
{
    if ((yyin = fopen(argv[argc - 1], "r")) == NULL)
    {
        printf("can not open input file: %s\n", argv[argc - 1]);
        exit(1);
    }
    initialize();
    yyparse();
    if (!syntax_err)
        print_ast(root);

    return 0;
}