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
    INT_TYPE = 282,
    FLOAT_TYPE = 283,
    CHAR_TYPE = 284,
    VOID_TYPE = 285,
    PPLUS = 286,
    MMINUS = 287,
    ARROW = 288,
    GREAT = 289,
    LESS = 290,
    GREATEQ = 291,
    LESSEQ = 292,
    EQU = 293,
    NEQ = 294,
    AAND = 295,
    OOR = 296,
    PPPOINT = 297,
    LPAR = 298,
    RPAR = 299,
    LLPAR = 300,
    RLPAR = 301,
    LMPAR = 302,
    RMPAR = 303,
    COLON = 304,
    POINT = 305,
    COMMA = 306,
    EXC = 307,
    STAR = 308,
    DIV = 309,
    PER = 310,
    AND = 311,
    PLUS = 312,
    MINUS = 313,
    ASSIGN = 314,
    SEMCOLON = 315,
    SLASH = 316
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
#define INT_TYPE 282
#define FLOAT_TYPE 283
#define CHAR_TYPE 284
#define VOID_TYPE 285
#define PPLUS 286
#define MMINUS 287
#define ARROW 288
#define GREAT 289
#define LESS 290
#define GREATEQ 291
#define LESSEQ 292
#define EQU 293
#define NEQ 294
#define AAND 295
#define OOR 296
#define PPPOINT 297
#define LPAR 298
#define RPAR 299
#define LLPAR 300
#define RLPAR 301
#define LMPAR 302
#define RMPAR 303
#define COLON 304
#define POINT 305
#define COMMA 306
#define EXC 307
#define STAR 308
#define DIV 309
#define PER 310
#define AND 311
#define PLUS 312
#define MINUS 313
#define ASSIGN 314
#define SEMCOLON 315
#define SLASH 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
