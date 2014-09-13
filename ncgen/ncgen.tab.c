/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         ncgparse
#define yylex           ncglex
#define yyerror         ncgerror
#define yydebug         ncgdebug
#define yynerrs         ncgnerrs

#define yylval          ncglval
#define yychar          ncgchar

/* Copy the first part of user declarations.  */
#line 11 "ncgen.y" /* yacc.c:339  */

/*
static char SccsId[] = "$Id: ncgen.y,v 1.42 2010/05/18 21:32:46 dmh Exp $";
*/
#include        "includes.h"
#include        "offsets.h"
#include        "nc4compress.h"

/* Following are in ncdump (for now)*/
/* Need some (unused) definitions to get it to compile */
#define ncatt_t void*
#define ncvar_t void
#include "nctime.h"

/* parser controls */
#define YY_NO_INPUT 1

/* True if string a equals string b*/
#define STREQ(a, b)     (*(a) == *(b) && strcmp((a), (b)) == 0)
#define VLENSIZE  (sizeof(nc_vlen_t))
#define MAXFLOATDIM 4294967295.0

/* mnemonic */
typedef enum Attrkind {ATTRVAR, ATTRGLOBAL, DONTKNOW} Attrkind;

typedef nc_vlen_t vlen_t;

/* We retain the old representation of the symbol list
   as a linked list.
*/
Symbol* symlist;

/* Track rootgroup separately*/
Symbol* rootgroup;

/* Track the group sequence */
static List* groupstack;

/* Provide a separate sequence for accumulating values
   during the parse.
*/
static List* stack;

/* track homogeneity of types for data lists*/
static nc_type consttype;

/* Misc. */
static int stackbase;
static int stacklen;
static int count;
static int opaqueid; /* counter for opaque constants*/
static int arrayuid; /* counter for pseudo-array types*/

char* primtypenames[PRIMNO] = {
"nat",
"byte", "char", "short",
"int", "float", "double",
"ubyte", "ushort", "uint",
"int64", "uint64",
"string"
};

/*Defined in ncgen.l*/
extern int lineno;              /* line number for error messages */
extern Bytebuffer* lextext;           /* name or string with escapes removed */

extern double double_val;       /* last double value read */
extern float float_val;         /* last float value read */
extern long long int64_val;         /* last int64 value read */
extern int int32_val;             /* last int32 value read */
extern short int16_val;         /* last short value read */
extern unsigned long long uint64_val;         /* last int64 value read */
extern unsigned int uint32_val;             /* last int32 value read */
extern unsigned short uint16_val;         /* last short value read */
extern char char_val;           /* last char value read */
extern signed char byte_val;    /* last byte value read */
extern unsigned char ubyte_val;    /* last byte value read */

/* Track definitions of dims, types, attributes, and vars*/
List* grpdefs;
List* dimdefs;
List* attdefs; /* variable-specific attributes*/
List* gattdefs; /* global attributes only*/
List* xattdefs; /* unknown attributes*/
List* typdefs;
List* vardefs;
List* condefs; /* non-dimension constants used in type defs*/
List* tmp;

/* Forward */
static NCConstant makeconstdata(nc_type);
static NCConstant evaluate(Symbol* fcn, Datalist* arglist);
static NCConstant makeenumconstref(Symbol*);
static void addtogroup(Symbol*);
static Symbol* currentgroup(void);
static Symbol* createrootgroup(const char*);
static Symbol* creategroup(Symbol*);
static int dupobjectcheck(nc_class,Symbol*);
static void setpathcurrent(Symbol* sym);
static Symbol* makeattribute(Symbol*,Symbol*,Symbol*,Datalist*,Attrkind);
static Symbol* makeprimitivetype(nc_type i);
static Symbol* makespecial(int tag, Symbol* vsym, Symbol* tsym, void* data, int isconst);
static int containsfills(Datalist* list);
static void datalistextend(Datalist* dl, NCConstant* con);
static void vercheck(int ncid);

int yylex(void);

#ifndef NO_STDARG
static void yyerror(const char *fmt, ...);
#else
static void yyerror(fmt,va_alist) const char* fmt; va_dcl;
#endif

/* Extern */
extern int lex_init(void);


#line 193 "ncgen.tab.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "ncgen.tab.h".  */
#ifndef YY_NCG_NCGEN_TAB_H_INCLUDED
# define YY_NCG_NCGEN_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int ncgdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NC_UNLIMITED_K = 258,
    CHAR_K = 259,
    BYTE_K = 260,
    SHORT_K = 261,
    INT_K = 262,
    FLOAT_K = 263,
    DOUBLE_K = 264,
    UBYTE_K = 265,
    USHORT_K = 266,
    UINT_K = 267,
    INT64_K = 268,
    UINT64_K = 269,
    IDENT = 270,
    TERMSTRING = 271,
    CHAR_CONST = 272,
    BYTE_CONST = 273,
    SHORT_CONST = 274,
    INT_CONST = 275,
    INT64_CONST = 276,
    UBYTE_CONST = 277,
    USHORT_CONST = 278,
    UINT_CONST = 279,
    UINT64_CONST = 280,
    FLOAT_CONST = 281,
    DOUBLE_CONST = 282,
    DIMENSIONS = 283,
    VARIABLES = 284,
    NETCDF = 285,
    DATA = 286,
    TYPES = 287,
    COMPOUND = 288,
    ENUM = 289,
    OPAQUE = 290,
    OPAQUESTRING = 291,
    GROUP = 292,
    PATH = 293,
    FILLMARKER = 294,
    NIL = 295,
    _FILLVALUE = 296,
    _FORMAT = 297,
    _STORAGE = 298,
    _CHUNKSIZES = 299,
    _DEFLATELEVEL = 300,
    _SHUFFLE = 301,
    _ENDIANNESS = 302,
    _NOFILL = 303,
    _FLETCHER32 = 304,
    _COMPRESSION = 305,
    DATASETID = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 132 "ncgen.y" /* yacc.c:355  */

Symbol* sym;
unsigned long  size; /* allow for zero size to indicate e.g. UNLIMITED*/
long           mark; /* track indices into the sequence*/
int            nctype; /* for tracking attribute list type*/
Datalist*      datalist;
NCConstant       constant;

#line 294 "ncgen.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ncglval;

int ncgparse (void);

#endif /* !YY_NCG_NCGEN_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 309 "ncgen.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   373

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      57,    58,    59,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    54,
       2,    56,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   216,   218,   225,   232,   232,   235,   244,
     234,   249,   250,   251,   255,   255,   257,   267,   267,   270,
     271,   272,   273,   276,   276,   279,   309,   311,   328,   337,
     349,   363,   396,   397,   400,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   427,   428,   429,   432,
     433,   436,   436,   438,   439,   443,   450,   461,   474,   484,
     496,   497,   498,   501,   502,   505,   505,   507,   529,   533,
     537,   564,   565,   568,   569,   573,   587,   591,   596,   625,
     626,   630,   631,   636,   646,   666,   677,   688,   707,   714,
     714,   717,   719,   728,   739,   741,   743,   745,   747,   749,
     751,   753,   755,   757,   759,   764,   771,   780,   781,   782,
     785,   786,   789,   793,   794,   798,   802,   803,   808,   809,
     813,   814,   815,   816,   817,   818,   822,   826,   830,   832,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   852,   853,   857,   859,   861,   863,   868,   872,
     873,   879
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NC_UNLIMITED_K", "CHAR_K", "BYTE_K",
  "SHORT_K", "INT_K", "FLOAT_K", "DOUBLE_K", "UBYTE_K", "USHORT_K",
  "UINT_K", "INT64_K", "UINT64_K", "IDENT", "TERMSTRING", "CHAR_CONST",
  "BYTE_CONST", "SHORT_CONST", "INT_CONST", "INT64_CONST", "UBYTE_CONST",
  "USHORT_CONST", "UINT_CONST", "UINT64_CONST", "FLOAT_CONST",
  "DOUBLE_CONST", "DIMENSIONS", "VARIABLES", "NETCDF", "DATA", "TYPES",
  "COMPOUND", "ENUM", "OPAQUE", "OPAQUESTRING", "GROUP", "PATH",
  "FILLMARKER", "NIL", "_FILLVALUE", "_FORMAT", "_STORAGE", "_CHUNKSIZES",
  "_DEFLATELEVEL", "_SHUFFLE", "_ENDIANNESS", "_NOFILL", "_FLETCHER32",
  "_COMPRESSION", "DATASETID", "'{'", "'}'", "';'", "','", "'='", "'('",
  "')'", "'*'", "':'", "$accept", "ncdesc", "datasetid", "rootgroup",
  "groupbody", "subgrouplist", "namedgroup", "$@1", "$@2", "typesection",
  "typedecls", "typename", "type_or_attr_decl", "typedecl", "optsemicolon",
  "enumdecl", "enumidlist", "enumid", "opaquedecl", "vlendecl",
  "compounddecl", "fields", "field", "primtype", "dimsection", "dimdecls",
  "dim_or_attr_decl", "dimdeclist", "dimdecl", "dimd", "vasection",
  "vadecls", "vadecl_or_attr", "vardecl", "varlist", "varspec", "dimspec",
  "dimlist", "dimref", "fieldlist", "fieldspec", "fielddimspec",
  "fielddimlist", "fielddim", "varref", "typeref", "type_var_ref",
  "attrdecllist", "attrdecl", "path", "datasection", "datadecls",
  "datadecl", "datalist", "datalist0", "datalist1", "dataitem",
  "constdata", "econstref", "function", "arglist", "simpleconstant",
  "intlist", "constint", "conststring", "constbool", "ident", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   123,   125,    59,    44,    61,    40,    41,    42,
      58
};
# endif

