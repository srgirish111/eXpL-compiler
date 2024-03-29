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
	struct Typetable *currtype;
	int size=0;

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
    TYPETKN = 293,                 /* TYPETKN  */
    ENDTYPETKN = 294,              /* ENDTYPETKN  */
    INITIALIZE = 295,              /* INITIALIZE  */
    ALLOC = 296,                   /* ALLOC  */
    FREE = 297,                    /* FREE  */
    NULLTKN = 298,                 /* NULLTKN  */
    MOD = 299                      /* MOD  */
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
#define TYPETKN 293
#define ENDTYPETKN 294
#define INITIALIZE 295
#define ALLOC 296
#define FREE 297
#define NULLTKN 298
#define MOD 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "task.y"

	struct tnode *no;
	struct param *par;
	struct Fieldlist *field;
	struct Typetable *typ;
	int numb;
	char *name;

#line 238 "y.tab.c"

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
  YYSYMBOL_TYPETKN = 38,                   /* TYPETKN  */
  YYSYMBOL_ENDTYPETKN = 39,                /* ENDTYPETKN  */
  YYSYMBOL_INITIALIZE = 40,                /* INITIALIZE  */
  YYSYMBOL_ALLOC = 41,                     /* ALLOC  */
  YYSYMBOL_FREE = 42,                      /* FREE  */
  YYSYMBOL_NULLTKN = 43,                   /* NULLTKN  */
  YYSYMBOL_MOD = 44,                       /* MOD  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ']'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_54_ = 54,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_Program = 56,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 57,              /* TypeDefBlock  */
  YYSYMBOL_TYPE_TKN = 58,                  /* TYPE_TKN  */
  YYSYMBOL_TypeDefList = 59,               /* TypeDefList  */
  YYSYMBOL_Type_name = 60,                 /* Type_name  */
  YYSYMBOL_TypeDef = 61,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 62,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 63,                 /* FieldDecl  */
  YYSYMBOL_TypeName = 64,                  /* TypeName  */
  YYSYMBOL_GdeclBlock = 65,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 66,                 /* GdeclList  */
  YYSYMBOL_GDecl = 67,                     /* GDecl  */
  YYSYMBOL_GidList = 68,                   /* GidList  */
  YYSYMBOL_Gid = 69,                       /* Gid  */
  YYSYMBOL_FdefBlock = 70,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 71,                      /* Fdef  */
  YYSYMBOL_Ftype_param = 72,               /* Ftype_param  */
  YYSYMBOL_ParamList = 73,                 /* ParamList  */
  YYSYMBOL_Param = 74,                     /* Param  */
  YYSYMBOL_Ptype = 75,                     /* Ptype  */
  YYSYMBOL_LdeclBlock = 76,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 77,                  /* LDecList  */
  YYSYMBOL_LDecl = 78,                     /* LDecl  */
  YYSYMBOL_IdList = 79,                    /* IdList  */
  YYSYMBOL_Type = 80,                      /* Type  */
  YYSYMBOL_MainBlock = 81,                 /* MainBlock  */
  YYSYMBOL_Body = 82,                      /* Body  */
  YYSYMBOL_Rstmt = 83,                     /* Rstmt  */
  YYSYMBOL_Slist = 84,                     /* Slist  */
  YYSYMBOL_Stmt = 85,                      /* Stmt  */
  YYSYMBOL_Assign_stmt = 86,               /* Assign_stmt  */
  YYSYMBOL_Inp_stmt = 87,                  /* Inp_stmt  */
  YYSYMBOL_out_stmt = 88,                  /* out_stmt  */
  YYSYMBOL_Heapstuff = 89,                 /* Heapstuff  */
  YYSYMBOL_FIELD = 90,                     /* FIELD  */
  YYSYMBOL_Ifstmt = 91,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 92,                 /* Whilestmt  */
  YYSYMBOL_expr = 93,                      /* expr  */
  YYSYMBOL_ArgList = 94,                   /* ArgList  */
  YYSYMBOL_IDEN = 95                       /* IDEN  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   456

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      51,    52,     2,     2,    48,     2,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    43,    44,    48,    49,    51,    53,    54,
      56,    57,    65,    67,    70,    76,    77,    78,    82,    91,
      93,    93,    94,    95,    97,    99,   100,   101,   105,   105,
     107,   127,   141,   152,   154,   155,   158,   161,   162,   163,
     172,   172,   174,   174,   176,   178,   179,   183,   185,   189,
     207,   225,   241,   247,   253,   254,   256,   257,   258,   259,
     260,   261,   262,   264,   267,   268,   269,   271,   273,   276,
     277,   282,   307,   328,   329,   332,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   358,   359,
     361,   363
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
  "RETURN", "MAINFN", "ANDTKN", "ORTKN", "NOTTKN", "TYPETKN", "ENDTYPETKN",
  "INITIALIZE", "ALLOC", "FREE", "NULLTKN", "MOD", "'{'", "'}'", "';'",
  "','", "'['", "']'", "'('", "')'", "'='", "'.'", "$accept", "Program",
  "TypeDefBlock", "TYPE_TKN", "TypeDefList", "Type_name", "TypeDef",
  "FieldDeclList", "FieldDecl", "TypeName", "GdeclBlock", "GdeclList",
  "GDecl", "GidList", "Gid", "FdefBlock", "Fdef", "Ftype_param",
  "ParamList", "Param", "Ptype", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "Type", "MainBlock", "Body", "Rstmt", "Slist", "Stmt",
  "Assign_stmt", "Inp_stmt", "out_stmt", "Heapstuff", "FIELD", "Ifstmt",
  "Whilestmt", "expr", "ArgList", "IDEN", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,  -164,    19,    28,    -8,  -164,  -164,  -164,    51,  -164,
      14,    -4,  -164,  -164,   -17,    -9,  -164,  -164,   107,  -164,
      26,    14,  -164,    37,    57,  -164,    39,  -164,  -164,    86,
    -164,  -164,    78,    15,  -164,  -164,  -164,    10,    53,    60,
    -164,  -164,  -164,    82,    86,   106,   140,    94,  -164,    26,
     414,   114,   127,   110,    94,   108,  -164,  -164,   115,   113,
    -164,  -164,  -164,    63,  -164,   137,  -164,   119,   125,   147,
     148,   153,   154,   155,   156,   365,  -164,  -164,  -164,  -164,
      -5,  -164,  -164,    43,  -164,   163,  -164,   174,   162,  -164,
      97,    10,  -164,  -164,    94,  -164,  -164,   177,   191,   191,
     191,  -164,  -164,   191,   177,   191,   186,  -164,   191,   177,
     189,   177,  -164,  -164,  -164,    72,  -164,  -164,   127,   166,
    -164,   164,  -164,  -164,   126,   191,  -164,   191,   160,    81,
     170,    88,   161,   231,   165,   272,  -164,   305,  -164,   176,
     180,   168,   325,  -164,  -164,   193,   172,  -164,   192,     0,
       1,   167,   191,   191,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,   194,   222,   228,  -164,   197,
    -164,  -164,   195,   202,  -164,  -164,  -164,  -164,  -164,  -164,
     251,   207,  -164,    20,    20,  -164,  -164,     1,     1,     1,
       1,     1,     1,     1,     1,  -164,  -164,   414,   414,  -164,
    -164,  -164,   191,  -164,   345,   385,  -164,   414,   198,   199,
     405,  -164,  -164,   213,  -164
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     7,     0,     0,     0,     1,    47,    48,     0,    49,
       0,     0,     4,    10,     0,     0,     9,    19,     0,    21,
       0,     0,    29,     0,     0,     3,     0,     5,     8,     0,
      18,    20,    25,     0,    24,    28,     2,     0,     0,     0,
      15,    16,    17,     0,    13,     0,     0,    35,    22,     0,
       0,     0,     0,     0,    35,     0,    11,    12,     0,     0,
      37,    38,    39,     0,    34,     0,    23,     0,     0,     0,
       0,     0,     0,   100,     0,     0,    55,    56,    57,    58,
       0,    59,    60,     0,    41,     0,    43,     0,     0,    31,
       0,     0,    14,    26,     0,    27,    36,     0,     0,     0,
       0,    62,    61,     0,     0,     0,     0,    54,     0,     0,
       0,     0,    40,    42,    46,     0,    30,    32,     0,     0,
      33,     0,    92,    93,   100,     0,    97,     0,    96,     0,
      91,     0,     0,     0,     0,     0,    52,     0,    72,     0,
       0,     0,     0,    71,    44,     0,     0,    51,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,     0,
      53,    65,     0,     0,    66,    64,    45,    50,    67,    94,
      99,     0,    90,    76,    77,    78,    79,    81,    82,    83,
      84,    85,    86,    87,    88,    80,    68,     0,     0,    63,
      69,    70,     0,    95,     0,     0,    98,     0,     0,     0,
       0,    74,    75,     0,    73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,  -164,  -164,   247,   218,  -164,  -164,
    -164,  -164,   245,  -164,   215,  -164,   244,  -164,   220,   188,
    -164,   205,  -164,   200,  -164,    -1,     7,   -38,  -164,  -163,
     -74,  -164,  -164,  -164,  -164,   -46,  -164,  -164,   -87,    95,
     -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    14,    15,    16,    43,    44,    45,
      10,    18,    19,    33,    34,    21,    22,    23,    63,    64,
      65,    52,    85,    86,   115,    20,    12,    53,   106,    75,
      76,    77,    78,    79,   141,   128,    81,    82,   180,   181,
     130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,   107,    11,   122,    80,   152,   153,   154,   155,    24,
       1,   129,   131,   132,    88,    13,   133,    25,   135,     5,
      24,   137,    27,   142,    13,    83,   154,   155,    36,    80,
      26,   123,   124,    50,   204,   205,    29,   125,   150,    51,
     151,     6,     7,   126,   210,   164,     9,   121,   108,   109,
      87,   127,   179,   119,   134,     6,     7,     8,    32,   138,
       9,   143,    48,    49,   164,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,     6,     7,
     146,    17,    37,     9,    87,   152,   153,   154,   155,    38,
      39,    26,   152,   153,   154,   155,   110,   111,   156,   157,
     158,   159,   160,   161,    54,   156,   157,   158,   159,   160,
     161,    94,    55,    40,    41,    95,   162,   163,    42,   144,
     145,    60,    61,   162,   163,   164,    62,    46,    56,    47,
     107,   107,   164,   165,     6,     7,   107,    30,    58,     9,
     166,     6,     7,    59,    84,    94,     9,    83,    83,   117,
      50,    80,    80,    91,    83,    83,    89,    83,    80,    80,
      83,    80,    92,    93,    80,   152,   153,   154,   155,    96,
      97,   152,   153,   154,   155,   103,    98,   149,   156,   157,
     158,   159,   160,   161,   156,   157,   158,   159,   160,   161,
       6,     7,   122,   112,   122,     9,   162,   163,    99,   100,
     101,   102,   162,   163,   103,   164,   114,   104,   116,    73,
     136,   164,   147,   167,   109,   174,   148,   169,   177,   182,
     123,   124,   123,   124,   111,   176,   125,   172,   125,   139,
     140,   173,   126,   197,   126,   152,   153,   154,   155,   178,
     127,   196,   127,   198,   199,   211,   212,   200,   156,   157,
     158,   159,   160,   161,   201,   152,   153,   154,   155,   203,
     214,    28,    57,    31,    66,    35,   162,   163,   156,   157,
     158,   159,   160,   161,    90,   164,   152,   153,   154,   155,
       0,   168,   120,     0,     0,   113,   162,   163,     0,   156,
     157,   158,   159,   160,   161,   164,   118,   206,     0,   202,
       0,     0,     0,     0,     0,     0,     0,   162,   163,   152,
     153,   154,   155,     0,     0,     0,   164,     0,     0,   170,
       0,     0,   156,   157,   158,   159,   160,   161,     0,   152,
     153,   154,   155,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   156,   157,   158,   159,   160,   161,     0,   164,
       0,     0,   171,    67,    68,    69,     0,   207,   208,    70,
     162,   163,     0,     0,     0,     0,     0,     0,     0,   164,
      71,    72,   175,    67,    68,    69,     0,    73,     0,    70,
       0,     0,     0,     0,     0,     0,     0,    74,     0,     0,
      71,    72,     0,    67,    68,    69,     0,    73,   105,    70,
       0,   209,     0,     0,     0,     0,     0,    74,     0,     0,
      71,    72,     0,    67,    68,    69,     0,    73,   213,    70,
       0,     0,    67,    68,    69,     0,     0,    74,    70,     0,
      71,    72,     0,     0,     0,     0,     0,    73,     0,    71,
      72,     0,     0,     0,     0,     0,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,    74
};

static const yytype_int16 yycheck[] =
{
      50,    75,     3,     3,    50,     4,     5,     6,     7,    10,
      38,    98,    99,   100,    52,    32,   103,    10,   105,     0,
      21,   108,    39,   110,    32,    75,     6,     7,    21,    75,
      34,    31,    32,    23,   197,   198,    45,    37,   125,    29,
     127,    27,    28,    43,   207,    44,    32,    97,    53,    54,
      51,    51,    52,    91,   104,    27,    28,    29,    32,   109,
      32,   111,    47,    48,    44,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,    27,    28,
     118,    30,    45,    32,    85,     4,     5,     6,     7,    32,
      51,    34,     4,     5,     6,     7,    53,    54,    17,    18,
      19,    20,    21,    22,    51,    17,    18,    19,    20,    21,
      22,    48,    52,    27,    28,    52,    35,    36,    32,    47,
      48,    27,    28,    35,    36,    44,    32,    49,    46,    51,
     204,   205,    44,    52,    27,    28,   210,    30,    32,    32,
      52,    27,    28,     3,    30,    48,    32,   197,   198,    52,
      23,   197,   198,    45,   204,   205,    46,   207,   204,   205,
     210,   207,    47,    50,   210,     4,     5,     6,     7,    32,
      51,     4,     5,     6,     7,    49,    51,    51,    17,    18,
      19,    20,    21,    22,    17,    18,    19,    20,    21,    22,
      27,    28,     3,    30,     3,    32,    35,    36,    51,    51,
      47,    47,    35,    36,    49,    44,    32,    51,    46,    32,
      24,    44,    46,    52,    54,    47,    52,    52,    46,    52,
      31,    32,    31,    32,    54,    32,    37,    51,    37,    40,
      41,    51,    43,    11,    43,     4,     5,     6,     7,    47,
      51,    47,    51,    15,    47,    47,    47,    52,    17,    18,
      19,    20,    21,    22,    52,     4,     5,     6,     7,    52,
      47,    14,    44,    18,    49,    21,    35,    36,    17,    18,
      19,    20,    21,    22,    54,    44,     4,     5,     6,     7,
      -1,    50,    94,    -1,    -1,    85,    35,    36,    -1,    17,
      18,    19,    20,    21,    22,    44,    91,   202,    -1,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,     4,
       5,     6,     7,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    17,    18,    19,    20,    21,    22,    -1,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    17,    18,    19,    20,    21,    22,    -1,    44,
      -1,    -1,    47,     8,     9,    10,    -1,    12,    13,    14,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      25,    26,    47,     8,     9,    10,    -1,    32,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      25,    26,    -1,     8,     9,    10,    -1,    32,    33,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      25,    26,    -1,     8,     9,    10,    -1,    32,    13,    14,
      -1,    -1,     8,     9,    10,    -1,    -1,    42,    14,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    32,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    56,    57,    58,     0,    27,    28,    29,    32,
      65,    80,    81,    32,    59,    60,    61,    30,    66,    67,
      80,    70,    71,    72,    80,    81,    34,    39,    61,    45,
      30,    67,    32,    68,    69,    71,    81,    45,    32,    51,
      27,    28,    32,    62,    63,    64,    49,    51,    47,    48,
      23,    29,    76,    82,    51,    52,    46,    62,    32,     3,
      27,    28,    32,    73,    74,    75,    69,     8,     9,    10,
      14,    25,    26,    32,    42,    84,    85,    86,    87,    88,
      90,    91,    92,    95,    30,    77,    78,    80,    82,    46,
      73,    45,    47,    50,    48,    52,    32,    51,    51,    51,
      51,    47,    47,    49,    51,    33,    83,    85,    53,    54,
      53,    54,    30,    78,    32,    79,    46,    52,    76,    82,
      74,    95,     3,    31,    32,    37,    43,    51,    90,    93,
      95,    93,    93,    93,    95,    93,    24,    93,    95,    40,
      41,    89,    93,    95,    47,    48,    82,    46,    52,    51,
      93,    93,     4,     5,     6,     7,    17,    18,    19,    20,
      21,    22,    35,    36,    44,    52,    52,    52,    50,    52,
      47,    47,    51,    51,    47,    47,    32,    46,    47,    52,
      93,    94,    52,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    47,    11,    15,    47,
      52,    52,    48,    52,    84,    84,    94,    12,    13,    16,
      84,    47,    47,    13,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    56,    57,    57,    58,    59,    59,
      60,    61,    62,    62,    63,    64,    64,    64,    65,    65,
      66,    66,    67,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    73,    74,    75,    75,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    80,
      81,    81,    82,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    87,    88,    89,
      89,    90,    90,    91,    91,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     0,     1,     2,     1,
       1,     4,     2,     1,     3,     1,     1,     1,     3,     2,
       2,     1,     3,     3,     1,     1,     4,     4,     2,     1,
       5,     4,     5,     3,     1,     0,     2,     1,     1,     1,
       3,     2,     2,     1,     3,     3,     1,     1,     1,     1,
       8,     7,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     5,     4,     4,     4,     5,     5,     3,
       3,     3,     3,    10,     8,     8,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     1,     3,     4,     1,     1,     3,     1,
       1,     4
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
  case 2: /* Program: TypeDefBlock GdeclBlock FdefBlock MainBlock  */
