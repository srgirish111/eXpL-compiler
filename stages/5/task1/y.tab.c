/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "task.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	
	#include"task.h"
	#include"task.c"
	int yylex();
	int yyerror(char const*);
	int yywrap();
	int i;
	FILE *fp;
	extern FILE *yyin;
	int currtype;

#line 87 "y.tab.c"

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

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    PLUS = 259,                    /* PLUS  */
    MINUS = 260,                   /* MINUS  */
    MUL = 261,                     /* MUL  */
    DIV = 262,                     /* DIV  */
    READ = 263,                    /* READ  */
    WRITE = 264,                   /* WRITE  */
    IF = 265,                      /* IF  */
    THEN = 266,                    /* THEN  */
    ELSE = 267,                    /* ELSE  */
    ENDIF = 268,                   /* ENDIF  */
    WHILE = 269,                   /* WHILE  */
    DO = 270,                      /* DO  */
    ENDWHILE = 271,                /* ENDWHILE  */
    GT = 272,                      /* GT  */
    LT = 273,                      /* LT  */
    GE = 274,                      /* GE  */
    LE = 275,                      /* LE  */
    EQ = 276,                      /* EQ  */
    NE = 277,                      /* NE  */
    PBEGIN = 278,                  /* PBEGIN  */
    PEND = 279,                    /* PEND  */
    CONTINUE = 280,                /* CONTINUE  */
    BREAK = 281,                   /* BREAK  */
    INT = 282,                     /* INT  */
    STR = 283,                     /* STR  */
    DECL = 284,                    /* DECL  */
    ENDDECL = 285,                 /* ENDDECL  */
    MESG = 286,                    /* MESG  */
    ID = 287,                      /* ID  */
    RETURN = 288,                  /* RETURN  */
    MAINFN = 289,                  /* MAINFN  */
    ANDTKN = 290,                  /* ANDTKN  */
    ORTKN = 291,                   /* ORTKN  */
    NOTTKN = 292,                  /* NOTTKN  */
    MOD = 293                      /* MOD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define READ 263
#define WRITE 264
#define IF 265
#define THEN 266
#define ELSE 267
#define ENDIF 268
#define WHILE 269
#define DO 270
#define ENDWHILE 271
#define GT 272
#define LT 273
#define GE 274
#define LE 275
#define EQ 276
#define NE 277
#define PBEGIN 278
#define PEND 279
#define CONTINUE 280
#define BREAK 281
#define INT 282
#define STR 283
#define DECL 284
#define ENDDECL 285
#define MESG 286
#define ID 287
#define RETURN 288
#define MAINFN 289
#define ANDTKN 290
#define ORTKN 291
#define NOTTKN 292
#define MOD 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "task.y"

	struct tnode *no;
	struct param *par;
	int numb;
	char *name;

#line 223 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_PLUS = 4,                       /* PLUS  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_READ = 8,                       /* READ  */
  YYSYMBOL_WRITE = 9,                      /* WRITE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_THEN = 11,                      /* THEN  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_ENDIF = 13,                     /* ENDIF  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_ENDWHILE = 16,                  /* ENDWHILE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_PBEGIN = 23,                    /* PBEGIN  */
  YYSYMBOL_PEND = 24,                      /* PEND  */
  YYSYMBOL_CONTINUE = 25,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 26,                     /* BREAK  */
  YYSYMBOL_INT = 27,                       /* INT  */
  YYSYMBOL_STR = 28,                       /* STR  */
  YYSYMBOL_DECL = 29,                      /* DECL  */
  YYSYMBOL_ENDDECL = 30,                   /* ENDDECL  */
  YYSYMBOL_MESG = 31,                      /* MESG  */
  YYSYMBOL_ID = 32,                        /* ID  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_MAINFN = 34,                    /* MAINFN  */
  YYSYMBOL_ANDTKN = 35,                    /* ANDTKN  */
  YYSYMBOL_ORTKN = 36,                     /* ORTKN  */
  YYSYMBOL_NOTTKN = 37,                    /* NOTTKN  */
  YYSYMBOL_MOD = 38,                       /* MOD  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_43_ = 43,                       /* '('  */
  YYSYMBOL_44_ = 44,                       /* ')'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Program = 49,                   /* Program  */
  YYSYMBOL_GdeclBlock = 50,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 51,                 /* GdeclList  */
  YYSYMBOL_GDecl = 52,                     /* GDecl  */
  YYSYMBOL_Type = 53,                      /* Type  */
  YYSYMBOL_GidList = 54,                   /* GidList  */
  YYSYMBOL_Gid = 55,                       /* Gid  */
  YYSYMBOL_ParamList = 56,                 /* ParamList  */
  YYSYMBOL_Param = 57,                     /* Param  */
  YYSYMBOL_FdefBlock = 58,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 59,                      /* Fdef  */
  YYSYMBOL_LdeclBlock = 60,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 61,                  /* LDecList  */
  YYSYMBOL_LDecl = 62,                     /* LDecl  */
  YYSYMBOL_IdList = 63,                    /* IdList  */
  YYSYMBOL_MainBlock = 64,                 /* MainBlock  */
  YYSYMBOL_Body = 65,                      /* Body  */
  YYSYMBOL_Rstmt = 66,                     /* Rstmt  */
  YYSYMBOL_Slist = 67,                     /* Slist  */
  YYSYMBOL_Stmt = 68,                      /* Stmt  */
  YYSYMBOL_Ifstmt = 69,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 70,                 /* Whilestmt  */
  YYSYMBOL_expr = 71,                      /* expr  */
  YYSYMBOL_ArgList = 72,                   /* ArgList  */
  YYSYMBOL_IDEN = 73                       /* IDEN  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    38,    39,    41,    42,    44,    44,    45,
      46,    47,    50,    52,    54,    55,    56,    59,    61,    62,
      64,    69,    69,    71,    75,    75,    77,    77,    79,    81,
      81,    94,    95,    97,   100,   105,   106,   108,   109,   110,
     111,   112,   113,   114,   117,   118,   121,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   146,   147,   148,
     150
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "PLUS", "MINUS",
  "MUL", "DIV", "READ", "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE",
  "DO", "ENDWHILE", "GT", "LT", "GE", "LE", "EQ", "NE", "PBEGIN", "PEND",
  "CONTINUE", "BREAK", "INT", "STR", "DECL", "ENDDECL", "MESG", "ID",
  "RETURN", "MAINFN", "ANDTKN", "ORTKN", "NOTTKN", "MOD", "';'", "','",
  "'['", "']'", "'('", "')'", "'{'", "'}'", "'='", "$accept", "Program",
  "GdeclBlock", "GdeclList", "GDecl", "Type", "GidList", "Gid",
  "ParamList", "Param", "FdefBlock", "Fdef", "LdeclBlock", "LDecList",
  "LDecl", "IdList", "MainBlock", "Body", "Rstmt", "Slist", "Stmt",
  "Ifstmt", "Whilestmt", "expr", "ArgList", "IDEN", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,  -122,  -122,    39,    29,   -11,    27,  -122,  -122,    48,
    -122,     0,  -122,    58,   -11,  -122,  -122,    34,  -122,  -122,
      67,    11,  -122,    37,  -122,  -122,    40,    93,   -11,  -122,
       0,   -11,    52,    51,    69,   -25,  -122,  -122,    -9,    31,
    -122,  -122,   -11,  -122,    79,   301,    61,    88,    86,  -122,
      96,   103,   105,   106,   107,   120,   122,   125,   260,  -122,
    -122,  -122,   127,  -122,   135,   112,  -122,   136,  -122,    88,
     149,    25,    25,    25,  -122,  -122,    25,    25,   159,  -122,
      25,  -122,   144,  -122,  -122,  -122,   139,   146,  -122,  -122,
     100,    25,    25,   109,  -122,   116,   151,   193,   201,   152,
     237,   156,  -122,   153,    21,    66,   158,    25,    25,    25,
      25,    25,    25,    25,    25,    25,    25,    25,    25,    25,
     162,   192,   189,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
     243,    19,  -122,    -2,    -2,  -122,  -122,    66,    66,    66,
      66,    66,    66,    66,    66,  -122,  -122,   301,   301,    25,
    -122,    73,   274,   243,   301,   170,   177,   288,  -122,  -122,
     178,  -122
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,    11,     0,     0,     0,     0,     4,     6,     0,
       8,     0,     1,     0,     0,    22,     3,     0,     5,     7,
      14,     0,    13,     0,    21,     2,     0,     0,    19,     9,
       0,    19,     0,     0,     0,     0,    18,    12,     0,     0,
      15,    20,     0,    16,     0,     0,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,    69,     0,    36,
      40,    41,     0,    25,     0,     0,    27,     0,    32,     0,
       0,     0,     0,     0,    43,    42,     0,     0,     0,    35,
       0,    30,    28,    24,    26,    31,     0,     0,    63,    64,
      69,     0,     0,     0,    62,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    34,    33,    39,    29,    37,    65,
      68,     0,    61,    47,    48,    49,    50,    52,    53,    55,
      54,    56,    57,    58,    59,    51,    38,     0,     0,     0,
      66,     0,     0,    67,     0,     0,     0,     0,    45,    46,
       0,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,   215,     9,  -122,   195,   196,   184,
    -122,   216,   182,  -122,   168,  -122,     6,   -39,  -122,  -121,
     -57,  -122,  -122,   -70,  -122,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     9,    10,    34,    21,    22,    35,    36,
      14,    15,    47,    65,    66,    82,     7,    48,    78,    58,
      59,    60,    61,    93,   131,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    79,    95,    96,   109,   110,    97,    98,    67,     6,
     100,    16,    11,    62,    13,    42,     1,     2,    11,    43,
      25,   105,   106,    13,    88,    87,   151,   152,    88,    12,
      86,    42,    20,   157,   130,    44,   119,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
      29,    30,    89,    90,    45,    64,    89,    90,    91,   149,
      46,    17,    91,   150,    92,   129,     1,     2,    92,     8,
     107,   108,   109,   110,    64,     1,     2,    26,    18,   153,
      31,    51,    52,    53,    32,   154,   155,    54,     1,     2,
      23,    63,    17,    40,    79,    79,    33,    39,    55,    56,
      79,    41,    62,    62,   119,    57,    62,    62,    27,    62,
      28,    45,    62,   107,   108,   109,   110,     1,     2,     3,
     107,   108,   109,   110,    50,    46,   111,   112,   113,   114,
     115,   116,    68,   111,   112,   113,   114,   115,   116,     1,
       2,    76,    83,   104,   117,   118,    70,   119,    71,    72,
      73,   117,   118,   120,   119,   107,   108,   109,   110,    74,
     121,    75,   107,   108,   109,   110,    76,    81,   111,   112,
     113,   114,   115,   116,    80,   111,   112,   113,   114,   115,
     116,    57,    85,    99,   101,   102,   117,   118,   127,   119,
     103,   125,   128,   117,   118,   122,   119,   107,   108,   109,
     110,   146,   132,   147,   148,   107,   108,   109,   110,   158,
     111,   112,   113,   114,   115,   116,   159,   161,   111,   112,
     113,   114,   115,   116,    19,    37,    49,    38,   117,   118,
      24,   119,    69,    84,     0,   123,   117,   118,     0,   119,
     124,   107,   108,   109,   110,     0,     0,   107,   108,   109,
     110,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     111,   112,   113,   114,   115,   116,     0,     0,    51,    52,
      53,     0,   117,   118,    54,   119,   126,     0,   117,   118,
       0,   119,    51,    52,    53,    55,    56,     0,    54,     0,
     156,     0,    57,    77,     0,     0,    51,    52,    53,    55,
      56,   160,    54,     0,     0,     0,    57,     0,     0,    51,
      52,    53,     0,    55,    56,    54,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,    57
};

static const yytype_int16 yycheck[] =
{
      45,    58,    72,    73,     6,     7,    76,    77,    47,     0,
      80,     5,     3,    58,     5,    40,    27,    28,     9,    44,
      14,    91,    92,    14,     3,    70,   147,   148,     3,     0,
      69,    40,    32,   154,   104,    44,    38,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      39,    40,    31,    32,    23,    46,    31,    32,    37,    40,
      29,    34,    37,    44,    43,    44,    27,    28,    43,    30,
       4,     5,     6,     7,    65,    27,    28,    43,    30,   149,
      43,     8,     9,    10,    44,    12,    13,    14,    27,    28,
      32,    30,    34,    42,   151,   152,     3,    45,    25,    26,
     157,    32,   147,   148,    38,    32,   151,   152,    41,   154,
      43,    23,   157,     4,     5,     6,     7,    27,    28,    29,
       4,     5,     6,     7,    45,    29,    17,    18,    19,    20,
      21,    22,    46,    17,    18,    19,    20,    21,    22,    27,
      28,    41,    30,    43,    35,    36,    43,    38,    43,    43,
      43,    35,    36,    44,    38,     4,     5,     6,     7,    39,
      44,    39,     4,     5,     6,     7,    41,    32,    17,    18,
      19,    20,    21,    22,    47,    17,    18,    19,    20,    21,
      22,    32,    46,    24,    40,    46,    35,    36,    32,    38,
      44,    39,    39,    35,    36,    44,    38,     4,     5,     6,
       7,    39,    44,    11,    15,     4,     5,     6,     7,    39,
      17,    18,    19,    20,    21,    22,    39,    39,    17,    18,
      19,    20,    21,    22,     9,    30,    42,    31,    35,    36,
      14,    38,    50,    65,    -1,    42,    35,    36,    -1,    38,
      39,     4,     5,     6,     7,    -1,    -1,     4,     5,     6,
       7,    -1,    -1,    -1,    17,    18,    19,    20,    21,    22,
      17,    18,    19,    20,    21,    22,    -1,    -1,     8,     9,
      10,    -1,    35,    36,    14,    38,    39,    -1,    35,    36,
      -1,    38,     8,     9,    10,    25,    26,    -1,    14,    -1,
      16,    -1,    32,    33,    -1,    -1,     8,     9,    10,    25,
      26,    13,    14,    -1,    -1,    -1,    32,    -1,    -1,     8,
       9,    10,    -1,    25,    26,    14,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,    29,    49,    50,    53,    64,    30,    51,
      52,    53,     0,    53,    58,    59,    64,    34,    30,    52,
      32,    54,    55,    32,    59,    64,    43,    41,    43,    39,
      40,    43,    44,     3,    53,    56,    57,    55,    56,    45,
      42,    32,    40,    44,    44,    23,    29,    60,    65,    57,
      45,     8,     9,    10,    14,    25,    26,    32,    67,    68,
      69,    70,    73,    30,    53,    61,    62,    65,    46,    60,
      43,    43,    43,    43,    39,    39,    41,    33,    66,    68,
      47,    32,    63,    30,    62,    46,    65,    73,     3,    31,
      32,    37,    43,    71,    73,    71,    71,    71,    71,    24,
      71,    40,    46,    44,    43,    71,    71,     4,     5,     6,
       7,    17,    18,    19,    20,    21,    22,    35,    36,    38,
      44,    44,    44,    42,    39,    39,    39,    32,    39,    44,
      71,    72,    44,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    39,    11,    15,    40,
      44,    67,    67,    71,    12,    13,    16,    67,    39,    39,
      13,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    55,    56,    56,    56,
      57,    58,    58,    59,    60,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     3,     1,     1,     4,     4,     3,     1,     0,
       2,     2,     1,     9,     3,     2,     2,     1,     2,     3,
       1,     8,     7,     5,     3,     2,     1,     5,     5,     4,
       1,     1,     2,     2,    10,     8,     8,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     1,     3,     4,     3,     1,     1,
       4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 5: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 41 "task.y"
                                    {print_symbol_table();}
#line 1412 "y.tab.c"
    break;

  case 6: /* GdeclBlock: DECL ENDDECL  */