#define YYPACT_NINF -128

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-128)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,   -12,    28,  -128,   -10,  -128,   217,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,    -7,  -128,  -128,   335,    -3,     8,    -1,  -128,  -128,
      13,    14,   -16,    21,    15,   160,    62,   217,    59,   286,
      80,  -128,  -128,    -5,    40,    45,    57,    58,    65,    66,
      68,    69,    70,    71,    80,    50,   160,  -128,  -128,    74,
      74,    74,    74,    86,   229,    75,   217,    94,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,   286,  -128,    76,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,    77,    84,    81,    83,
     286,    59,    73,    73,    67,    59,    67,    67,    59,   286,
      89,  -128,   122,  -128,  -128,  -128,  -128,  -128,  -128,    80,
      88,  -128,   217,    95,    93,  -128,    87,  -128,    96,   217,
     119,    55,   286,   336,  -128,   286,   286,    76,  -128,  -128,
    -128,  -128,  -128,    99,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,    76,   335,    97,   105,   100,   106,  -128,
      80,    47,   217,   124,  -128,   335,  -128,   335,  -128,  -128,
    -128,   -14,  -128,   217,    76,    76,    73,   283,   125,    80,
    -128,    80,    80,    80,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,   126,  -128,   121,  -128,   -31,   127,  -128,   335,   128,
     336,  -128,  -128,  -128,  -128,   130,  -128,   131,  -128,   132,
    -128,    64,  -128,   134,  -128,  -128,    80,     0,  -128,   286,
     137,  -128,  -128,   144,  -128,    80,     7,  -128,  -128,    80,
      73,  -128,   135,    27,  -128,  -128,    76,  -128,   141,  -128,
    -128,  -128,    51,  -128,  -128,  -128,     0,  -128,   217,     7,
    -128,  -128,  -128,  -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,    89,     2,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   151,
     106,     0,     6,    88,     0,    86,    11,     0,    87,   105,
       0,     0,     0,     0,     0,    12,    46,    89,     0,   115,
       0,     4,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    17,    23,
      23,    23,    23,    88,     0,     0,    47,    60,    90,   148,
     104,   141,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   121,   122,   123,   115,   126,    91,   113,
     114,   116,   118,   124,   125,   120,   105,     0,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,   115,
       0,    16,     0,    15,    24,    19,    22,    21,    20,     0,
       0,    18,    48,     0,    51,    53,     0,    52,   105,    61,
     107,     0,     0,     0,     8,   115,   115,    94,    96,   144,
     146,   145,   147,    97,   142,    99,   150,   149,   100,   101,
     102,    98,   103,    93,     0,     0,     0,     0,     0,    49,
       0,     0,    62,     0,    65,     0,    66,   108,     5,   119,
     117,     0,   128,    89,    95,    92,     0,     0,     0,     0,
      86,     0,     0,     0,    50,    54,    59,    58,    56,    55,
      57,     0,    63,    67,    68,    71,     0,    85,   109,     0,
       0,   127,     6,   143,    31,     0,    32,    34,    76,    79,
      29,     0,    26,     0,    30,    64,     0,     0,    70,   115,
       0,   110,   129,     9,    33,     0,     0,    78,    25,     0,
       0,    69,    71,     0,    73,    75,   112,   111,     0,    77,
      84,    83,     0,    81,    27,    28,     0,    72,    89,     0,
      80,    74,    10,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,    24,    -2,  -128,  -128,  -128,  -128,
    -128,   -97,   145,  -128,   -13,  -128,  -128,   -41,  -128,  -128,
    -128,  -128,    25,   -23,  -128,  -128,    82,  -128,    43,  -128,
    -128,  -128,    44,  -128,  -128,    -9,  -128,  -128,   -38,  -128,
     -15,  -128,  -128,   -36,  -128,   -24,   -21,   -37,   -11,   -32,
    -128,  -128,    17,   -84,  -128,  -128,    85,  -128,  -128,  -128,
    -128,  -127,  -128,   -98,   -29,   -89,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     4,     7,    22,    32,    42,   173,   238,    36,
      56,   110,    57,    58,   115,    59,   211,   212,    60,    61,
      62,   177,   178,    23,    67,   122,   123,   124,   125,   126,
     130,   162,   163,   164,   193,   194,   218,   233,   234,   207,
     208,   227,   242,   243,   196,    24,    25,    26,    27,    28,
     168,   198,   199,    88,    89,    90,    91,    92,    93,    94,
     171,    95,   143,   146,   147,   148,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    31,   131,    33,   144,   145,   172,    87,    19,    70,
      19,    64,    63,     1,    53,    19,   137,   150,   151,    96,
      97,    40,   156,    99,    65,   153,   217,   240,     5,  -105,
      19,   241,    64,    63,   111,    30,    98,    41,    20,     3,
      35,   200,     6,    33,   201,    65,   128,   116,   117,   118,
     187,   174,   175,    37,    87,   127,    44,    34,    45,    46,
      47,    48,    49,    50,    51,    52,    96,   188,    87,    38,
      39,   189,   138,   222,   190,    69,   149,    87,   203,   152,
      96,    43,   246,    69,   210,   247,   214,   139,   140,    96,
      66,   141,   142,   139,   140,    19,   100,   141,   142,   111,
      87,   101,   128,    87,    87,   165,   249,   112,   169,   250,
     132,   127,    96,   102,   103,    96,    96,   228,   166,   229,
     119,   104,   105,   129,   106,   107,   108,   109,   114,   121,
     179,   132,   245,   180,   133,   236,   134,   135,   165,   136,
     186,   154,   155,   161,    33,   195,   197,   157,   160,   159,
     167,   166,   -59,   179,   176,   181,   180,   182,   183,   209,
     184,   111,   213,   111,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   216,   197,   192,   206,
     215,    40,   221,   219,   224,   235,   225,    87,   244,   226,
     230,   237,   217,    54,   248,    55,   232,   202,    20,    96,
     223,   113,   205,   185,   158,   209,   191,   231,   251,   213,
     239,   252,     0,   253,   235,   220,     0,   170,     0,     0,
      21,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    19,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,    20,    83,     0,    20,    84,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,    86,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20
};