#line 42 "task.y"
                                                     {}
#line 1505 "y.tab.c"
    break;

  case 3: /* Program: TypeDefBlock GdeclBlock MainBlock  */
#line 43 "task.y"
                                                                {}
#line 1511 "y.tab.c"
    break;

  case 4: /* Program: TypeDefBlock MainBlock  */
#line 44 "task.y"
                                                        {}
#line 1517 "y.tab.c"
    break;

  case 5: /* TypeDefBlock: TYPE_TKN TypeDefList ENDTYPETKN  */
#line 48 "task.y"
                                                {printf("typedefblck\n");}
#line 1523 "y.tab.c"
    break;

  case 7: /* TYPE_TKN: TYPETKN  */
#line 51 "task.y"
                   {TypeTableCreate();}
#line 1529 "y.tab.c"
    break;

  case 8: /* TypeDefList: TypeDefList TypeDef  */
#line 53 "task.y"
                                    {}
#line 1535 "y.tab.c"
    break;

  case 9: /* TypeDefList: TypeDef  */
#line 54 "task.y"
                        {}
#line 1541 "y.tab.c"
    break;

  case 10: /* Type_name: ID  */
#line 56 "task.y"
                {(yyval.typ) =TInstall((yyvsp[0].name),0,NULL);}
#line 1547 "y.tab.c"
    break;

  case 11: /* TypeDef: Type_name '{' FieldDeclList '}'  */
