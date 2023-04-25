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

	//abhis project
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
	struct Classtable *currclass;
	struct Gsymbol *func_=NULL;
	struct Memberfunclist *mem_func=NULL;
	int size=0;
	int cls_fld_idx=0,cls_mtd_idx=0;
	struct Classtable *Cptr=NULL;

#line 94 "y.tab.c"

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
    CLASS = 299,                   /* CLASS  */
    ENDCLASS = 300,                /* ENDCLASS  */
    SELF = 301,                    /* SELF  */
    NEW = 302,                     /* NEW  */
    DELETE = 303,                  /* DELETE  */
    MOD = 304                      /* MOD  */
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
#define CLASS 299
#define ENDCLASS 300
#define SELF 301
#define NEW 302
#define DELETE 303
#define MOD 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "task.y"

	struct tnode *no;
	struct param *par;
	struct Fieldlist *field;
	struct Typetable *typ;
	int numb;
	char *name;

#line 254 "y.tab.c"

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
  YYSYMBOL_CLASS = 44,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 45,                  /* ENDCLASS  */
  YYSYMBOL_SELF = 46,                      /* SELF  */
  YYSYMBOL_NEW = 47,                       /* NEW  */
  YYSYMBOL_DELETE = 48,                    /* DELETE  */
  YYSYMBOL_MOD = 49,                       /* MOD  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '}'  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* '.'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_59_ = 59,                       /* '='  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 62,              /* TypeDefBlock  */
  YYSYMBOL_TYPE_TKN = 63,                  /* TYPE_TKN  */
  YYSYMBOL_TypeDefList = 64,               /* TypeDefList  */
  YYSYMBOL_Type_name = 65,                 /* Type_name  */
  YYSYMBOL_TypeDef = 66,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 67,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 68,                 /* FieldDecl  */
  YYSYMBOL_TypeName = 69,                  /* TypeName  */
  YYSYMBOL_ClassDefBlock = 70,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 71,              /* ClassDefList  */
  YYSYMBOL_Classdef = 72,                  /* Classdef  */
  YYSYMBOL_Cname = 73,                     /* Cname  */
  YYSYMBOL_Fieldlists = 74,                /* Fieldlists  */
  YYSYMBOL_Fld = 75,                       /* Fld  */
  YYSYMBOL_MethodDecl = 76,                /* MethodDecl  */
  YYSYMBOL_MDecl = 77,                     /* MDecl  */
  YYSYMBOL_MethodDefns = 78,               /* MethodDefns  */
  YYSYMBOL_FieldFunction = 79,             /* FieldFunction  */
  YYSYMBOL_FIELD = 80,                     /* FIELD  */
  YYSYMBOL_GdeclBlock = 81,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 82,                 /* GdeclList  */
  YYSYMBOL_GDecl = 83,                     /* GDecl  */
  YYSYMBOL_GType = 84,                     /* GType  */
  YYSYMBOL_GidList = 85,                   /* GidList  */
  YYSYMBOL_Gid = 86,                       /* Gid  */
  YYSYMBOL_FdefBlock = 87,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 88,                      /* Fdef  */
  YYSYMBOL_Ftype_param = 89,               /* Ftype_param  */
  YYSYMBOL_ParamList = 90,                 /* ParamList  */
  YYSYMBOL_Param = 91,                     /* Param  */
  YYSYMBOL_Ptype = 92,                     /* Ptype  */
  YYSYMBOL_LdeclBlock = 93,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 94,                  /* LDecList  */
  YYSYMBOL_LDecl = 95,                     /* LDecl  */
  YYSYMBOL_IdList = 96,                    /* IdList  */
  YYSYMBOL_Type = 97,                      /* Type  */
  YYSYMBOL_MainBlock = 98,                 /* MainBlock  */
  YYSYMBOL_Type_main = 99,                 /* Type_main  */
  YYSYMBOL_Body = 100,                     /* Body  */
  YYSYMBOL_Rstmt = 101,                    /* Rstmt  */
  YYSYMBOL_Slist = 102,                    /* Slist  */
  YYSYMBOL_Stmt = 103,                     /* Stmt  */
  YYSYMBOL_class_stmts = 104,              /* class_stmts  */
  YYSYMBOL_Assign_stmt = 105,              /* Assign_stmt  */
  YYSYMBOL_Inp_stmt = 106,                 /* Inp_stmt  */
  YYSYMBOL_out_stmt = 107,                 /* out_stmt  */
  YYSYMBOL_Heapstuff = 108,                /* Heapstuff  */
  YYSYMBOL_Ifstmt = 109,                   /* Ifstmt  */
  YYSYMBOL_Whilestmt = 110,                /* Whilestmt  */
  YYSYMBOL_expr = 111,                     /* expr  */
  YYSYMBOL_ArgList = 112,                  /* ArgList  */
  YYSYMBOL_IDEN = 113                      /* IDEN  */
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
#define YYLAST   526

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      53,    54,     2,     2,    56,     2,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,    59,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    51,    52,    56,    66,    76,    78,    79,
      81,    82,    90,    92,    95,   101,   102,   103,   111,   112,
     114,   115,   118,   133,   137,   138,   141,   146,   147,   150,
     159,   160,   165,   187,   222,   258,   286,   345,   393,   396,
     398,   398,   399,   400,   402,   406,   424,   426,   428,   429,
     430,   434,   434,   436,   463,   484,   505,   507,   508,   511,
     514,   515,   516,   525,   531,   536,   536,   538,   540,   541,
     545,   547,   551,   569,   593,   608,   609,   614,   620,   656,
     657,   659,   660,   661,   662,   663,   664,   665,   666,   668,
     671,   687,   701,   709,   710,   711,   713,   715,   718,   719,
     727,   728,   731,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   753,   754,   755,   756,   758,   759,   760,   762,   764
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
  "INITIALIZE", "ALLOC", "FREE", "NULLTKN", "CLASS", "ENDCLASS", "SELF",
  "NEW", "DELETE", "MOD", "'{'", "'}'", "';'", "'('", "')'", "'.'", "','",
  "'['", "']'", "'='", "$accept", "Program", "TypeDefBlock", "TYPE_TKN",
  "TypeDefList", "Type_name", "TypeDef", "FieldDeclList", "FieldDecl",
  "TypeName", "ClassDefBlock", "ClassDefList", "Classdef", "Cname",
  "Fieldlists", "Fld", "MethodDecl", "MDecl", "MethodDefns",
  "FieldFunction", "FIELD", "GdeclBlock", "GdeclList", "GDecl", "GType",
  "GidList", "Gid", "FdefBlock", "Fdef", "Ftype_param", "ParamList",
  "Param", "Ptype", "LdeclBlock", "LDecList", "LDecl", "IdList", "Type",
  "MainBlock", "Type_main", "Body", "Rstmt", "Slist", "Stmt",
  "class_stmts", "Assign_stmt", "Inp_stmt", "out_stmt", "Heapstuff",
  "Ifstmt", "Whilestmt", "expr", "ArgList", "IDEN", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-246)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,  -246,    49,    12,    40,  -246,    42,    41,  -246,    -8,
      38,  -246,  -246,   -17,  -246,    56,  -246,  -246,    85,  -246,
      54,    90,  -246,    30,  -246,  -246,    77,  -246,  -246,    82,
    -246,  -246,  -246,  -246,   118,  -246,    87,    54,  -246,    80,
       1,  -246,  -246,    93,  -246,  -246,  -246,   104,    77,    99,
    -246,  -246,  -246,    18,    33,  -246,  -246,  -246,    19,   110,
     120,  -246,  -246,   123,    77,   141,   200,  -246,    87,   407,
     132,   197,   176,   141,    19,  -246,   196,  -246,   160,  -246,
    -246,  -246,  -246,   100,  -246,   203,   178,  -246,   184,   185,
     188,   189,   191,   192,   193,   279,   198,   190,   199,    59,
     222,   407,  -246,  -246,  -246,  -246,  -246,  -246,  -246,    94,
    -246,   174,  -246,   217,   208,  -246,   140,   197,   209,   -27,
      54,   241,  -246,  -246,   141,  -246,  -246,   249,   279,   279,
     279,  -246,  -246,   279,  -246,  -246,   136,   279,  -246,   228,
     279,  -246,   229,   322,   232,   249,   249,   -16,   249,   271,
    -246,   264,  -246,   249,    14,  -246,  -246,  -246,   139,  -246,
    -246,   238,  -246,  -246,   141,   -14,  -246,   259,   237,  -246,
     242,   204,   212,   250,   116,   279,    16,   249,   258,   249,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,  -246,   249,   243,  -246,     8,   240,  -246,
     239,   329,  -246,  -246,   245,   247,   248,   253,   378,  -246,
     274,  -246,   158,  -246,  -246,   257,   261,   304,   305,  -246,
     122,   265,   268,  -246,   270,     4,     4,  -246,  -246,    16,
      16,    16,    16,    16,    16,    16,    16,  -246,   277,   285,
     286,   249,  -246,   291,   298,   249,  -246,  -246,  -246,   301,
    -246,  -246,   478,   478,   279,  -246,   279,   279,   279,  -246,
    -246,   300,  -246,  -246,   302,  -246,   380,   434,  -246,   306,
     307,   308,   303,   311,   478,   314,   315,  -246,  -246,  -246,
    -246,  -246,   459,  -246,  -246,   316,  -246
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     7,     0,    19,     0,     1,     0,     0,    10,     0,
       0,     9,    23,     0,    21,     0,    70,    71,     0,    72,
       0,     0,     4,     0,     5,     8,     0,    18,    20,     0,
      43,    44,    39,    45,     0,    41,     0,     0,    52,     0,
       0,     3,    75,     0,    15,    16,    17,     0,    13,     0,
      25,    38,    40,    48,     0,    47,    51,     2,     0,     0,
       0,    11,    12,     0,     0,    58,     0,    42,     0,     0,
       0,     0,     0,    58,     0,    14,     0,    24,     0,    28,
      60,    61,    62,     0,    57,     0,     0,    46,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,    80,    86,    81,    82,    83,    84,    85,     0,
      64,     0,    66,     0,     0,    54,     0,     0,     0,     0,
       0,     0,    27,    50,     0,    59,    49,     0,     0,     0,
       0,    88,    87,     0,   119,   120,   128,     0,   124,     0,
       0,   123,   122,     0,   118,     0,     0,     0,     0,     0,
      77,     0,    79,     0,     0,    63,    65,    69,     0,    53,
      55,     0,    74,    26,    58,     0,    31,     0,     0,    56,
       0,     0,     0,     0,     0,   127,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,    37,     0,     0,    36,
       0,     0,    76,    35,     0,     0,     0,     0,     0,    67,
       0,    73,     0,    22,    30,     0,     0,     0,     0,   129,
     126,     0,    37,   117,    36,   103,   104,   105,   106,   108,
     109,   110,   111,   112,   113,   114,   115,   107,    35,     0,
       0,     0,    94,     0,     0,     0,    95,    93,    68,     0,
      96,    97,     0,     0,   127,   121,   127,   127,   127,    89,
      92,     0,    98,    99,     0,    29,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,    32,    34,    33,
      91,    90,     0,   101,   102,     0,   100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -246,  -246,  -246,  -246,  -246,  -246,   350,   283,  -246,   -37,
    -246,  -246,   356,  -246,  -246,  -246,  -246,   292,  -246,  -246,
     -67,  -246,  -246,   338,  -246,  -246,   309,  -246,   -33,  -246,
     -61,   251,  -246,   299,  -246,   269,  -246,    -4,    -1,  -246,
     -65,   275,  -245,  -100,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,   -90,   -77,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     9,    10,    11,    47,    48,    49,
       7,    13,    14,    15,    64,    77,    78,    79,   165,   141,
     142,    20,    34,    35,    36,    54,    55,    37,    38,    39,
      83,    84,    85,    71,   111,   112,   158,    40,    22,    23,
      72,   100,   101,   102,   103,   104,   105,   106,   207,   107,
     108,   220,   221,   144
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     109,   152,    99,    21,    56,   143,   114,   266,   267,   118,
     182,   183,   116,    16,    17,    12,    94,   134,    19,    41,
     180,   181,   182,   183,     8,   163,   164,    76,    27,   282,
      97,    24,   109,    59,    99,    42,    57,   213,   171,   172,
     173,   121,    69,   174,     1,   135,   136,   176,    70,     5,
     178,   137,   161,   192,   204,   205,     6,   138,   170,   201,
     139,   206,   240,   148,   208,   192,   113,   140,    16,    17,
      18,    65,     8,    19,    12,    66,   195,   196,   198,   199,
     197,    16,    17,    43,   203,    67,    19,   166,    26,    68,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   212,    44,    45,    29,   113,   222,    46,
     224,    50,    30,    31,   148,    32,   167,    33,   149,    53,
     180,   181,   182,   183,    42,   238,   180,   181,   182,   183,
      58,    63,   214,   184,   185,   186,   187,   188,   189,   184,
     185,   186,   187,   188,   189,    30,    31,    60,    51,   153,
      33,   190,   191,   154,   123,    61,   124,   190,   191,    16,
      17,   167,   110,    73,    19,   192,   152,   152,    80,    81,
      74,   192,   261,    82,   219,    75,   264,   268,   254,   269,
     270,   271,   152,   109,   109,    99,    99,    44,    45,   175,
     120,   209,    46,   133,   160,   210,   124,   109,   109,    99,
      99,    16,    17,    86,   155,   109,    19,    99,   180,   181,
     182,   183,   249,   109,   124,    99,   180,   181,   182,   183,
      69,   184,   185,   186,   187,   188,   189,   115,   119,   184,
     185,   186,   187,   188,   189,   125,   126,   127,   128,   190,
     191,   129,   130,   131,   132,   146,   150,   190,   191,   157,
     133,   145,   147,   192,   180,   181,   182,   183,   216,   159,
     162,   192,   180,   181,   182,   183,   217,   184,   185,   186,
     187,   188,   189,   168,   134,   184,   185,   186,   187,   188,
     189,    94,   134,   177,   179,   190,   191,   194,   202,   211,
     164,    59,   241,   190,   191,   153,   215,   239,   243,   192,
     244,   245,   135,   136,   218,   246,   248,   192,   137,   250,
     135,   136,   223,   251,   138,   252,   137,   139,   200,   255,
     253,   256,   138,   257,   140,   139,   180,   181,   182,   183,
     258,    62,   140,   180,   181,   182,   183,   259,   260,   184,
     185,   186,   187,   188,   189,   262,   184,   185,   186,   187,
     188,   189,   263,   265,   272,   280,   273,   190,   191,    25,
     277,   278,   279,   281,   190,   191,   283,   284,   286,    28,
     122,   192,    52,   117,   193,   169,   151,    87,   192,     0,
     156,   242,   180,   181,   182,   183,     0,     0,    88,    89,
      90,     0,   274,   275,    91,   184,   185,   186,   187,   188,
     189,     0,     0,     0,     0,    92,    93,     0,     0,     0,
       0,     0,    94,   190,   191,    88,    89,    90,     0,     0,
       0,    91,    96,     0,     0,     0,    97,   192,    98,     0,
     247,     0,    92,    93,     0,     0,     0,     0,     0,    94,
      95,     0,    88,    89,    90,     0,     0,     0,    91,    96,
     276,     0,     0,    97,     0,    98,     0,     0,     0,    92,
      93,     0,     0,     0,     0,     0,    94,    88,    89,    90,
       0,     0,   285,    91,     0,     0,    96,     0,     0,     0,
      97,     0,    98,     0,    92,    93,    88,    89,    90,     0,
       0,    94,    91,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,    92,    93,    97,     0,    98,     0,     0,
      94,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,    97,     0,    98
};