static const yytype_int16 yycheck[] =
{
      37,    21,    86,    24,   102,   103,   133,    39,    15,    38,
      15,    35,    35,    30,    34,    15,   100,   106,   107,    39,
      40,    37,   119,    43,    35,   109,    57,    20,     0,    60,
      15,    24,    56,    56,    54,    42,    41,    53,    38,    51,
      32,    55,    52,    64,    58,    56,    66,    60,    61,    62,
       3,   135,   136,    54,    86,    66,    41,    60,    43,    44,
      45,    46,    47,    48,    49,    50,    86,    20,   100,    56,
      56,    24,   101,   200,    27,    16,   105,   109,   176,   108,
     100,    60,    55,    16,   181,    58,   183,    20,    21,   109,
      28,    24,    25,    20,    21,    15,    56,    24,    25,   119,
     132,    56,   122,   135,   136,   129,    55,    57,    53,    58,
      55,   122,   132,    56,    56,   135,   136,    53,   129,    55,
      34,    56,    56,    29,    56,    56,    56,    56,    54,    54,
     154,    55,   230,   154,    57,   219,    52,    56,   162,    56,
     160,    52,    20,    56,   165,   165,   167,    59,    55,    54,
      31,   162,    56,   177,    55,    58,   177,    52,    58,   179,
      54,   181,   182,   183,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    55,   198,    54,    54,
      54,    37,    54,    56,    54,   217,    55,   219,   229,    57,
      56,    54,    57,    33,    53,    35,   216,   173,    38,   219,
     202,    56,   177,   160,   122,   225,   162,   216,   246,   229,
     225,   248,    -1,   249,   246,   198,    -1,   132,    -1,    -1,
      60,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    36,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    52,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    62,    51,    63,     0,    52,    64,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      38,    60,    65,    84,   106,   107,   108,   109,   110,   127,
      42,   127,    66,   107,    60,    32,    70,    54,    56,    56,
      37,    53,    67,    60,    41,    43,    44,    45,    46,    47,
      48,    49,    50,   127,    33,    35,    71,    73,    74,    76,
      79,    80,    81,    84,   106,   109,    28,    85,   108,    16,
     125,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    36,    39,    40,    52,   110,   114,   115,
     116,   117,   118,   119,   120,   122,   127,   127,    41,   127,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      72,   127,    57,    73,    54,    75,    75,    75,    75,    34,
      57,    54,    86,    87,    88,    89,    90,   109,   127,    29,
      91,   114,    55,    57,    52,    56,    56,   114,   125,    20,
      21,    24,    25,   123,   124,   124,   124,   125,   126,   125,
     126,   126,   125,   114,    52,    20,    72,    59,    87,    54,
      55,    56,    92,    93,    94,   106,   109,    31,   111,    53,
     117,   121,   122,    68,   114,   114,    55,    82,    83,   106,
     107,    58,    52,    58,    54,    89,   127,     3,    20,    24,
      27,    93,    54,    95,    96,   127,   105,   107,   112,   113,
      55,    58,    65,   124,    53,    83,    54,   100,   101,   127,
      72,    77,    78,   127,    72,    54,    55,    57,    97,    56,
     113,    54,   122,    66,    54,    55,    57,   102,    53,    55,
      56,    96,   127,    98,    99,   110,   114,    54,    69,   101,
      20,    24,   103,   104,    78,   124,    55,    58,    53,    55,
      58,    99,   108,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    65,    66,    66,    68,    69,
      67,    70,    70,    70,    71,    71,    72,    73,    73,    74,
      74,    74,    74,    75,    75,    76,    77,    77,    78,    79,
      80,    81,    82,    82,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    90,
      91,    91,    91,    92,    92,    93,    93,    94,    95,    95,
      96,    97,    97,    98,    98,    99,   100,   100,   101,   102,
     102,   103,   103,   104,   104,   105,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   111,   111,
     112,   112,   113,   114,   114,   115,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   119,   120,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   124,   124,   124,   124,   125,   126,
     126,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     4,     5,     0,     2,     0,     0,
       9,     0,     1,     2,     1,     2,     1,     1,     2,     2,
       2,     2,     2,     0,     1,     6,     1,     3,     3,     5,
       5,     5,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     2,     2,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     1,
       0,     1,     2,     2,     3,     1,     1,     2,     1,     3,
       2,     0,     3,     1,     3,     1,     1,     3,     2,     0,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     0,
       3,     4,     6,     5,     5,     6,     5,     5,     5,     5,
       5,     5,     5,     5,     4,     1,     1,     0,     1,     2,
       2,     3,     3,     1,     1,     0,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 213 "ncgen.y" /* yacc.c:1646  */
    {if (error_count > 0) YYABORT;}
#line 1593 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 216 "ncgen.y" /* yacc.c:1646  */
    {createrootgroup(datasetname);}
#line 1599 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 235 "ncgen.y" /* yacc.c:1646  */
    {
		Symbol* id = (yyvsp[-1].sym);
                markcdf4("Group specification");
		if(creategroup(id) == NULL) 
                    yyerror("duplicate group declaration within parent group for %s",
                                id->name);
            }
#line 1611 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 244 "ncgen.y" /* yacc.c:1646  */
    {listpop(groupstack);}
#line 1617 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 250 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1623 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 252 "ncgen.y" /* yacc.c:1646  */
    {markcdf4("Type specification");}
#line 1629 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 258 "ncgen.y" /* yacc.c:1646  */
    { /* Use when defining a type */
              (yyvsp[0].sym)->objectclass = NC_TYPE;
              if(dupobjectcheck(NC_TYPE,(yyvsp[0].sym)))
                    yyerror("duplicate type declaration for %s",
                            (yyvsp[0].sym)->name);
              listpush(typdefs,(void*)(yyvsp[0].sym));
	    }
#line 1641 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 267 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1647 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 267 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1653 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 281 "ncgen.y" /* yacc.c:1646  */
    {
		int i;
                addtogroup((yyvsp[-3].sym)); /* sets prefix*/
                (yyvsp[-3].sym)->objectclass=NC_TYPE;
                (yyvsp[-3].sym)->subclass=NC_ENUM;
                (yyvsp[-3].sym)->typ.basetype=(yyvsp[-5].sym);
                (yyvsp[-3].sym)->typ.size = (yyvsp[-5].sym)->typ.size;
                (yyvsp[-3].sym)->typ.alignment = (yyvsp[-5].sym)->typ.alignment;
                stackbase=(yyvsp[-1].mark);
                stacklen=listlength(stack);
                (yyvsp[-3].sym)->subnodes = listnew();
                /* Variety of field fixups*/
		/* 1. add in the enum values*/
		/* 2. make this type be their container*/
		/* 3. make constant names visible in the group*/
		/* 4. set field basetype to be same as enum basetype*/
                for(i=stackbase;i<stacklen;i++) {
                   Symbol* eid = (Symbol*)listget(stack,i);
		   assert(eid->subclass == NC_ECONST);
		   addtogroup(eid);
                   listpush((yyvsp[-3].sym)->subnodes,(void*)eid);
                   eid->container = (yyvsp[-3].sym);
		   eid->typ.basetype = (yyvsp[-3].sym)->typ.basetype;
                }               
                listsetlength(stack,stackbase);/* remove stack nodes*/
              }
#line 1684 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 310 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=listlength(stack); listpush(stack,(void*)(yyvsp[0].sym));}
#line 1690 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 312 "ncgen.y" /* yacc.c:1646  */
    {
		    int i;
		    (yyval.mark)=(yyvsp[-2].mark);
		    /* check for duplicates*/
		    stackbase=(yyvsp[-2].mark);
		    stacklen=listlength(stack);
		    for(i=stackbase;i<stacklen;i++) {
		      Symbol* elem = (Symbol*)listget(stack,i);
		      if(strcmp((yyvsp[0].sym)->name,elem->name)==0)
  	                yyerror("duplicate enum declaration for %s",
        	                 elem->name);
		    }    	    
		    listpush(stack,(void*)(yyvsp[0].sym));
		}
#line 1709 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 329 "ncgen.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].sym)->objectclass=NC_TYPE;
            (yyvsp[-2].sym)->subclass=NC_ECONST;
            (yyvsp[-2].sym)->typ.econst=(yyvsp[0].constant);
	    (yyval.sym)=(yyvsp[-2].sym);
        }
#line 1720 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 338 "ncgen.y" /* yacc.c:1646  */
    {
		    vercheck(NC_OPAQUE);
                    addtogroup((yyvsp[0].sym)); /*sets prefix*/
                    (yyvsp[0].sym)->objectclass=NC_TYPE;
                    (yyvsp[0].sym)->subclass=NC_OPAQUE;
                    (yyvsp[0].sym)->typ.typecode=NC_OPAQUE;
                    (yyvsp[0].sym)->typ.size=int32_val;
                    (yyvsp[0].sym)->typ.alignment=nctypealignment(NC_OPAQUE);
                }
#line 1734 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 350 "ncgen.y" /* yacc.c:1646  */
    {
                    Symbol* basetype = (yyvsp[-4].sym);
		    vercheck(NC_VLEN);
                    addtogroup((yyvsp[0].sym)); /*sets prefix*/
                    (yyvsp[0].sym)->objectclass=NC_TYPE;
                    (yyvsp[0].sym)->subclass=NC_VLEN;
                    (yyvsp[0].sym)->typ.basetype=basetype;
                    (yyvsp[0].sym)->typ.typecode=NC_VLEN;
                    (yyvsp[0].sym)->typ.size=VLENSIZE;
                    (yyvsp[0].sym)->typ.alignment=nctypealignment(NC_VLEN);
                }
