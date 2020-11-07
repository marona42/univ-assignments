digit   [0-9]
letter  [a-zA-Z_]
delim   [\t]
line    [\n]
ws      {delim}+
%{
//ifndef YYSTYPE_IS_DECLARED
//   #define YYSTYPE_IS_DECLARED 1
//   typedef long YYSTYPE;
//endif
    #include "y.tab.h"
    extern YYSTYPE yylval;
    extern int line_no;
    line_no=1;
    char *makeString();
    int checkIdentifier();
%}
%option noyywrap
%%
{ws}        {}
"/*"([^*/]|[^*]"/"|"*"[^/])*"*/"  {}
"//"[^\n]*  {}
"#"[^\n]*   {}
{line}      {line_no++;} 
auto        {return(AUTO_SYM);}
break       {return(BREAK_SYM);}
case        {return(CASE_SYM);}
continue    {return(CONTINUE_SYM);}
default     {return(DEFAULT_SYM);}
do          {return(DO_SYM);}
else        {return(ELSE_SYM);}
enum        {return(ENUM_SYM);}
for         {return(FOR_SYM);}
if          {return(IF_SYM);}
return      {return(RETURN_SYM);}
sizeof      {return(SIZEOF_SYM);}
static      {return(STATIC_SYM);}
struct      {return(STRUCT_SYM);}
switch      {return(SWITCH_SYM);}
typedef     {return(TYPEDEF_SYM);}
union       {return(UNION_SYM);}
while       {return(WHILE_SYM);}
"\+\+"      {return(PPLUS);}
"\-\-"      {return(MMINUS);}
"\->"       {return(ARROW);}
"<"         {return(LESS);}
">"         {return(GREAT);}
"<="        {return(LESSEQ);}
">="        {return(GREATEQ);}
"=="        {return(EQU);}
"!="        {return(NEQ);}
"&&"        {return(AAND);}
"||"        {return(OOR);}
"\.\.\."    {return(PPPOINT);}
"\["        {return(LLPAR);}
"\]"        {return(RLPAR);}
"\{"        {return(LMPAR);}
"\}"        {return(RMPAR);}
"\:"        {return(COLON);}
"\."        {return(POINT);}
"\,"        {return(COMMA);}
"\!"        {return(EXC);}
"\/"        {return(SLASH);}
"\%"        {return(PER);}
"\&"        {return(AND);}
"\;"        {return(SEMCOLON);}
"\+"        {return(PLUS);}
"\-"        {return(MINUS);}
"\*"        {return(STAR);}
"\("        {return(LPAR);}
"\)"        {return(RPAR);}
"\="        {return(EQU);}
{digit}+                        { yylval = atoi(yytext);        return(INTEGER_CONSTANT);}
{digit}+\.{digit}+              { return(FLOAT_CONSTANT);}    //yylval = makeString(yytext);
{letter}({letter}|{digit})*     { return(checkIdentifier(yytext)); }
\"([^"\n]|\\["\n])*\"           { return(STRING_LITERAL);}    //yylval = makeString(yytext);
\'([^'\n]|\'\')\'               { yylval = *(yytext+1);         return(CHARACTER_CONSTANT);}

%%

char *makeString(char *s)
{
    char *t;
    t=malloc(strlen(s)+1);
    strcpy(t,s);
    return t;
}
int checkIdentifier(char *s)
{
    if(!strcmp(s,"int"))    { yylval = INT_TYPE;    return(TYPE_IDENTIFIER);}
    if(!strcmp(s,"float"))  { yylval = FLOAT_TYPE;  return(TYPE_IDENTIFIER);}
    if(!strcmp(s,"char"))   { yylval = CHAR_TYPE;   return(TYPE_IDENTIFIER);}
    if(!strcmp(s,"void"))   { yylval = VOID_TYPE;   return(TYPE_IDENTIFIER);}

    //yylval=makeString(s);

    printf("found IDENTIFIER %s\n",s);
    return(IDENTIFIER);
}