static const yytype_int16 yycheck[] =
{
      69,   101,    69,     7,    37,    95,    71,   252,   253,    74,
       6,     7,    73,    27,    28,    32,    32,     3,    32,    20,
       4,     5,     6,     7,    32,    52,    53,    64,    45,   274,
      46,    39,   101,    32,   101,    34,    37,    51,   128,   129,
     130,    78,    23,   133,    38,    31,    32,   137,    29,     0,
     140,    37,   117,    49,    40,    41,    44,    43,   127,   149,
      46,    47,    54,    55,   154,    49,    70,    53,    27,    28,
      29,    53,    32,    32,    32,    57,   145,   146,   147,   148,
     147,    27,    28,    53,   153,    52,    32,   120,    50,    56,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   164,    27,    28,    50,   111,   177,    32,
     179,    29,    27,    28,    55,    30,   120,    32,    59,    32,
       4,     5,     6,     7,    34,   194,     4,     5,     6,     7,
      50,    32,   165,    17,    18,    19,    20,    21,    22,    17,
      18,    19,    20,    21,    22,    27,    28,    54,    30,    55,
      32,    35,    36,    59,    54,    51,    56,    35,    36,    27,
      28,   165,    30,    53,    32,    49,   266,   267,    27,    28,
      50,    49,   241,    32,    58,    52,   245,   254,    56,   256,
     257,   258,   282,   252,   253,   252,   253,    27,    28,    53,
      30,    52,    32,    57,    54,    56,    56,   266,   267,   266,
     267,    27,    28,     3,    30,   274,    32,   274,     4,     5,
       6,     7,    54,   282,    56,   282,     4,     5,     6,     7,
      23,    17,    18,    19,    20,    21,    22,    51,    32,    17,
      18,    19,    20,    21,    22,    32,    58,    53,    53,    35,
      36,    53,    53,    52,    52,    55,    24,    35,    36,    32,
      57,    53,    53,    49,     4,     5,     6,     7,    54,    51,
      51,    49,     4,     5,     6,     7,    54,    17,    18,    19,
      20,    21,    22,    32,     3,    17,    18,    19,    20,    21,
      22,    32,     3,    55,    55,    35,    36,    55,    24,    51,
      53,    32,    53,    35,    36,    55,    54,    54,    53,    49,
      53,    53,    31,    32,    54,    52,    32,    49,    37,    52,
      31,    32,    54,    52,    43,    11,    37,    46,    47,    54,
      15,    53,    43,    53,    53,    46,     4,     5,     6,     7,
      53,    48,    53,     4,     5,     6,     7,    52,    52,    17,
      18,    19,    20,    21,    22,    54,    17,    18,    19,    20,
      21,    22,    54,    52,    54,    52,    54,    35,    36,     9,
      54,    54,    54,    52,    35,    36,    52,    52,    52,    13,
      78,    49,    34,    74,    52,   124,   101,    68,    49,    -1,
     111,    52,     4,     5,     6,     7,    -1,    -1,     8,     9,
      10,    -1,    12,    13,    14,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32,    35,    36,     8,     9,    10,    -1,    -1,
      -1,    14,    42,    -1,    -1,    -1,    46,    49,    48,    -1,
      52,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,
      33,    -1,     8,     9,    10,    -1,    -1,    -1,    14,    42,
      16,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    32,     8,     9,    10,
      -1,    -1,    13,    14,    -1,    -1,    42,    -1,    -1,    -1,
      46,    -1,    48,    -1,    25,    26,     8,     9,    10,    -1,
      -1,    32,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    25,    26,    46,    -1,    48,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    61,    62,    63,     0,    44,    70,    32,    64,
      65,    66,    32,    71,    72,    73,    27,    28,    29,    32,
      81,    97,    98,    99,    39,    66,    50,    45,    72,    50,
      27,    28,    30,    32,    82,    83,    84,    87,    88,    89,
      97,    98,    34,    53,    27,    28,    32,    67,    68,    69,
      29,    30,    83,    32,    85,    86,    88,    98,    50,    32,
      54,    51,    67,    32,    74,    53,    57,    52,    56,    23,
      29,    93,   100,    53,    50,    52,    69,    75,    76,    77,
      27,    28,    32,    90,    91,    92,     3,    86,     8,     9,
      10,    14,    25,    26,    32,    33,    42,    46,    48,    80,
     101,   102,   103,   104,   105,   106,   107,   109,   110,   113,
      30,    94,    95,    97,   100,    51,    90,    93,   100,    32,
      30,    69,    77,    54,    56,    32,    58,    53,    53,    53,
      53,    52,    52,    57,     3,    31,    32,    37,    43,    46,
      53,    79,    80,   111,   113,    53,    55,    53,    55,    59,
      24,   101,   103,    55,    59,    30,    95,    32,    96,    51,
      54,   100,    51,    52,    53,    78,    88,    97,    32,    91,
     113,   111,   111,   111,   111,    53,   111,    55,   111,    55,
       4,     5,     6,     7,    17,    18,    19,    20,    21,    22,
      35,    36,    49,    52,    55,   113,   113,    80,   113,   113,
      47,   111,    24,   113,    40,    41,    47,   108,   111,    52,
      56,    51,    90,    51,    88,    54,    54,    54,    54,    58,
     111,   112,   113,    54,   113,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   113,    54,
      54,    53,    52,    53,    53,    53,    52,    52,    32,    54,
      52,    52,    11,    15,    56,    54,    53,    53,    53,    52,
      52,   113,    54,    54,   113,    52,   102,   102,   112,   112,
     112,   112,    54,    54,    12,    13,    16,    54,    54,    54,
      52,    52,   102,    52,    52,    13,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    63,    64,    64,
      65,    66,    67,    67,    68,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    74,    74,    75,    76,    76,    77,
      78,    78,    79,    79,    79,    80,    80,    80,    81,    81,
      82,    82,    83,    84,    84,    84,    85,    85,    86,    86,
      86,    87,    87,    88,    88,    89,    90,    90,    90,    91,
      92,    92,    92,    93,    93,    94,    94,    95,    96,    96,
      97,    97,    97,    98,    98,    99,   100,   100,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   105,   106,   107,   108,   108,
     109,   109,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   113,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     1,     2,     1,
       1,     4,     2,     1,     3,     1,     1,     1,     3,     0,
       2,     1,     8,     1,     2,     0,     3,     2,     1,     6,
       2,     1,     6,     6,     6,     3,     3,     3,     3,     2,
       2,     1,     3,     1,     1,     1,     3,     1,     1,     4,
       4,     2,     1,     5,     4,     5,     3,     1,     0,     2,
       1,     1,     1,     3,     2,     2,     1,     3,     3,     1,
       1,     1,     1,     7,     6,     2,     4,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     5,
       7,     7,     5,     4,     4,     4,     5,     5,     3,     3,
      10,     8,     8,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     4,     1,     1,     1,     3,     1,     0,     1,     4
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
  case 2: /* Program: TypeDefBlock ClassDefBlock GdeclBlock FdefBlock MainBlock  */
#line 50 "task.y"
                                                                   {}
#line 1586 "y.tab.c"
    break;

  case 3: /* Program: TypeDefBlock ClassDefBlock GdeclBlock MainBlock  */
#line 51 "task.y"
                                                                                {}
#line 1592 "y.tab.c"
    break;

  case 4: /* Program: TypeDefBlock ClassDefBlock MainBlock  */
#line 52 "task.y"
                                                                        {}
#line 1598 "y.tab.c"
    break;

  case 5: /* TypeDefBlock: TYPE_TKN TypeDefList ENDTYPETKN  */
#line 57 "task.y"
                                {
						headergen();
						fp=fopen("task.xsm","a");
						fprintf(fp,"PUSH R0\n");//Space for return value
						fprintf(fp,"CALL F0\n");
						fclose(fp);
						i = sys_call("Exit",0,0);

				}
#line 1612 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 66 "task.y"
                {
				TypeTableCreate();
					headergen();
					fp=fopen("task.xsm","a");
					fprintf(fp,"PUSH R0\n");//Space for return value
					fprintf(fp,"CALL F0\n");
					fclose(fp);
					i = sys_call("Exit",0,0);
				}
#line 1626 "y.tab.c"
    break;

  case 7: /* TYPE_TKN: TYPETKN  */
#line 76 "task.y"
                   {TypeTableCreate();}
#line 1632 "y.tab.c"
    break;

  case 8: /* TypeDefList: TypeDefList TypeDef  */
#line 78 "task.y"
                                    {}
#line 1638 "y.tab.c"
    break;

  case 9: /* TypeDefList: TypeDef  */
#line 79 "task.y"
                        {}
#line 1644 "y.tab.c"
    break;

  case 10: /* Type_name: ID  */
#line 81 "task.y"
                {(yyval.typ) =TInstall((yyvsp[0].name),0,NULL);}
#line 1650 "y.tab.c"
    break;

  case 11: /* TypeDef: Type_name '{' FieldDeclList '}'  */
#line 82 "task.y"
                                                  { 
					(yyval.typ) = (yyvsp[-3].typ);
					(yyval.typ)->fields = (yyvsp[-1].field);
					(yyval.typ)->size = size;
					//print_type($$);
					size=0; }
#line 1661 "y.tab.c"
    break;

  case 12: /* FieldDeclList: FieldDecl FieldDeclList  */
#line 90 "task.y"
                                        {(yyvsp[-1].field)->next=(yyvsp[0].field);
					(yyval.field)=(yyvsp[-1].field);}
#line 1668 "y.tab.c"
    break;

  case 13: /* FieldDeclList: FieldDecl  */
#line 92 "task.y"
                          {(yyval.field) =(yyvsp[0].field);}
#line 1674 "y.tab.c"
    break;

  case 14: /* FieldDecl: TypeName ID ';'  */
#line 95 "task.y"
                                {
					(yyval.field) = Fcreate((yyvsp[-1].name),(yyvsp[-2].name));
					//printf("%s  %s\n",$1,$2);
					++size;
					}
#line 1684 "y.tab.c"
    break;

  case 15: /* TypeName: INT  */
#line 101 "task.y"
                   {(yyval.name)="int";}
#line 1690 "y.tab.c"
    break;

  case 16: /* TypeName: STR  */
#line 102 "task.y"
                   {(yyval.name)="str";}
#line 1696 "y.tab.c"
    break;

  case 17: /* TypeName: ID  */
#line 103 "task.y"
                  {(yyval.name)=(yyvsp[0].name);}
#line 1702 "y.tab.c"
    break;

  case 20: /* ClassDefList: ClassDefList Classdef  */
#line 114 "task.y"
                                        {}
#line 1708 "y.tab.c"
    break;

  case 21: /* ClassDefList: Classdef  */
#line 115 "task.y"
                           {}
#line 1714 "y.tab.c"
    break;

  case 22: /* Classdef: Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}'  */
#line 119 "task.y"
                                {
					
					Cptr->Fieldcount=cls_fld_idx ;
					Cptr->Methodcount=cls_mtd_idx;
					cls_fld_idx=0;
					cls_mtd_idx=0;
					//cls_idx=0;
					Cptr = NULL;
					//free_classtab();
					//printf("class done\n");

				}
#line 1731 "y.tab.c"
    break;

  case 23: /* Cname: ID  */
#line 133 "task.y"
                            {Cptr = CInstall((yyvsp[0].name),NULL);}
#line 1737 "y.tab.c"
    break;

  case 24: /* Fieldlists: Fieldlists Fld  */
#line 137 "task.y"
                                 {}
#line 1743 "y.tab.c"
    break;

  case 26: /* Fld: TypeName ID ';'  */
#line 141 "task.y"
                                   {Class_Finstall(Cptr,(yyvsp[-2].name),(yyvsp[-1].name),cls_fld_idx);
							++cls_fld_idx;
							}
#line 1751 "y.tab.c"
    break;

  case 27: /* MethodDecl: MethodDecl MDecl  */
#line 146 "task.y"
                                   {}
#line 1757 "y.tab.c"
    break;

  case 28: /* MethodDecl: MDecl  */
#line 147 "task.y"
                        {}
#line 1763 "y.tab.c"
    break;

  case 29: /* MDecl: TypeName ID '(' ParamList ')' ';'  */
#line 150 "task.y"
                                                    {
						Class_Minstall(Cptr,(yyvsp[-4].name),TLookup((yyvsp[-5].name)),(yyvsp[-2].par),cls_mtd_idx);
						++cls_mtd_idx;
						
						//print_mthd(Cptr);
						}
#line 1774 "y.tab.c"
    break;

  case 32: /* FieldFunction: SELF '.' IDEN '(' ArgList ')'  */
#line 166 "task.y"
                                        {
						if(Cptr==NULL)
						{
							printf("you cant have self stmts outside a class\n");
							exit(1);
						}
						struct Memberfunclist * Mtemp = Class_Mlookup(Cptr, (yyvsp[-3].no)->varname);
						if(Mtemp == NULL)
						{
                	        printf("Function -->%s not a member function of the class-->%s \n",(yyvsp[-3].no)->varname,Cptr->name);
                        	exit(1);
                        }
						(yyvsp[-3].no)->val= Mtemp->Flabel;
						(yyvsp[-3].no)->nodetype =  self_meth_node;
						(yyvsp[-3].no)->left=(yyvsp[-1].no);
						(yyvsp[-3].no)->Ctype=Cptr;
						//$$=create_tree(0,TLookup("void"),"self",self_meth_node,NULL,NULL,$3);
						(yyval.no)=(yyvsp[-3].no);
						(yyval.no)->Lentry = LLookup("self");
                        (yyval.no)->type = Mtemp->type;
					}
#line 1800 "y.tab.c"
    break;

  case 33: /* FieldFunction: IDEN '.' IDEN '(' ArgList ')'  */
#line 188 "task.y"
                                        {
						if(Cptr!=NULL)
						{
							printf("you cant have id.id(args) stmts inside a class\n");
							exit(1);
						}
						(yyvsp[-5].no)->mid =(yyvsp[-3].no);
						struct Gsymbol *Gtemp = GLookup((yyvsp[-5].no)->varname);
						if(Gtemp==NULL)
						{
							printf("no %s was declared\n",(yyvsp[-5].no)->varname);
							exit(1);
						}
						(yyvsp[-5].no)->Ctype = Gtemp->Ctype;
						(yyvsp[-3].no)->Ctype = Gtemp->Ctype;
						(yyvsp[-5].no)->Gentry = Gtemp;
						(yyvsp[-5].no)->nodetype=cls_meth_node;


						struct Memberfunclist * Mtemp;
						Mtemp = Class_Mlookup(Gtemp->Ctype, (yyvsp[-3].no)->varname);
						if(Mtemp == NULL)
						{
                	        printf("Function -->%s not a member function of the class-->%s \n",(yyvsp[-3].no)->varname,Gtemp->Ctype->name);
                        	exit(1);
                        }
						(yyvsp[-3].no)->val= Mtemp->Flabel;
						(yyvsp[-3].no)->nodetype =  mth_call_node;
						(yyvsp[-3].no)->left=(yyvsp[-1].no);
						(yyval.no)=(yyvsp[-5].no);
						(yyval.no)->Lentry = NULL;
                        (yyval.no)->type = Mtemp->type;
						
					}
#line 1839 "y.tab.c"
    break;

  case 34: /* FieldFunction: FIELD '.' IDEN '(' ArgList ')'  */
#line 223 "task.y"
                                        {
						//if(Cptr == NULL)
						//else
						//$1->nodetype = $1;
						struct tnode *temp; 
						temp=(yyvsp[-5].no);
						while(temp->mid!=NULL)
							temp=temp->mid;
						
						if(temp->Ctype==NULL)
						{
							printf("field doesnt end with a class type\n");
							exit(1);
						}
						temp->mid = (yyvsp[-3].no);
						struct Memberfunclist* m;
						m=Class_Mlookup(temp->Ctype,(yyvsp[-3].no)->varname);
						if(m==NULL)
						{
							printf("Function -->%s not a member function of the class-->%s \n",(yyvsp[-3].no)->varname,Cptr->name);
                        	exit(1);
						}
						(yyvsp[-3].no)->val= m->Flabel;
						(yyvsp[-3].no)->nodetype =  mth_call_node;
						//$$->nodetype=self_meth_node;
						(yyvsp[-3].no)->left=(yyvsp[-1].no);
						(yyval.no)=(yyvsp[-5].no);
						//$$->Lentry = NULL; would be set to self
                        (yyval.no)->type = m->type;
					}
#line 1874 "y.tab.c"
    break;

  case 35: /* FIELD: IDEN '.' IDEN  */
#line 259 "task.y"
                {
		//cant occur in context of a class
					
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
			
		}
#line 1906 "y.tab.c"
    break;

  case 36: /* FIELD: FIELD '.' IDEN  */
#line 286 "task.y"
                           {  //can't occur in a class 
		  		if((yyval.no)->Ctype!=NULL)
				{
					//print_node($$);
					printf("%s --- %s\n",(yyval.no)->Ctype->name,(yyvsp[0].no)->varname);
					printf("variables of a class are protected so you cant access them this way\ncall its methods if possible--%d\n",ins_cnt);
					exit(1);
				}
		  		struct tnode *temp; 
				struct Fieldlist *f;
				struct Fieldlist *mem_f;
				temp=(yyvsp[-2].no);
				int len=0;
				while(temp->mid!=NULL)
				{
					temp=temp->mid;
					++len;
				}
		  		if(Cptr==NULL)
				{
					f=FLookup(temp->type,(yyvsp[0].no)->varname);
					if(f==NULL)
					{
						printf("No field :%s in %s type\n",(yyvsp[0].no)->varname,temp->type->name);
						exit(1);
					}
					temp->nodetype=field_node;
					(yyvsp[0].no)->type=f->type;
					(yyvsp[0].no)->val=f->fieldIndex;
				}
				else
				{
					mem_f=NULL;
					if(len>0)
					{
						mem_f=Class_Flookup(Cptr,(yyvsp[0].no)->varname);
					}
					else
					{
						mem_f=FLookup(temp->type,(yyvsp[0].no)->varname);
					}
					if(mem_f==NULL)
					{
						printf("No field :%s in %s type\n",(yyvsp[0].no)->varname,temp->type->name);
						exit(1);
					}
					//printf("--%s--\n",$3->varname);
					temp->nodetype=self_fld_node;
					(yyvsp[0].no)->type=mem_f->type;
					(yyvsp[0].no)->val=mem_f->fieldIndex;
					//$3->nodetype= 

				}
				temp->mid=(yyvsp[0].no);

				(yyvsp[-2].no)->type=(yyvsp[0].no)->type;
				(yyval.no)=(yyvsp[-2].no);
		  }
#line 1969 "y.tab.c"
    break;

  case 37: /* FIELD: SELF '.' IDEN  */
#line 346 "task.y"
                  {
			   //recognise error if this statement occurs outside a class --> implemented in tyepcheck
			   	struct Fieldlist *var;
				if(Cptr==NULL)
				{
					printf("self shouldnt be used outside a class\n");
					exit(1);
				}
			   	var = Class_Flookup(Cptr,(yyvsp[0].no)->varname);
				(yyval.no)->Ctype =Cptr;
				if(var!=NULL)
				{
						(yyval.no)=(yyvsp[0].no);
						(yyval.no)->Lentry = LLookup("self");
						(yyval.no)->val= var->fieldIndex;
			   			(yyval.no)->nodetype=self_fld_node;
						(yyval.no)->type= var->type;
						(yyval.no)->Ctype=var->ctype;
				}
				else
				{
					//print_field(Cptr);
					printf("no field matching -->%s in class -->%s\n",(yyvsp[0].no)->varname,Cptr->name);
					exit(1);
				}
		  }
#line 2000 "y.tab.c"
    break;

  case 38: /* GdeclBlock: DECL GdeclList ENDDECL  */
#line 393 "task.y"
                                    {
	//print_symbol_table();
	}
#line 2008 "y.tab.c"
    break;

  case 39: /* GdeclBlock: DECL ENDDECL  */
#line 396 "task.y"
                {}
#line 2014 "y.tab.c"
    break;

  case 40: /* GdeclList: GdeclList GDecl  */
#line 398 "task.y"
                            {}
#line 2020 "y.tab.c"
    break;

  case 41: /* GdeclList: GDecl  */
#line 398 "task.y"
                                      {}
#line 2026 "y.tab.c"
    break;

  case 42: /* GDecl: GType GidList ';'  */
#line 399 "task.y"
                          {}
#line 2032 "y.tab.c"
    break;

  case 43: /* GType: INT  */
#line 400 "task.y"
                                                {currtype=TLookup("int");
								(yyval.typ) =currtype;}
#line 2039 "y.tab.c"
    break;

  case 44: /* GType: STR  */
#line 402 "task.y"
                                                {currtype=TLookup("str");
							 (yyval.typ) =currtype;
						
							}
#line 2048 "y.tab.c"
    break;

  case 45: /* GType: ID  */
#line 406 "task.y"
             {
			currtype = TLookup((yyvsp[0].name));
			currclass=NULL;
			if(currtype==NULL)
			{
				currtype=NULL;
    			currclass= CLookup((yyvsp[0].name));
				if(currclass==NULL)
				{
					printf("no class or type of -->%s\n",(yyvsp[0].name));
					exit(1);
				}

			}
			//$$=currtype;
			
		
		}
#line 2071 "y.tab.c"
    break;

  case 46: /* GidList: GidList ',' Gid  */
#line 424 "task.y"
                          {}
#line 2077 "y.tab.c"
    break;

  case 47: /* GidList: Gid  */
#line 426 "task.y"
                    {}
#line 2083 "y.tab.c"
    break;

  case 48: /* Gid: ID  */
#line 428 "task.y"
         {GInstall((yyvsp[0].name),currtype,1,NULL,currclass);}
#line 2089 "y.tab.c"
    break;

  case 49: /* Gid: ID '[' NUM ']'  */
#line 429 "task.y"
                      {GInstall((yyvsp[-3].name),currtype,(yyvsp[-1].numb),NULL,currclass);}
#line 2095 "y.tab.c"
    break;

  case 50: /* Gid: ID '(' ParamList ')'  */
#line 430 "task.y"
                            {GInstall((yyvsp[-3].name),currtype,-1,(yyvsp[-1].par),currclass);}
#line 2101 "y.tab.c"
    break;

  case 53: /* Fdef: Ftype_param '{' LdeclBlock Body '}'  */
#line 437 "task.y"
                {
			//codegen
			(yyval.no)= (yyvsp[-1].no);
			//print_lcl_tab();
			//printf("Abstract syntax tree created succesfully\n");
			
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			inorder((yyval.no));
			printf("------------------------------------------\n");
			printf("------------------------------------------\n");
			printf("------------------------------------------\n");
			//printf("tree printed done\n");
			func_starter((yyvsp[-4].name));
			
			i=codegen((yyval.no));
			//codegen  break task.c:
			//printf("codegenerated for func\n");
			//deletetree($$);
			//printf("tree deleted\n");
			//print_lcl_tab();
			free_lcl_tab();
			//printf("lcl_tabfreed\n");
		}
#line 2131 "y.tab.c"
    break;

  case 54: /* Fdef: Ftype_param '{' Body '}'  */
#line 464 "task.y"
                {
			(yyval.no)=(yyvsp[-1].no);
			//printf("Abstract syntax tree created succesfully\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			inorder((yyval.no));
			printf("------------------------------------------\n");
			printf("------------------------------------------\n");
			printf("------------------------------------------\n");
			//printf("tree printed done\n");
			func_starter((yyvsp[-3].name));
			i=codegen((yyval.no));
			//codegen
			//deletetree($$);
			//printf("tree deleted\n");
			free_lcl_tab();
			//printf("lcl_tabfreed\n");
		}
#line 2155 "y.tab.c"
    break;

  case 55: /* Ftype_param: Type ID '(' ParamList ')'  */
#line 485 "task.y"
        {
		if(Cptr==NULL)
		{
			func_=GLookup((yyvsp[-3].name));
		}
		else
		{
			mem_func=Class_Mlookup(Cptr,(yyvsp[-3].name));
		}
		//printf("in ftype_param\n");
		check_name_equi((yyvsp[-4].typ),(yyvsp[-3].name),(yyvsp[-1].par));
		//printf("nameequichecked\n");
		alocate_param((yyvsp[-1].par));
		//printf("ftype_param_done\n");
		(yyval.name) =(yyvsp[-3].name);
	}
#line 2176 "y.tab.c"
    break;

  case 56: /* ParamList: ParamList ',' Param  */
#line 505 "task.y"
                                {PInstall((yyvsp[-2].par),(yyvsp[0].par));
								 (yyval.par) =(yyvsp[-2].par);}
#line 2183 "y.tab.c"
    break;

  case 57: /* ParamList: Param  */
#line 507 "task.y"
                        {(yyval.par) =(yyvsp[0].par);}
#line 2189 "y.tab.c"
    break;

  case 58: /* ParamList: %empty  */
#line 508 "task.y"
                      {(yyval.par)=NULL;}
#line 2195 "y.tab.c"
    break;

  case 59: /* Param: Ptype ID  */
#line 511 "task.y"
                 {(yyval.par) = create_par((yyvsp[0].name),(yyvsp[-1].typ));}
#line 2201 "y.tab.c"
    break;

  case 60: /* Ptype: INT  */
#line 514 "task.y"
                        {(yyval.typ)=TLookup("int"); }
#line 2207 "y.tab.c"
    break;

  case 61: /* Ptype: STR  */
#line 515 "task.y"
                                {(yyval.typ)=TLookup("str"); }
#line 2213 "y.tab.c"
    break;

  case 62: /* Ptype: ID  */
#line 516 "task.y"
                                {(yyval.typ)=TLookup((yyvsp[0].name)); }
#line 2219 "y.tab.c"
    break;

  case 63: /* LdeclBlock: DECL LDecList ENDDECL  */
#line 526 "task.y"
        {
		//printf("lcl_block done\n");
		

	}
#line 2229 "y.tab.c"
    break;

  case 64: /* LdeclBlock: DECL ENDDECL  */
#line 532 "task.y"
         {
		
	 }
#line 2237 "y.tab.c"
    break;

  case 65: /* LDecList: LDecList LDecl  */
#line 536 "task.y"
                          {}
#line 2243 "y.tab.c"
    break;

  case 66: /* LDecList: LDecl  */
#line 536 "task.y"
                                    {}
#line 2249 "y.tab.c"
    break;

  case 67: /* LDecl: Type IdList ';'  */
#line 538 "task.y"
                        {}
#line 2255 "y.tab.c"
    break;

  case 68: /* IdList: IdList ',' ID  */
#line 540 "task.y"
                      {LInstall((yyvsp[0].name),currtype);}
#line 2261 "y.tab.c"
    break;

  case 69: /* IdList: ID  */
#line 541 "task.y"
                     {LInstall((yyvsp[0].name),currtype);}
#line 2267 "y.tab.c"
    break;

  case 70: /* Type: INT  */
#line 545 "task.y"
                                                {currtype=TLookup("int");
								(yyval.typ) =currtype;}
#line 2274 "y.tab.c"
    break;

  case 71: /* Type: STR  */
#line 547 "task.y"
                                                {currtype=TLookup("str");
							 (yyval.typ) =currtype;
						
							}
#line 2283 "y.tab.c"
    break;

  case 72: /* Type: ID  */
#line 551 "task.y"
             {
			currtype = TLookup((yyvsp[0].name));
			if(currtype==NULL)
			{
				printf("type not declared --> %s\n",(yyvsp[0].name));
				exit(1);
			}
			(yyval.typ)=currtype;
			
		
		}
#line 2299 "y.tab.c"
    break;

  case 73: /* MainBlock: Type_main '(' ')' '{' LdeclBlock Body '}'  */
#line 570 "task.y"
        {		
			(yyval.no)=(yyvsp[-1].no);
			//print_lcl_tab();
			//printf("Abstract syntax tree created succesfully\n");
			printf("------------------------------------------\n");
			printf("------------------------------------------\n");
			printf("------------------------------------------\n");
		    inorder((yyval.no));
			printf("------------------------------------------\n");
		 	printf("------------------------------------------\n");
			printf("------------------------------------------\n");
			printf("tree printed done\n");
			//inorder($$);
			//printf("tree printed\n");
			//codegen
			(yyval.no)->right->val=1;
			main_starter();
			i=codegen((yyval.no));
			//printf("xsm file generated\n");
			///
			//deletetree($$);
			free_lcl_tab();
	}
#line 2327 "y.tab.c"
    break;

  case 74: /* MainBlock: Type_main '(' ')' '{' Body '}'  */
#line 593 "task.y"
                                                        {
			(yyval.no)=(yyvsp[-1].no);
			//printf("Abstract syntax tree created succesfully\n");
			//inorder($$);
			//printf("tree printed\n");
			//codegen
			(yyval.no)->right->val=1;
			main_starter();
			i=codegen((yyval.no));
			//printf("xsm file generated\n");
			///
			//deletetree($$);
			free_lcl_tab();
	}
#line 2346 "y.tab.c"
    break;

  case 75: /* Type_main: Type MAINFN  */
#line 608 "task.y"
                        {func_= NULL;}
#line 2352 "y.tab.c"
    break;

  case 76: /* Body: PBEGIN Slist Rstmt PEND  */
#line 610 "task.y"
        {
		(yyval.no)=create_tree(0,TLookup("void"),NULL,conn_node,(yyvsp[-2].no),(yyvsp[-1].no),NULL);
	}
#line 2360 "y.tab.c"
    break;

  case 77: /* Body: PBEGIN Rstmt PEND  */
#line 615 "task.y"
        {
		(yyval.no)=(yyvsp[-1].no);
	}
#line 2368 "y.tab.c"
    break;

  case 78: /* Rstmt: RETURN expr ';'  */
#line 620 "task.y"
                        {
				if(Cptr!=NULL)
				{
					if(strcmp((yyvsp[-1].no)->type->name,mem_func->type->name)!=0)
					{
						printf("return type error --> %s\n",mem_func->name);
						exit(1);
					}
				}
				else
				{
					if(func_==NULL)
					{
						if(strcmp((yyvsp[-1].no)->type->name,"int")!=0)
						{
							printf("%s\n",(yyvsp[-1].no)->type->name);
							printf("return type error --> main\n");
							exit(1);
						}
					}
					else
					{
						if(strcmp((yyvsp[-1].no)->type->name,func_->type->name)!=0)
						{
							printf("return type error --> %s\n",mem_func->name);
							exit(1);
						}
					}
				}
				(yyval.no) =create_tree(0,TLookup("void"),NULL,ret_node,(yyvsp[-1].no),NULL,NULL);

				}
#line 2405 "y.tab.c"
    break;

  case 79: /* Slist: Slist Stmt  */
#line 656 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,conn_node,(yyvsp[-1].no),(yyvsp[0].no),NULL);}
#line 2411 "y.tab.c"
    break;

  case 80: /* Slist: Stmt  */
#line 657 "task.y"
                                {(yyval.no) =(yyvsp[0].no);}
#line 2417 "y.tab.c"
    break;

  case 81: /* Stmt: Assign_stmt  */
#line 659 "task.y"
                  {(yyval.no)=(yyvsp[0].no);}
#line 2423 "y.tab.c"
    break;

  case 82: /* Stmt: Inp_stmt  */
#line 660 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2429 "y.tab.c"
    break;

  case 83: /* Stmt: out_stmt  */
#line 661 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2435 "y.tab.c"
    break;

  case 84: /* Stmt: Ifstmt  */
#line 662 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2441 "y.tab.c"
    break;

  case 85: /* Stmt: Whilestmt  */
#line 663 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2447 "y.tab.c"
    break;

  case 86: /* Stmt: class_stmts  */
#line 664 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2453 "y.tab.c"
    break;

  case 87: /* Stmt: BREAK ';'  */
#line 665 "task.y"
                   {(yyval.no)=create_tree(0,TLookup("void"),NULL,break_node,NULL,NULL,NULL);}
#line 2459 "y.tab.c"
    break;

  case 88: /* Stmt: CONTINUE ';'  */
#line 666 "task.y"
                     {(yyval.no)=create_tree(0,TLookup("void"),NULL,continue_node,NULL,NULL,NULL);}
#line 2465 "y.tab.c"
    break;

  case 89: /* Stmt: FREE '(' IDEN ')' ';'  */
#line 668 "task.y"
                            {typecheck((yyvsp[-2].no));(yyval.no)=create_tree(0,TLookup("void"),NULL,free_node,(yyvsp[-2].no),NULL,NULL);}
#line 2471 "y.tab.c"
    break;

  case 90: /* class_stmts: IDEN '=' NEW '(' IDEN ')' ';'  */
#line 672 "task.y"
                                {
					typecheck((yyvsp[-6].no));
					struct Classtable* ctemp=CLookup((yyvsp[-2].no)->varname);
					if(ctemp==NULL)
					{
						printf("class %s not found\n",ctemp->name);
						exit(1);
					}
					(yyvsp[-6].no)->Ctype=ctemp;
					(yyvsp[-2].no)->nodetype=new_node;
					(yyvsp[-2].no)->Ctype=ctemp;
					(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-6].no),(yyvsp[-2].no),NULL);
				}
