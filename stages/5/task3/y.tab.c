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
	FILE *fp=NULL;
	extern FILE *yyin;
	int currtype;


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
#line 19 "task.y"

	struct tnode *no;
	struct param *par;
	int numb;
	char *name;

#line 224 "y.tab.c"

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
  YYSYMBOL_GidList = 53,                   /* GidList  */
  YYSYMBOL_Gid = 54,                       /* Gid  */
  YYSYMBOL_FdefBlock = 55,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 56,                      /* Fdef  */
  YYSYMBOL_Ftype_param = 57,               /* Ftype_param  */
  YYSYMBOL_ParamList = 58,                 /* ParamList  */
  YYSYMBOL_Ptype = 59,                     /* Ptype  */
  YYSYMBOL_Param = 60,                     /* Param  */
  YYSYMBOL_LdeclBlock = 61,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 62,                  /* LDecList  */
  YYSYMBOL_LDecl = 63,                     /* LDecl  */
  YYSYMBOL_IdList = 64,                    /* IdList  */
  YYSYMBOL_Type = 65,                      /* Type  */
  YYSYMBOL_MainBlock = 66,                 /* MainBlock  */
  YYSYMBOL_Body = 67,                      /* Body  */
  YYSYMBOL_Rstmt = 68,                     /* Rstmt  */
  YYSYMBOL_Slist = 69,                     /* Slist  */
  YYSYMBOL_Stmt = 70,                      /* Stmt  */
  YYSYMBOL_Ifstmt = 71,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 72,                 /* Whilestmt  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_IDEN = 74,                      /* IDEN  */
  YYSYMBOL_ArgList = 75                    /* ArgList  */
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
#define YYLAST   330

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

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
       0,    38,    38,    39,    40,    44,    53,    55,    55,    56,
      57,    59,    61,    62,    63,    68,    68,    70,    89,   102,
     113,   115,   116,   118,   119,   121,   132,   132,   134,   134,
     136,   138,   139,   143,   145,   156,   174,   190,   196,   205,
     206,   208,   209,   210,   211,   212,   213,   214,   217,   218,
     221,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   246,   248,   251,   252
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
  "GdeclBlock", "GdeclList", "GDecl", "GidList", "Gid", "FdefBlock",
  "Fdef", "Ftype_param", "ParamList", "Ptype", "Param", "LdeclBlock",
  "LDecList", "LDecl", "IdList", "Type", "MainBlock", "Body", "Rstmt",
  "Slist", "Stmt", "Ifstmt", "Whilestmt", "expr", "IDEN", "ArgList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-137)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,  -137,  -137,     5,    24,    11,   -23,  -137,  -137,   172,
    -137,    32,  -137,    11,  -137,   -11,    -4,  -137,     0,  -137,
    -137,    31,    47,  -137,  -137,  -137,   -10,    37,    50,   100,
      74,  -137,    32,   298,   237,    85,    75,    74,    73,    83,
    -137,  -137,   -22,    95,  -137,  -137,    91,    92,    93,    98,
      89,   103,    76,   236,  -137,  -137,  -137,   102,  -137,   255,
    -137,   124,   117,  -137,   -19,   -10,  -137,    74,  -137,  -137,
     134,    28,    28,    28,  -137,  -137,    28,    28,   141,  -137,
      28,  -137,  -137,  -137,    72,  -137,  -137,    85,   121,  -137,
     132,  -137,  -137,    38,    28,    28,    71,  -137,    78,   126,
     168,   213,  -137,   219,  -137,   146,   138,  -137,   140,    26,
     153,   133,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,   162,   181,   190,  -137,  -137,
    -137,  -137,  -137,  -137,  -137,   176,   163,  -137,    35,    35,
    -137,  -137,   153,   153,   153,   153,   153,   153,   153,   153,
    -137,  -137,   298,   298,    28,  -137,   262,   270,  -137,   298,
     169,   170,   290,  -137,  -137,   174,  -137
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    33,    34,     0,     0,     0,     0,     4,     6,     0,
       8,     0,     1,     0,    16,     0,     0,     3,     0,     5,
       7,    12,     0,    11,    15,     2,     0,     0,     0,     0,
      22,     9,     0,     0,     0,     0,     0,    22,     0,     0,
      23,    24,     0,     0,    21,    10,     0,     0,     0,     0,
       0,     0,    71,     0,    40,    44,    45,     0,    27,     0,
      29,     0,     0,    18,     0,     0,    13,     0,    14,    25,
       0,     0,     0,     0,    47,    46,     0,     0,     0,    39,
       0,    26,    28,    32,     0,    17,    19,     0,     0,    20,
       0,    67,    68,    71,     0,     0,     0,    66,     0,     0,
       0,     0,    37,     0,    30,     0,     0,    36,     0,     0,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    38,
      43,    31,    35,    41,    69,    74,     0,    65,    51,    52,
      53,    54,    56,    57,    58,    59,    60,    61,    62,    63,
      55,    42,     0,     0,     0,    70,     0,     0,    73,     0,
       0,     0,     0,    49,    50,     0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,  -137,  -137,   206,  -137,   189,  -137,   209,  -137,
     191,  -137,   160,   164,  -137,   183,  -137,     2,     1,   -25,
    -137,  -136,   -52,  -137,  -137,   -68,   -33,    99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     9,    10,    22,    23,    13,    14,    15,
      42,    43,    44,    35,    59,    60,    84,    11,     7,    36,
      78,    53,    54,    55,    56,   135,    97,   136
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    79,     6,    96,    98,    99,    17,    16,   100,   101,
      62,    18,   103,    33,    25,    16,   156,   157,    67,    34,
      57,    67,    68,   162,    12,    86,   110,   111,    27,    91,
      18,    91,     1,     2,    26,     8,    61,    90,     1,     2,
      88,   114,   115,    28,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    92,    93,    92,
      93,    61,   106,    94,    21,    94,     1,     2,     3,    95,
     134,    95,    29,   124,    30,   112,   113,   114,   115,    76,
      37,   109,   112,   113,   114,   115,    31,    32,   116,   117,
     118,   119,   120,   121,    38,   116,   117,   118,   119,   120,
     121,    40,    41,    39,    79,    79,   122,   123,    33,   124,
      79,   104,   105,   122,   123,   125,   124,    76,    65,    57,
      57,    63,   126,    57,    57,    66,    57,    69,    74,    57,
     112,   113,   114,   115,    70,    71,    72,   112,   113,   114,
     115,    73,    75,   116,   117,   118,   119,   120,   121,    80,
     116,   117,   118,   119,   120,   121,    83,   112,   113,   114,
     115,   122,   123,    85,   124,   102,    52,   107,   122,   123,
     127,   124,   112,   113,   114,   115,   108,   137,   131,   133,
     112,   113,   114,   115,   132,   116,   117,   118,   119,   120,
     121,   124,   152,   116,   117,   118,   119,   120,   121,     1,
       2,   151,    19,   122,   123,   153,   124,   155,   163,   164,
     128,   122,   123,   166,   124,    20,   154,   112,   113,   114,
     115,    45,    24,   112,   113,   114,   115,    89,    64,    87,
     116,   117,   118,   119,   120,   121,   116,   117,   118,   119,
     120,   121,    82,     0,    46,    47,    48,     0,   122,   123,
      49,   124,   129,   158,   122,   123,     0,   124,   130,     0,
       0,    50,    51,     0,     1,     2,     0,    58,    52,    77,
      46,    47,    48,     0,   159,   160,    49,     0,    46,    47,
      48,     0,     1,     2,    49,    81,   161,    50,    51,     0,
       0,     0,     0,     0,    52,    50,    51,     0,    46,    47,
      48,     0,    52,   165,    49,     0,    46,    47,    48,     0,
       0,     0,    49,     0,     0,    50,    51,     0,     0,     0,
       0,     0,    52,    50,    51,     0,     0,     0,     0,     0,
      52
};

