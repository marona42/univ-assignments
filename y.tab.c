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

#ifndef YYSTYPE_IS_DECLARED
    #define YYSTYPE_IS_DECLARED 1
    typedef long YYSTYPE;
#endif
    #include "y.tab.h"
    #include <stdio.h>
    #include "builder.h"
    extern int line_no, syntax_err, current_level;
    extern A_NODE *root;
    extern A_ID *current_id;
    extern A_TYPE *int_type;

    int yyerror();
    int yylex();
    FILE *yyin;

#line 88 "y.tab.c"

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
#define YYLAST   527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    29,    29,    33,    34,    37,    38,    41,    41,    42,
      42,    45,    46,    49,    50,    53,    56,    57,    58,    59,
      62,    63,    64,    67,    68,    71,    72,    75,    76,    79,
      80,    81,    84,    84,    84,    85,    85,    85,    86,    89,
      90,    93,    94,    97,   100,   101,   104,   107,   107,   108,
     109,   112,   113,   116,   117,   117,   120,   121,   124,   125,
     128,   129,   130,   131,   131,   134,   135,   138,   139,   142,
     143,   146,   147,   150,   151,   154,   155,   158,   159,   160,
     163,   164,   165,   166,   167,   170,   171,   174,   175,   178,
     179,   180,   181,   182,   183,   186,   187,   190,   191,   194,
     194,   197,   198,   201,   202,   205,   206,   207,   210,   211,
     212,   215,   218,   219,   222,   223,   224,   228,   229,   230,
     231,   232,   233,   237,   238,   239,   240,   241,   242,   243,
     246,   247,   250,   251,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   266,   267,   270,   273,   274,   275,
     276,   279,   280,   281,   284,   285,   286,   287,   288,   291,
     292,   293,   297,   298,   301,   302,   305,   308,   312,   313
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
  "UNION_SYM", "WHILE_SYM", "INT_TYPE", "FLOAT_TYPE", "CHAR_TYPE",
  "VOID_TYPE", "PPLUS", "MMINUS", "ARROW", "GREAT", "LESS", "GREATEQ",
  "LESSEQ", "EQU", "NEQ", "AAND", "OOR", "PPPOINT", "LPAR", "RPAR",
  "LLPAR", "RLPAR", "LMPAR", "RMPAR", "COLON", "POINT", "COMMA", "EXC",
  "STAR", "DIV", "PER", "AND", "PLUS", "MINUS", "ASSIGN", "SEMCOLON",
  "SLASH", "$accept", "program", "translation_unit",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF (-209)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,  -209,  -209,  -209,    13,  -209,  -209,  -209,  -209,    15,
     -23,    82,    31,  -209,  -209,  -209,    15,   188,   188,  -209,
      87,  -209,  -209,    22,    21,    51,    94,    62,  -209,  -209,
    -209,    79,    71,  -209,   -14,  -209,  -209,    81,   100,   102,
      21,  -209,   387,   113,   103,   -17,  -209,  -209,  -209,    15,
     323,   102,   120,  -209,  -209,  -209,   188,  -209,  -209,  -209,
    -209,  -209,   394,   428,   428,   331,   387,   387,   387,   387,
     387,   123,  -209,   125,   114,  -209,    78,    29,   195,    77,
     136,   139,  -209,  -209,  -209,    94,   118,  -209,    94,  -209,
     135,   323,  -209,  -209,  -209,  -209,   199,   188,    14,   151,
    -209,    -7,  -209,   288,  -209,   387,  -209,  -209,   156,   157,
    -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,   198,
     387,   387,   201,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   387,     3,   387,  -209,
    -209,    54,   199,    15,    92,  -209,   230,   188,  -209,    15,
     448,   387,  -209,    35,  -209,  -209,    32,  -209,  -209,   188,
      50,   162,   387,  -209,  -209,   167,   165,  -209,   171,  -209,
    -209,  -209,  -209,  -209,    78,    78,    29,    29,    29,    29,
     195,   195,    77,   136,  -209,  -209,  -209,   323,   130,   -10,
    -209,  -209,  -209,  -209,   158,   387,   160,   173,   230,   180,
     182,   387,   202,   203,  -209,  -209,  -209,   230,  -209,   190,
    -209,  -209,  -209,  -209,   191,  -209,   208,   210,   209,    32,
     188,   387,  -209,   474,    68,  -209,  -209,  -209,  -209,   387,
    -209,  -209,  -209,    15,  -209,  -209,   214,  -209,   230,   238,
     387,   387,   205,  -209,   387,   387,  -209,  -209,  -209,  -209,
    -209,  -209,   222,   221,  -209,  -209,   230,  -209,   225,   226,
     211,   228,  -209,   231,   232,  -209,  -209,  -209,   387,   230,
     387,   230,   230,   230,   234,  -209,   219,   254,  -209,  -209,
     220,   387,   230,  -209,  -209,  -209
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
    -209,  -209,  -209,   262,  -209,  -209,  -209,  -209,  -209,   -71,
       7,  -209,  -209,  -209,   235,   -59,  -209,  -209,  -209,  -209,
    -209,  -209,   143,  -116,  -209,    48,  -209,  -209,   204,   212,
    -209,    -6,    -9,   -19,  -209,  -124,   -54,  -209,  -209,   140,
     138,  -132,  -136,   -75,  -209,  -108,  -209,  -209,    -3,  -209,
    -209,  -209,  -209,  -209,  -209,  -208,  -209,  -209,  -209,  -209,
    -209,    57,   -55,  -209,     8,   128,    38,   166,   169,  -209,
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
      25,     1,     1,   109,    35,    36,   148,   218,   193,     1,
      10,    87,   260,    -7,    88,   158,    55,   143,     1,     2,
       3,   233,     1,    90,   159,    50,    93,     4,    94,    83,
     234,   184,     5,     6,    88,     7,     8,   150,     9,   151,
      26,   109,   276,   109,    41,     9,    42,    10,    10,   171,
     172,   173,   193,   284,     9,   220,   215,   221,   150,   168,
     151,   170,    29,   143,    10,   143,   127,   128,   219,   153,
     239,   217,   152,   223,    37,   151,   185,   253,   -47,   246,
       2,    44,   186,    10,   149,   187,    47,   227,     4,    83,
     160,   223,   231,   151,     6,   133,   134,     8,   254,   104,
     106,   107,    49,   110,   110,   110,   110,   110,   -32,   143,
     257,   124,   125,   126,    40,   174,   175,   191,     2,    48,
     192,   153,    93,    90,    27,    83,     4,    53,   267,    54,
     236,   224,     6,    83,   149,     8,   117,   118,   119,   243,
      85,   275,   -54,   277,   278,   279,   252,    95,   120,   116,
     121,   180,   181,   123,   285,   122,   135,   138,   232,    83,
     136,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,    50,   157,     2,     3,   243,   261,
     162,   163,   263,   264,     4,   164,   226,     2,   169,     5,
       6,   228,     7,     8,   224,     4,   229,   230,   235,   110,
     237,     6,   238,   240,     8,   241,   274,   191,   243,   129,
     130,   131,   132,    57,    58,    59,    60,    61,   247,   243,
     194,   195,   196,   197,   198,   244,   245,   199,   200,   201,
      62,   248,   249,   202,   250,   251,   203,   176,   177,   178,
     179,    63,    64,   256,   258,   262,   265,   266,   268,   282,
     269,   270,   271,    65,    30,   272,   273,    54,   280,   281,
     283,   255,    66,    67,    89,   188,    68,    69,    70,   137,
     204,    57,    58,    59,    60,    61,     2,     3,   225,   222,
     139,   182,     0,     0,     4,   183,     0,     0,    62,     5,
       6,     0,     7,     8,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    65,     0,     0,    57,    58,    59,    60,    61,     2,
      66,    67,     0,    62,    68,    69,    70,     4,     0,     0,
       0,    62,     0,     6,    63,    64,     8,     0,     0,     0,
       0,     0,    63,    64,     0,     0,    65,     0,     0,     0,
      91,     0,     0,     0,    65,    66,    67,     0,     0,    68,
      69,    70,     0,    66,    67,     0,     0,    68,    69,    70,
      57,    58,    59,    60,    61,     0,     0,    57,    58,    59,
      60,    61,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,    63,    64,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
      65,    57,    58,    59,    60,    61,     0,   103,     0,    66,
      67,     0,     0,    68,    69,    70,    66,    67,    62,     0,
      68,    69,    70,     0,     0,     1,     2,     3,     0,    63,
      64,     0,     0,     0,     4,     0,     0,     0,     0,     5,
       6,   105,     7,     8,     0,     0,     0,     0,     0,     0,
      66,    67,     2,     3,    68,    69,    70,     0,     0,     0,
       4,   150,     0,   151,     0,     5,     6,     0,     7,     8,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,     0,   151,
       0,     0,     0,     0,     0,     0,     0,    10
};

