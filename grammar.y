%{
    //#include "y.tab.h"
    #include <stdio.h>
    extern int line_no;
    int yyerror();
    int yylex();
%}
%start program
%token INTEGER_CONSTANT FLOAT_CONSTANT CHARACTER_CONSTANT STRING_LITERAL
%token IDENTIFIER TYPE_IDENTIFIER AUTO_SYM BREAK_SYM CASE_SYM CONTINUE_SYM DEFAULT_SYM DO_SYM ELSE_SYM ENUM_SYM FOR_SYM IF_SYM RETURN_SYM SIZEOF_SYM STATIC_SYM STRUCT_SYM SWITCH_SYM TYPEDEF_SYM UNION_SYM WHILE_SYM
%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE
%token PPLUS MMINUS ARROW GREAT LESS GREATEQ LESSEQ EQU NEQ AAND OOR PPPOINT LPAR RPAR LLPAR RLPAR LMPAR RMPAR COLON POINT COMMA EXC STAR DIV PER AND PLUS MINUS ASSIGN SEMCOLON SLASH
/*     ++ -- -> > < >= <= == != && || *** ( ) [ ] { } : . , ! * / % & + - = ; / */ 
%%
program
    : translation_unit
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
    : declaration_specifiers declarator compound_statement
    | declarator compound_statement
;
declaration
    : declaration_specifiers SEMCOLON
    | declaration_specifiers init_declarator_list SEMCOLON
    ;
declaration_specifiers
    : type_specifier
    | storage_class_specifier
    | type_specifier declaration_specifiers
    | storage_class_specifier declaration_specifiers
    ;
storage_class_specifier
    : AUTO_SYM
    | STATIC_SYM
    | TYPEDEF_SYM
    ;
init_declarator_list
    : init_declarator 
    | init_declarator_list COMMA init_declarator
    ;
init_declarator
    : declarator
    | declarator ASSIGN initializer
    ;
type_specifier
    : struct_specifier
    | enum_specifier
    | TYPE_IDENTIFIER
    ;
struct_specifier
    : struct_or_union IDENTIFIER LMPAR struct_declaration_list RMPAR
    | struct_or_union LMPAR struct_declaration_list RMPAR
    | struct_or_union IDENTIFIER
    ;
struct_or_union
    : STRUCT_SYM
    | UNION_SYM
    ;
struct_declaration_list
    : struct_declaration
    | struct_declaration_list struct_declaration
    ;
struct_declaration
    : type_specifier struct_declarator_list
    ;
struct_declarator_list
    : struct_declarator
    | struct_declarator_list COMMA struct_declarator
    ;
struct_declarator
    : declarator
    ;
enum_specifier
    : ENUM_SYM IDENTIFIER LMPAR enumerator_list RMPAR
    | ENUM_SYM LMPAR enumerator_list RMPAR
    | ENUM_SYM IDENTIFIER
    ;
enumerator_list
    : enumerator
    | enumerator_list COMMA enumerator
    ;
enumerator
    : IDENTIFIER
    | IDENTIFIER ASSIGN constant_expression
    ;
declarator
    : pointer direct_declartor
    | direct_declartor
    ;
pointer
    : STAR
    | STAR pointer
    ;
direct_declartor
    : IDENTIFIER
    | LPAR declarator RPAR
    | direct_declartor LLPAR constant_expression_opt RLPAR
    | direct_declartor LPAR parameter_type_list_opt RPAR
    ;
constant_expression_opt
    :
    | constant_expression
    ;
parameter_type_list_opt
    :
    | parameter_type_list
    ;
parameter_type_list
    : parameter_list
    | parameter_list PPPOINT
    ;
parameter_list
    : parameter_declaration
    | parameter_list COMMA parameter_declaration
    ;
parameter_declaration
    : declaration_specifiers declarator
    | declaration_specifiers abstract_declarator
    | declaration_specifiers
    ;
abstract_declarator
    : pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;