#line 57 "task.y"
                                                  { 
					(yyval.typ) = (yyvsp[-3].typ);
					(yyval.typ)->fields = (yyvsp[-1].field);
					(yyval.typ)->size = size;
					print_type((yyval.typ));
					size=0; }
#line 1558 "y.tab.c"
    break;

  case 12: /* FieldDeclList: FieldDecl FieldDeclList  */
#line 65 "task.y"
                                        {(yyvsp[-1].field)->next=(yyvsp[0].field);
					(yyval.field)=(yyvsp[-1].field);}
#line 1565 "y.tab.c"
    break;

  case 13: /* FieldDeclList: FieldDecl  */
#line 67 "task.y"
                          {(yyval.field) =(yyvsp[0].field);}
#line 1571 "y.tab.c"
    break;

  case 14: /* FieldDecl: TypeName ID ';'  */
#line 70 "task.y"
                                {
					(yyval.field) = Fcreate((yyvsp[-1].name),(yyvsp[-2].name));
					//printf("%s  %s\n",$1,$2);
					++size;
					}
#line 1581 "y.tab.c"
    break;

  case 15: /* TypeName: INT  */
#line 76 "task.y"
                   {(yyval.name)="int";}
#line 1587 "y.tab.c"
    break;

  case 16: /* TypeName: STR  */