static const yytype_int16 yycheck[] =
{
      42,    10,    56,     9,    23,    50,    65,     0,    50,   120,
      16,    66,    67,    68,    69,    70,    91,   153,   150,    12,
       7,     7,     7,    65,    17,    18,    97,   151,   144,     7,
      53,    48,   240,    47,    51,    42,    39,    96,     7,     8,
       9,    51,     7,    49,    51,    59,    91,    16,    51,    91,
      60,    48,    21,    22,    51,    24,    25,    43,    43,    45,
      47,   103,   270,   105,    43,    43,    45,    53,    53,   124,
     125,   126,   188,   281,    43,    43,   147,    45,    43,   121,
      45,   123,     0,   142,    53,   144,    57,    58,   224,    98,
     198,   223,    98,    43,     7,    45,   138,   221,    47,   207,
       8,     7,    48,    53,    97,    51,    44,   162,    16,   151,
     103,    43,   187,    45,    22,    38,    39,    25,   229,    62,
      63,    64,    51,    66,    67,    68,    69,    70,    47,   188,
     238,    53,    54,    55,   153,   127,   128,   143,     8,    60,
      48,   150,   187,   149,   150,   187,    16,    47,   256,    47,
     195,   160,    22,   195,   147,    25,    31,    32,    33,   201,
      47,   269,    59,   271,   272,   273,   220,    47,    43,    46,
      45,   133,   134,    59,   282,    50,    40,    59,    48,   221,
      41,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,    59,    44,     8,     9,   240,   241,
      44,    44,   244,   245,    16,     7,    44,     8,     7,    21,
      22,    44,    24,    25,   223,    16,    51,    46,    60,   162,
      60,    22,    49,    43,    25,    43,   268,   233,   270,    34,
      35,    36,    37,     3,     4,     5,     6,     7,    48,   281,
      10,    11,    12,    13,    14,    43,    43,    17,    18,    19,
      20,    60,    44,    23,    44,    46,    26,   129,   130,   131,
     132,    31,    32,    49,    26,    60,    44,    46,    43,    15,
      44,    60,    44,    43,    12,    44,    44,    47,    44,    60,
      60,   233,    52,    53,    49,   142,    56,    57,    58,    85,
      60,     3,     4,     5,     6,     7,     8,     9,   160,   159,
      88,   135,    -1,    -1,    16,   136,    -1,    -1,    20,    21,
      22,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    43,    -1,    -1,     3,     4,     5,     6,     7,     8,
      52,    53,    -1,    20,    56,    57,    58,    16,    -1,    -1,
      -1,    20,    -1,    22,    31,    32,    25,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    43,    52,    53,    -1,    -1,    56,
      57,    58,    -1,    52,    53,    -1,    -1,    56,    57,    58,
       3,     4,     5,     6,     7,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      43,     3,     4,     5,     6,     7,    -1,    43,    -1,    52,
      53,    -1,    -1,    56,    57,    58,    52,    53,    20,    -1,
      56,    57,    58,    -1,    -1,     7,     8,     9,    -1,    31,
      32,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    21,
      22,    43,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,     8,     9,    56,    57,    58,    -1,    -1,    -1,
      16,    43,    -1,    45,    -1,    21,    22,    -1,    24,    25,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    16,    21,    22,    24,    25,    43,
      53,    63,    64,    65,    66,    71,    72,    73,    77,    78,
      83,    88,    93,    94,    95,     7,    47,    93,    94,     0,
      65,    74,    75,    76,    93,    72,    72,     7,    81,    68,
      95,    43,    45,    89,     7,    90,    91,    44,    60,    51,
      59,    67,    79,    47,    47,   110,    96,     3,     4,     5,
       6,     7,    20,    31,    32,    43,    52,    53,    56,    57,
      58,    97,   119,   120,   123,   124,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    47,    92,    48,    51,    76,
      93,    47,   105,   132,   110,    47,    82,   111,    72,    98,
      99,   100,   101,    43,   123,    43,   123,   123,    77,   133,
     123,   124,   124,   124,   124,   124,    46,    31,    32,    33,
      43,    45,    50,    59,    53,    54,    55,    57,    58,    34,
      35,    36,    37,    38,    39,    40,    41,    90,    59,    91,
     105,   106,    80,    77,    84,    85,    69,    70,    71,    72,
      43,    45,    93,    94,   102,   103,   104,    44,    42,    51,
      72,   125,    44,    44,     7,   121,   122,   134,   133,     7,
     133,   124,   124,   124,   126,   126,   127,   127,   127,   127,
     128,   128,   129,   130,    48,   133,    48,    51,    84,    86,
      87,    93,    48,    85,    10,    11,    12,    13,    14,    17,
      18,    19,    23,    26,    60,   107,   108,   109,   110,   112,
     113,   114,   115,   118,   133,    71,    98,   103,    97,   104,
      43,    45,   101,    43,    94,   102,    44,   124,    44,    51,
      46,   105,    48,    51,    60,    60,   132,    60,    49,   107,
      43,    43,   117,   133,    43,    43,   107,    48,    60,    44,
      44,    46,    98,    97,   134,    87,    49,   107,    26,   116,
     117,   133,    60,   133,   133,    44,    46,   107,    43,    44,
      60,    44,    44,    44,   133,   107,   117,   107,   107,   107,
      44,    60,    15,    60,   117,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    67,    66,    68,
      66,    69,    69,    70,    70,    71,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    79,    80,    78,    81,    82,    78,    78,    83,
      83,    84,    84,    85,    86,    86,    87,    89,    88,    88,
      88,    90,    90,    91,    92,    91,    93,    93,    94,    94,
      95,    95,    95,    96,    95,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   103,
     104,   104,   104,   104,   104,   105,   105,   106,   106,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   109,   111,
     110,   112,   112,   113,   113,   114,   114,   114,   115,   115,
     115,   116,   117,   117,   118,   118,   118,   119,   119,   119,
     119,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   124,   124,   125,   126,   126,   126,
     126,   127,   127,   127,   128,   128,   128,   128,   128,   129,
     129,   129,   130,   130,   131,   131,   132,   133,   134,   134
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
#line 30 "grammar.y"
    { root=makeNode(N_PROGRAM,NIL,yyvsp[0],NIL);   checkForwardReference(); }
#line 1712 "y.tab.c"
    break;

  case 3:
#line 33 "grammar.y"
                            {yyval=yyvsp[0];}
#line 1718 "y.tab.c"
    break;

  case 4:
#line 34 "grammar.y"
                                            {yyval=linkDeclaratorList(yyvsp[-1],yyvsp[0]);}
#line 1724 "y.tab.c"
    break;

  case 5:
#line 37 "grammar.y"
                            {yyval=yyvsp[0];}
#line 1730 "y.tab.c"
    break;

  case 6:
#line 38 "grammar.y"
                            {yyval=yyvsp[0];}
#line 1736 "y.tab.c"
    break;

  case 7:
#line 41 "grammar.y"
                                        { yyval = setFunctionDeclaratorSpecifier(yyvsp[0],yyvsp[-1]);}
#line 1742 "y.tab.c"
    break;

  case 8:
#line 41 "grammar.y"
                                                                                                          {yyval=setFunctionDeclaratorBody(yyvsp[-1],yyvsp[0]);}
#line 1748 "y.tab.c"
    break;

  case 9:
#line 42 "grammar.y"
                 { yyval = setFunctionDeclaratorSpecifier(yyvsp[0],makeSpecifier(int_type,0));}
#line 1754 "y.tab.c"
    break;

  case 10:
#line 42 "grammar.y"
                                                                                                          {yyval=setFunctionDeclaratorBody(yyvsp[-1],yyvsp[0]);}
#line 1760 "y.tab.c"
    break;

  case 11:
#line 45 "grammar.y"
        {yyval=NIL;}
#line 1766 "y.tab.c"
    break;

  case 12:
#line 46 "grammar.y"
                         {yyval=yyvsp[0];}
#line 1772 "y.tab.c"
    break;

  case 13:
#line 49 "grammar.y"
                    {yyval=yyvsp[0];}
#line 1778 "y.tab.c"
    break;

  case 14:
#line 50 "grammar.y"
                                    {yyval=linkDeclaratorList(yyvsp[-1],yyvsp[0]);}
#line 1784 "y.tab.c"
    break;

  case 15:
#line 53 "grammar.y"
                                                               {yyval=setDeclaratorListSpecifier(yyvsp[-1],yyvsp[-1]); }
#line 1790 "y.tab.c"
    break;

  case 16:
#line 56 "grammar.y"
                            {yyval=makeSpecifier(yyvsp[0],0);}
#line 1796 "y.tab.c"
    break;

  case 17:
#line 57 "grammar.y"
                                {yyval=makeSpecifier(0,yyvsp[0]);}
#line 1802 "y.tab.c"
    break;

  case 18:
#line 58 "grammar.y"
                                            {yyval=updateSpecifier(yyvsp[0],yyvsp[-1],0);}
#line 1808 "y.tab.c"
    break;

  case 19:
#line 59 "grammar.y"
                                                        {yyval=updateSpecifier(yyvsp[0],0,yyvsp[-1]);}
#line 1814 "y.tab.c"
    break;

  case 20:
#line 62 "grammar.y"
                    {yyval=S_AUTO;}
#line 1820 "y.tab.c"
    break;

  case 21:
#line 63 "grammar.y"
                    {yyval=S_STATIC;}
#line 1826 "y.tab.c"
    break;

  case 22:
#line 64 "grammar.y"
                    {yyval=S_TYPEDEF;}
#line 1832 "y.tab.c"
    break;

  case 23:
#line 67 "grammar.y"
            {yyval=makeDummyIdentifier();}
#line 1838 "y.tab.c"
    break;

  case 24:
#line 68 "grammar.y"
                            {yyval=yyvsp[0];}
#line 1844 "y.tab.c"
    break;

  case 25:
#line 71 "grammar.y"
                            {yyval=yyvsp[0];}
#line 1850 "y.tab.c"
    break;

  case 26:
#line 72 "grammar.y"
                                                        {yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]);}