#line 1750 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 364 "ncgen.y" /* yacc.c:1646  */
    {
	    int i,j;
	    vercheck(NC_COMPOUND);
            addtogroup((yyvsp[-3].sym));
	    /* check for duplicate field names*/
	    stackbase=(yyvsp[-1].mark);
	    stacklen=listlength(stack);
	    for(i=stackbase;i<stacklen;i++) {
	      Symbol* elem1 = (Symbol*)listget(stack,i);
	      for(j=i+1;j<stacklen;j++) {
	          Symbol* elem2 = (Symbol*)listget(stack,j);
	          if(strcmp(elem1->name,elem2->name)==0) {
	            yyerror("duplicate field declaration for %s",elem1->name);
		  }
	      }
	    }
	    (yyvsp[-3].sym)->objectclass=NC_TYPE;
            (yyvsp[-3].sym)->subclass=NC_COMPOUND;
            (yyvsp[-3].sym)->typ.basetype=NULL;
            (yyvsp[-3].sym)->typ.typecode=NC_COMPOUND;
	    (yyvsp[-3].sym)->subnodes = listnew();
	    /* Add in the fields*/
	    for(i=stackbase;i<stacklen;i++) {
	        Symbol* fsym = (Symbol*)listget(stack,i);
		fsym->container = (yyvsp[-3].sym);
 	        listpush((yyvsp[-3].sym)->subnodes,(void*)fsym);
	    }    	    
	    listsetlength(stack,stackbase);/* remove stack nodes*/
          }
#line 1784 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 396 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-1].mark);}
#line 1790 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 397 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-2].mark);}
#line 1796 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 401 "ncgen.y" /* yacc.c:1646  */
    {
	    int i;
	    (yyval.mark)=(yyvsp[0].mark);
	    stackbase=(yyvsp[0].mark);
	    stacklen=listlength(stack);
	    /* process each field in the fieldlist*/
            for(i=stackbase;i<stacklen;i++) {
                Symbol* f = (Symbol*)listget(stack,i);
		f->typ.basetype = (yyvsp[-1].sym);
            }
        }
#line 1812 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 414 "ncgen.y" /* yacc.c:1646  */
    { (yyval.sym) = primsymbols[NC_CHAR]; }
#line 1818 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 415 "ncgen.y" /* yacc.c:1646  */
    { (yyval.sym) = primsymbols[NC_BYTE]; }
#line 1824 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 416 "ncgen.y" /* yacc.c:1646  */
    { (yyval.sym) = primsymbols[NC_SHORT]; }
#line 1830 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 417 "ncgen.y" /* yacc.c:1646  */
    { (yyval.sym) = primsymbols[NC_INT]; }
#line 1836 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 418 "ncgen.y" /* yacc.c:1646  */
    { (yyval.sym) = primsymbols[NC_FLOAT]; }
#line 1842 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 419 "ncgen.y" /* yacc.c:1646  */
    { (yyval.sym) = primsymbols[NC_DOUBLE]; }
#line 1848 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 420 "ncgen.y" /* yacc.c:1646  */
    { vercheck(NC_UBYTE); (yyval.sym) = primsymbols[NC_UBYTE]; }
#line 1854 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 421 "ncgen.y" /* yacc.c:1646  */
    { vercheck(NC_USHORT); (yyval.sym) = primsymbols[NC_USHORT]; }
#line 1860 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 422 "ncgen.y" /* yacc.c:1646  */
    { vercheck(NC_UINT); (yyval.sym) = primsymbols[NC_UINT]; }
#line 1866 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 423 "ncgen.y" /* yacc.c:1646  */
    { vercheck(NC_INT64); (yyval.sym) = primsymbols[NC_INT64]; }
#line 1872 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 424 "ncgen.y" /* yacc.c:1646  */
    { vercheck(NC_UINT64); (yyval.sym) = primsymbols[NC_UINT64]; }
#line 1878 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 428 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1884 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 429 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1890 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 436 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1896 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 436 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1902 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 444 "ncgen.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].sym)->dim.declsize = (size_t)uint32_val;
#ifdef GENDEBUG1
fprintf(stderr,"dimension: %s = %lu\n",(yyvsp[-2].sym)->name,(unsigned long)(yyvsp[-2].sym)->dim.declsize);
#endif
	      }
#line 1913 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 451 "ncgen.y" /* yacc.c:1646  */
    {
		if(int32_val <= 0) {
		    derror("dimension size must be positive");
		    YYABORT;
		}
		(yyvsp[-2].sym)->dim.declsize = (size_t)int32_val;
#ifdef GENDEBUG1
fprintf(stderr,"dimension: %s = %lu\n",(yyvsp[-2].sym)->name,(unsigned long)(yyvsp[-2].sym)->dim.declsize);
#endif
	      }
#line 1928 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 462 "ncgen.y" /* yacc.c:1646  */
    { /* for rare case where 2^31 < dimsize < 2^32 */
                       if (double_val <= 0)
                         yyerror("dimension length must be positive");
                       if (double_val > MAXFLOATDIM)
                         yyerror("dimension too large");
                       if (double_val - (size_t) double_val > 0)
                         yyerror("dimension length must be an integer");
                       (yyvsp[-2].sym)->dim.declsize = (size_t)double_val;
#ifdef GENDEBUG1
fprintf(stderr,"dimension: %s = %lu\n",(yyvsp[-2].sym)->name,(unsigned long)(yyvsp[-2].sym)->dim.declsize);
#endif
                   }
#line 1945 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 475 "ncgen.y" /* yacc.c:1646  */
    {
		        (yyvsp[-2].sym)->dim.declsize = NC_UNLIMITED;
		        (yyvsp[-2].sym)->dim.isunlimited = 1;
#ifdef GENDEBUG1
fprintf(stderr,"dimension: %s = UNLIMITED\n",(yyvsp[-2].sym)->name);
#endif
		   }
#line 1957 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 485 "ncgen.y" /* yacc.c:1646  */
    { 
                     (yyvsp[0].sym)->objectclass=NC_DIM;
                     if(dupobjectcheck(NC_DIM,(yyvsp[0].sym)))
                        yyerror( "Duplicate dimension declaration for %s",
                                (yyvsp[0].sym)->name);
		     addtogroup((yyvsp[0].sym));
		     (yyval.sym)=(yyvsp[0].sym);
		     listpush(dimdefs,(void*)(yyvsp[0].sym));
                   }
#line 1971 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 497 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1977 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 498 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1983 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 505 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1989 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 505 "ncgen.y" /* yacc.c:1646  */
    {}
#line 1995 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 508 "ncgen.y" /* yacc.c:1646  */
    {
		    int i;
		    stackbase=(yyvsp[0].mark);
		    stacklen=listlength(stack);
		    /* process each variable in the varlist*/
	            for(i=stackbase;i<stacklen;i++) {
	                Symbol* sym = (Symbol*)listget(stack,i);
			sym->objectclass = NC_VAR;
		        if(dupobjectcheck(NC_VAR,sym)) {
                            yyerror("Duplicate variable declaration for %s",
                                    sym->name);
			} else {
		  	    sym->typ.basetype = (yyvsp[-1].sym);
	                    addtogroup(sym);
		            listpush(vardefs,(void*)sym);
			}
		    }
		    listsetlength(stack,stackbase);/* remove stack nodes*/
		}
#line 2019 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 530 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=listlength(stack);
                 listpush(stack,(void*)(yyvsp[0].sym));
		}
#line 2027 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 534 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-2].mark); listpush(stack,(void*)(yyvsp[0].sym));}
#line 2033 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 538 "ncgen.y" /* yacc.c:1646  */
    {
		    int i;
		    Dimset dimset;
		    stacklen=listlength(stack);
		    stackbase=(yyvsp[0].mark);
		    count = stacklen - stackbase;
		    if(count >= NC_MAX_VAR_DIMS) {
			yyerror("%s has too many dimensions",(yyvsp[-1].sym)->name);
			count = NC_MAX_VAR_DIMS - 1;
			stacklen = stackbase + count;
		    }
  	            dimset.ndims = count;
		    /* extract the actual dimensions*/
		    if(dimset.ndims > 0) {
		        for(i=0;i<count;i++) {
			    Symbol* dsym = (Symbol*)listget(stack,stackbase+i);
			    dimset.dimsyms[i] = dsym;
			}
			(yyvsp[-1].sym)->typ.dimset = dimset;
		    }
		    (yyvsp[-1].sym)->typ.basetype = NULL; /* not yet known*/
                    (yyvsp[-1].sym)->objectclass=NC_VAR;
		    listsetlength(stack,stackbase);/* remove stack nodes*/
		    }