static const yytype_int16 yycheck[] =
{
      33,    53,     0,    71,    72,    73,     5,     5,    76,    77,
      35,    34,    80,    23,    13,    13,   152,   153,    40,    29,
      53,    40,    44,   159,     0,    44,    94,    95,    32,     3,
      34,     3,    27,    28,    45,    30,    34,    70,    27,    28,
      65,     6,     7,    43,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    31,    32,    31,
      32,    59,    87,    37,    32,    37,    27,    28,    29,    43,
      44,    43,    41,    38,    43,     4,     5,     6,     7,    41,
      43,    43,     4,     5,     6,     7,    39,    40,    17,    18,
      19,    20,    21,    22,    44,    17,    18,    19,    20,    21,
      22,    27,    28,     3,   156,   157,    35,    36,    23,    38,
     162,    39,    40,    35,    36,    44,    38,    41,    45,   152,
     153,    46,    44,   156,   157,    42,   159,    32,    39,   162,
       4,     5,     6,     7,    43,    43,    43,     4,     5,     6,
       7,    43,    39,    17,    18,    19,    20,    21,    22,    47,
      17,    18,    19,    20,    21,    22,    32,     4,     5,     6,
       7,    35,    36,    46,    38,    24,    32,    46,    35,    36,
      44,    38,     4,     5,     6,     7,    44,    44,    32,    39,
       4,     5,     6,     7,    46,    17,    18,    19,    20,    21,
      22,    38,    11,    17,    18,    19,    20,    21,    22,    27,
      28,    39,    30,    35,    36,    15,    38,    44,    39,    39,
      42,    35,    36,    39,    38,     9,    40,     4,     5,     6,
       7,    32,    13,     4,     5,     6,     7,    67,    37,    65,
      17,    18,    19,    20,    21,    22,    17,    18,    19,    20,
      21,    22,    59,    -1,     8,     9,    10,    -1,    35,    36,
      14,    38,    39,   154,    35,    36,    -1,    38,    39,    -1,
      -1,    25,    26,    -1,    27,    28,    -1,    30,    32,    33,
       8,     9,    10,    -1,    12,    13,    14,    -1,     8,     9,
      10,    -1,    27,    28,    14,    30,    16,    25,    26,    -1,
      -1,    -1,    -1,    -1,    32,    25,    26,    -1,     8,     9,
      10,    -1,    32,    13,    14,    -1,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32,    25,    26,    -1,    -1,    -1,    -1,    -1,
      32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,    29,    49,    50,    65,    66,    30,    51,
      52,    65,     0,    55,    56,    57,    65,    66,    34,    30,
      52,    32,    53,    54,    56,    66,    45,    32,    43,    41,
      43,    39,    40,    23,    29,    61,    67,    43,    44,     3,
      27,    28,    58,    59,    60,    54,     8,     9,    10,    14,
      25,    26,    32,    69,    70,    71,    72,    74,    30,    62,
      63,    65,    67,    46,    58,    45,    42,    40,    44,    32,
      43,    43,    43,    43,    39,    39,    41,    33,    68,    70,
      47,    30,    63,    32,    64,    46,    44,    61,    67,    60,
      74,     3,    31,    32,    37,    43,    73,    74,    73,    73,
      73,    73,    24,    73,    39,    40,    67,    46,    44,    43,
      73,    73,     4,     5,     6,     7,    17,    18,    19,    20,
      21,    22,    35,    36,    38,    44,    44,    44,    42,    39,
      39,    32,    46,    39,    44,    73,    75,    44,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    39,    11,    15,    40,    44,    69,    69,    75,    12,
      13,    16,    69,    39,    39,    13,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    49,    50,    50,    51,    51,    52,
      53,    53,    54,    54,    54,    55,    55,    56,    56,    57,
      58,    58,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     4,     2,     1,     5,     4,     5,
       3,     1,     0,     1,     1,     2,     3,     2,     2,     1,
       3,     3,     1,     1,     1,     8,     7,     4,     3,     2,
       1,     5,     5,     4,     1,     1,     2,     2,    10,     8,
       8,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     3,
       4,     1,     4,     3,     1
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
  case 2: /* Program: GdeclBlock FdefBlock MainBlock  */
#line 38 "task.y"
                                        {}
#line 1415 "y.tab.c"
    break;

  case 3: /* Program: GdeclBlock MainBlock  */
#line 39 "task.y"
                                                {}
#line 1421 "y.tab.c"
    break;

  case 4: /* Program: MainBlock  */
#line 40 "task.y"
                                                {}
#line 1427 "y.tab.c"
    break;

  case 5: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 44 "task.y"
                                    {
	print_symbol_table();
	headergen();
	fp=fopen("task.xsm","a");
	fprintf(fp,"PUSH R0\n");//Space for return value
	fprintf(fp,"CALL F0\n");
	fclose(fp);
	i = sys_call("Exit",0,0);
	}
#line 1441 "y.tab.c"
    break;

  case 6: /* GdeclBlock: DECL ENDDECL  */
#line 53 "task.y"
                {}
#line 1447 "y.tab.c"
    break;

  case 7: /* GdeclList: GdeclList GDecl  */
#line 55 "task.y"
                            {}
#line 1453 "y.tab.c"
    break;

  case 8: /* GdeclList: GDecl  */
#line 55 "task.y"
                                      {}
#line 1459 "y.tab.c"
    break;

  case 9: /* GDecl: Type GidList ';'  */
#line 56 "task.y"
                         {}
#line 1465 "y.tab.c"
    break;

  case 10: /* GidList: GidList ',' Gid  */
#line 57 "task.y"
                          {}
#line 1471 "y.tab.c"
    break;

  case 11: /* GidList: Gid  */
#line 59 "task.y"
                    {}
#line 1477 "y.tab.c"
    break;

  case 12: /* Gid: ID  */
#line 61 "task.y"
         {GInstall((yyvsp[0].name),currtype,1,NULL);}
#line 1483 "y.tab.c"
    break;

  case 13: /* Gid: ID '[' NUM ']'  */
#line 62 "task.y"
                      {GInstall((yyvsp[-3].name),currtype,(yyvsp[-1].numb),NULL);}
#line 1489 "y.tab.c"
    break;

  case 14: /* Gid: ID '(' ParamList ')'  */
#line 63 "task.y"
                            {GInstall((yyvsp[-3].name),currtype,-1,(yyvsp[-1].par));}
#line 1495 "y.tab.c"
    break;

  case 17: /* Fdef: Ftype_param '{' LdeclBlock Body '}'  */
#line 71 "task.y"
                {
			//codegen
			(yyval.no)= (yyvsp[-1].no);
			print_lcl_tab();
			printf("Abstract syntax tree created succesfully\n");
			
			//inorder($$);
			printf("tree printed done\n");
			func_starter((yyvsp[-4].name));
			
			i=codegen((yyval.no));
			//codegen
			printf("codegenerated for func\n");
			deletetree((yyval.no));
			printf("tree deleted\n");
			free_lcl_tab();
		}
#line 1517 "y.tab.c"
    break;

  case 18: /* Fdef: Ftype_param '{' Body '}'  */
#line 90 "task.y"
                {
			(yyval.no)=(yyvsp[-1].no);
			printf("Abstract syntax tree created succesfully\n");
			//inorder($$);
			printf("tree printed\n");
			func_starter((yyvsp[-3].name));
			i=codegen((yyval.no));
			//codegen
			deletetree((yyval.no));
			free_lcl_tab();
		}
#line 1533 "y.tab.c"
    break;

  case 19: /* Ftype_param: Type ID '(' ParamList ')'  */
#line 103 "task.y"
        {
		check_name_equi((yyvsp[-4].numb),(yyvsp[-3].name),(yyvsp[-1].par));
		alocate_param((yyvsp[-1].par));
		//printf("ftype_param_done\n");
		(yyval.name) =(yyvsp[-3].name);
	}
#line 1544 "y.tab.c"
    break;

  case 20: /* ParamList: ParamList ',' Param  */
#line 113 "task.y"
                                {PInstall((yyvsp[-2].par),(yyvsp[0].par));
								 (yyval.par) =(yyvsp[-2].par);}
#line 1551 "y.tab.c"
    break;

  case 21: /* ParamList: Param  */
#line 115 "task.y"
                        {(yyval.par) =(yyvsp[0].par);}
#line 1557 "y.tab.c"
    break;

  case 22: /* ParamList: %empty  */
#line 116 "task.y"
                      {(yyval.par)=NULL;}
#line 1563 "y.tab.c"
    break;

  case 23: /* Ptype: INT  */
#line 118 "task.y"
                        {(yyval.numb)=inttype; }
#line 1569 "y.tab.c"
    break;

  case 24: /* Ptype: STR  */
#line 119 "task.y"
                                {(yyval.numb)=strtype; }
#line 1575 "y.tab.c"
    break;

  case 25: /* Param: Ptype ID  */
#line 121 "task.y"
                 {(yyval.par) = create_par((yyvsp[0].name),(yyvsp[-1].numb));

printf("param\n");}
#line 1583 "y.tab.c"
    break;

  case 26: /* LdeclBlock: DECL LDecList ENDDECL  */
#line 132 "task.y"
                                   {printf("lcldecl block done\n");}
#line 1589 "y.tab.c"
    break;

  case 27: /* LdeclBlock: DECL ENDDECL  */
#line 132 "task.y"
                                                                                    {}
#line 1595 "y.tab.c"
    break;

  case 28: /* LDecList: LDecList LDecl  */
#line 134 "task.y"
                          {}
#line 1601 "y.tab.c"
    break;

  case 29: /* LDecList: LDecl  */
#line 134 "task.y"
                                    {}
#line 1607 "y.tab.c"
    break;

  case 30: /* LDecl: Type IdList ';'  */
#line 136 "task.y"
                        {}
#line 1613 "y.tab.c"
    break;

  case 31: /* IdList: IdList ',' ID  */
#line 138 "task.y"
                      {LInstall((yyvsp[0].name),currtype);}
#line 1619 "y.tab.c"
    break;

  case 32: /* IdList: ID  */
#line 139 "task.y"
                     {LInstall((yyvsp[0].name),currtype);}
#line 1625 "y.tab.c"
    break;

  case 33: /* Type: INT  */
#line 143 "task.y"
                                                {currtype=inttype;
								(yyval.numb) =inttype;}
#line 1632 "y.tab.c"
    break;

  case 34: /* Type: STR  */
#line 145 "task.y"
                                                {currtype=strtype;
							 (yyval.numb) =strtype;
							//print_symbol_table();
							}
#line 1641 "y.tab.c"
    break;

  case 35: /* MainBlock: Type MAINFN '(' ')' '{' LdeclBlock Body '}'  */
#line 157 "task.y"
        {		
			(yyval.no)=(yyvsp[-1].no);
			print_lcl_tab();
			printf("Abstract syntax tree created succesfully\n");
			
			//inorder($$);
			printf("tree printed\n");
			//codegen
			main_starter();
			
			
			i=codegen((yyval.no));
			printf("xsm file generated\n");
			///
			deletetree((yyval.no));
			free_lcl_tab();
	}
#line 1663 "y.tab.c"
    break;

  case 36: /* MainBlock: Type MAINFN '(' ')' '{' Body '}'  */
#line 174 "task.y"
                                                        {
			(yyval.no)=(yyvsp[-1].no);
			printf("Abstract syntax tree created succesfully\n");
			//inorder($$);
			printf("tree printed\n");
			//codegen

			main_starter();
			i=codegen((yyval.no));
			printf("xsm file generated\n");
			///
			deletetree((yyval.no));
			free_lcl_tab();
	}
#line 1682 "y.tab.c"
    break;

  case 37: /* Body: PBEGIN Slist Rstmt PEND  */
#line 191 "task.y"
        {
		(yyval.no)=create_tree(0,0,NULL,conn_node,(yyvsp[-2].no),(yyvsp[-1].no),NULL);
	}
#line 1690 "y.tab.c"
    break;

  case 38: /* Rstmt: RETURN expr ';'  */
#line 196 "task.y"
                        {
				(yyval.no) =create_tree(0,0,NULL,ret_node,(yyvsp[-1].no),NULL,NULL);}
#line 1697 "y.tab.c"
    break;

  case 39: /* Slist: Slist Stmt  */
#line 205 "task.y"
                                {(yyval.no)=create_tree(0,0,NULL,conn_node,(yyvsp[-1].no),(yyvsp[0].no),NULL);}
#line 1703 "y.tab.c"
    break;

  case 40: /* Slist: Stmt  */
#line 206 "task.y"
                                {(yyval.no) =(yyvsp[0].no);}
#line 1709 "y.tab.c"
    break;

  case 41: /* Stmt: READ '(' IDEN ')' ';'  */
#line 208 "task.y"
                                {(yyval.no)=create_tree(0,0,NULL,read_node,(yyvsp[-2].no),NULL,NULL);}
#line 1715 "y.tab.c"
    break;

  case 42: /* Stmt: WRITE '(' expr ')' ';'  */
#line 209 "task.y"
                                {(yyval.no)=create_tree(0,0,NULL,write_node,(yyvsp[-2].no),NULL,NULL);}
#line 1721 "y.tab.c"
    break;

  case 43: /* Stmt: IDEN '=' expr ';'  */
#line 210 "task.y"
                        {(yyval.no)=create_tree(0,0,"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 1727 "y.tab.c"
    break;

  case 44: /* Stmt: Ifstmt  */
#line 211 "task.y"
                {(yyval.no)=(yyvsp[0].no);}
#line 1733 "y.tab.c"
    break;

  case 45: /* Stmt: Whilestmt  */
#line 212 "task.y"
                   {(yyval.no)=(yyvsp[0].no);}
#line 1739 "y.tab.c"
    break;

  case 46: /* Stmt: BREAK ';'  */
#line 213 "task.y"
                  {(yyval.no)=create_tree(0,0,NULL,break_node,NULL,NULL,NULL);}
#line 1745 "y.tab.c"
    break;

  case 47: /* Stmt: CONTINUE ';'  */
#line 214 "task.y"
                    {(yyval.no)=create_tree(0,0,NULL,continue_node,NULL,NULL,NULL);}
#line 1751 "y.tab.c"
    break;

  case 48: /* Ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 217 "task.y"
                                                      {(yyval.no)=create_tree(0,0,NULL,if_node,(yyvsp[-7].no),(yyvsp[-2].no),(yyvsp[-4].no));}
#line 1757 "y.tab.c"
    break;

  case 49: /* Ifstmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 218 "task.y"
                                            {(yyval.no)=create_tree(0,0,NULL,if_node,(yyvsp[-5].no),NULL,(yyvsp[-2].no));}
#line 1763 "y.tab.c"
    break;

  case 50: /* Whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 221 "task.y"
                                                  {(yyval.no)= create_tree(0,0,NULL,while_node,(yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 1769 "y.tab.c"
    break;

  case 51: /* expr: expr PLUS expr  */
#line 224 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"+",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1775 "y.tab.c"
    break;

  case 52: /* expr: expr MINUS expr  */
#line 225 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"-",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1781 "y.tab.c"
    break;

  case 53: /* expr: expr MUL expr  */
#line 226 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"*",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1787 "y.tab.c"
    break;

  case 54: /* expr: expr DIV expr  */
#line 227 "task.y"
                                {(yyval.no)=create_tree(0,inttype,"/",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1793 "y.tab.c"
    break;

  case 55: /* expr: expr MOD expr  */
#line 228 "task.y"
                        {(yyval.no) = create_tree(0,inttype,"%",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1799 "y.tab.c"
    break;

  case 56: /* expr: expr GT expr  */
#line 229 "task.y"
                      {(yyval.no)=create_tree(0,booltype,">",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1805 "y.tab.c"
    break;

  case 57: /* expr: expr LT expr  */
#line 230 "task.y"
                      {(yyval.no) =create_tree(0,booltype,"<",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1811 "y.tab.c"
    break;

  case 58: /* expr: expr GE expr  */
#line 231 "task.y"
                      {(yyval.no) =create_tree(0,booltype,">=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1817 "y.tab.c"
    break;

  case 59: /* expr: expr LE expr  */
#line 232 "task.y"
                      {(yyval.no) =create_tree(0,booltype,"<=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1823 "y.tab.c"
    break;

  case 60: /* expr: expr EQ expr  */
#line 233 "task.y"
                      {	(yyval.no) =create_tree(0,booltype,"==",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1829 "y.tab.c"
    break;

  case 61: /* expr: expr NE expr  */
#line 234 "task.y"
                      {(yyval.no) =create_tree(0,booltype,"!=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1835 "y.tab.c"
    break;

  case 62: /* expr: expr ANDTKN expr  */
#line 235 "task.y"
                          {(yyval.no) =create_tree(0,booltype,"&&",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1841 "y.tab.c"
    break;

  case 63: /* expr: expr ORTKN expr  */
#line 236 "task.y"
                         {(yyval.no) =create_tree(0,booltype,"||",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 1847 "y.tab.c"
    break;

  case 64: /* expr: NOTTKN expr  */
#line 237 "task.y"
                     {(yyval.no) =create_tree(0,booltype,"!",log_node,(yyvsp[0].no),NULL,NULL);}
#line 1853 "y.tab.c"
    break;

  case 65: /* expr: '(' expr ')'  */
#line 238 "task.y"
                                {(yyval.no)=(yyvsp[-1].no);}
#line 1859 "y.tab.c"
    break;

  case 66: /* expr: IDEN  */
#line 239 "task.y"
                                {(yyval.no)=(yyvsp[0].no);}
#line 1865 "y.tab.c"
    break;

  case 67: /* expr: NUM  */
#line 240 "task.y"
                                {(yyval.no)=create_tree((yyvsp[0].numb),inttype,NULL,iconst_node,NULL,NULL,NULL);}
#line 1871 "y.tab.c"
    break;

  case 68: /* expr: MESG  */
#line 241 "task.y"
                                {(yyval.no)=create_tree(0,strtype,(yyvsp[0].name),sconst_node,NULL,NULL,NULL);}
#line 1877 "y.tab.c"
    break;

  case 69: /* expr: ID '(' ')'  */
#line 242 "task.y"
                                {(yyval.no)=create_tree(0,notype,(yyvsp[-2].name),func_node,NULL,NULL,NULL);}
#line 1883 "y.tab.c"
    break;

  case 70: /* expr: ID '(' ArgList ')'  */
#line 243 "task.y"
                      {(yyval.no)=create_tree(0,notype,(yyvsp[-3].name),func_node,(yyvsp[-1].no),NULL,NULL);}
#line 1889 "y.tab.c"
    break;

  case 71: /* IDEN: ID  */
#line 246 "task.y"
          {(yyval.no)=create_tree(0,notype,(yyvsp[0].name),var_node,NULL,NULL,NULL);}
#line 1895 "y.tab.c"
    break;

  case 72: /* IDEN: ID '[' expr ']'  */
#line 248 "task.y"
                              {(yyval.no)=create_tree(0,notype,(yyvsp[-3].name),var_node,(yyvsp[-1].no),NULL,NULL);}
#line 1901 "y.tab.c"
    break;

  case 73: /* ArgList: expr ',' ArgList  */
#line 251 "task.y"
                           {(yyvsp[-2].no)->mid =(yyvsp[0].no);(yyval.no)=(yyvsp[-2].no);}
#line 1907 "y.tab.c"
    break;

  case 74: /* ArgList: expr  */
#line 252 "task.y"
               {(yyval.no)=(yyvsp[0].no);}
#line 1913 "y.tab.c"
    break;


#line 1917 "y.tab.c"

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

#line 254 "task.y"

int yyerror(char const *s)
{
	printf("yyerror %s",s);
}		
int main()
{
	yyin=fopen("inp.expl","r");
	yyparse();
	return 0;
}