direct_abstract_declarator
    : LPAR abstract_declarator RPAR
    | LLPAR constant_expression_opt RLPAR
    | LPAR parameter_type_list_opt RPAR
    | direct_abstract_declarator LLPAR constant_expression_opt RLPAR
    | direct_abstract_declarator LPAR parameter_type_list_opt RPAR
    ;
initializer
    : constant_expression
    | LMPAR initializer_list RMPAR
    ;
initializer_list
    : initializer
    | initializer_list COMMA initializer
    ;
statement
    : labeled_statement
    | compound_statement
    | expression_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;
labeled_statement
    : CASE_SYM constant_expression COLON statement
    | DEFAULT_SYM COLON statement
    ;
compound_statement
    : LMPAR declaration_list statement_list RMPAR
    ;
declaration_list
    :
    | declaration_list declaration
    ;
statement_list
    :
    | statement_list statement
    ;
expression_statement
    : SEMCOLON
    | expression SEMCOLON
    ;
selection_statement
    : IF_SYM LPAR expression RPAR statement
    | IF_SYM LPAR expression RPAR statement ELSE_SYM statement
    | SWITCH_SYM LPAR expression RPAR statement
    ;
iteration_statement
    : WHILE_SYM LPAR expression RPAR statement
    | DO_SYM statement WHILE_SYM LPAR expression RPAR SEMCOLON
    | FOR_SYM LPAR expression_opt SEMCOLON expression_opt SEMCOLON expression_opt RPAR statement
    ;
expression_opt
    :
    | expression
    ;
jump_statement
    : RETURN_SYM expression_opt SEMCOLON
    | CONTINUE_SYM SEMCOLON
    | BREAK_SYM SEMCOLON
    ;

primary_expression
    : IDENTIFIER        
    | INTEGER_CONSTANT  
    | FLOAT_CONSTANT    
    | CHARACTER_CONSTANT
    | STRING_LITERAL    
    | LPAR expression RPAR
    ;

postfix_expression
    : primary_expression
    | postfix_expression LLPAR expression RLPAR
    | postfix_expression LPAR arg_expression_list_opt RPAR
    | postfix_expression POINT IDENTIFIER
    | postfix_expression ARROW IDENTIFIER
    | postfix_expression PPLUS
    | postfix_expression MMINUS
    ;
arg_expression_list_opt
    :
    | arg_expression_list
    ;
arg_expression_list
    : assignment_expression
    | arg_expression_list COMMA assignment_expression
    ;
unary_expression
    : postfix_expression
    | PPLUS unary_expression
    | MMINUS unary_expression
    | AND cast_expression
    | STAR cast_expression
    | EXC cast_expression
    | MINUS cast_expression
    | PLUS cast_expression
    | SIZEOF_SYM unary_expression
    | SIZEOF_SYM LPAR type_name RPAR
    ;
cast_expression
    : unary_expression
    | LPAR type_specifier RPAR cast_expression
    ;
type_name
    : declaration_specifiers
    | declaration_specifiers abstract_declarator
    ;
multiplicative_expression
    : cast_expression
    | multiplicative_expression STAR cast_expression
    | multiplicative_expression DIV cast_expression
    | multiplicative_expression PER cast_expression
    ;
additive_expression
    : multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
    ;
relational_expression
    : additive_expression
    | relational_expression LESS additive_expression
    | relational_expression GREAT additive_expression
    | relational_expression LESSEQ additive_expression
    | relational_expression GREATEQ additive_expression
    ;
equality_expression
    : relational_expression
    | equality_expression EQU relational_expression
    | equality_expression NEQ relational_expression
    ;
logical_and_expression
    : equality_expression
    | logical_and_expression AAND equality_expression
    ;
logical_or_expression
    : logical_and_expression
    | logical_or_expression OOR logical_and_expression
    ;
constant_expression
    : expression
    ;
expression
    : assignment_expression

    ;
assignment_expression
    : logical_or_expression
    | unary_expression ASSIGN expression
    ;
%%
extern char *yytext;
int yyerror(const char *s) {fprintf(stderr,"line %d: %s near '%s'\n",line_no,s,yytext);}
int main()
{
    yyparse();
}