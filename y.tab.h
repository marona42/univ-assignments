/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 20 "grammar.y"

    #include "builder.h" 

#line 52 "y.tab.h"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER_CONSTANT = 258,
    FLOAT_CONSTANT = 259,
    CHARACTER_CONSTANT = 260,
    STRING_LITERAL = 261,
    IDENTIFIER = 262,
    TYPE_IDENTIFIER = 263,
    AUTO_SYM = 264,
    BREAK_SYM = 265,
    CASE_SYM = 266,
    CONTINUE_SYM = 267,
    DEFAULT_SYM = 268,
    DO_SYM = 269,
    ELSE_SYM = 270,
    ENUM_SYM = 271,
    FOR_SYM = 272,
    IF_SYM = 273,
    RETURN_SYM = 274,
    SIZEOF_SYM = 275,
    STATIC_SYM = 276,
    STRUCT_SYM = 277,
    SWITCH_SYM = 278,
    TYPEDEF_SYM = 279,
    UNION_SYM = 280,
    WHILE_SYM = 281,
    PPLUS = 282,
    MMINUS = 283,
    ARROW = 284,
    GREAT = 285,
    LESS = 286,
    GREATEQ = 287,
    LESSEQ = 288,
    EQU = 289,
    NEQ = 290,
    AAND = 291,
    OOR = 292,
    PPPOINT = 293,
    LPAR = 294,
    RPAR = 295,
    LLPAR = 296,
    RLPAR = 297,
    LMPAR = 298,
    RMPAR = 299,
    COLON = 300,
    POINT = 301,
    COMMA = 302,
    EXC = 303,
    STAR = 304,
    DIV = 305,
    PER = 306,
    AND = 307,
    PLUS = 308,
    MINUS = 309,
    ASSIGN = 310,
    SEMCOLON = 311,
    SLASH = 312
  };
#endif
/* Tokens.  */
#define INTEGER_CONSTANT 258
#define FLOAT_CONSTANT 259
#define CHARACTER_CONSTANT 260
#define STRING_LITERAL 261
#define IDENTIFIER 262
#define TYPE_IDENTIFIER 263
#define AUTO_SYM 264
#define BREAK_SYM 265
#define CASE_SYM 266
#define CONTINUE_SYM 267
#define DEFAULT_SYM 268
#define DO_SYM 269
#define ELSE_SYM 270
#define ENUM_SYM 271
#define FOR_SYM 272
#define IF_SYM 273
#define RETURN_SYM 274
#define SIZEOF_SYM 275
#define STATIC_SYM 276
#define STRUCT_SYM 277
#define SWITCH_SYM 278
#define TYPEDEF_SYM 279
#define UNION_SYM 280
#define WHILE_SYM 281
#define PPLUS 282
#define MMINUS 283
#define ARROW 284
#define GREAT 285
#define LESS 286
#define GREATEQ 287
#define LESSEQ 288
#define EQU 289
#define NEQ 290
#define AAND 291
#define OOR 292
#define PPPOINT 293
#define LPAR 294
#define RPAR 295
#define LLPAR 296
#define RLPAR 297
#define LMPAR 298
#define RMPAR 299
#define COLON 300
#define POINT 301
#define COMMA 302
#define EXC 303
#define STAR 304
#define DIV 305
#define PER 306
#define AND 307
#define PLUS 308
#define MINUS 309
#define ASSIGN 310
#define SEMCOLON 311
#define SLASH 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "grammar.y"
int num; char *str; A_NODE *node;A_TYPE *typet; A_ID *idt; A_SPECIFIER *spect;

#line 180 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