#line 1856 "y.tab.c"
    break;

  case 27:
#line 75 "grammar.y"
                     {yyval=yyvsp[0];}
#line 1862 "y.tab.c"
    break;

  case 28:
#line 76 "grammar.y"
                                    {yyval=setDeclaratorInit(yyvsp[-2],yyvsp[0]);}
#line 1868 "y.tab.c"
    break;

  case 29:
#line 79 "grammar.y"
                                 {yyval=yyvsp[0];}
#line 1874 "y.tab.c"
    break;

  case 30:
#line 80 "grammar.y"
                                 {yyval=yyvsp[0];}
#line 1880 "y.tab.c"
    break;

  case 31:
#line 81 "grammar.y"
                            {yyval=yyvsp[0];}
#line 1886 "y.tab.c"
    break;

  case 32:
#line 84 "grammar.y"
                                 { yyval = setTypeStructOrEnumIdentifier(yyvsp[-1],yyvsp[0],ID_STRUCT); }
#line 1892 "y.tab.c"
    break;

  case 33:
#line 84 "grammar.y"
                                                                                                {yyval=current_id; current_level++;}
#line 1898 "y.tab.c"
    break;

  case 34:
#line 84 "grammar.y"
                                                                                                                                                                {checkForwardReference();yyval=setTypeField(yyvsp[-4],yyvsp[-1]); current_level--; current_id=yyvsp[-2];}