#line 77 "task.y"
                   {(yyval.name)="str";}
#line 1593 "y.tab.c"
    break;

  case 17: /* TypeName: ID  */
#line 78 "task.y"
                  {(yyval.name)=(yyvsp[0].name);}
#line 1599 "y.tab.c"
    break;

  case 18: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 82 "task.y"
                                    {
	print_symbol_table();
	headergen();
	fp=fopen("task.xsm","a");
	fprintf(fp,"PUSH R0\n");//Space for return value
	fprintf(fp,"CALL F0\n");
	fclose(fp);
	i = sys_call("Exit",0,0);
	}
#line 1613 "y.tab.c"
    break;

  case 19: /* GdeclBlock: DECL ENDDECL  */
#line 91 "task.y"
                {}
#line 1619 "y.tab.c"
    break;

  case 20: /* GdeclList: GdeclList GDecl  */
#line 93 "task.y"
                            {}
#line 1625 "y.tab.c"
    break;

  case 21: /* GdeclList: GDecl  */
#line 93 "task.y"
                                      {}
#line 1631 "y.tab.c"
    break;

  case 22: /* GDecl: Type GidList ';'  */
#line 94 "task.y"
                         {}
#line 1637 "y.tab.c"
    break;

  case 23: /* GidList: GidList ',' Gid  */
