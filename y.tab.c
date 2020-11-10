/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

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

#line 89 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 136 "y.tab.c"

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

#line 264 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   497

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

#define YYUNDEFTOK  2
#define YYMAXUTOK   312


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    36,    36,    40,    41,    44,    45,    48,    48,    49,
      49,    52,    53,    56,    57,    60,    63,    64,    65,    66,
      69,    70,    71,    74,    75,    78,    79,    82,    83,    86,
      87,    88,    91,    91,    91,    92,    92,    92,    93,    96,
      97,   100,   101,   104,   107,   108,   111,   114,   114,   115,
     116,   119,   120,   123,   124,   124,   127,   128,   131,   132,
     135,   136,   137,   138,   138,   141,   142,   145,   146,   149,
     150,   153,   154,   157,   158,   161,   162,   165,   166,   167,
     170,   171,   172,   173,   174,   177,   178,   181,   182,   185,
     186,   187,   188,   189,   190,   193,   194,   197,   198,   201,
     201,   204,   205,   208,   209,   212,   213,   214,   217,   218,
     219,   222,   225,   226,   229,   230,   231,   235,   236,   237,
     238,   239,   240,   244,   245,   246,   247,   248,   249,   250,
     253,   254,   257,   258,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   273,   274,   277,   280,   281,   282,
     283,   286,   287,   288,   291,   292,   293,   294,   295,   298,
     299,   300,   304,   305,   308,   309,   312,   315,   319,   320
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_CONSTANT", "FLOAT_CONSTANT",
  "CHARACTER_CONSTANT", "STRING_LITERAL", "IDENTIFIER", "TYPE_IDENTIFIER",
  "AUTO_SYM", "BREAK_SYM", "CASE_SYM", "CONTINUE_SYM", "DEFAULT_SYM",
  "DO_SYM", "ELSE_SYM", "ENUM_SYM", "FOR_SYM", "IF_SYM", "RETURN_SYM",
  "SIZEOF_SYM", "STATIC_SYM", "STRUCT_SYM", "SWITCH_SYM", "TYPEDEF_SYM",
  "UNION_SYM", "WHILE_SYM", "PPLUS", "MMINUS", "ARROW", "GREAT", "LESS",
  "GREATEQ", "LESSEQ", "EQU", "NEQ", "AAND", "OOR", "PPPOINT", "LPAR",
  "RPAR", "LLPAR", "RLPAR", "LMPAR", "RMPAR", "COLON", "POINT", "COMMA",
  "EXC", "STAR", "DIV", "PER", "AND", "PLUS", "MINUS", "ASSIGN",
  "SEMCOLON", "SLASH", "$accept", "program", "translation_unit",
  "external_declaration", "function_definition", "@1", "@2",
  "declaration_list_opt", "declaration_list", "declaration",
  "declaration_specifiers", "storage_class_specifier",
  "init_declarator_list_opt", "init_declarator_list", "init_declarator",
  "type_specifier", "struct_type_specifier", "@3", "@4", "@5", "@6",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_type_specifier",
  "@7", "enumerator_list", "enumerator", "@8", "declarator", "pointer",
  "direct_declarator", "@9", "constant_expression_opt",
  "parameter_type_list_opt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "abstract_declarator_opt",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement", "statement_list",
  "compound_statement", "@10", "statement_list_opt",
  "expression_statement", "selection_statement", "iteration_statement",
  "for_expression", "expression_opt", "jump_statement",
  "primary_expression", "postfix_expression", "arg_expression_list_opt",
  "arg_expression_list", "unary_expression", "cast_expression",
  "type_name", "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "constant_expression", "expression",
  "assignment_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
# endif