#line 2062 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 564 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=listlength(stack);}
#line 2068 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 565 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-1].mark);}
#line 2074 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 568 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=listlength(stack); listpush(stack,(void*)(yyvsp[0].sym));}
#line 2080 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 570 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-2].mark); listpush(stack,(void*)(yyvsp[0].sym));}
#line 2086 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 574 "ncgen.y" /* yacc.c:1646  */
    {Symbol* dimsym = (yyvsp[0].sym);
		dimsym->objectclass = NC_DIM;
		/* Find the actual dimension*/
		dimsym = locate(dimsym);
		if(dimsym == NULL) {
		    derror("Undefined or forward referenced dimension: %s",(yyvsp[0].sym)->name);
		    YYABORT;
		}
		(yyval.sym)=dimsym;
	    }
#line 2101 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 588 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=listlength(stack);
             listpush(stack,(void*)(yyvsp[0].sym));
	    }
#line 2109 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 592 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-2].mark); listpush(stack,(void*)(yyvsp[0].sym));}
#line 2115 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 597 "ncgen.y" /* yacc.c:1646  */
    {
		int i;
		Dimset dimset;
		stackbase=(yyvsp[0].mark);
		stacklen=listlength(stack);
		count = stacklen - stackbase;
		if(count >= NC_MAX_VAR_DIMS) {
		    yyerror("%s has too many dimensions",(yyvsp[-1].sym)->name);
		    count = NC_MAX_VAR_DIMS - 1;
		    stacklen = stackbase + count;
		}
  	        dimset.ndims = count;
		if(count > 0) {
		    /* extract the actual dimensions*/
		    for(i=0;i<count;i++) {
		        Symbol* dsym = (Symbol*)listget(stack,stackbase+i);
		        dimset.dimsyms[i] = dsym;
		    }
		    (yyvsp[-1].sym)->typ.dimset = dimset;
		}
		(yyvsp[-1].sym)->typ.basetype = NULL; /* not yet known*/
                (yyvsp[-1].sym)->objectclass=NC_TYPE;
                (yyvsp[-1].sym)->subclass=NC_FIELD;
		listsetlength(stack,stackbase);/* remove stack nodes*/
		(yyval.sym) = (yyvsp[-1].sym);
	    }
#line 2146 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 625 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=listlength(stack);}
#line 2152 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 626 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-1].mark);}
#line 2158 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 630 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=listlength(stack); listpush(stack,(void*)(yyvsp[0].sym));}
#line 2164 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 632 "ncgen.y" /* yacc.c:1646  */
    {(yyval.mark)=(yyvsp[-2].mark); listpush(stack,(void*)(yyvsp[0].sym));}
#line 2170 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 637 "ncgen.y" /* yacc.c:1646  */
    {  /* Anonymous integer dimension.
	         Can only occur in type definitions*/
	     char anon[32];
	     sprintf(anon,"const%u",uint32_val);
	     (yyval.sym) = install(anon);
	     (yyval.sym)->objectclass = NC_DIM;
	     (yyval.sym)->dim.isconstant = 1;
	     (yyval.sym)->dim.declsize = uint32_val;
	    }
#line 2184 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 647 "ncgen.y" /* yacc.c:1646  */
    {  /* Anonymous integer dimension.
	         Can only occur in type definitions*/
	     char anon[32];
	     if(int32_val <= 0) {
		derror("field dimension must be positive");
		YYABORT;
	     }
	     sprintf(anon,"const%d",int32_val);
	     (yyval.sym) = install(anon);
	     (yyval.sym)->objectclass = NC_DIM;
	     (yyval.sym)->dim.isconstant = 1;
	     (yyval.sym)->dim.declsize = int32_val;
	    }
#line 2202 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 667 "ncgen.y" /* yacc.c:1646  */
    {Symbol* vsym = (yyvsp[0].sym);
		if(vsym->objectclass != NC_VAR) {
		    derror("Undefined or forward referenced variable: %s",vsym->name);
		    YYABORT;
		}
		(yyval.sym)=vsym;
	    }
#line 2214 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 678 "ncgen.y" /* yacc.c:1646  */
    {Symbol* tsym = (yyvsp[0].sym);
		if(tsym->objectclass != NC_TYPE) {
		    derror("Undefined or forward referenced type: %s",tsym->name);
		    YYABORT;
		}
		(yyval.sym)=tsym;
	    }
#line 2226 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 689 "ncgen.y" /* yacc.c:1646  */
    {Symbol* tvsym = (yyvsp[0].sym); Symbol* sym;
		/* disambiguate*/
		tvsym->objectclass = NC_VAR;
		sym = locate(tvsym);
		if(sym == NULL) {
		    tvsym->objectclass = NC_TYPE;
		    sym = locate(tvsym);
		    if(tvsym == NULL) {
		        derror("Undefined or forward referenced name: %s",(yyvsp[0].sym)->name);
		        YYABORT;
		    } else tvsym = sym;
		} else tvsym = sym;
		if(tvsym == NULL) {
		    derror("Undefined name (line %d): %s",(yyvsp[0].sym)->lineno,(yyvsp[0].sym)->name);
		    YYABORT;
		}
		(yyval.sym)=tvsym;
	    }
#line 2249 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 707 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym)=(yyvsp[0].sym);}
#line 2255 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 714 "ncgen.y" /* yacc.c:1646  */
    {}
#line 2261 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 714 "ncgen.y" /* yacc.c:1646  */
    {}
#line 2267 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 718 "ncgen.y" /* yacc.c:1646  */
    { (yyval.sym)=makeattribute((yyvsp[-2].sym),NULL,NULL,(yyvsp[0].datalist),ATTRGLOBAL);}
#line 2273 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 720 "ncgen.y" /* yacc.c:1646  */
    {Symbol* tsym = (yyvsp[-5].sym); Symbol* vsym = (yyvsp[-4].sym); Symbol* asym = (yyvsp[-2].sym);
		if(vsym->objectclass == NC_VAR) {
		    (yyval.sym)=makeattribute(asym,vsym,tsym,(yyvsp[0].datalist),ATTRVAR);
		} else {
		    derror("Doubly typed attribute: %s",asym->name);
		    YYABORT;
		}
	    }
#line 2286 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 729 "ncgen.y" /* yacc.c:1646  */
    {Symbol* sym = (yyvsp[-4].sym); Symbol* asym = (yyvsp[-2].sym);
		if(sym->objectclass == NC_VAR) {
		    (yyval.sym)=makeattribute(asym,sym,NULL,(yyvsp[0].datalist),ATTRVAR);
		} else if(sym->objectclass == NC_TYPE) {
		    (yyval.sym)=makeattribute(asym,NULL,sym,(yyvsp[0].datalist),ATTRGLOBAL);
		} else {
		    derror("Attribute prefix not a variable or type: %s",asym->name);
		    YYABORT;
		}
	    }
#line 2301 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 740 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_FILLVALUE_FLAG,(yyvsp[-4].sym),NULL,(void*)(yyvsp[0].datalist),0);}
#line 2307 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 742 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_FILLVALUE_FLAG,(yyvsp[-4].sym),(yyvsp[-5].sym),(void*)(yyvsp[0].datalist),0);}
#line 2313 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 744 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_STORAGE_FLAG,(yyvsp[-4].sym),NULL,(void*)&(yyvsp[0].constant),1);}
#line 2319 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 746 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_CHUNKSIZES_FLAG,(yyvsp[-4].sym),NULL,(void*)(yyvsp[0].datalist),0);}
#line 2325 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 748 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_FLETCHER32_FLAG,(yyvsp[-4].sym),NULL,(void*)&(yyvsp[0].constant),1);}
#line 2331 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 750 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_DEFLATE_FLAG,(yyvsp[-4].sym),NULL,(void*)&(yyvsp[0].constant),1);}
#line 2337 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 752 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_SHUFFLE_FLAG,(yyvsp[-4].sym),NULL,(void*)&(yyvsp[0].constant),1);}
#line 2343 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 754 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_ENDIAN_FLAG,(yyvsp[-4].sym),NULL,(void*)&(yyvsp[0].constant),1);}
#line 2349 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 756 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_NOFILL_FLAG,(yyvsp[-4].sym),NULL,(void*)&(yyvsp[0].constant),1);}
#line 2355 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 758 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_COMPRESSION_FLAG,(yyvsp[-4].sym),NULL,(void*)&(yyvsp[0].constant),1);}
#line 2361 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 760 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym) = makespecial(_FORMAT_FLAG,NULL,NULL,(void*)&(yyvsp[0].constant),1);}
#line 2367 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 765 "ncgen.y" /* yacc.c:1646  */
    {
	        (yyval.sym)=(yyvsp[0].sym);
                (yyvsp[0].sym)->ref.is_ref=1;
                (yyvsp[0].sym)->is_prefixed=0;
                setpathcurrent((yyvsp[0].sym));
	    }