#line 95 "task.y"
                          {}
#line 1643 "y.tab.c"
    break;

  case 24: /* GidList: Gid  */
#line 97 "task.y"
                    {}
#line 1649 "y.tab.c"
    break;

  case 25: /* Gid: ID  */
#line 99 "task.y"
         {GInstall((yyvsp[0].name),currtype,1,NULL);}
#line 1655 "y.tab.c"
    break;

  case 26: /* Gid: ID '[' NUM ']'  */
#line 100 "task.y"
                      {GInstall((yyvsp[-3].name),currtype,(yyvsp[-1].numb),NULL);}
#line 1661 "y.tab.c"
    break;

  case 27: /* Gid: ID '(' ParamList ')'  */
#line 101 "task.y"
                            {GInstall((yyvsp[-3].name),currtype,-1,(yyvsp[-1].par));}
#line 1667 "y.tab.c"
    break;

  case 30: /* Fdef: Ftype_param '{' LdeclBlock Body '}'  */
#line 108 "task.y"
                {
			//codegen
			(yyval.no)= (yyvsp[-1].no);
			print_lcl_tab();
			printf("Abstract syntax tree created succesfully\n");
			
			//inorder($$);
			//printf("tree printed done\n");
			printf("------------------------------------------\n");
			func_starter((yyvsp[-4].name));
			
			i=codegen((yyval.no));
			//codegen
			printf("codegenerated for func\n");
			deletetree((yyval.no));
			printf("tree deleted\n");
			free_lcl_tab();
		}
#line 1690 "y.tab.c"
    break;

  case 31: /* Fdef: Ftype_param '{' Body '}'  */
#line 128 "task.y"
                {
			(yyval.no)=(yyvsp[-1].no);
			printf("Abstract syntax tree created succesfully\n");
			//inorder($$);
			//printf("tree printed\n");
			printf("------------------------------------------\n");
			func_starter((yyvsp[-3].name));
			i=codegen((yyval.no));
			//codegen
			deletetree((yyval.no));
			free_lcl_tab();
		}
#line 1707 "y.tab.c"
    break;

  case 32: /* Ftype_param: Type ID '(' ParamList ')'  */
#line 142 "task.y"
        {
		check_name_equi((yyvsp[-4].typ),(yyvsp[-3].name),(yyvsp[-1].par));
		alocate_param((yyvsp[-1].par));
		printf("ftype_param_done\n");
		(yyval.name) =(yyvsp[-3].name);
	}
#line 1718 "y.tab.c"
    break;

  case 33: /* ParamList: ParamList ',' Param  */
#line 152 "task.y"
                                {PInstall((yyvsp[-2].par),(yyvsp[0].par));
								 (yyval.par) =(yyvsp[-2].par);}