#define YYPACT_NINF (-184)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     345,  -184,  -184,  -184,    15,  -184,  -184,  -184,  -184,    28,
     -29,    51,   345,  -184,  -184,  -184,    28,   188,   188,  -184,
      73,  -184,  -184,    21,    -1,    52,    95,    82,  -184,  -184,
    -184,    91,   105,  -184,   -14,  -184,  -184,   112,   126,   130,
      -1,  -184,   383,   135,   125,   -11,  -184,  -184,  -184,    28,
     353,   130,   151,  -184,  -184,  -184,   188,  -184,  -184,  -184,
    -184,  -184,   413,   443,   443,   323,   383,   383,   383,   383,
     383,   153,  -184,   129,   145,  -184,     4,    85,   175,    40,
     131,   164,  -184,  -184,  -184,    95,   156,  -184,    95,  -184,
     165,   353,  -184,  -184,  -184,  -184,   124,   188,    45,   181,
    -184,    35,  -184,   284,  -184,   383,  -184,  -184,   182,   183,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   217,
     383,   383,   218,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,    69,   383,  -184,
    -184,    84,   124,    28,    34,  -184,   230,   188,  -184,    28,
      23,   383,  -184,    27,  -184,  -184,    94,  -184,  -184,   188,
      62,   189,   383,  -184,  -184,   190,   184,  -184,   196,  -184,
    -184,  -184,  -184,  -184,     4,     4,    85,    85,    85,    85,
     175,   175,    40,   131,  -184,  -184,  -184,   353,    92,    59,
    -184,  -184,  -184,  -184,   176,   383,   195,   200,   230,   207,
     213,   383,   215,   216,  -184,  -184,  -184,   230,  -184,   219,
    -184,  -184,  -184,  -184,   203,  -184,   220,   221,   222,    94,
     188,   383,  -184,   435,   121,  -184,  -184,  -184,  -184,   383,
    -184,  -184,  -184,    28,  -184,  -184,   223,  -184,   230,   236,
     383,   383,   209,  -184,   383,   383,  -184,  -184,  -184,  -184,
    -184,  -184,   226,   225,  -184,  -184,   230,  -184,   231,   232,
     224,   234,  -184,   235,   237,  -184,  -184,  -184,   383,   230,
     383,   230,   230,   230,   241,  -184,   229,   256,  -184,  -184,
     238,   383,   230,  -184,  -184,  -184
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    60,    31,    20,     0,    21,    39,    22,    40,     0,
      58,     0,     2,     3,     5,     6,    23,    17,    16,    29,
      35,    30,     9,     0,    57,    50,     0,     0,    59,     1,
       4,     0,    24,    25,    27,    19,    18,    38,     0,     0,
      56,    63,    65,     0,    53,     0,    51,    61,    15,     0,
       0,     0,     0,    36,    99,    10,    67,   118,   119,   120,
     121,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   134,   144,   147,   151,   154,   159,   162,
     164,   168,    66,   166,   167,     0,     0,    49,     0,    26,
      27,     0,    28,    85,     8,    33,     0,    11,    75,     0,
      68,    69,    71,     0,   142,     0,   135,   136,     0,     0,
     144,   139,   138,   137,   141,   140,    62,   128,   129,     0,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      87,     0,     0,     0,     0,    41,   101,    12,    13,    23,
      67,    65,    73,    77,    74,    76,    78,    64,    70,     0,
      75,     0,     0,   122,   127,     0,   131,   132,     0,   126,
     169,   148,   149,   150,   152,   153,   156,   155,   158,   157,
     160,   161,   163,   165,    48,    55,    86,     0,     0,     0,
      44,    46,    37,    42,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,   103,    97,    89,   102,    90,     0,
      91,    92,    93,    94,     0,    14,     0,     0,     0,    79,
      67,    65,    72,    67,    77,   146,   143,   145,   125,     0,
     124,    88,    34,     0,    43,   116,     0,   115,     0,     0,
     112,     0,     0,   113,     0,     0,    98,   100,   104,    82,
      80,    81,     0,     0,   133,    45,     0,    96,     0,     0,
       0,     0,   114,     0,     0,    84,    83,    95,     0,     0,
     112,     0,     0,     0,     0,   110,     0,   105,   107,   108,
       0,   112,     0,   109,   111,   106
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,   264,  -184,  -184,  -184,  -184,  -184,   -71,
       7,  -184,  -184,  -184,   246,   -59,  -184,  -184,  -184,  -184,
    -184,  -184,   154,  -123,  -184,    64,  -184,  -184,   214,   210,
    -184,    -6,    -9,   -19,  -184,  -124,   -54,  -184,  -184,   142,
     143,  -132,  -136,   -75,  -184,  -108,  -184,  -184,    54,  -184,
    -184,  -184,  -184,  -184,  -184,  -183,  -184,  -184,  -184,  -184,
    -184,    57,   -55,  -184,    44,    86,    43,   167,   171,  -184,
     -45,   -42,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    51,    39,   146,   147,    15,
      98,    17,    31,    32,    33,    18,    19,    52,   142,    38,
      96,    20,   144,   145,   189,   190,    21,    43,    45,    46,
      86,    22,    23,    24,    56,    71,   216,   100,   101,   102,
     154,   155,   156,    92,   141,   205,   206,   207,   208,    97,
     209,   210,   211,   212,   259,   242,   213,    72,    73,   165,
     166,    74,    75,   161,    76,    77,    78,    79,    80,    81,
      82,   214,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    28,    99,    27,    40,    93,   108,    16,    83,   167,
      34,   111,   112,   113,   114,   115,   140,   219,   217,    16,
      10,   193,    25,   109,    35,    36,   148,   218,     1,    -7,
       1,     2,     3,    87,     1,     1,    88,   143,    41,     4,
      42,    50,     2,    90,     5,     6,    93,     7,     8,    83,
       4,    29,     1,   124,   125,   126,     6,   260,    26,     8,
       9,   109,   150,   109,   151,   193,   150,     9,   151,   171,
     172,   173,    10,   158,   133,   134,   215,    10,   192,   168,
      37,   170,   159,   143,   150,   143,   151,   276,   219,   153,
     239,   217,   152,    55,    10,   -47,   185,   253,   284,   246,
       2,   223,    44,   151,   149,    94,   233,   227,     4,    83,
     160,    10,   231,   184,     6,   234,    88,     8,   254,   104,
     106,   107,    47,   110,   110,   110,   110,   110,   186,   143,
     257,   187,     2,   220,    40,   221,   232,   191,   127,   128,
       4,   153,    93,    90,    27,    83,     6,    48,   267,     8,
     236,   224,    49,    83,   149,   -32,   117,   118,   119,   243,
     223,   275,   151,   277,   278,   279,   252,   135,   120,    53,
     121,   174,   175,    54,   285,   122,   180,   181,    85,    83,
     -54,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,    95,   116,     2,     3,   243,   261,
     123,   136,   263,   264,     4,   129,   130,   131,   132,     5,
       6,   138,     7,     8,   224,   176,   177,   178,   179,   110,
      50,   157,   162,   163,   164,   169,   274,   191,   243,   226,
     228,   229,   235,    57,    58,    59,    60,    61,   230,   243,
     194,   195,   196,   197,   198,   238,   240,   199,   200,   201,
      62,   237,   241,   202,   244,   245,   203,    63,    64,   248,
     249,   250,   258,   247,   251,   262,   265,   266,   256,    65,
     268,   282,   269,    54,   271,   272,    30,   273,    66,    67,
     270,   280,    68,    69,    70,   281,   204,    57,    58,    59,
      60,    61,     2,     3,   283,    89,   188,   255,   139,   137,
       4,   222,   182,   225,    62,     5,     6,   183,     7,     8,
       0,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,    57,    58,    59,    60,
      61,     2,    66,    67,     0,     0,    68,    69,    70,     4,
       0,     0,     0,    62,     0,     6,     0,     0,     8,     0,
      63,    64,     1,     2,     3,     0,    57,    58,    59,    60,
      61,     4,    65,     0,     0,     0,     5,     6,     0,     7,
       8,    66,    67,    62,     0,    68,    69,    70,     0,     0,
      63,    64,     0,     0,     9,     0,    57,    58,    59,    60,
      61,     0,    65,     0,    10,     0,    91,     0,     0,     0,
       0,    66,    67,    62,     0,    68,    69,    70,     0,     0,
      63,    64,     0,     0,     0,     0,    57,    58,    59,    60,
      61,     0,    65,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    67,    62,     0,    68,    69,    70,     0,     0,
      63,    64,     0,     2,     3,     0,    57,    58,    59,    60,
      61,     4,   103,     0,     0,     0,     5,     6,     0,     7,
       8,    66,    67,    62,     0,    68,    69,    70,     0,     0,
      63,    64,     0,     0,   223,     0,   151,     0,     0,     0,
       0,     0,   105,     0,    10,     0,     0,     0,     0,     0,
       0,    66,    67,     0,     0,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      42,    10,    56,     9,    23,    50,    65,     0,    50,   120,
      16,    66,    67,    68,    69,    70,    91,   153,   150,    12,
      49,   144,     7,    65,    17,    18,    97,   151,     7,    43,
       7,     8,     9,    44,     7,     7,    47,    96,    39,    16,
      41,    55,     8,    49,    21,    22,    91,    24,    25,    91,
      16,     0,     7,    49,    50,    51,    22,   240,    43,    25,
      39,   103,    39,   105,    41,   188,    39,    39,    41,   124,
     125,   126,    49,    38,    34,    35,   147,    49,    44,   121,
       7,   123,    47,   142,    39,   144,    41,   270,   224,    98,
     198,   223,    98,    39,    49,    43,   138,   221,   281,   207,
       8,    39,     7,    41,    97,    51,    47,   162,    16,   151,
     103,    49,   187,    44,    22,    56,    47,    25,   229,    62,
      63,    64,    40,    66,    67,    68,    69,    70,    44,   188,
     238,    47,     8,    39,   153,    41,    44,   143,    53,    54,
      16,   150,   187,   149,   150,   187,    22,    56,   256,    25,
     195,   160,    47,   195,   147,    43,    27,    28,    29,   201,
      39,   269,    41,   271,   272,   273,   220,    36,    39,    43,
      41,   127,   128,    43,   282,    46,   133,   134,    43,   221,
      55,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,    43,    42,     8,     9,   240,   241,
      55,    37,   244,   245,    16,    30,    31,    32,    33,    21,
      22,    55,    24,    25,   223,   129,   130,   131,   132,   162,
      55,    40,    40,    40,     7,     7,   268,   233,   270,    40,
      40,    47,    56,     3,     4,     5,     6,     7,    42,   281,
      10,    11,    12,    13,    14,    45,    39,    17,    18,    19,
      20,    56,    39,    23,    39,    39,    26,    27,    28,    56,
      40,    40,    26,    44,    42,    56,    40,    42,    45,    39,
      39,    15,    40,    43,    40,    40,    12,    40,    48,    49,
      56,    40,    52,    53,    54,    56,    56,     3,     4,     5,
       6,     7,     8,     9,    56,    49,   142,   233,    88,    85,
      16,   159,   135,   160,    20,    21,    22,   136,    24,    25,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,     3,     4,     5,     6,
       7,     8,    48,    49,    -1,    -1,    52,    53,    54,    16,
      -1,    -1,    -1,    20,    -1,    22,    -1,    -1,    25,    -1,
      27,    28,     7,     8,     9,    -1,     3,     4,     5,     6,
       7,    16,    39,    -1,    -1,    -1,    21,    22,    -1,    24,
      25,    48,    49,    20,    -1,    52,    53,    54,    -1,    -1,
      27,    28,    -1,    -1,    39,    -1,     3,     4,     5,     6,
       7,    -1,    39,    -1,    49,    -1,    43,    -1,    -1,    -1,
      -1,    48,    49,    20,    -1,    52,    53,    54,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    20,    -1,    52,    53,    54,    -1,    -1,
      27,    28,    -1,     8,     9,    -1,     3,     4,     5,     6,
       7,    16,    39,    -1,    -1,    -1,    21,    22,    -1,    24,
      25,    48,    49,    20,    -1,    52,    53,    54,    -1,    -1,
      27,    28,    -1,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    -1,    -1,    52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    16,    21,    22,    24,    25,    39,
      49,    59,    60,    61,    62,    67,    68,    69,    73,    74,
      79,    84,    89,    90,    91,     7,    43,    89,    90,     0,
      61,    70,    71,    72,    89,    68,    68,     7,    77,    64,
      91,    39,    41,    85,     7,    86,    87,    40,    56,    47,
      55,    63,    75,    43,    43,   106,    92,     3,     4,     5,
       6,     7,    20,    27,    28,    39,    48,    49,    52,    53,
      54,    93,   115,   116,   119,   120,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    43,    88,    44,    47,    72,
      89,    43,   101,   128,   106,    43,    78,   107,    68,    94,
      95,    96,    97,    39,   119,    39,   119,   119,    73,   129,
     119,   120,   120,   120,   120,   120,    42,    27,    28,    29,
      39,    41,    46,    55,    49,    50,    51,    53,    54,    30,
      31,    32,    33,    34,    35,    36,    37,    86,    55,    87,
     101,   102,    76,    73,    80,    81,    65,    66,    67,    68,
      39,    41,    89,    90,    98,    99,   100,    40,    38,    47,
      68,   121,    40,    40,     7,   117,   118,   130,   129,     7,
     129,   120,   120,   120,   122,   122,   123,   123,   123,   123,
     124,   124,   125,   126,    44,   129,    44,    47,    80,    82,
      83,    89,    44,    81,    10,    11,    12,    13,    14,    17,
      18,    19,    23,    26,    56,   103,   104,   105,   106,   108,
     109,   110,   111,   114,   129,    67,    94,    99,    93,   100,
      39,    41,    97,    39,    90,    98,    40,   120,    40,    47,
      42,   101,    44,    47,    56,    56,   128,    56,    45,   103,
      39,    39,   113,   129,    39,    39,   103,    44,    56,    40,
      40,    42,    94,    93,   130,    83,    45,   103,    26,   112,
     113,   129,    56,   129,   129,    40,    42,   103,    39,    40,
      56,    40,    40,    40,   129,   103,   113,   103,   103,   103,
      40,    56,    15,    56,   113,   103
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    63,    62,    64,
      62,    65,    65,    66,    66,    67,    68,    68,    68,    68,
      69,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    75,    76,    74,    77,    78,    74,    74,    79,
      79,    80,    80,    81,    82,    82,    83,    85,    84,    84,
      84,    86,    86,    87,    88,    87,    89,    89,    90,    90,
      91,    91,    91,    92,    91,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    99,    99,    99,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   103,
     103,   103,   103,   103,   103,   104,   104,   105,   105,   107,
     106,   108,   108,   109,   109,   110,   110,   110,   111,   111,
     111,   112,   113,   113,   114,   114,   114,   115,   115,   115,
     115,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   122,   122,   122,
     122,   123,   123,   123,   124,   124,   124,   124,   124,   125,
     125,   125,   126,   126,   127,   127,   128,   129,   130,   130
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     4,     0,
       3,     0,     1,     1,     2,     3,     1,     1,     2,     2,
       1,     1,     1,     0,     1,     1,     3,     1,     3,     1,
       1,     1,     0,     0,     7,     0,     0,     6,     2,     1,
       1,     1,     2,     3,     1,     3,     1,     0,     6,     4,
       2,     1,     3,     1,     0,     4,     2,     1,     1,     2,
       1,     3,     4,     0,     5,     0,     1,     0,     1,     1,
       2,     1,     3,     2,     2,     0,     1,     1,     1,     2,
       3,     3,     3,     4,     4,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     2,     0,
       5,     0,     1,     1,     2,     5,     7,     5,     5,     7,
       5,     5,     0,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     3,     1,     4,     4,     3,     3,     2,     2,
       0,     1,     1,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     1,     4,     2,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 37 "grammar.y"
    { printf("program:"); root=makeNode(N_PROGRAM,NIL,(yyvsp[0].idt)->init,NIL);   checkForwardReference(); }