#line 1904 "y.tab.c"
    break;

  case 35:
#line 85 "grammar.y"
                      {yyval=makeType(yyvsp[0]);}
#line 1910 "y.tab.c"
    break;

  case 36:
#line 85 "grammar.y"
                                               {yyval=current_id; current_level++;}
#line 1916 "y.tab.c"
    break;

  case 37:
#line 85 "grammar.y"
                                                                                                               {checkForwardReference(); yyval=setTypeField(yyvsp[-4],yyvsp[-1]); current_level--; current_id=yyvsp[-2];}
#line 1922 "y.tab.c"
    break;

  case 38:
#line 86 "grammar.y"
                                 { yyval = getTypeOfStructOrEnumRefIdentifier(yyvsp[-1],yyvsp[0],ID_STRUCT); }
#line 1928 "y.tab.c"
    break;

  case 39:
#line 89 "grammar.y"
                    {yyval=T_STRUCT;}
#line 1934 "y.tab.c"
    break;

  case 40:
#line 90 "grammar.y"
                    {yyval=T_UNION;}
#line 1940 "y.tab.c"
    break;

  case 41:
#line 93 "grammar.y"
                                {yyval=yyvsp[0];}
#line 1946 "y.tab.c"
    break;

  case 42:
#line 94 "grammar.y"
                                                    {yyval=linkDeclaratorList(yyvsp[-1],yyvsp[0]);}
#line 1952 "y.tab.c"
    break;

  case 43:
#line 97 "grammar.y"
                                                     {yyval=setStructDeclaratorListSpecifier(yyvsp[-1],yyvsp[-2]);}
#line 1958 "y.tab.c"
    break;

  case 44:
#line 100 "grammar.y"
                        {yyval=yyvsp[0];}
#line 1964 "y.tab.c"
    break;

  case 45:
#line 101 "grammar.y"
                                                     {yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]);}