#line 42 "task.y"
                {}
#line 1418 "y.tab.c"
    break;

  case 7: /* GdeclList: GdeclList GDecl  */
#line 44 "task.y"
                            {}
#line 1424 "y.tab.c"
    break;

  case 8: /* GdeclList: GDecl  */
#line 44 "task.y"
                                      {}
#line 1430 "y.tab.c"
    break;

  case 9: /* GDecl: Type GidList ';'  */
#line 45 "task.y"
                         {}
#line 1436 "y.tab.c"
    break;

  case 10: /* Type: INT  */
#line 46 "task.y"
                                                {currtype=inttype;}
#line 1442 "y.tab.c"
    break;

  case 11: /* Type: STR  */
#line 47 "task.y"
                                                {currtype=strtype;
							//print_symbol_table();
							}
#line 1450 "y.tab.c"
    break;

  case 12: /* GidList: GidList ',' Gid  */
#line 50 "task.y"
                          {}
#line 1456 "y.tab.c"
    break;

  case 13: /* GidList: Gid  */
#line 52 "task.y"
                    {}
#line 1462 "y.tab.c"
    break;

  case 14: /* Gid: ID  */
#line 54 "task.y"
         {GInstall((yyvsp[0].name),currtype,1,NULL);}
#line 1468 "y.tab.c"
    break;

  case 15: /* Gid: ID '[' NUM ']'  */