#line 1725 "y.tab.c"
    break;

  case 34: /* ParamList: Param  */
#line 154 "task.y"
                        {(yyval.par) =(yyvsp[0].par);}
#line 1731 "y.tab.c"
    break;

  case 35: /* ParamList: %empty  */
#line 155 "task.y"
                      {(yyval.par)=NULL;}
#line 1737 "y.tab.c"
    break;

  case 36: /* Param: Ptype ID  */
#line 158 "task.y"
                 {(yyval.par) = create_par((yyvsp[0].name),(yyvsp[-1].typ));}
#line 1743 "y.tab.c"
    break;

  case 37: /* Ptype: INT  */
#line 161 "task.y"
                        {(yyval.typ)=TLookup("int"); }
#line 1749 "y.tab.c"
    break;

  case 38: /* Ptype: STR  */
#line 162 "task.y"
                                {(yyval.typ)=TLookup("str"); }
#line 1755 "y.tab.c"
    break;

  case 39: /* Ptype: ID  */
#line 163 "task.y"
                                {(yyval.typ)=TLookup((yyvsp[0].name)); }
#line 1761 "y.tab.c"
    break;

  case 40: /* LdeclBlock: DECL LDecList ENDDECL  */
#line 172 "task.y"
                                   {printf("lcl_block done\n");}
#line 1767 "y.tab.c"
    break;

  case 41: /* LdeclBlock: DECL ENDDECL  */
#line 172 "task.y"
                                                                                {}
#line 1773 "y.tab.c"
    break;

  case 42: /* LDecList: LDecList LDecl  */
#line 174 "task.y"
                          {}
#line 1779 "y.tab.c"
    break;

  case 43: /* LDecList: LDecl  */
#line 174 "task.y"
                                    {print_lcl_tab();}
#line 1785 "y.tab.c"
    break;

  case 44: /* LDecl: Type IdList ';'  */
#line 176 "task.y"
                        {}
#line 1791 "y.tab.c"
    break;

  case 45: /* IdList: IdList ',' ID  */
#line 178 "task.y"
                      {LInstall((yyvsp[0].name),currtype);}
#line 1797 "y.tab.c"
    break;

  case 46: /* IdList: ID  */
#line 179 "task.y"
                     {LInstall((yyvsp[0].name),currtype);}
#line 1803 "y.tab.c"
    break;

  case 47: /* Type: INT  */
#line 183 "task.y"
                                                {currtype=TLookup("int");
								(yyval.typ) =currtype;}
#line 1810 "y.tab.c"
    break;

  case 48: /* Type: STR  */
#line 185 "task.y"
                                                {currtype=TLookup("str");
							 (yyval.typ) =currtype;
						
							}
#line 1819 "y.tab.c"
    break;

  case 49: /* Type: ID  */
#line 189 "task.y"
             {
			currtype = TLookup((yyvsp[0].name));
			if(currtype==NULL)
			{
				printf("type not declared --> %s\n",(yyvsp[0].name));
				exit(1);
			}
			(yyval.typ)=currtype;
			
		
		}
#line 1835 "y.tab.c"
    break;

  case 50: /* MainBlock: Type MAINFN '(' ')' '{' LdeclBlock Body '}'  */
#line 208 "task.y"
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
#line 1857 "y.tab.c"
    break;

  case 51: /* MainBlock: Type MAINFN '(' ')' '{' Body '}'  */
#line 225 "task.y"
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
#line 1876 "y.tab.c"
    break;

  case 52: /* Body: PBEGIN Slist Rstmt PEND  */
#line 242 "task.y"
        {
		(yyval.no)=create_tree(0,TLookup("void"),NULL,conn_node,(yyvsp[-2].no),(yyvsp[-1].no),NULL);
	}
#line 1884 "y.tab.c"
    break;

  case 53: /* Rstmt: RETURN expr ';'  */
#line 247 "task.y"
                        {
				(yyval.no) =create_tree(0,TLookup("void"),NULL,ret_node,(yyvsp[-1].no),NULL,NULL);}
#line 1891 "y.tab.c"
    break;

  case 54: /* Slist: Slist Stmt  */
#line 253 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,conn_node,(yyvsp[-1].no),(yyvsp[0].no),NULL);}
#line 1897 "y.tab.c"
    break;

  case 55: /* Slist: Stmt  */
#line 254 "task.y"
                                {(yyval.no) =(yyvsp[0].no);}
#line 1903 "y.tab.c"
    break;

  case 56: /* Stmt: Assign_stmt  */
#line 256 "task.y"
                  {(yyval.no)=(yyvsp[0].no);}
#line 1909 "y.tab.c"
    break;

  case 57: /* Stmt: Inp_stmt  */
#line 257 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 1915 "y.tab.c"
    break;

  case 58: /* Stmt: out_stmt  */
#line 258 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 1921 "y.tab.c"
    break;

  case 59: /* Stmt: Ifstmt  */
#line 259 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 1927 "y.tab.c"
    break;

  case 60: /* Stmt: Whilestmt  */