#line 1970 "y.tab.c"
    break;

  case 46:
#line 104 "grammar.y"
                    {yyval=yyvsp[0];}
#line 1976 "y.tab.c"
    break;

  case 47:
#line 107 "grammar.y"
                          {yyval=setTypeStructOrEnumIdentifier(T_ENUM,yyvsp[0],ID_ENUM);}
#line 1982 "y.tab.c"
    break;

  case 48:
#line 107 "grammar.y"
                                                                                                            {yyval=setTypeField(yyvsp[-3],yyvsp[-1]);}
#line 1988 "y.tab.c"
    break;

  case 49:
#line 108 "grammar.y"
                                            {yyval=makeType(T_ENUM);}
#line 1994 "y.tab.c"
    break;

  case 50:
#line 109 "grammar.y"
                            {yyval=getTypeOfStructOrEnumRefIdentifier(T_ENUM,yyvsp[0],ID_ENUM);}
#line 2000 "y.tab.c"
    break;

  case 51:
#line 112 "grammar.y"
                    {yyval=yyvsp[0];}
#line 2006 "y.tab.c"
    break;

  case 52:
#line 113 "grammar.y"
                                        {yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]);}
#line 2012 "y.tab.c"
    break;

  case 53:
#line 116 "grammar.y"
                    {yyval=setDeclaratorKind(makeIdentifier(yyvsp[0]),ID_ENUM_LITERAL);}
#line 2018 "y.tab.c"
    break;

  case 54:
#line 117 "grammar.y"
                 {yyval=setDeclaratorKind(makeIdentifier(yyvsp[0]),ID_ENUM_LITERAL);}
#line 2024 "y.tab.c"
    break;

  case 55:
#line 117 "grammar.y"
                                                                                              {yyval=setDeclaratorInit(yyvsp[-2],yyvsp[0]);}
#line 2030 "y.tab.c"
    break;

  case 56:
#line 120 "grammar.y"
                                    {yyval=setDeclaratorElementType(yyvsp[0],yyvsp[-1]);}
#line 2036 "y.tab.c"
    break;

  case 57:
#line 121 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2042 "y.tab.c"
    break;

  case 58:
#line 124 "grammar.y"
            {yyval=makeType(T_POINTER);}
#line 2048 "y.tab.c"
    break;

  case 59:
#line 125 "grammar.y"
                    {yyval=setTypeElementType(yyvsp[0],makeType(T_POINTER));}
#line 2054 "y.tab.c"
    break;

  case 60:
#line 128 "grammar.y"
                    {yyval=makeIdentifier(yyvsp[0]);}
#line 2060 "y.tab.c"
    break;

  case 61:
#line 129 "grammar.y"
                            {yyval=yyvsp[-1];}
#line 2066 "y.tab.c"
    break;

  case 62:
#line 130 "grammar.y"
                                                            {yyval=setDeclaratorElementType(yyvsp[-3],setTypeExpr(makeType(T_ARRAY),yyvsp[-1]));}
#line 2072 "y.tab.c"
    break;

  case 63:
#line 131 "grammar.y"
                             {yyval=current_id; current_level++;}
#line 2078 "y.tab.c"
    break;

  case 64:
#line 131 "grammar.y"
                                                                                            {checkForwardReference(); current_id=yyvsp[-2]; current_level--; yyval=setDeclaratorElementType(yyvsp[-4],setTypeField(makeType(T_FUNC),yyvsp[-1]));}
#line 2084 "y.tab.c"
    break;

  case 65:
#line 134 "grammar.y"
        {yyval=NIL;}
#line 2090 "y.tab.c"
    break;

  case 66:
#line 135 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2096 "y.tab.c"
    break;

  case 67:
#line 138 "grammar.y"
        {yyval=NIL;}
#line 2102 "y.tab.c"
    break;

  case 68:
#line 139 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2108 "y.tab.c"
    break;

  case 69:
#line 142 "grammar.y"
                        {yyval=yyvsp[0];}
#line 2114 "y.tab.c"
    break;

  case 70:
#line 143 "grammar.y"
                                {yyval=linkDeclaratorList(yyvsp[-1],setDeclaratorKind(makeDummyIdentifier(),ID_PARM));}
#line 2120 "y.tab.c"
    break;

  case 71:
#line 146 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2126 "y.tab.c"
    break;

  case 72:
#line 147 "grammar.y"
                                                    {yyval=linkDeclaratorList(yyvsp[-2],yyvsp[0]);}
#line 2132 "y.tab.c"
    break;

  case 73:
#line 150 "grammar.y"
                                        {yyval=setParameterDeclaratorSpecifier(yyvsp[0],yyvsp[-1]);}
#line 2138 "y.tab.c"
    break;

  case 74:
#line 151 "grammar.y"
                                                     {yyval=setParameterDeclaratorSpecifier(setDeclaratorType(makeDummyIdentifier(),yyvsp[0]),yyvsp[-1]);}
#line 2144 "y.tab.c"
    break;

  case 75:
#line 154 "grammar.y"
        {yyval=NIL;}
#line 2150 "y.tab.c"
    break;

  case 76:
#line 155 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2156 "y.tab.c"
    break;

  case 77:
#line 158 "grammar.y"
                {yyval=makeType(T_POINTER);}
#line 2162 "y.tab.c"
    break;

  case 78:
#line 159 "grammar.y"
                                    {yyval=yyvsp[0];}
#line 2168 "y.tab.c"
    break;

  case 79:
#line 160 "grammar.y"
                                            {yyval=setTypeElementType(yyvsp[0],makeType(T_POINTER));}