#line 2489 "y.tab.c"
    break;

  case 91: /* class_stmts: FIELD '=' NEW '(' IDEN ')' ';'  */
#line 688 "task.y"
                                {
					struct Classtable* ctemp=CLookup((yyvsp[-2].no)->varname);
					if(ctemp==NULL)
					{
						printf("class %s not found\n",ctemp->name);
						exit(1);
					}
					(yyvsp[-6].no)->Ctype=ctemp;
					(yyvsp[-2].no)->nodetype=new_node;
					(yyvsp[-2].no)->Ctype=ctemp;
					(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-6].no),(yyvsp[-2].no),NULL);
				}
#line 2506 "y.tab.c"
    break;

  case 92: /* class_stmts: DELETE '(' FIELD ')' ';'  */
#line 702 "task.y"
                                {
					typecheck((yyvsp[-2].no));
					(yyval.no)=create_tree(0,TLookup("void"),NULL,del_node,(yyvsp[-2].no),NULL,NULL);
				}
#line 2515 "y.tab.c"
    break;

  case 93: /* Assign_stmt: IDEN '=' expr ';'  */
#line 709 "task.y"
                                {typecheck((yyvsp[-3].no));(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 2521 "y.tab.c"
    break;

  case 94: /* Assign_stmt: FIELD '=' expr ';'  */
#line 710 "task.y"
                          {(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 2527 "y.tab.c"
    break;

  case 95: /* Assign_stmt: IDEN '=' Heapstuff ';'  */
#line 711 "task.y"
                             {typecheck((yyvsp[-3].no));(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 2533 "y.tab.c"
    break;

  case 96: /* Inp_stmt: READ '(' IDEN ')' ';'  */
#line 713 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,read_node,(yyvsp[-2].no),NULL,NULL);}
#line 2539 "y.tab.c"
    break;

  case 97: /* out_stmt: WRITE '(' expr ')' ';'  */
#line 715 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,write_node,(yyvsp[-2].no),NULL,NULL);}
#line 2545 "y.tab.c"
    break;

  case 98: /* Heapstuff: INITIALIZE '(' ')'  */
#line 718 "task.y"
                             {(yyval.no)=create_tree(0,TLookup("int"),NULL,initia_node,NULL,NULL,NULL);}
#line 2551 "y.tab.c"
    break;

  case 99: /* Heapstuff: ALLOC '(' ')'  */
#line 719 "task.y"
                                    {(yyval.no)=create_tree(0,TLookup("void"),NULL,alloc_node,NULL,NULL,NULL);}
#line 2557 "y.tab.c"
    break;

  case 100: /* Ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 727 "task.y"
                                                      {(yyval.no)=create_tree(0,TLookup("void"),NULL,if_node,(yyvsp[-7].no),(yyvsp[-2].no),(yyvsp[-4].no));}
#line 2563 "y.tab.c"
    break;

  case 101: /* Ifstmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 728 "task.y"
                                            {(yyval.no)=create_tree(0,TLookup("void"),NULL,if_node,(yyvsp[-5].no),NULL,(yyvsp[-2].no));}
#line 2569 "y.tab.c"
    break;

  case 102: /* Whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 731 "task.y"
                                                  {(yyval.no)= create_tree(0,TLookup("void"),NULL,while_node,(yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2575 "y.tab.c"
    break;

  case 103: /* expr: expr PLUS expr  */
#line 734 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"+",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2581 "y.tab.c"
    break;

  case 104: /* expr: expr MINUS expr  */
#line 735 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"-",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2587 "y.tab.c"
    break;

  case 105: /* expr: expr MUL expr  */
#line 736 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"*",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2593 "y.tab.c"
    break;

  case 106: /* expr: expr DIV expr  */
#line 737 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"/",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2599 "y.tab.c"
    break;

  case 107: /* expr: expr MOD expr  */
#line 738 "task.y"
                        {(yyval.no) = create_tree(0,TLookup("int"),"%",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2605 "y.tab.c"
    break;

  case 108: /* expr: expr GT expr  */
#line 739 "task.y"
                      {(yyval.no)=create_tree(0,TLookup("bool"),">",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2611 "y.tab.c"
    break;

  case 109: /* expr: expr LT expr  */
#line 740 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"<",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2617 "y.tab.c"
    break;

  case 110: /* expr: expr GE expr  */
#line 741 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),">=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2623 "y.tab.c"
    break;

  case 111: /* expr: expr LE expr  */
#line 742 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"<=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2629 "y.tab.c"
    break;

  case 112: /* expr: expr EQ expr  */
#line 743 "task.y"
                      {	(yyval.no) =create_tree(0,TLookup("bool"),"==",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2635 "y.tab.c"
    break;

  case 113: /* expr: expr NE expr  */
#line 744 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"!=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2641 "y.tab.c"
    break;

  case 114: /* expr: expr ANDTKN expr  */
#line 745 "task.y"
                          {(yyval.no) =create_tree(0,TLookup("bool"),"&&",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2647 "y.tab.c"
    break;

  case 115: /* expr: expr ORTKN expr  */
#line 746 "task.y"
                         {(yyval.no) =create_tree(0,TLookup("bool"),"||",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2653 "y.tab.c"
    break;

  case 116: /* expr: NOTTKN expr  */
#line 747 "task.y"
                     {(yyval.no) =create_tree(0,TLookup("bool"),"!",log_node,(yyvsp[0].no),NULL,NULL);}
#line 2659 "y.tab.c"
    break;

  case 117: /* expr: '(' expr ')'  */
#line 748 "task.y"
                                {(yyval.no)=(yyvsp[-1].no);}
#line 2665 "y.tab.c"
    break;

  case 118: /* expr: IDEN  */
#line 749 "task.y"
                                {(yyval.no)=(yyvsp[0].no);typecheck((yyval.no));}
#line 2671 "y.tab.c"
    break;

  case 119: /* expr: NUM  */
#line 750 "task.y"
                                {(yyval.no)=create_tree((yyvsp[0].numb),TLookup("int"),NULL,iconst_node,NULL,NULL,NULL);}
#line 2677 "y.tab.c"
    break;

  case 120: /* expr: MESG  */
#line 751 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("str"),(yyvsp[0].name),sconst_node,NULL,NULL,NULL);}
#line 2683 "y.tab.c"
    break;

  case 121: /* expr: ID '(' ArgList ')'  */
#line 753 "task.y"
                      {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[-3].name),func_node,(yyvsp[-1].no),NULL,NULL);}
#line 2689 "y.tab.c"
    break;

  case 122: /* expr: FIELD  */
#line 754 "task.y"
                {(yyval.no)= (yyvsp[0].no);}
#line 2695 "y.tab.c"
    break;

  case 123: /* expr: FieldFunction  */
#line 755 "task.y"
                       {(yyval.no)=(yyvsp[0].no);}
#line 2701 "y.tab.c"
    break;

  case 124: /* expr: NULLTKN  */
#line 756 "task.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2707 "y.tab.c"
    break;

  case 125: /* ArgList: expr ',' ArgList  */
#line 758 "task.y"
                           {(yyvsp[-2].no)->arg =(yyvsp[0].no);(yyval.no)=(yyvsp[-2].no);}
#line 2713 "y.tab.c"
    break;

  case 126: /* ArgList: expr  */
#line 759 "task.y"
               {(yyval.no)=(yyvsp[0].no);(yyval.no)->arg=NULL;}
#line 2719 "y.tab.c"
    break;

  case 127: /* ArgList: %empty  */
#line 760 "task.y"
                  {(yyval.no) =NULL;}
#line 2725 "y.tab.c"
    break;

  case 128: /* IDEN: ID  */
#line 762 "task.y"
          {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[0].name),var_node,NULL,NULL,NULL);}
#line 2731 "y.tab.c"
    break;

  case 129: /* IDEN: ID '[' expr ']'  */
#line 764 "task.y"
                              {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[-3].name),arr_node,(yyvsp[-1].no),NULL,NULL);}
#line 2737 "y.tab.c"
    break;


#line 2741 "y.tab.c"

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

#line 766 "task.y"

int yyerror(char const *s)
{
	printf("yyerror %s-->%d\n",s,ins_cnt);
}
int main()
{
	yyin=fopen("inp.expl","r");
	FILE *fp =fopen("task.xsm","wt");
	yyparse();
	return 0;
}