#line 55 "task.y"
                      {GInstall((yyvsp[-3].name),currtype,(yyvsp[-1].numb),NULL);}
#line 1474 "y.tab.c"
    break;

  case 16: /* Gid: ID '(' ParamList ')'  */
#line 56 "task.y"
                            {GInstall((yyvsp[-3].name),currtype,-1,(yyvsp[-1].par));}
#line 1480 "y.tab.c"
    break;

  case 17: /* ParamList: ParamList ',' Param  */
#line 59 "task.y"
                                {PInstall((yyvsp[-2].par),(yyvsp[0].par));
								 (yyval.par) =(yyvsp[-2].par);}
#line 1487 "y.tab.c"
    break;

  case 18: /* ParamList: Param  */
#line 61 "task.y"
                        {(yyval.par) =(yyvsp[0].par);}
#line 1493 "y.tab.c"
    break;

  case 19: /* ParamList: %empty  */
#line 62 "task.y"
                      {(yyval.par)=NULL;}
#line 1499 "y.tab.c"
    break;

  case 20: /* Param: Type ID  */
#line 64 "task.y"
                {(yyval.par) = create_par((yyvsp[0].name),currtype);}
#line 1505 "y.tab.c"
    break;

  case 35: /* Slist: Slist Stmt  */
#line 105 "task.y"
                                {}