#line 2378 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 772 "ncgen.y" /* yacc.c:1646  */
    {
	        (yyval.sym)=(yyvsp[0].sym);
                (yyvsp[0].sym)->ref.is_ref=1;
                (yyvsp[0].sym)->is_prefixed=1;
	        /* path is set in ncgen.l*/
	    }
#line 2389 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 781 "ncgen.y" /* yacc.c:1646  */
    {}
#line 2395 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 782 "ncgen.y" /* yacc.c:1646  */
    {}
#line 2401 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 790 "ncgen.y" /* yacc.c:1646  */
    {(yyvsp[-2].sym)->data = (yyvsp[0].datalist);}
#line 2407 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 793 "ncgen.y" /* yacc.c:1646  */
    {(yyval.datalist) = (yyvsp[0].datalist);}
#line 2413 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 794 "ncgen.y" /* yacc.c:1646  */
    {(yyval.datalist) = (yyvsp[0].datalist);}
#line 2419 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 798 "ncgen.y" /* yacc.c:1646  */
    {(yyval.datalist) = builddatalist(0);}
#line 2425 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 802 "ncgen.y" /* yacc.c:1646  */
    {(yyval.datalist) = builddatalist(0); datalistextend((yyval.datalist),&((yyvsp[0].constant)));}
#line 2431 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 804 "ncgen.y" /* yacc.c:1646  */
    {datalistextend((yyvsp[-2].datalist),&((yyvsp[0].constant))); (yyval.datalist)=(yyvsp[-2].datalist);}
#line 2437 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 808 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=(yyvsp[0].constant);}
#line 2443 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 809 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=builddatasublist((yyvsp[-1].datalist));}
#line 2449 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 813 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=(yyvsp[0].constant);}
#line 2455 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 814 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_OPAQUE);}
#line 2461 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 815 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_FILLVALUE);}
#line 2467 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 816 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_NIL);}
#line 2473 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 817 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=(yyvsp[0].constant);}
#line 2479 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 822 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant) = makeenumconstref((yyvsp[0].sym));}
#line 2485 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 826 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=evaluate((yyvsp[-3].sym),(yyvsp[-1].datalist));}
#line 2491 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 831 "ncgen.y" /* yacc.c:1646  */
    {(yyval.datalist) = builddatalist(0); datalistextend((yyval.datalist),&((yyvsp[0].constant)));}
#line 2497 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 833 "ncgen.y" /* yacc.c:1646  */
    {datalistextend((yyvsp[-2].datalist),&((yyvsp[0].constant))); (yyval.datalist)=(yyvsp[-2].datalist);}
#line 2503 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 837 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_CHAR);}
#line 2509 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 838 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_BYTE);}
#line 2515 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 839 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_SHORT);}
#line 2521 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 840 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_INT);}
#line 2527 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 841 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_INT64);}
#line 2533 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 842 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_UBYTE);}
#line 2539 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 843 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_USHORT);}
#line 2545 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 844 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_UINT);}
#line 2551 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 845 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_UINT64);}
#line 2557 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 846 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_FLOAT);}
#line 2563 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 847 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_DOUBLE);}
#line 2569 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 848 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_STRING);}
#line 2575 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 852 "ncgen.y" /* yacc.c:1646  */
    {(yyval.datalist) = builddatalist(0); datalistextend((yyval.datalist),&((yyvsp[0].constant)));}
#line 2581 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 853 "ncgen.y" /* yacc.c:1646  */
    {(yyval.datalist)=(yyvsp[-2].datalist); datalistextend((yyvsp[-2].datalist),&((yyvsp[0].constant)));}
#line 2587 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 858 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_INT);}
#line 2593 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 860 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_UINT);}
#line 2599 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 862 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_INT64);}
#line 2605 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 864 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_UINT64);}
#line 2611 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 868 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=makeconstdata(NC_STRING);}
#line 2617 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 872 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=(yyvsp[0].constant);}
#line 2623 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 873 "ncgen.y" /* yacc.c:1646  */
    {(yyval.constant)=(yyvsp[0].constant);}
#line 2629 "ncgen.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 879 "ncgen.y" /* yacc.c:1646  */
    {(yyval.sym)=(yyvsp[0].sym);}
#line 2635 "ncgen.tab.c" /* yacc.c:1646  */
    break;


#line 2639 "ncgen.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 882 "ncgen.y" /* yacc.c:1906  */


#ifndef NO_STDARG
static void
yyerror(const char *fmt, ...)
#else
static void
yyerror(fmt,va_alist) const char* fmt; va_dcl
#endif
{
    va_list argv;
    vastart(argv,fmt);
    (void)fprintf(stderr,"%s: %s line %d: ", progname, cdlname, lineno);
    vderror(fmt,argv);
}

/* undefine yywrap macro, in case we are using bison instead of yacc */
#ifdef yywrap
#undef yywrap
#endif

static int
ncgwrap(void)                    /* returns 1 on EOF if no more input */
{
    return  1;
}

/* get lexical input routine generated by lex  */
#include "ncgenyy.c"

/* Really should init our data within this file */
void
parse_init(void)
{
    int i;
    opaqueid = 0;
    arrayuid = 0;
    symlist = NULL;
    stack = listnew();
    groupstack = listnew();
    consttype = NC_NAT;
    grpdefs = listnew();
    dimdefs = listnew();
    attdefs = listnew();
    gattdefs = listnew();
    xattdefs = listnew();
    typdefs = listnew();
    vardefs = listnew();
    condefs = listnew();
    tmp = listnew();
    /* Create the primitive types */
    for(i=NC_NAT+1;i<=NC_STRING;i++) {
        primsymbols[i] = makeprimitivetype(i);
    }
    lex_init();
}

static Symbol*
makeprimitivetype(nc_type nctype)
{
    Symbol* sym = install(primtypenames[nctype]);
    sym->objectclass=NC_TYPE;
    sym->subclass=NC_PRIM;
    sym->ncid = nctype;
    sym->typ.typecode = nctype;
    sym->typ.size = ncsize(nctype);
    sym->typ.nelems = 1;
    sym->typ.alignment = nctypealignment(nctype);
    /* Make the basetype circular so we can always ask for it */
    sym->typ.basetype = sym;
    sym->prefix = listnew();
    return sym;
}

/* Symbol table operations for ncgen tool */
/* install sname in symbol table even if it is already there */
Symbol*
install(const char *sname)
{
    Symbol* sp;
    sp = (Symbol*) emalloc (sizeof (struct Symbol));
    memset((void*)sp,0,sizeof(struct Symbol));    
    sp->name = nulldup(sname);
    sp->next = symlist;
    sp->lineno = lineno;
    sp->location = currentgroup();
    sp->container = currentgroup();
    symlist = sp;
    return sp;
}


static Symbol*
currentgroup(void)
{
    if(listlength(groupstack) == 0) return rootgroup;
    return (Symbol*)listtop(groupstack);
}

static Symbol*
createrootgroup(const char* dataset)
{
    Symbol* gsym = install(dataset);
    gsym->objectclass = NC_GRP;
    gsym->container = NULL;
    gsym->subnodes = listnew();
    gsym->grp.is_root = 1;
    gsym->prefix = listnew();
    listpush(grpdefs,(void*)gsym);
    rootgroup = gsym;
    return gsym;
}

static Symbol*
creategroup(Symbol * gsym)
{
    /* See if this group already exists in currentgroup */
    gsym->objectclass = NC_GRP;
    if(dupobjectcheck(NC_GRP,gsym)) {
        derror("Duplicate group name in same scope: %s",gsym->name);
	return NULL;
    }
    addtogroup(gsym);
    gsym->subnodes = listnew();
    listpush(groupstack,(void*)gsym);
    listpush(grpdefs,(void*)gsym);
    return gsym;
}