#line 2174 "y.tab.c"
    break;

  case 80:
#line 163 "grammar.y"
                                    {yyval=yyvsp[-1];}
#line 2180 "y.tab.c"
    break;

  case 81:
#line 164 "grammar.y"
                                            {yyval=setTypeExpr(makeType(T_ARRAY),yyvsp[-1]);}
#line 2186 "y.tab.c"
    break;

  case 82:
#line 165 "grammar.y"
                                        {yyval=setTypeExpr(makeType(T_FUNC),yyvsp[-1]);}
#line 2192 "y.tab.c"
    break;

  case 83:
#line 166 "grammar.y"
                                                                        {yyval=setTypeElementType(yyvsp[-3],setTypeExpr(makeType(T_ARRAY),yyvsp[-1]));}
#line 2198 "y.tab.c"
    break;

  case 84:
#line 167 "grammar.y"
                                                                        {yyval=setTypeElementType(yyvsp[-3],setTypeExpr(makeType(T_FUNC),yyvsp[-1]));}
#line 2204 "y.tab.c"
    break;

  case 85:
#line 170 "grammar.y"
                            {yyval=makeNode(N_INIT_LIST_ONE,NIL,yyvsp[0],NIL);}
#line 2210 "y.tab.c"
    break;

  case 86:
#line 171 "grammar.y"
                                    {yyval=yyvsp[-1];}
#line 2216 "y.tab.c"
    break;

  case 87:
#line 174 "grammar.y"
                        {yyval=makeNode(N_INIT_LIST,yyvsp[0],NIL,makeNode(N_INIT_LIST_NIL,NIL,NIL,NIL));}
#line 2222 "y.tab.c"
    break;

  case 88:
#line 175 "grammar.y"
                                            {yyval=makeNodeList(N_INIT_LIST,yyvsp[-2],yyvsp[0]);}
#line 2228 "y.tab.c"
    break;

  case 89:
#line 178 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2234 "y.tab.c"
    break;

  case 90:
#line 179 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2240 "y.tab.c"
    break;

  case 91:
#line 180 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2246 "y.tab.c"
    break;

  case 92:
#line 181 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2252 "y.tab.c"
    break;

  case 93:
#line 182 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2258 "y.tab.c"
    break;

  case 94:
#line 183 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2264 "y.tab.c"
    break;

  case 95:
#line 186 "grammar.y"
                                                   {yyval=makeNode(N_STMT_LABEL_CASE,yyvsp[-2],NIL,yyvsp[0]);}
#line 2270 "y.tab.c"
    break;

  case 96:
#line 187 "grammar.y"
                                    {yyval=makeNode(N_STMT_LABEL_DEFAULT,NIL,yyvsp[0],NIL);}
#line 2276 "y.tab.c"
    break;

  case 97:
#line 190 "grammar.y"
                {yyval=makeNode(N_STMT_LIST,yyvsp[0],NIL,makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL));}
#line 2282 "y.tab.c"
    break;

  case 98:
#line 191 "grammar.y"
                               {yyval=makeNodeList(N_STMT_LIST,yyvsp[-1],yyvsp[0]);}
#line 2288 "y.tab.c"
    break;

  case 99:
#line 194 "grammar.y"
            {yyval=current_id; current_level++;}
#line 2294 "y.tab.c"
    break;

  case 100:
#line 194 "grammar.y"
                                                                                            {checkForwardReference(); yyval=makeNode(N_STMT_COMPOUND,yyvsp[-2],NIL,yyvsp[-1]); current_id=yyvsp[-3]; current_level--;}
#line 2300 "y.tab.c"
    break;

  case 101:
#line 197 "grammar.y"
        {yyval=makeNode(N_STMT_LIST_NIL,NIL,NIL,NIL);}
#line 2306 "y.tab.c"
    break;

  case 102:
#line 198 "grammar.y"
                       {yyval=yyvsp[0];}
#line 2312 "y.tab.c"
    break;

  case 103:
#line 201 "grammar.y"
                {yyval=makeNode(N_STMT_EMPTY,NIL,NIL,NIL);}
#line 2318 "y.tab.c"
    break;

  case 104:
#line 202 "grammar.y"
                            {yyval=makeNode(N_STMT_EXPRESSION,NIL,yyvsp[-1],NIL);}
#line 2324 "y.tab.c"
    break;

  case 105:
#line 205 "grammar.y"
                                            {yyval=makeNode(N_STMT_IF,yyvsp[-2],NIL,yyvsp[0]);}
#line 2330 "y.tab.c"
    break;

  case 106:
#line 206 "grammar.y"
                                                               {yyval=makeNode(N_STMT_IF_ELSE,yyvsp[-4],yyvsp[-2],yyvsp[0]);}
#line 2336 "y.tab.c"
    break;

  case 107:
#line 207 "grammar.y"
                                                    {yyval=makeNode(N_STMT_SWITCH,yyvsp[-2],NIL,yyvsp[0]);}
#line 2342 "y.tab.c"
    break;

  case 108:
#line 210 "grammar.y"
                                                {yyval=makeNode(N_STMT_WHILE,yyvsp[-2],NIL,yyvsp[0]);}
#line 2348 "y.tab.c"
    break;

  case 109:
#line 211 "grammar.y"
                                                               {yyval=makeNode(N_STMT_DO,yyvsp[-5],NIL,yyvsp[-2]);}
#line 2354 "y.tab.c"
    break;

  case 110:
#line 212 "grammar.y"
                                                 {yyval=makeNode(N_STMT_FOR,yyvsp[-2],NIL,yyvsp[0]);}