#line 1511 "y.tab.c"
    break;

  case 36: /* Slist: Stmt  */
#line 106 "task.y"
                                {}
#line 1517 "y.tab.c"
    break;

  case 37: /* Stmt: READ '(' IDEN ')' ';'  */
#line 108 "task.y"
                                {}
#line 1523 "y.tab.c"
    break;

  case 38: /* Stmt: WRITE '(' expr ')' ';'  */
#line 109 "task.y"
                                {}
#line 1529 "y.tab.c"
    break;

  case 39: /* Stmt: IDEN '=' expr ';'  */
#line 110 "task.y"
                        {}
#line 1535 "y.tab.c"
    break;

  case 42: /* Stmt: BREAK ';'  */
#line 113 "task.y"
                  {}
#line 1541 "y.tab.c"
    break;

  case 43: /* Stmt: CONTINUE ';'  */
#line 114 "task.y"
                    {}
#line 1547 "y.tab.c"
    break;

  case 44: /* Ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 117 "task.y"
                                                      {}
#line 1553 "y.tab.c"
    break;

  case 45: /* Ifstmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 118 "task.y"
                                            {}
#line 1559 "y.tab.c"
    break;

  case 46: /* Whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 121 "task.y"
                                                  {}
#line 1565 "y.tab.c"
    break;

  case 47: /* expr: expr PLUS expr  */