#line 1711 "y.tab.c"
    break;

  case 3:
#line 40 "grammar.y"
                            {(yyval.idt)=(yyvsp[0].idt);}
#line 1717 "y.tab.c"
    break;

  case 4:
#line 41 "grammar.y"
                                            {(yyval.idt)=linkDeclaratorList((yyvsp[-1].idt),(yyvsp[0].idt));}
#line 1723 "y.tab.c"
    break;

  case 5:
#line 44 "grammar.y"
                            {(yyval.idt)=(yyvsp[0].idt);}
#line 1729 "y.tab.c"
    break;

  case 6:
#line 45 "grammar.y"
                            {(yyval.idt)=(yyvsp[0].idt);}
#line 1735 "y.tab.c"
    break;

  case 7:
#line 48 "grammar.y"
                                       { printf("funcdef:1"); (yyval.idt) = setFunctionDeclaratorSpecifier((yyvsp[0].idt),(yyvsp[-1].spect));printf("funcdefe:");}
#line 1741 "y.tab.c"
    break;

  case 8:
#line 48 "grammar.y"
                                                                                                                                                       {printf("funcAFTERcmp:");(yyval.idt)=setFunctionDeclaratorBody((yyvsp[-1].idt),(yyvsp[0].node));}
#line 1747 "y.tab.c"
    break;

  case 9:
#line 49 "grammar.y"
                 { printf("funcdef2:"); (yyval.idt) = setFunctionDeclaratorSpecifier((yyvsp[0].idt),makeSpecifier(int_type,0));printf("funcdefe:");}
#line 1753 "y.tab.c"
    break;

  case 10:
#line 49 "grammar.y"
                                                                                                                                                        {printf("funcsAFTERcmp:"); (yyval.idt)=setFunctionDeclaratorBody((yyvsp[-1].idt),(yyvsp[0].node));}
#line 1759 "y.tab.c"
    break;

  case 11:
#line 52 "grammar.y"
        {printf("declarationlistoptend:");(yyval.idt)=NIL;}
#line 1765 "y.tab.c"
    break;

  case 12:
#line 53 "grammar.y"
                         {printf("declistend:");(yyval.idt)=(yyvsp[0].idt);}
#line 1771 "y.tab.c"
    break;

  case 13:
#line 56 "grammar.y"
                    {printf("decst:");(yyval.idt)=(yyvsp[0].idt);}
#line 1777 "y.tab.c"
    break;

  case 14:
#line 57 "grammar.y"
                                    {printf("decst!!:");(yyval.idt)=linkDeclaratorList((yyvsp[-1].idt),(yyvsp[0].idt));}
#line 1783 "y.tab.c"
    break;

  case 15:
#line 60 "grammar.y"
                                                               {printf("decstn:");(yyval.idt)=setDeclaratorListSpecifier((yyvsp[-1].idt),(yyvsp[-2].spect)); }
#line 1789 "y.tab.c"
    break;

  case 16:
#line 63 "grammar.y"
                            {printf("decspec:");(yyval.spect)=makeSpecifier((yyvsp[0].typet),0);}
#line 1795 "y.tab.c"
    break;

  case 17:
#line 64 "grammar.y"
                                {printf("decspec:");(yyval.spect)=makeSpecifier(0,(yyvsp[0].num));}
#line 1801 "y.tab.c"
    break;

  case 18:
#line 65 "grammar.y"
                                            {printf("decspec:");(yyval.spect)=updateSpecifier((yyvsp[0].spect),(yyvsp[-1].typet),0);}
#line 1807 "y.tab.c"
    break;

  case 19:
#line 66 "grammar.y"
                                                        {printf("decspec:");(yyval.spect)=updateSpecifier((yyvsp[0].spect),0,(yyvsp[-1].num));}
#line 1813 "y.tab.c"
    break;

  case 20:
#line 69 "grammar.y"
                    {(yyval.num)=S_AUTO;}
#line 1819 "y.tab.c"
    break;

  case 21:
#line 70 "grammar.y"
                    {(yyval.num)=S_STATIC;}
#line 1825 "y.tab.c"
    break;

  case 22:
#line 71 "grammar.y"
                    {(yyval.num)=S_TYPEDEF;}
#line 1831 "y.tab.c"
    break;

  case 23:
#line 74 "grammar.y"
            {(yyval.idt)=makeDummyIdentifier();}
#line 1837 "y.tab.c"
    break;

  case 24:
#line 75 "grammar.y"
                            {(yyval.idt)=(yyvsp[0].idt);}
#line 1843 "y.tab.c"
    break;

  case 25:
#line 78 "grammar.y"
                            {(yyval.idt)=(yyvsp[0].idt);}
#line 1849 "y.tab.c"
    break;

  case 26:
#line 79 "grammar.y"
                                                        {(yyval.idt)=linkDeclaratorList((yyvsp[-2].idt),(yyvsp[0].idt));}
#line 1855 "y.tab.c"
    break;

  case 27:
#line 82 "grammar.y"
                     {(yyval.idt)=(yyvsp[0].idt);}
#line 1861 "y.tab.c"
    break;

  case 28:
#line 83 "grammar.y"
                                    { (yyval.idt)=setDeclaratorInit((yyvsp[-2].idt),(yyvsp[0].node));}
#line 1867 "y.tab.c"
    break;

  case 29:
#line 86 "grammar.y"
                                 {(yyval.typet)=(yyvsp[0].typet);}
#line 1873 "y.tab.c"
    break;

  case 30:
#line 87 "grammar.y"
                                 {(yyval.typet)=(yyvsp[0].typet);}
#line 1879 "y.tab.c"
    break;

  case 31:
#line 88 "grammar.y"
                            {(yyval.typet)=yylval.typet;}
#line 1885 "y.tab.c"
    break;

  case 32:
#line 91 "grammar.y"
                                 { (yyval.typet) = setTypeStructOrEnumIdentifier((yyvsp[-1].num),yyget_text(),ID_STRUCT); }
#line 1891 "y.tab.c"
    break;

  case 33:
#line 91 "grammar.y"
                                                                                                                 {(yyval.idt)=current_id; current_level++;}
#line 1897 "y.tab.c"
    break;

  case 34:
#line 91 "grammar.y"
                                                                                                                                                                                      {checkForwardReference();(yyval.typet)=setTypeField((yyvsp[-4].typet),(yyvsp[-1].idt)); current_level--; current_id=(yyvsp[-2].idt);}
#line 1903 "y.tab.c"
    break;

  case 35:
#line 92 "grammar.y"
                      {(yyval.typet)=makeType((yyvsp[0].num));}
#line 1909 "y.tab.c"
    break;

  case 36:
#line 92 "grammar.y"
                                                      {(yyval.idt)=current_id; current_level++;}
#line 1915 "y.tab.c"
    break;

  case 37:
#line 92 "grammar.y"
                                                                                                                           {checkForwardReference(); (yyval.typet)=setTypeField((yyvsp[-4].typet),(yyvsp[-1].idt)); current_level--; current_id=(yyvsp[-2].idt);}
#line 1921 "y.tab.c"
    break;

  case 38:
#line 93 "grammar.y"
                                 { (yyval.typet) = getTypeOfStructOrEnumRefIdentifier((yyvsp[-1].num),yyget_text(),ID_STRUCT); }
#line 1927 "y.tab.c"
    break;

  case 39:
#line 96 "grammar.y"
                    {(yyval.num)=T_STRUCT;}
#line 1933 "y.tab.c"
    break;

  case 40:
#line 97 "grammar.y"
                    {(yyval.num)=T_UNION;}
#line 1939 "y.tab.c"
    break;

  case 41:
#line 100 "grammar.y"
                                {(yyval.idt)=(yyvsp[0].idt);}
#line 1945 "y.tab.c"
    break;

  case 42:
#line 101 "grammar.y"
                                                    {(yyval.idt)=linkDeclaratorList((yyvsp[-1].idt),(yyvsp[0].idt));}
#line 1951 "y.tab.c"
    break;

  case 43:
#line 104 "grammar.y"
                                                     {(yyval.idt)=setStructDeclaratorListSpecifier((yyvsp[-1].idt),(yyvsp[-2].typet));}
#line 1957 "y.tab.c"
    break;

  case 44:
#line 107 "grammar.y"
                        {(yyval.idt)=(yyvsp[0].idt);}
#line 1963 "y.tab.c"
    break;

  case 45:
#line 108 "grammar.y"
                                                     {(yyval.idt)=linkDeclaratorList((yyvsp[-2].idt),(yyvsp[0].idt));}
#line 1969 "y.tab.c"
    break;

  case 46:
#line 111 "grammar.y"
                    {(yyval.idt)=(yyvsp[0].idt);}
#line 1975 "y.tab.c"
    break;

  case 47:
#line 114 "grammar.y"
                          {(yyval.typet)=setTypeStructOrEnumIdentifier(T_ENUM,yyget_text(),ID_ENUM);}
#line 1981 "y.tab.c"
    break;

  case 48:
#line 114 "grammar.y"
                                                                                                                             {(yyval.typet)=setTypeField((yyvsp[-3].typet),(yyvsp[-1].idt));}
#line 1987 "y.tab.c"
    break;

  case 49:
#line 115 "grammar.y"
                                            {(yyval.typet)=makeType(T_ENUM);}
#line 1993 "y.tab.c"
    break;

  case 50:
#line 116 "grammar.y"
                            {(yyval.typet)=getTypeOfStructOrEnumRefIdentifier(T_ENUM,yyget_text(),ID_ENUM);}
#line 1999 "y.tab.c"
    break;

  case 51:
#line 119 "grammar.y"
                    {(yyval.idt)=(yyvsp[0].idt);}
#line 2005 "y.tab.c"
    break;

  case 52:
#line 120 "grammar.y"
                                        {(yyval.idt)=linkDeclaratorList((yyvsp[-2].idt),(yyvsp[0].idt));}
#line 2011 "y.tab.c"
    break;

  case 53:
#line 123 "grammar.y"
                    {(yyval.idt)=setDeclaratorKind(makeIdentifier(yyget_text()),ID_ENUM_LITERAL);}
#line 2017 "y.tab.c"
    break;

  case 54:
#line 124 "grammar.y"
                 {(yyval.idt)=setDeclaratorKind(makeIdentifier(yyget_text()),ID_ENUM_LITERAL);}
#line 2023 "y.tab.c"
    break;

  case 55:
#line 124 "grammar.y"
                                                                                                             {(yyval.idt)=setDeclaratorInit((yyvsp[-2].idt),(yyvsp[0].node));}
#line 2029 "y.tab.c"
    break;

  case 56:
#line 127 "grammar.y"
                                    {(yyval.idt)=setDeclaratorElementType((yyvsp[0].idt),(yyvsp[-1].typet));}
#line 2035 "y.tab.c"
    break;

  case 57:
#line 128 "grammar.y"
                            {printf("dec2:");(yyval.idt)=(yyvsp[0].idt);}
#line 2041 "y.tab.c"
    break;

  case 58:
#line 131 "grammar.y"
            {(yyval.typet)=makeType(T_POINTER);}
#line 2047 "y.tab.c"
    break;

  case 59:
#line 132 "grammar.y"
                    {(yyval.typet)=setTypeElementType((yyvsp[0].typet),makeType(T_POINTER));}
#line 2053 "y.tab.c"
    break;

  case 60:
#line 135 "grammar.y"
                    {(yyval.idt)=makeIdentifier(yyget_text());printf("ddec: %s ",yyget_text());}
#line 2059 "y.tab.c"
    break;

  case 61:
#line 136 "grammar.y"
                            {(yyval.idt)=(yyvsp[-1].idt);}
#line 2065 "y.tab.c"
    break;

  case 62:
#line 137 "grammar.y"
                                                            {(yyval.idt)=setDeclaratorElementType((yyvsp[-3].idt),setTypeExpr(makeType(T_ARRAY),(yyvsp[-1].node)));}
#line 2071 "y.tab.c"
    break;

  case 63:
#line 138 "grammar.y"
                             {(yyval.idt)=current_id; current_level++;}
#line 2077 "y.tab.c"
    break;

  case 64:
#line 138 "grammar.y"
                                                                                                 {checkForwardReference(); current_id=(yyvsp[-2].idt); current_level--; (yyval.idt)=setDeclaratorElementType((yyvsp[-4].idt),setTypeField(makeType(T_FUNC),(yyvsp[-1].idt)));}
#line 2083 "y.tab.c"
    break;

  case 65:
#line 141 "grammar.y"
        {(yyval.node)=NIL;}
#line 2089 "y.tab.c"
    break;

  case 66:
#line 142 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2095 "y.tab.c"
    break;

  case 67:
#line 145 "grammar.y"
        {(yyval.idt)=NIL;}
#line 2101 "y.tab.c"
    break;

  case 68:
#line 146 "grammar.y"
                            {(yyval.idt)=(yyvsp[0].idt);}
#line 2107 "y.tab.c"
    break;

  case 69:
#line 149 "grammar.y"
                        {(yyval.idt)=(yyvsp[0].idt);}
#line 2113 "y.tab.c"
    break;

  case 70:
#line 150 "grammar.y"
                                {(yyval.idt)=linkDeclaratorList((yyvsp[-1].idt),setDeclaratorKind(makeDummyIdentifier(),ID_PARM));}
#line 2119 "y.tab.c"
    break;

  case 71:
#line 153 "grammar.y"
                            {(yyval.idt)=(yyvsp[0].idt);}
#line 2125 "y.tab.c"
    break;

  case 72:
#line 154 "grammar.y"
                                                    {(yyval.idt)=linkDeclaratorList((yyvsp[-2].idt),(yyvsp[0].idt));}
#line 2131 "y.tab.c"
    break;

  case 73:
#line 157 "grammar.y"
                                        {(yyval.idt)=setParameterDeclaratorSpecifier((yyvsp[0].idt),(yyvsp[-1].spect));}
#line 2137 "y.tab.c"
    break;

  case 74:
#line 158 "grammar.y"
                                                     {(yyval.idt)=setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(),(yyvsp[0].typet)),(yyvsp[-1].spect));}
#line 2143 "y.tab.c"
    break;

  case 75:
#line 161 "grammar.y"
        {(yyval.typet)=NIL;}
#line 2149 "y.tab.c"
    break;

  case 76:
#line 162 "grammar.y"
                            {(yyval.typet)=(yyvsp[0].typet);}
#line 2155 "y.tab.c"
    break;

  case 77:
#line 165 "grammar.y"
                {(yyval.typet)=makeType(T_POINTER);}
#line 2161 "y.tab.c"
    break;

  case 78:
#line 166 "grammar.y"
                                    {(yyval.typet)=(yyvsp[0].typet);}
#line 2167 "y.tab.c"
    break;

  case 79:
#line 167 "grammar.y"
                                            {(yyval.typet)=setTypeElementType((yyvsp[0].typet),makeType(T_POINTER));}
#line 2173 "y.tab.c"
    break;

  case 80:
#line 170 "grammar.y"
                                    {(yyval.typet)=(yyvsp[-1].typet);}
#line 2179 "y.tab.c"
    break;

  case 81:
#line 171 "grammar.y"
                                            {(yyval.typet)=setTypeExpr(makeType(T_ARRAY),(yyvsp[-1].node));}
#line 2185 "y.tab.c"
    break;

  case 82:
#line 172 "grammar.y"
                                        {(yyval.typet)=setTypeExpr(makeType(T_FUNC),(yyvsp[-1].idt)->init);}
#line 2191 "y.tab.c"
    break;

  case 83:
#line 173 "grammar.y"
                                                                        {(yyval.typet)=setTypeElementType((yyvsp[-3].typet),setTypeExpr(makeType(T_ARRAY),(yyvsp[-1].node)));}
#line 2197 "y.tab.c"
    break;

  case 84:
#line 174 "grammar.y"
                                                                        {(yyval.typet)=setTypeElementType((yyvsp[-3].typet),setTypeExpr(makeType(T_FUNC),(yyvsp[-1].idt)->init));}
#line 2203 "y.tab.c"
    break;

  case 85:
#line 177 "grammar.y"
                            {printf("init1:\n");(yyval.node)=makeNode(N_INIT_LIST_ONE,NIL,(yyvsp[0].node),NIL);}
#line 2209 "y.tab.c"
    break;

  case 86:
#line 178 "grammar.y"
                                    {printf("init2:\n");(yyval.node)=(yyvsp[-1].node);}
#line 2215 "y.tab.c"
    break;

  case 87:
#line 181 "grammar.y"
                        {(yyval.node)=makeNode(N_INIT_LIST,(yyvsp[0].node),NIL,makeNode(N_INIT_LIST_NIL,NIL,NIL,NIL));}
#line 2221 "y.tab.c"
    break;

  case 88:
#line 182 "grammar.y"
                                            {(yyval.node)=makeNodeList(N_INIT_LIST,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2227 "y.tab.c"
    break;

  case 89:
#line 185 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2233 "y.tab.c"
    break;

  case 90:
#line 186 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2239 "y.tab.c"
    break;

  case 91:
#line 187 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2245 "y.tab.c"
    break;

  case 92:
#line 188 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2251 "y.tab.c"
    break;

  case 93:
#line 189 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2257 "y.tab.c"
    break;

  case 94:
#line 190 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2263 "y.tab.c"
    break;

  case 95:
#line 193 "grammar.y"
                                                   {(yyval.node)=makeNode(N_STMT_LABEL_CASE,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2269 "y.tab.c"
    break;

  case 96:
#line 194 "grammar.y"
                                    {(yyval.node)=makeNode(N_STMT_LABEL_DEFAULT,NIL,(yyvsp[0].node),NIL);}
#line 2275 "y.tab.c"
    break;

  case 97:
#line 197 "grammar.y"
                {printf("stlist:"); (yyval.node)=makeNode(N_STMT_LIST,(yyvsp[0].node),NIL,makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL));}
#line 2281 "y.tab.c"
    break;

  case 98:
#line 198 "grammar.y"
                               {(yyval.node)=makeNodeList(N_STMT_LIST,(yyvsp[-1].node),(yyvsp[0].node));}
#line 2287 "y.tab.c"
    break;

  case 99:
#line 201 "grammar.y"
            {printf("cmpstmt:");(yyval.idt)=current_id; current_level++;}
#line 2293 "y.tab.c"
    break;

  case 100:
#line 201 "grammar.y"
                                                                                                                    {checkForwardReference(); printf("cmpend:");(yyval.node)=makeNode(N_STMT_COMPOUND,(yyvsp[-2].idt)->init,NIL,(yyvsp[-1].node)); current_id=(yyvsp[-3].idt); current_level--;}
#line 2299 "y.tab.c"
    break;

  case 101:
#line 204 "grammar.y"
        {printf("stmtlist:");(yyval.node)=makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL);}
#line 2305 "y.tab.c"
    break;

  case 102:
#line 205 "grammar.y"
                       {printf("stmtlist:");(yyval.node)=(yyvsp[0].node);}
#line 2311 "y.tab.c"
    break;

  case 103:
#line 208 "grammar.y"
                {printf("noexp;");(yyval.node)=makeNode(N_STMT_EMPTY,NIL,NIL,NIL);}
#line 2317 "y.tab.c"
    break;

  case 104:
#line 209 "grammar.y"
                            {printf("exp;");(yyval.node)=makeNode(N_STMT_EXPRESSION,NIL,(yyvsp[-1].node),NIL);}
#line 2323 "y.tab.c"
    break;

  case 105:
#line 212 "grammar.y"
                                            {(yyval.node)=makeNode(N_STMT_IF,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2329 "y.tab.c"
    break;

  case 106:
#line 213 "grammar.y"
                                                               {(yyval.node)=makeNode(N_STMT_IF_ELSE,(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2335 "y.tab.c"
    break;

  case 107:
#line 214 "grammar.y"
                                                    {(yyval.node)=makeNode(N_STMT_SWITCH,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2341 "y.tab.c"
    break;

  case 108:
#line 217 "grammar.y"
                                                {(yyval.node)=makeNode(N_STMT_WHILE,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2347 "y.tab.c"
    break;

  case 109:
#line 218 "grammar.y"
                                                               {(yyval.node)=makeNode(N_STMT_DO,(yyvsp[-5].node),NIL,(yyvsp[-2].node));}
#line 2353 "y.tab.c"
    break;

  case 110:
#line 219 "grammar.y"
                                                 {(yyval.node)=makeNode(N_STMT_FOR,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2359 "y.tab.c"
    break;

  case 111:
#line 222 "grammar.y"
                                                                     {(yyval.node)=makeNode(N_FOR_EXP,(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2365 "y.tab.c"
    break;

  case 112:
#line 225 "grammar.y"
        {(yyval.node)=NIL;}
#line 2371 "y.tab.c"
    break;

  case 113:
#line 226 "grammar.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2377 "y.tab.c"
    break;

  case 114:
#line 229 "grammar.y"
                                            {(yyval.node)=makeNode(N_STMT_RETURN,NIL,(yyvsp[-1].node),NIL);}
#line 2383 "y.tab.c"
    break;

  case 115:
#line 230 "grammar.y"
                            {(yyval.node)=makeNode(N_STMT_CONTINUE,NIL,NIL,NIL);}
#line 2389 "y.tab.c"
    break;

  case 116:
#line 231 "grammar.y"
                            {(yyval.node)=makeNode(N_STMT_BREAK,NIL,NIL,NIL);}
#line 2395 "y.tab.c"
    break;

  case 117:
#line 235 "grammar.y"
                        {printf("priident:");(yyval.node)=makeNode(N_EXP_IDENT,NIL,NULL,NIL); printf("IDENT: %s\n",yyget_text());}
#line 2401 "y.tab.c"
    break;

  case 118:
#line 236 "grammar.y"
                        {printf("priint:");(yyval.node)=makeNode(N_EXP_INT_CONST,NIL,NULL,NIL);}
#line 2407 "y.tab.c"
    break;

  case 119:
#line 237 "grammar.y"
                        {(yyval.node)=makeNode(N_EXP_FLOAT_CONST,NIL,NULL,NIL);}
#line 2413 "y.tab.c"
    break;

  case 120:
#line 238 "grammar.y"
                        {(yyval.node)=makeNode(N_EXP_CHAR_CONST,NIL,NULL,NIL);}
#line 2419 "y.tab.c"
    break;

  case 121:
#line 239 "grammar.y"
                        {(yyval.node)=makeNode(N_EXP_STRING_LITERAL,NIL,NULL,NIL);}
#line 2425 "y.tab.c"
    break;

  case 122:
#line 240 "grammar.y"
                            {printf("priexp:");(yyval.node)=(yyvsp[-1].node);}
#line 2431 "y.tab.c"
    break;

  case 123:
#line 244 "grammar.y"
                                {printf("priexp:");(yyval.node)=(yyvsp[0].node);}
#line 2437 "y.tab.c"
    break;

  case 124:
#line 245 "grammar.y"
                                                {printf("postexp:");(yyval.node)=makeNode(N_EXP_ARRAY,(yyvsp[-3].node),NIL,(yyvsp[-1].node));}
#line 2443 "y.tab.c"
    break;

  case 125:
#line 246 "grammar.y"
                                                            {printf("postexp:");(yyval.node)=makeNode(N_EXP_FUNCTION_CALL,(yyvsp[-3].node),NIL,(yyvsp[-1].node));}
#line 2449 "y.tab.c"
    break;

  case 126:
#line 247 "grammar.y"
                                                {printf("postexp:");(yyval.node)=makeNode(N_EXP_STRUCT,(yyvsp[-2].node),NIL,NULL);}
#line 2455 "y.tab.c"
    break;

  case 127:
#line 248 "grammar.y"
                                                {printf("postexp:");(yyval.node)=makeNode(N_EXP_ARROW,(yyvsp[-2].node),NIL,NULL);}
#line 2461 "y.tab.c"
    break;

  case 128:
#line 249 "grammar.y"
                                    {printf("postexp:");(yyval.node)=makeNode(N_EXP_POST_INC,NIL,(yyvsp[-1].node),NIL);}
#line 2467 "y.tab.c"
    break;

  case 129:
#line 250 "grammar.y"
                                    {printf("postexp:");(yyval.node)=makeNode(N_EXP_POST_DEC,NIL,(yyvsp[-1].node),NIL);}
#line 2473 "y.tab.c"
    break;

  case 130:
#line 253 "grammar.y"
        {(yyval.node)=makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL);}
#line 2479 "y.tab.c"
    break;

  case 131:
#line 254 "grammar.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2485 "y.tab.c"
    break;

  case 132:
#line 257 "grammar.y"
                            {(yyval.node)=makeNode(N_ARG_LIST,(yyvsp[0].node),NIL,makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL));}
#line 2491 "y.tab.c"
    break;

  case 133:
#line 258 "grammar.y"
                                                        {(yyval.node)=makeNodeList(N_ARG_LIST,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2497 "y.tab.c"
    break;

  case 134:
#line 261 "grammar.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2503 "y.tab.c"
    break;

  case 135:
#line 262 "grammar.y"
                                {(yyval.node)=makeNode(N_EXP_PRE_INC,NIL,(yyvsp[0].node),NIL);}
#line 2509 "y.tab.c"
    break;

  case 136:
#line 263 "grammar.y"
                                {(yyval.node)=makeNode(N_EXP_PRE_DEC,NIL,(yyvsp[0].node),NIL);}
#line 2515 "y.tab.c"
    break;

  case 137:
#line 264 "grammar.y"
                                {(yyval.node)=makeNode(N_EXP_AMP,NIL,(yyvsp[0].node),NIL);}
#line 2521 "y.tab.c"
    break;

  case 138:
#line 265 "grammar.y"
                                {(yyval.node)=makeNode(N_EXP_STAR,NIL,(yyvsp[0].node),NIL);}
#line 2527 "y.tab.c"
    break;

  case 139:
#line 266 "grammar.y"
                                {(yyval.node)=makeNode(N_EXP_NOT,NIL,(yyvsp[0].node),NIL);}
#line 2533 "y.tab.c"
    break;

  case 140:
#line 267 "grammar.y"
                                {(yyval.node)=makeNode(N_EXP_MINUS,NIL,(yyvsp[0].node),NIL);}
#line 2539 "y.tab.c"
    break;

  case 141:
#line 268 "grammar.y"
                                {(yyval.node)=makeNode(N_EXP_PLUS,NIL,(yyvsp[0].node),NIL);}
#line 2545 "y.tab.c"
    break;

  case 142:
#line 269 "grammar.y"
                                    {(yyval.node)=makeNode(N_EXP_SIZE_EXP,NIL,(yyvsp[0].node),NIL);}
#line 2551 "y.tab.c"
    break;

  case 143:
#line 270 "grammar.y"
                                        {(yyval.node)=makeNode(N_EXP_SIZE_TYPE,NIL,(yyvsp[-1].typet)->expr,NIL);}
#line 2557 "y.tab.c"
    break;

  case 144:
#line 273 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2563 "y.tab.c"
    break;

  case 145:
#line 274 "grammar.y"
                                                {(yyval.node)=makeNode(N_EXP_CAST,(yyvsp[-2].typet)->expr,NIL,(yyvsp[0].node));}
#line 2569 "y.tab.c"
    break;

  case 146:
#line 277 "grammar.y"
                                                        {(yyval.typet)=setTypeNameSpecifier((yyvsp[0].typet),(yyvsp[-1].spect));}
#line 2575 "y.tab.c"
    break;

  case 147:
#line 280 "grammar.y"
                        {(yyval.node)=(yyvsp[0].node);}
#line 2581 "y.tab.c"
    break;

  case 148:
#line 281 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_MUL,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2587 "y.tab.c"
    break;

  case 149:
#line 282 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_DIV,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2593 "y.tab.c"
    break;

  case 150:
#line 283 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_MOD,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2599 "y.tab.c"
    break;

  case 151:
#line 286 "grammar.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2605 "y.tab.c"
    break;

  case 152:
#line 287 "grammar.y"
                                                            {(yyval.node)=makeNode(N_EXP_ADD,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2611 "y.tab.c"
    break;

  case 153:
#line 288 "grammar.y"
                                                            {(yyval.node)=makeNode(N_EXP_SUB,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2617 "y.tab.c"
    break;

  case 154:
#line 291 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2623 "y.tab.c"
    break;

  case 155:
#line 292 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_LSS,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2629 "y.tab.c"
    break;

  case 156:
#line 293 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_GTR,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2635 "y.tab.c"
    break;

  case 157:
#line 294 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_LEQ,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2641 "y.tab.c"
    break;

  case 158:
#line 295 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_GEQ,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2647 "y.tab.c"
    break;

  case 159:
#line 298 "grammar.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2653 "y.tab.c"
    break;

  case 160:
#line 299 "grammar.y"
                                                    {(yyval.node)=makeNode(N_EXP_EQL,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2659 "y.tab.c"
    break;

  case 161:
#line 300 "grammar.y"
                                                    {(yyval.node)=makeNode(N_EXP_NEQ,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2665 "y.tab.c"
    break;

  case 162:
#line 304 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2671 "y.tab.c"
    break;

  case 163:
#line 305 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_OR,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2677 "y.tab.c"
    break;

  case 164:
#line 308 "grammar.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2683 "y.tab.c"
    break;

  case 165:
#line 309 "grammar.y"
                                                        {(yyval.node)=makeNode(N_EXP_OR,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2689 "y.tab.c"
    break;

  case 166:
#line 312 "grammar.y"
                    {(yyval.node)=(yyvsp[0].node);}
#line 2695 "y.tab.c"
    break;

  case 167:
#line 315 "grammar.y"
                            {(yyval.node)=(yyvsp[0].node);}
#line 2701 "y.tab.c"
    break;

  case 168:
#line 319 "grammar.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 2707 "y.tab.c"
    break;

  case 169:
#line 320 "grammar.y"
                                            {printf("assigexp=:");(yyval.node)=makeNode(N_EXP_ASSIGN,(yyvsp[-2].node),NIL,(yyvsp[0].node));}
#line 2713 "y.tab.c"
    break;


#line 2717 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 322 "grammar.y"

#include "print.h"
extern char *yytext;
int yyerror(const char *s) {fprintf(stderr,"why line %d: %s near '%s'\n",line_no,s,yytext);}
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