#line 2360 "y.tab.c"
    break;

  case 111:
#line 215 "grammar.y"
                                                                     {yyval=makeNode(N_FOR_EXP,yyvsp[-4],yyvsp[-2],yyvsp[0]);}
#line 2366 "y.tab.c"
    break;

  case 112:
#line 218 "grammar.y"
        {yyval=NIL;}
#line 2372 "y.tab.c"
    break;

  case 113:
#line 219 "grammar.y"
                    {yyval=yyvsp[0];}
#line 2378 "y.tab.c"
    break;

  case 114:
#line 222 "grammar.y"
                                            {yyval=makeNode(N_STMT_RETURN,NIL,yyvsp[-1],NIL);}
#line 2384 "y.tab.c"
    break;

  case 115:
#line 223 "grammar.y"
                            {yyval=makeNode(N_STMT_CONTINUE,NIL,NIL,NIL);}
#line 2390 "y.tab.c"
    break;

  case 116:
#line 224 "grammar.y"
                            {yyval=makeNode(N_STMT_BREAK,NIL,NIL,NIL);}
#line 2396 "y.tab.c"
    break;

  case 117:
#line 228 "grammar.y"
                        {yyval=makeNode(N_EXP_IDENT,NIL,getIdentifierDeclared(yyvsp[0]),NIL);}
#line 2402 "y.tab.c"
    break;

  case 118:
#line 229 "grammar.y"
                        {yyval=makeNode(N_EXP_INT_CONST,NIL,yyvsp[0],NIL);}
#line 2408 "y.tab.c"
    break;

  case 119:
#line 230 "grammar.y"
                        {yyval=makeNode(N_EXP_FLOAT_CONST,NIL,yyvsp[0],NIL);}
#line 2414 "y.tab.c"
    break;

  case 120:
#line 231 "grammar.y"
                        {yyval=makeNode(N_EXP_CHAR_CONST,NIL,yyvsp[0],NIL);}
#line 2420 "y.tab.c"
    break;

  case 121:
#line 232 "grammar.y"
                        {yyval=makeNode(N_EXP_STRING_LITERAL,NIL,yyvsp[0],NIL);}
#line 2426 "y.tab.c"
    break;

  case 122:
#line 233 "grammar.y"
                            {yyval=yyvsp[-1];}
#line 2432 "y.tab.c"
    break;

  case 123:
#line 237 "grammar.y"
                                {yyval=yyvsp[0];}
#line 2438 "y.tab.c"
    break;

  case 124:
#line 238 "grammar.y"
                                                {yyval=makeNode(N_EXP_ARRAY,yyvsp[-3],NIL,yyvsp[-1]);}
#line 2444 "y.tab.c"
    break;

  case 125:
#line 239 "grammar.y"
                                                            {yyval=makeNode(N_EXP_FUNCTION_CALL,yyvsp[-3],NIL,yyvsp[-1]);}
#line 2450 "y.tab.c"
    break;

  case 126:
#line 240 "grammar.y"
                                                {yyval=makeNode(N_EXP_STRUCT,yyvsp[-2],NIL,yyvsp[0]);}
#line 2456 "y.tab.c"
    break;

  case 127:
#line 241 "grammar.y"
                                                {yyval=makeNode(N_EXP_ARROW,yyvsp[-2],NIL,yyvsp[0]);}
#line 2462 "y.tab.c"
    break;

  case 128:
#line 242 "grammar.y"
                                    {yyval=makeNode(N_EXP_POST_INC,NIL,yyvsp[-1],NIL);}
#line 2468 "y.tab.c"
    break;

  case 129:
#line 243 "grammar.y"
                                    {yyval=makeNode(N_EXP_POST_DEC,NIL,yyvsp[-1],NIL);}
#line 2474 "y.tab.c"
    break;

  case 130:
#line 246 "grammar.y"
        {yyval=makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL);}
#line 2480 "y.tab.c"
    break;

  case 131:
#line 247 "grammar.y"
                          {yyval=yyvsp[0];}
#line 2486 "y.tab.c"
    break;

  case 132:
#line 250 "grammar.y"
                            {yyval=makeNode(N_ARG_LIST,yyvsp[0],NIL,makeNode(N_ARG_LIST_NIL,NIL,NIL,NIL));}
#line 2492 "y.tab.c"
    break;

  case 133:
#line 251 "grammar.y"
                                                        {yyval=makeNodeList(N_ARG_LIST,yyvsp[-2],yyvsp[0]);}
#line 2498 "y.tab.c"
    break;

  case 134:
#line 254 "grammar.y"
                                {yyval=yyvsp[0];}
#line 2504 "y.tab.c"
    break;

  case 135:
#line 255 "grammar.y"
                                {yyval=makeNode(N_EXP_PRE_INC,NIL,yyvsp[0],NIL);}
#line 2510 "y.tab.c"
    break;

  case 136:
#line 256 "grammar.y"
                                {yyval=makeNode(N_EXP_PRE_DEC,NIL,yyvsp[0],NIL);}
#line 2516 "y.tab.c"
    break;

  case 137:
#line 257 "grammar.y"
                                {yyval=makeNode(N_EXP_AMP,NIL,yyvsp[0],NIL);}
#line 2522 "y.tab.c"
    break;

  case 138:
#line 258 "grammar.y"
                                {yyval=makeNode(N_EXP_STAR,NIL,yyvsp[0],NIL);}
#line 2528 "y.tab.c"
    break;

  case 139:
#line 259 "grammar.y"
                                {yyval=makeNode(N_EXP_NOT,NIL,yyvsp[0],NIL);}
#line 2534 "y.tab.c"
    break;

  case 140:
#line 260 "grammar.y"
                                {yyval=makeNode(N_EXP_MINUS,NIL,yyvsp[0],NIL);}
#line 2540 "y.tab.c"
    break;

  case 141:
#line 261 "grammar.y"
                                {yyval=makeNode(N_EXP_PLUS,NIL,yyvsp[0],NIL);}
#line 2546 "y.tab.c"
    break;

  case 142:
#line 262 "grammar.y"
                                    {yyval=makeNode(N_EXP_SIZE_EXP,NIL,yyvsp[0],NIL);}
#line 2552 "y.tab.c"
    break;

  case 143:
#line 263 "grammar.y"
                                        {yyval=makeNode(N_EXP_SIZE_TYPE,NIL,yyvsp[-1],NIL);}
#line 2558 "y.tab.c"
    break;

  case 144:
#line 266 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2564 "y.tab.c"
    break;

  case 145:
#line 267 "grammar.y"
                                                {yyval=makeNode(N_EXP_CAST,yyvsp[-2],NIL,yyvsp[0]);}
#line 2570 "y.tab.c"
    break;

  case 146:
#line 270 "grammar.y"
                                                        {yyval=setTypeNameSpecifier(yyvsp[0],yyvsp[-1]);}
#line 2576 "y.tab.c"
    break;

  case 147:
#line 273 "grammar.y"
                        {yyval=yyvsp[0];}
#line 2582 "y.tab.c"
    break;

  case 148:
#line 274 "grammar.y"
                                                        {yyval=makeNode(N_EXP_MUL,yyvsp[-2],NIL,yyvsp[0]);}
#line 2588 "y.tab.c"
    break;

  case 149:
#line 275 "grammar.y"
                                                        {yyval=makeNode(N_EXP_DIV,yyvsp[-2],NIL,yyvsp[0]);}
#line 2594 "y.tab.c"
    break;

  case 150:
#line 276 "grammar.y"
                                                        {yyval=makeNode(N_EXP_MOD,yyvsp[-2],NIL,yyvsp[0]);}
#line 2600 "y.tab.c"
    break;

  case 151:
#line 279 "grammar.y"
                                {yyval=yyvsp[0];}
#line 2606 "y.tab.c"
    break;

  case 152:
#line 280 "grammar.y"
                                                            {yyval=makeNode(N_EXP_ADD,yyvsp[-2],NIL,yyvsp[0]);}
#line 2612 "y.tab.c"
    break;

  case 153:
#line 281 "grammar.y"
                                                            {yyval=makeNode(N_EXP_SUB,yyvsp[-2],NIL,yyvsp[0]);}
#line 2618 "y.tab.c"
    break;

  case 154:
#line 284 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2624 "y.tab.c"
    break;

  case 155:
#line 285 "grammar.y"
                                                        {yyval=makeNode(N_EXP_LSS,yyvsp[-2],NIL,yyvsp[0]);}
#line 2630 "y.tab.c"
    break;

  case 156:
#line 286 "grammar.y"
                                                        {yyval=makeNode(N_EXP_GTR,yyvsp[-2],NIL,yyvsp[0]);}
#line 2636 "y.tab.c"
    break;

  case 157:
#line 287 "grammar.y"
                                                        {yyval=makeNode(N_EXP_LEQ,yyvsp[-2],NIL,yyvsp[0]);}
#line 2642 "y.tab.c"
    break;

  case 158:
#line 288 "grammar.y"
                                                        {yyval=makeNode(N_EXP_GEQ,yyvsp[-2],NIL,yyvsp[0]);}
#line 2648 "y.tab.c"
    break;

  case 159:
#line 291 "grammar.y"
                                {yyval=yyvsp[0];}
#line 2654 "y.tab.c"
    break;

  case 160:
#line 292 "grammar.y"
                                                    {yyval=makeNode(N_EXP_EQL,yyvsp[-2],NIL,yyvsp[0]);}
#line 2660 "y.tab.c"
    break;

  case 161:
#line 293 "grammar.y"
                                                    {yyval=makeNode(N_EXP_NEQ,yyvsp[-2],NIL,yyvsp[0]);}
#line 2666 "y.tab.c"
    break;

  case 162:
#line 297 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2672 "y.tab.c"
    break;

  case 163:
#line 298 "grammar.y"
                                                        {yyval=makeNode(N_EXP_OR,yyvsp[-2],NIL,yyvsp[0]);}
#line 2678 "y.tab.c"
    break;

  case 164:
#line 301 "grammar.y"
                                {yyval=yyvsp[0];}
#line 2684 "y.tab.c"
    break;

  case 165:
#line 302 "grammar.y"
                                                        {yyval=makeNode(N_EXP_OR,yyvsp[-2],NIL,yyvsp[0]);}
#line 2690 "y.tab.c"
    break;

  case 166:
#line 305 "grammar.y"
                    {yyval=yyvsp[0];}
#line 2696 "y.tab.c"
    break;

  case 167:
#line 308 "grammar.y"
                            {yyval=yyvsp[0];}
#line 2702 "y.tab.c"
    break;

  case 168:
#line 312 "grammar.y"
                                {yyval=yyvsp[0];}
#line 2708 "y.tab.c"
    break;

  case 169:
#line 313 "grammar.y"
                                            {yyval=makeNode(N_EXP_ASSIGN,yyvsp[-2],NIL,yyvsp[0]);}
#line 2714 "y.tab.c"
    break;


#line 2718 "y.tab.c"

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
#line 315 "grammar.y"

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
    yyparse();
    if (!syntax_err)
        print_ast(root);

    return 0;
}