#line 260 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 1933 "y.tab.c"
    break;

  case 61: /* Stmt: BREAK ';'  */
#line 261 "task.y"
                   {(yyval.no)=create_tree(0,TLookup("void"),NULL,break_node,NULL,NULL,NULL);}
#line 1939 "y.tab.c"
    break;

  case 62: /* Stmt: CONTINUE ';'  */
#line 262 "task.y"
                     {(yyval.no)=create_tree(0,TLookup("void"),NULL,continue_node,NULL,NULL,NULL);}
#line 1945 "y.tab.c"
    break;

  case 63: /* Stmt: FREE '(' IDEN ')' ';'  */
#line 264 "task.y"
                            {typecheck((yyvsp[-2].no));(yyval.no)=create_tree(0,TLookup("void"),NULL,free_node,(yyvsp[-2].no),NULL,NULL);}
#line 1951 "y.tab.c"
    break;

  case 64: /* Assign_stmt: IDEN '=' expr ';'  */
#line 267 "task.y"
                                {typecheck((yyvsp[-3].no));(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 1957 "y.tab.c"
    break;

  case 65: /* Assign_stmt: FIELD '=' expr ';'  */
#line 268 "task.y"
                          {(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 1963 "y.tab.c"
    break;

  case 66: /* Assign_stmt: IDEN '=' Heapstuff ';'  */
#line 269 "task.y"
                             {typecheck((yyvsp[-3].no));(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 1969 "y.tab.c"
    break;

  case 67: /* Inp_stmt: READ '(' IDEN ')' ';'  */
#line 271 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,read_node,(yyvsp[-2].no),NULL,NULL);}
#line 1975 "y.tab.c"
    break;

  case 68: /* out_stmt: WRITE '(' expr ')' ';'  */
#line 273 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,write_node,(yyvsp[-2].no),NULL,NULL);}
#line 1981 "y.tab.c"
    break;

  case 69: /* Heapstuff: INITIALIZE '(' ')'  */
#line 276 "task.y"
                             {(yyval.no)=create_tree(0,TLookup("int"),NULL,initia_node,NULL,NULL,NULL);printf("initialize\n");}
#line 1987 "y.tab.c"
    break;

  case 70: /* Heapstuff: ALLOC '(' ')'  */
#line 277 "task.y"
                                    {(yyval.no)=create_tree(0,TLookup("void"),NULL,alloc_node,NULL,NULL,NULL);}
#line 1993 "y.tab.c"
    break;

  case 71: /* FIELD: IDEN '.' IDEN  */
#line 282 "task.y"
                        {
				typecheck((yyvsp[-2].no));
				//printf("%s---%s\n ",$1->type->name,$3->varname);
				struct Fieldlist *f;
				if((yyvsp[-2].no)->type==TLookup("int") || (yyvsp[-2].no)->type==TLookup("str"))
				{
					printf("invalid field access\n");
							exit(1);
				}
				//printf("f1\n");
				f=FLookup((yyvsp[-2].no)->type,(yyvsp[0].no)->varname);
				//printf("f1\n");
				if(f==NULL)
				{
			      	printf("No field :%s in %s type\n",(yyvsp[0].no)->varname,(yyvsp[-2].no)->type->name);
				 	exit(1);
				}
				(yyvsp[-2].no)->nodetype=field_node;
				(yyvsp[-2].no)->mid=(yyvsp[0].no);
				(yyvsp[0].no)->type=f->type;
				(yyvsp[0].no)->val=f->fieldIndex;
				(yyvsp[-2].no)->type=(yyvsp[0].no)->type;
				(yyval.no)=(yyvsp[-2].no);	
				//printf("f1\n");
						}
#line 2023 "y.tab.c"
    break;

  case 72: /* FIELD: FIELD '.' IDEN  */
#line 307 "task.y"
                           {
				struct tnode *temp; 
				struct Fieldlist *f;
				temp=(yyvsp[-2].no);
				while(temp->mid!=NULL)
					temp=temp->mid;
				f=FLookup(temp->type,(yyvsp[0].no)->varname);
				if(f==NULL)
				{
					printf("No field :%s in %s type\n",(yyvsp[0].no)->varname,temp->type->name);
				 	exit(1);
				}
				temp->nodetype=field_node;
				temp->mid=(yyvsp[0].no);
				(yyvsp[0].no)->type=f->type;
				(yyvsp[0].no)->val=f->fieldIndex;
				(yyvsp[-2].no)->type=(yyvsp[0].no)->type;
				(yyval.no)=(yyvsp[-2].no);
		  }
#line 2047 "y.tab.c"
    break;

  case 73: /* Ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 328 "task.y"
                                                      {(yyval.no)=create_tree(0,TLookup("void"),NULL,if_node,(yyvsp[-7].no),(yyvsp[-2].no),(yyvsp[-4].no));}
#line 2053 "y.tab.c"
    break;

  case 74: /* Ifstmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 329 "task.y"
                                            {(yyval.no)=create_tree(0,TLookup("void"),NULL,if_node,(yyvsp[-5].no),NULL,(yyvsp[-2].no));}
#line 2059 "y.tab.c"
    break;

  case 75: /* Whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 332 "task.y"
                                                  {(yyval.no)= create_tree(0,TLookup("void"),NULL,while_node,(yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2065 "y.tab.c"
    break;

  case 76: /* expr: expr PLUS expr  */
#line 335 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"+",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2071 "y.tab.c"
    break;

  case 77: /* expr: expr MINUS expr  */
#line 336 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"-",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2077 "y.tab.c"
    break;

  case 78: /* expr: expr MUL expr  */
#line 337 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"*",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2083 "y.tab.c"
    break;

  case 79: /* expr: expr DIV expr  */
#line 338 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"/",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2089 "y.tab.c"
    break;

  case 80: /* expr: expr MOD expr  */
#line 339 "task.y"
                        {(yyval.no) = create_tree(0,TLookup("int"),"%",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2095 "y.tab.c"
    break;

  case 81: /* expr: expr GT expr  */
#line 340 "task.y"
                      {(yyval.no)=create_tree(0,TLookup("bool"),">",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2101 "y.tab.c"
    break;

  case 82: /* expr: expr LT expr  */
#line 341 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"<",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2107 "y.tab.c"
    break;

  case 83: /* expr: expr GE expr  */
#line 342 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),">=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2113 "y.tab.c"
    break;

  case 84: /* expr: expr LE expr  */
#line 343 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"<=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2119 "y.tab.c"
    break;

  case 85: /* expr: expr EQ expr  */
#line 344 "task.y"
                      {	(yyval.no) =create_tree(0,TLookup("bool"),"==",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2125 "y.tab.c"
    break;

  case 86: /* expr: expr NE expr  */
#line 345 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"!=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2131 "y.tab.c"
    break;

  case 87: /* expr: expr ANDTKN expr  */
#line 346 "task.y"
                          {(yyval.no) =create_tree(0,TLookup("bool"),"&&",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2137 "y.tab.c"
    break;

  case 88: /* expr: expr ORTKN expr  */
#line 347 "task.y"
                         {(yyval.no) =create_tree(0,TLookup("bool"),"||",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2143 "y.tab.c"
    break;

  case 89: /* expr: NOTTKN expr  */
#line 348 "task.y"
                     {(yyval.no) =create_tree(0,TLookup("bool"),"!",log_node,(yyvsp[0].no),NULL,NULL);}
#line 2149 "y.tab.c"
    break;

  case 90: /* expr: '(' expr ')'  */
#line 349 "task.y"
                                {(yyval.no)=(yyvsp[-1].no);}
#line 2155 "y.tab.c"
    break;

  case 91: /* expr: IDEN  */
#line 350 "task.y"
                                {(yyval.no)=(yyvsp[0].no);typecheck((yyval.no));}
#line 2161 "y.tab.c"
    break;

  case 92: /* expr: NUM  */
#line 351 "task.y"
                                {(yyval.no)=create_tree((yyvsp[0].numb),TLookup("int"),NULL,iconst_node,NULL,NULL,NULL);}
#line 2167 "y.tab.c"
    break;

  case 93: /* expr: MESG  */
#line 352 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("str"),(yyvsp[0].name),sconst_node,NULL,NULL,NULL);}
#line 2173 "y.tab.c"
    break;

  case 94: /* expr: ID '(' ')'  */
#line 353 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[-2].name),func_node,NULL,NULL,NULL);}
#line 2179 "y.tab.c"
    break;

  case 95: /* expr: ID '(' ArgList ')'  */
#line 354 "task.y"
                      {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[-3].name),func_node,(yyvsp[-1].no),NULL,NULL);}
#line 2185 "y.tab.c"
    break;

  case 96: /* expr: FIELD  */
#line 355 "task.y"
                {(yyval.no)= (yyvsp[0].no);}
#line 2191 "y.tab.c"
    break;

  case 97: /* expr: NULLTKN  */
#line 356 "task.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2197 "y.tab.c"
    break;

  case 98: /* ArgList: expr ',' ArgList  */
#line 358 "task.y"
                           {(yyvsp[-2].no)->arg =(yyvsp[0].no);(yyval.no)=(yyvsp[-2].no);}
#line 2203 "y.tab.c"
    break;

  case 99: /* ArgList: expr  */
#line 359 "task.y"
               {(yyval.no)=(yyvsp[0].no);(yyval.no)->arg=NULL;}
#line 2209 "y.tab.c"
    break;

  case 100: /* IDEN: ID  */
#line 361 "task.y"
          {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[0].name),var_node,NULL,NULL,NULL);}
#line 2215 "y.tab.c"
    break;

  case 101: /* IDEN: ID '[' expr ']'  */
#line 363 "task.y"
                              {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[-3].name),arr_node,(yyvsp[-1].no),NULL,NULL);}
#line 2221 "y.tab.c"
    break;


#line 2225 "y.tab.c"

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

#line 365 "task.y"

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