static NCConstant
makeconstdata(nc_type nctype)
{
    NCConstant con = nullconstant;
    consttype = nctype;
    con.nctype = nctype;
    con.lineno = lineno;
    con.filled = 0;
    switch (nctype) {
	case NC_CHAR: con.value.charv = char_val; break;
        case NC_BYTE: con.value.int8v = byte_val; break;
        case NC_SHORT: con.value.int16v = int16_val; break;
        case NC_INT: con.value.int32v = int32_val; break;
        case NC_FLOAT:
	    con.value.floatv = float_val;
	    break;
        case NC_DOUBLE:
	    con.value.doublev = double_val;
	    break;
        case NC_STRING: { /* convert to a set of chars*/
	    size_t len;
	    len = bbLength(lextext);
	    con.value.stringv.len = len;
	    con.value.stringv.stringv = bbDup(lextext);
	    bbClear(lextext);	    
	    }
	    break;

	/* Allow these constants even in netcdf-3 */
        case NC_UBYTE: con.value.uint8v = ubyte_val; break;
        case NC_USHORT: con.value.uint16v = uint16_val; break;
        case NC_UINT: con.value.uint32v = uint32_val; break;
        case NC_INT64: con.value.int64v = int64_val; break;
        case NC_UINT64: con.value.uint64v = uint64_val; break;

#ifdef USE_NETCDF4
	case NC_OPAQUE: {
	    char* s;
	    int len;
	    len = bbLength(lextext);
	    s = (char*)emalloc(len+1);
	    strncpy(s,bbContents(lextext),len);
	    s[len] = '\0';
	    con.value.opaquev.stringv = s;
	    con.value.opaquev.len = len;
	    } break;

	case NC_NIL:
	    break; /* no associated value*/
#endif

	case NC_FILLVALUE:
	    break; /* no associated value*/

	default:
	    yyerror("Data constant: unexpected NC type: %s",
		    nctypename(nctype));
	    con.value.stringv.stringv = NULL;    
	    con.value.stringv.len = 0;
    }
    return con;
}

static NCConstant
makeenumconstref(Symbol* refsym)
{
    NCConstant con;

    markcdf4("Enum type");
    consttype = NC_ENUM;
    con.nctype = NC_ECONST;
    con.lineno = lineno;
    con.filled = 0;
    refsym->objectclass = NC_TYPE;
    refsym->subclass = NC_ECONST;
    con.value.enumv = refsym;
    return con;
}

static void
addtogroup(Symbol* sym)
{
    Symbol* grp = currentgroup();
    sym->container = grp;
    listpush(grp->subnodes,(void*)sym);
    setpathcurrent(sym);
}

/* Check for duplicate name of given type within current group*/
static int
dupobjectcheck(nc_class objectclass, Symbol* pattern)
{
    int i;
    Symbol* grp;
    if(pattern == NULL) return 0;
    grp = pattern->container;
    if(grp == NULL || grp->subnodes == NULL) return 0;
    for(i=0;i<listlength(grp->subnodes);i++) {
	Symbol* sym = (Symbol*)listget(grp->subnodes,i);
	if(!sym->ref.is_ref && sym->objectclass == objectclass
	   && strcmp(sym->name,pattern->name)==0) return 1;
    }
    return 0;
}

static void
setpathcurrent(Symbol* sym)
{
    sym->is_prefixed = 0;
    sym->prefix = prefixdup(groupstack);
}

/* Convert an nc_type code to the corresponding Symbol*/
Symbol*
basetypefor(nc_type nctype)
{
    return primsymbols[nctype];
}

char*
specialname(int flag)
{
    switch (flag) {
    case _FILLVALUE_FLAG: return "_FillValue";
    case _FORMAT_FLAG: return "_Format";
    case _STORAGE_FLAG: return "_Storage";
    case _CHUNKSIZES_FLAG: return "_ChunkSizes";
    case _FLETCHER32_FLAG: return "_Fletcher32";
    case _DEFLATE_FLAG: return "_DeflateLevel";
    case _SHUFFLE_FLAG: return "_Shuffle";
    case _ENDIAN_FLAG: return "_Endianness";
    case _NOFILL_FLAG: return "_NoFill";
    case _COMPRESSION_FLAG: return "_Compression";
    default: break;
    }
    return "<unknown>";
}

static int
truefalse(NCConstant* con, int tag)
{
    if(con->nctype == NC_STRING) {
	char* sdata = con->value.stringv.stringv;
	if(strncmp(sdata,"false",NC_MAX_NAME) == 0
           || strncmp(sdata,"0",NC_MAX_NAME) == 0)
	    return 0;
	else if(strncmp(sdata,"true",NC_MAX_NAME) == 0
           || strncmp(sdata,"1",NC_MAX_NAME) == 0)
	    return 1;
	else goto fail;
    } else if(con->value.int32v < 0 || con->value.int32v > 1)
	goto fail;
    return con->value.int32v;

fail:
    derror("%s: illegal value",specialname(tag));
    return 0;
}