#line 123 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"+",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1571 "y.tab.c"
    break;

  case 48: /* expr: expr MINUS expr  */
#line 124 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"-",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1577 "y.tab.c"
    break;

  case 49: /* expr: expr MUL expr  */
#line 125 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"*",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1583 "y.tab.c"
    break;

  case 50: /* expr: expr DIV expr  */
#line 126 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"/",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1589 "y.tab.c"
    break;

  case 51: /* expr: expr MOD expr  */
#line 127 "task.y"
                        {(yyval.no) = create_tree(0,inttype,"%",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1595 "y.tab.c"
    break;

  case 52: /* expr: expr GT expr  */
#line 128 "task.y"
                      {(yyval.no)=create_tree(0,booltype,"<",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1601 "y.tab.c"
    break;

  case 53: /* expr: expr LT expr  */
#line 129 "task.y"
                      {(yyval.no) =create_tree(0,booltype,">",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1607 "y.tab.c"
    break;

  case 54: /* expr: expr LE expr  */
#line 130 "task.y"
                      {(yyval.no) =create_tree(0,booltype,">=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1613 "y.tab.c"
    break;

  case 55: /* expr: expr GE expr  */
#line 131 "task.y"
                      {(yyval.no) =create_tree(0,booltype,"<=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1619 "y.tab.c"
    break;

  case 56: /* expr: expr EQ expr  */
#line 132 "task.y"
                      {(yyval.no) =create_tree(0,booltype,"==",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1625 "y.tab.c"
    break;

  case 57: /* expr: expr NE expr  */
#line 133 "task.y"
                      {(yyval.no) =create_tree(0,booltype,"!=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1631 "y.tab.c"
    break;

  case 58: /* expr: expr ANDTKN expr  */
#line 134 "task.y"
                          {(yyval.no) =create_tree(0,booltype,"&&",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1637 "y.tab.c"
    break;

  case 59: /* expr: expr ORTKN expr  */
#line 135 "task.y"
                         {(yyval.no) =create_tree(0,booltype,"||",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1643 "y.tab.c"
    break;

  case 60: /* expr: NOTTKN expr  */
#line 136 "task.y"
                     {(yyval.no) =create_tree(0,booltype,"!",relop_node,(yyvsp[0].no),NULL,NULL);}
#line 1649 "y.tab.c"
    break;

  case 61: /* expr: '(' expr ')'  */
#line 137 "task.y"
                                {(yyval.no)=(yyvsp[-1].no);}
#line 1655 "y.tab.c"
    break;

  case 62: /* expr: IDEN  */
#line 138 "task.y"
                                {(yyval.no)=(yyvsp[0].no);}
#line 1661 "y.tab.c"
    break;

  case 63: /* expr: NUM  */
#line 139 "task.y"
                                {(yyval.no)=create_tree((yyvsp[0].numb),inttype,NULL,iconst_node,NULL,NULL,NULL);}
#line 1667 "y.tab.c"
    break;

  case 64: /* expr: MESG  */
#line 140 "task.y"
                                {(yyval.no)=create_tree(0,strtype,(yyvsp[0].name),sconst_node,NULL,NULL,NULL);}
#line 1673 "y.tab.c"
    break;

  case 65: /* expr: ID '(' ')'  */
#line 141 "task.y"
                   {}
#line 1679 "y.tab.c"
    break;

  case 66: /* expr: ID '(' ArgList ')'  */
#line 142 "task.y"
                      {}
#line 1685 "y.tab.c"
    break;

  case 67: /* ArgList: ArgList ',' expr  */
#line 146 "task.y"
                           {}
#line 1691 "y.tab.c"
    break;

  case 68: /* ArgList: expr  */
#line 147 "task.y"
               {}
#line 1697 "y.tab.c"
    break;

  case 69: /* IDEN: ID  */
#line 148 "task.y"
          {}
#line 1703 "y.tab.c"
    break;

  case 70: /* IDEN: ID '[' expr ']'  */
#line 150 "task.y"
                              {}
#line 1709 "y.tab.c"
    break;


#line 1713 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 153 "task.y"

int yyerror(char const *s)
{
	printf("yyerror %s",s);
}		
int main()
{
	//wrap_no=0;
	yyin=fopen("inp.txt","r");
	yyparse();
	return 0;
}