/* Since this may be affected by the _Format attribute, which
   may come last, capture all the special info and sort it out
   in semantics.
*/
static Symbol*
makespecial(int tag, Symbol* vsym, Symbol* tsym, void* data, int isconst)
{
    Symbol* attr = NULL;
    Datalist* list;
    NCConstant* con;
    NCConstant iconst;
    int tf = 0;
    char* sdata = NULL;
    int idata =  -1;

    if(tag == _FORMAT_FLAG) {
        if(vsym != NULL) {
            derror("_Format: must be global attribute");
            vsym = NULL;
        }
    } else {
        if(vsym == NULL) {
	    derror("%s: must have non-NULL vsym", specialname(tag));
	    return NULL;
        }
    }

    if(tag != _FILLVALUE_FLAG && tag != _FORMAT_FLAG)
        /*Main.*/specials_flag++;

    if(isconst) {
	con = (NCConstant*)data;
	list = builddatalist(1);
        dlappend(list,(NCConstant*)data);
    } else {
        list = (Datalist*)data;
        con = (NCConstant*)list->data;
    }

    switch (tag) {
    case _FLETCHER32_FLAG:
    case _SHUFFLE_FLAG:
    case _NOFILL_FLAG:
	iconst.nctype = (con->nctype == NC_STRING?NC_STRING:NC_INT);
	convert1(con,&iconst);
	tf = truefalse(&iconst,tag);
	break;
    case _FORMAT_FLAG:
    case _STORAGE_FLAG:
    case _ENDIAN_FLAG:
    case _COMPRESSION_FLAG:
	iconst.nctype = NC_STRING;
	convert1(con,&iconst);
	if(iconst.nctype == NC_STRING)
	    sdata = iconst.value.stringv.stringv;
	else
	    derror("%s: illegal value",specialname(tag));
	break;
    case _DEFLATE_FLAG:
	iconst.nctype = NC_INT;
	convert1(con,&iconst);
	if(iconst.nctype == NC_INT)
	    idata = iconst.value.int32v;
	else
	    derror("%s: illegal value",specialname(tag));
	break;
    case _CHUNKSIZES_FLAG:
    case _FILLVALUE_FLAG:
	/* Handle below */
	break;
    default: PANIC1("unexpected special tag: %d",tag);
    }
    
    if(tag == _FORMAT_FLAG) {
	/* Watch out: this is a global attribute */
	struct Kvalues* kvalue;
	int found = 0;

	/* Use the table in main.c */
        for(kvalue = legalkinds; kvalue->name; kvalue++) {
	    if(strcmp(sdata, kvalue->name) == 0) {
		/*Main.*/format_flag = kvalue->k_flag;
		found = 1;
	        break;
	    }
	}
	if(!found)
	    derror("_Format: illegal value: %s",sdata);
	/*Main.*/format_attribute = 1;
    } else {
        Specialdata* special;

        /* Set up special info */
        special = &vsym->var.special;

        if(tag == _FILLVALUE_FLAG) {
            special->_Fillvalue = list;
            /* fillvalue must be a single value*/
            if(list->length != 1)
                derror("_FillValue: must be a single (possibly compound) value",
                            vsym->name);
            /* check that the attribute value contains no fill values*/
            if(containsfills(list)) {
                derror("Attribute data may not contain fill values (i.e. _ )");
            }
            /* _FillValue is also a real attribute*/
            if(vsym->objectclass != NC_VAR) {
                derror("_FillValue attribute not associated with variable: %s",vsym->name);
            }
            if(tsym  == NULL) tsym = vsym->typ.basetype;
            else if(vsym->typ.basetype != tsym) {
                derror("_FillValue attribute type does not match variable type: %s",vsym->name);
            }
            attr = makeattribute(install("_FillValue"),vsym,tsym,list,ATTRVAR);
        } else switch (tag) {
	    // These will be output as attributes later
            case _STORAGE_FLAG:
                if(strcmp(sdata,"contiguous") == 0)
                    special->_Storage = NC_CONTIGUOUS;
                else if(strcmp(sdata,"chunked") == 0)
                    special->_Storage = NC_CHUNKED;
                else
                    derror("_Storage: illegal value: %s",sdata);
                special->flags |= _STORAGE_FLAG;
                break;
            case _FLETCHER32_FLAG:
                special->_Fletcher32 = tf;
                special->flags |= _FLETCHER32_FLAG;
                break;
            case _DEFLATE_FLAG:
                special->_DeflateLevel = idata;
                special->flags |= _DEFLATE_FLAG;
                break;
            case _SHUFFLE_FLAG:
                special->_Shuffle = tf;
                special->flags |= _SHUFFLE_FLAG;
                break;
            case _ENDIAN_FLAG:
                if(strcmp(sdata,"little") == 0)
                    special->_Endianness = 1;
                else if(strcmp(sdata,"big") == 0)
                    special->_Endianness = 2;
                else
                    derror("_Endianness: illegal value: %s",sdata);
                special->flags |= _ENDIAN_FLAG;
                break;
            case _NOFILL_FLAG:
                special->_Fill = (1 - tf); /* negate */
                special->flags |= _NOFILL_FLAG;
                break;
            case _CHUNKSIZES_FLAG: {
                int i;
                special->nchunks = list->length;
                special->_ChunkSizes = (size_t*)emalloc(sizeof(size_t)*special->nchunks);
                for(i=0;i<special->nchunks;i++) {
                    iconst.nctype = NC_INT;
                    convert1(&list->data[i],&iconst);
                    if(iconst.nctype == NC_INT) {
                        special->_ChunkSizes[i] = (size_t)iconst.value.int32v;
                    } else {
                        efree(special->_ChunkSizes);
                        derror("%s: illegal value",specialname(tag));
                    }
                }
                special->flags |= _CHUNKSIZES_FLAG;
                /* Chunksizes => storage == chunked */
                special->flags |= _STORAGE_FLAG;
                special->_Storage = NC_CHUNKED;
                } break;
            case _COMPRESSION_FLAG:
<<<<<<< HEAD
                strncpy(special->_Algorithm,sdata,NC_COMPRESSION_MAX_NAME);
=======
<<<<<<< HEAD
                strncpy(special->_Algorithm,sdata,COMPRESSION_MAX_NAME);
>>>>>>> Add support for multiple compression algorithms.
	        /* overrides zip (DEFLATE_FLAG) */
		special->flags &= (~_DEFLATE_FLAG);
=======
                if(strcmp(sdata,"zip") == 0) {
                    special->_Algorithm = NC_COMPRESS_DEFLATE;
		    /* overrides zip (DEFLATE_FLAG) */
		    special->flags &= (~_DEFLATE_FLAG);
                } else if(strcmp(sdata,"bzip2") == 0) {
                    special->_Algorithm = NC_COMPRESS_BZIP2;
		    /* overrides zip (DEFLATE_FLAG) */
		    special->flags &= (~_DEFLATE_FLAG);
                } else
                    derror("_Compression: illegal value: %s",sdata);
>>>>>>> Add support for multiple compression algorithms.
                special->flags |= _COMPRESSION_FLAG;
                break;
            default: PANIC1("makespecial: illegal token: %d",tag);
         }
    }
    return attr;
}

static Symbol*
makeattribute(Symbol* asym,
		Symbol* vsym,
		Symbol* tsym,
		Datalist* data,
		Attrkind kind) /* global var or unknown*/
{
    asym->objectclass = NC_ATT;
    asym->data = data;
    addtogroup(asym);
    switch (kind) {
    case ATTRVAR:
        asym->att.var = vsym;
        asym->typ.basetype = tsym;
        listpush(attdefs,(void*)asym);
	break;
    case ATTRGLOBAL:
        asym->att.var = NULL; /* NULL => NC_GLOBAL*/
        asym->typ.basetype = tsym;
        listpush(gattdefs,(void*)asym);
	break;
    default: PANIC1("unexpected attribute type: %d",kind);
    }
    /* finally; check that the attribute value contains no fill values*/
    if(containsfills(data)) {
	derror("Attribute data may not contain fill values (i.e. _ ): %s",asym->name);
    }
    return asym;
}

static int
containsfills(Datalist* list)
{
    if(list != NULL) {
        int i;
        NCConstant* con = list->data;
        for(i=0;i<list->length;i++,con++) {
	    if(con->nctype == NC_COMPOUND) {
	        if(containsfills(con->value.compoundv)) return 1;	
	    } else if(con->nctype == NC_FILLVALUE) return 1;	
	}
    }
    return 0;
}

static void
datalistextend(Datalist* dl, NCConstant* con)
{
    dlappend(dl,con);
}

static void
vercheck(int ncid)
{
    char* tmsg = NULL;
    switch (ncid) {
    case NC_UBYTE: tmsg = "netCDF4 type: UBYTE"; break;
    case NC_USHORT: tmsg = "netCDF4 type: USHORT"; break;
    case NC_UINT: tmsg = "netCDF4 type: UINT"; break;
    case NC_INT64: tmsg = "netCDF4 type: INT64"; break;
    case NC_UINT64: tmsg = "netCDF4 type: UINT64"; break;
    case NC_STRING: tmsg = "netCDF4 type: STRING"; break;
    case NC_VLEN: tmsg = "netCDF4 type: VLEN"; break;
    case NC_OPAQUE: tmsg = "netCDF4 type: OPAQUE"; break;
    case NC_ENUM: tmsg = "netCDF4 type: ENUM"; break;
    case NC_COMPOUND: tmsg = "netCDF4 type: COMPOUND"; break;
    default: break;
    }
    if(tmsg != NULL) markcdf4(tmsg);
}

/*
Since the arguments are all simple constants,
we can evaluate the function immediately
and return its value.
Note that currently, only a single value can
be returned.
*/

static NCConstant
evaluate(Symbol* fcn, Datalist* arglist)
{
    NCConstant result = nullconstant;

    /* prepare the result */
    result.lineno = fcn->lineno;

    if(strcasecmp(fcn->name,"time") == 0) {
        char* timekind = NULL;
        char* timevalue = NULL;
        result.nctype = NC_DOUBLE;
        result.value.doublev = 0;
	/* int time([string],string) */
	switch (arglist->length) {
	case 2:
	    if(arglist->data[1].nctype != NC_STRING) {
	        derror("Expected function signature: time([string,]string)");
	        goto done;
	    }
	    /* fall thru */
	case 1:
	    if(arglist->data[0].nctype != NC_STRING) {
	        derror("Expected function signature: time([string,]string)");
	        goto done;
	    }
	    break;
	case 0:
	default: 
	    derror("Expected function signature: time([string,]string)");
	    goto done;
	}
	if(arglist->length == 2) {
	    timekind = arglist->data[0].value.stringv.stringv;
            timevalue = arglist->data[1].value.stringv.stringv;
	} else
            timevalue = arglist->data[0].value.stringv.stringv;
	if(timekind == NULL) { /* use cd time as the default */
            cdCompTime comptime;
	    CdTime cdtime;
	    cdCalenType timetype = cdStandard;
	    cdChar2Comp(timetype,timevalue,&comptime);
	    /* convert comptime to cdTime */
	    cdtime.year = comptime.year;	    
	    cdtime.month = comptime.month;
	    cdtime.day = comptime.day;    
	    cdtime.hour = comptime.hour;
	    cdtime.baseYear = 1970;
	    cdtime.timeType = CdChron;
	    /* convert to double value */
	    Cdh2e(&cdtime,&result.value.doublev);
        } else {
	    derror("Time conversion '%s' not supported",timekind);
	    goto done;
	}
    } else {	/* Unknown function */
	derror("Unknown function name: %s",fcn->name);
	goto done;
    }

done:
    return result;
}
