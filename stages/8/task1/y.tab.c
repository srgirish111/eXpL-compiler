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
    EXTENDS = 304,                 /* EXTENDS  */
    MOD = 305                      /* MOD  */
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
#define EXTENDS 304
#define MOD 305

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

#line 256 "y.tab.c"

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
  YYSYMBOL_EXTENDS = 49,                   /* EXTENDS  */
  YYSYMBOL_MOD = 50,                       /* MOD  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* '.'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_60_ = 60,                       /* '='  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_Program = 62,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 63,              /* TypeDefBlock  */
  YYSYMBOL_TYPE_TKN = 64,                  /* TYPE_TKN  */
  YYSYMBOL_TypeDefList = 65,               /* TypeDefList  */
  YYSYMBOL_Type_name = 66,                 /* Type_name  */
  YYSYMBOL_TypeDef = 67,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 68,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 69,                 /* FieldDecl  */
  YYSYMBOL_TypeName = 70,                  /* TypeName  */
  YYSYMBOL_ClassDefBlock = 71,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 72,              /* ClassDefList  */
  YYSYMBOL_Classdef = 73,                  /* Classdef  */
  YYSYMBOL_Cname = 74,                     /* Cname  */
  YYSYMBOL_Fieldlists = 75,                /* Fieldlists  */
  YYSYMBOL_Fld = 76,                       /* Fld  */
  YYSYMBOL_MethodDecl = 77,                /* MethodDecl  */
  YYSYMBOL_MDecl = 78,                     /* MDecl  */
  YYSYMBOL_MethodDefns = 79,               /* MethodDefns  */
  YYSYMBOL_FieldFunction = 80,             /* FieldFunction  */
  YYSYMBOL_FIELD = 81,                     /* FIELD  */
  YYSYMBOL_GdeclBlock = 82,                /* GdeclBlock  */
  YYSYMBOL_GNULL_TKN = 83,                 /* GNULL_TKN  */
  YYSYMBOL_GdeclList = 84,                 /* GdeclList  */
  YYSYMBOL_GDecl = 85,                     /* GDecl  */
  YYSYMBOL_GType = 86,                     /* GType  */
  YYSYMBOL_GidList = 87,                   /* GidList  */
  YYSYMBOL_Gid = 88,                       /* Gid  */
  YYSYMBOL_FdefBlock = 89,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 90,                      /* Fdef  */
  YYSYMBOL_Ftype_param = 91,               /* Ftype_param  */
  YYSYMBOL_ParamList = 92,                 /* ParamList  */
  YYSYMBOL_Param = 93,                     /* Param  */
  YYSYMBOL_Ptype = 94,                     /* Ptype  */
  YYSYMBOL_LdeclBlock = 95,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 96,                  /* LDecList  */
  YYSYMBOL_LDecl = 97,                     /* LDecl  */
  YYSYMBOL_IdList = 98,                    /* IdList  */
  YYSYMBOL_Type = 99,                      /* Type  */
  YYSYMBOL_MainBlock = 100,                /* MainBlock  */
  YYSYMBOL_Type_main = 101,                /* Type_main  */
  YYSYMBOL_Body = 102,                     /* Body  */
  YYSYMBOL_Rstmt = 103,                    /* Rstmt  */
  YYSYMBOL_Slist = 104,                    /* Slist  */
  YYSYMBOL_Stmt = 105,                     /* Stmt  */
  YYSYMBOL_class_stmts = 106,              /* class_stmts  */
  YYSYMBOL_Assign_stmt = 107,              /* Assign_stmt  */
  YYSYMBOL_Inp_stmt = 108,                 /* Inp_stmt  */
  YYSYMBOL_out_stmt = 109,                 /* out_stmt  */
  YYSYMBOL_Heapstuff = 110,                /* Heapstuff  */
  YYSYMBOL_Ifstmt = 111,                   /* Ifstmt  */
  YYSYMBOL_Whilestmt = 112,                /* Whilestmt  */
  YYSYMBOL_expr = 113,                     /* expr  */
  YYSYMBOL_ArgList = 114,                  /* ArgList  */
  YYSYMBOL_IDEN = 115                      /* IDEN  */
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
#define YYLAST   506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
      54,    55,     2,     2,    57,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,    60,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    51,    52,    56,    66,    76,    78,    79,
      81,    82,    90,    92,    95,   101,   102,   103,   111,   112,
     114,   115,   118,   131,   132,   143,   144,   147,   152,   153,
     156,   170,   171,   176,   198,   233,   270,   298,   357,   405,
     408,   410,   411,   411,   412,   413,   415,   419,   437,   439,
     441,   442,   443,   447,   447,   449,   476,   497,   518,   520,
     521,   524,   527,   528,   529,   538,   544,   549,   549,   551,
     553,   554,   558,   560,   564,   582,   606,   621,   622,   627,
     633,   670,   671,   673,   674,   675,   676,   677,   678,   679,
     680,   682,   685,   701,   715,   723,   724,   725,   727,   733,
     740,   743,   744,   752,   753,   756,   759,   760,   761,   762,
     763,   764,   765,   766,   767,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   778,   779,   780,   781,   783,   784,
     785,   787,   789
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
  "NEW", "DELETE", "EXTENDS", "MOD", "'{'", "'}'", "';'", "'('", "')'",
  "'.'", "','", "'['", "']'", "'='", "$accept", "Program", "TypeDefBlock",
  "TYPE_TKN", "TypeDefList", "Type_name", "TypeDef", "FieldDeclList",
  "FieldDecl", "TypeName", "ClassDefBlock", "ClassDefList", "Classdef",
  "Cname", "Fieldlists", "Fld", "MethodDecl", "MDecl", "MethodDefns",
  "FieldFunction", "FIELD", "GdeclBlock", "GNULL_TKN", "GdeclList",
  "GDecl", "GType", "GidList", "Gid", "FdefBlock", "Fdef", "Ftype_param",
  "ParamList", "Param", "Ptype", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "Type", "MainBlock", "Type_main", "Body", "Rstmt", "Slist",
  "Stmt", "class_stmts", "Assign_stmt", "Inp_stmt", "out_stmt",
  "Heapstuff", "Ifstmt", "Whilestmt", "expr", "ArgList", "IDEN", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-240)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,  -240,    16,    12,    14,  -240,    35,   118,  -240,     3,
       0,  -240,    25,     2,  -240,    32,  -240,  -240,  -240,   118,
      47,    54,  -240,    59,  -240,  -240,   137,    92,  -240,  -240,
     108,   118,  -240,    98,    34,  -240,    57,  -240,   100,  -240,
    -240,  -240,   109,   137,   136,  -240,  -240,  -240,  -240,     7,
     140,  -240,  -240,  -240,  -240,    63,  -240,   170,   148,  -240,
    -240,   155,   137,   387,    93,   190,   172,   139,  -240,  -240,
      -5,    41,  -240,     7,  -240,   183,  -240,   103,  -240,   184,
     185,   186,   199,   201,   208,   204,   279,   209,   211,   210,
      62,   252,   387,  -240,  -240,  -240,  -240,  -240,  -240,  -240,
     126,  -240,   124,  -240,   245,   226,  -240,  -240,  -240,  -240,
      20,  -240,   249,   139,   280,  -240,   170,   190,   232,   120,
     118,   256,  -240,   -18,   279,   279,   279,  -240,  -240,   279,
    -240,  -240,   160,   279,  -240,   233,   279,  -240,   234,   323,
     235,   260,   260,   -18,   260,   116,  -240,   269,  -240,   260,
     272,  -240,  -240,  -240,   163,  -240,  -240,   139,  -240,    42,
     236,  -240,   242,  -240,  -240,   139,     5,  -240,   264,   243,
     125,   167,   171,   224,   230,     4,   279,    66,   260,   251,
     260,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,  -240,   260,   244,  -240,   177,   246,
    -240,   253,   330,  -240,  -240,   254,   263,   266,   247,   350,
    -240,   273,  -240,  -240,  -240,  -240,    79,  -240,  -240,   261,
     268,   270,   287,   309,  -240,   122,   276,   278,  -240,   284,
      11,    11,  -240,  -240,    66,    66,    66,    66,    66,    66,
      66,    66,  -240,   285,   293,   300,   260,  -240,   305,   306,
     260,  -240,  -240,  -240,   310,  -240,  -240,  -240,   458,   458,
     279,  -240,   279,   279,   279,  -240,  -240,   307,  -240,  -240,
     319,  -240,   379,   414,  -240,   320,   322,   324,   311,   325,
     458,   328,   329,  -240,  -240,  -240,  -240,  -240,   439,  -240,
    -240,   331,  -240
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     7,     0,    19,     0,     1,     0,    41,    10,     0,
       0,     9,    23,     0,    21,     0,    72,    73,    74,     0,
       0,     0,     4,     0,     5,     8,     0,     0,    18,    20,
       0,     0,    54,     0,     0,     3,     0,    77,     0,    15,
      16,    17,     0,    13,     0,    24,    26,    53,     2,     0,
       0,    45,    46,    40,    47,     0,    43,     0,     0,    11,
      12,     0,     0,     0,     0,     0,     0,    60,    39,    42,
      50,     0,    49,     0,    14,     0,    25,     0,    29,     0,
       0,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,     0,    82,    88,    83,    84,    85,    86,    87,
       0,    66,     0,    68,     0,     0,    56,    62,    63,    64,
       0,    59,     0,    60,     0,    44,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,    90,    89,     0,
     122,   123,   131,     0,   127,     0,     0,   126,   125,     0,
     121,     0,     0,     0,     0,     0,    79,     0,    81,     0,
       0,    65,    67,    71,     0,    55,    57,     0,    61,     0,
       0,    48,     0,    76,    27,    60,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   119,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    38,     0,     0,
      37,     0,     0,    78,    36,     0,     0,     0,     0,     0,
      69,     0,    58,    52,    51,    75,     0,    22,    31,     0,
       0,     0,     0,     0,   132,   129,     0,    38,   120,    37,
     106,   107,   108,   109,   111,   112,   113,   114,   115,   116,
     117,   118,   110,    36,     0,     0,     0,    96,     0,     0,
       0,    97,    95,    70,     0,    99,    98,   100,     0,     0,
     130,   124,   130,   130,   130,    91,    94,     0,   101,   102,
       0,    30,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    35,    34,    93,    92,     0,   104,
     105,     0,   103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -240,  -240,  -240,  -240,  -240,  -240,   381,   351,  -240,   -50,
    -240,  -240,   385,  -240,  -240,  -240,  -240,   332,  -240,  -240,
     -61,  -240,  -240,  -240,   344,  -240,  -240,   286,  -240,   -28,
    -240,  -100,   250,  -240,   333,  -240,   308,  -240,    -6,    19,
    -240,   -58,   316,  -239,   -88,  -240,  -240,  -240,  -240,  -240,
    -240,  -240,   -81,   -59,   -63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,     9,    10,    11,    42,    43,    44,
       7,    13,    14,    15,    62,    76,    77,    78,   166,   137,
     138,    19,    20,    55,    56,    57,    71,    72,    31,    32,
      33,   110,   111,   112,    65,   102,   103,   154,    34,    22,
      23,    66,    91,    92,    93,    94,    95,    96,    97,   208,
      98,    99,   225,   226,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     100,    21,    90,    47,   148,   139,     1,   105,   181,   182,
     183,   184,    75,   159,    85,   118,     5,   183,   184,   272,
     273,   185,   186,   187,   188,   189,   190,   121,    88,   100,
      63,    90,    16,    17,    12,     8,    64,    18,    35,   191,
     192,   288,    24,   172,   173,   174,     8,    28,   175,   113,
      48,    26,   177,   114,   193,   179,     6,   217,   104,   162,
     171,   193,   170,   224,   202,   216,    50,    12,    37,   209,
     181,   182,   183,   184,    27,   156,    36,   157,   196,   197,
     199,   200,   198,    30,    51,    52,   204,    53,    37,    54,
      51,    52,   167,    68,   115,    54,   104,   213,   116,   157,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    38,   168,   227,   193,   229,   144,   130,
      16,    17,   145,   101,    45,    18,   181,   182,   183,   184,
      39,    40,   243,   120,   254,    41,   157,    46,   218,   185,
     186,   187,   188,   189,   190,    16,    17,   131,   132,    49,
      18,    16,    17,   133,   151,    58,    18,   191,   192,   134,
     168,    59,   135,   201,    39,    40,   107,   108,    61,    41,
     136,   109,   193,   164,   165,   181,   182,   183,   184,   260,
     219,   144,   149,   267,   148,   148,   150,   270,   185,   186,
     187,   188,   189,   190,    67,   100,   100,    90,    90,    73,
     148,   274,    70,   275,   276,   277,   191,   192,    74,   100,
     100,    90,    90,    63,   176,   119,   210,   100,   129,    90,
     211,   193,   220,   149,   106,   100,   221,    90,   181,   182,
     183,   184,   245,   144,   181,   182,   183,   184,   123,   124,
     125,   185,   186,   187,   188,   189,   190,   185,   186,   187,
     188,   189,   190,   126,   127,   181,   182,   183,   184,   191,
     192,   128,   129,   141,   143,   191,   192,   142,   185,   186,
     187,   188,   189,   190,   193,   130,   146,   153,   155,   222,
     193,   158,   130,   160,   163,   223,   191,   192,   169,   178,
     180,   195,    85,   203,   215,   214,    50,   165,   258,   244,
     251,   193,   149,   131,   132,   253,   228,   246,   248,   133,
     131,   132,   205,   206,   255,   134,   133,   249,   135,   207,
     250,   256,   134,   257,   259,   135,   136,   181,   182,   183,
     184,   261,   262,   136,   181,   182,   183,   184,   263,   264,
     185,   186,   187,   188,   189,   190,   265,   185,   186,   187,
     188,   189,   190,   266,   181,   182,   183,   184,   191,   192,
     268,   269,   278,   271,   286,   191,   192,   185,   186,   187,
     188,   189,   190,   193,   279,   283,   194,   284,   287,   285,
     193,   289,   290,   247,   292,   191,   192,    79,    80,    81,
      25,   280,   281,    82,    60,    79,    80,    81,    29,    69,
     193,    82,   161,   252,    83,    84,   117,   212,   147,   122,
     152,    85,    83,    84,     0,     0,     0,     0,     0,    85,
      86,    87,    79,    80,    81,    88,     0,    89,    82,    87,
     282,     0,     0,    88,     0,    89,     0,     0,     0,    83,
      84,     0,     0,     0,     0,     0,    85,    79,    80,    81,
       0,     0,   291,    82,     0,     0,    87,     0,     0,     0,
      88,     0,    89,     0,    83,    84,    79,    80,    81,     0,
       0,    85,    82,     0,     0,     0,     0,     0,     0,     0,
       0,    87,     0,    83,    84,    88,     0,    89,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,     0,    88,     0,    89
};

static const yytype_int16 yycheck[] =
{
      63,     7,    63,    31,    92,    86,    38,    65,     4,     5,
       6,     7,    62,   113,    32,    73,     0,     6,     7,   258,
     259,    17,    18,    19,    20,    21,    22,    77,    46,    92,
      23,    92,    27,    28,    32,    32,    29,    32,    19,    35,
      36,   280,    39,   124,   125,   126,    32,    45,   129,    54,
      31,    51,   133,    58,    50,   136,    44,    52,    64,   117,
     123,    50,   123,    59,   145,   165,    32,    32,    34,   150,
       4,     5,     6,     7,    49,    55,    29,    57,   141,   142,
     143,   144,   143,    51,    27,    28,   149,    30,    34,    32,
      27,    28,   120,    30,    53,    32,   102,    55,    57,    57,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    54,   120,   178,    50,   180,    56,     3,
      27,    28,    60,    30,    32,    32,     4,     5,     6,     7,
      27,    28,   195,    30,    55,    32,    57,    29,   166,    17,
      18,    19,    20,    21,    22,    27,    28,    31,    32,    51,
      32,    27,    28,    37,    30,    55,    32,    35,    36,    43,
     166,    52,    46,    47,    27,    28,    27,    28,    32,    32,
      54,    32,    50,    53,    54,     4,     5,     6,     7,    57,
      55,    56,    56,   246,   272,   273,    60,   250,    17,    18,
      19,    20,    21,    22,    54,   258,   259,   258,   259,    51,
     288,   260,    32,   262,   263,   264,    35,    36,    53,   272,
     273,   272,   273,    23,    54,    32,    53,   280,    58,   280,
      57,    50,    55,    56,    52,   288,    55,   288,     4,     5,
       6,     7,    55,    56,     4,     5,     6,     7,    54,    54,
      54,    17,    18,    19,    20,    21,    22,    17,    18,    19,
      20,    21,    22,    54,    53,     4,     5,     6,     7,    35,
      36,    53,    58,    54,    54,    35,    36,    56,    17,    18,
      19,    20,    21,    22,    50,     3,    24,    32,    52,    55,
      50,    32,     3,     3,    52,    55,    35,    36,    32,    56,
      56,    56,    32,    24,    52,    59,    32,    54,    11,    55,
      53,    50,    56,    31,    32,    32,    55,    54,    54,    37,
      31,    32,    40,    41,    53,    43,    37,    54,    46,    47,
      54,    53,    43,    53,    15,    46,    54,     4,     5,     6,
       7,    55,    54,    54,     4,     5,     6,     7,    54,    54,
      17,    18,    19,    20,    21,    22,    53,    17,    18,    19,
      20,    21,    22,    53,     4,     5,     6,     7,    35,    36,
      55,    55,    55,    53,    53,    35,    36,    17,    18,    19,
      20,    21,    22,    50,    55,    55,    53,    55,    53,    55,
      50,    53,    53,    53,    53,    35,    36,     8,     9,    10,
       9,    12,    13,    14,    43,     8,     9,    10,    13,    55,
      50,    14,   116,    53,    25,    26,    73,   157,    92,    77,
     102,    32,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,
      33,    42,     8,     9,    10,    46,    -1,    48,    14,    42,
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
       0,    38,    62,    63,    64,     0,    44,    71,    32,    65,
      66,    67,    32,    72,    73,    74,    27,    28,    32,    82,
      83,    99,   100,   101,    39,    67,    51,    49,    45,    73,
      51,    89,    90,    91,    99,   100,    29,    34,    54,    27,
      28,    32,    68,    69,    70,    32,    29,    90,   100,    51,
      32,    27,    28,    30,    32,    84,    85,    86,    55,    52,
      68,    32,    75,    23,    29,    95,   102,    54,    30,    85,
      32,    87,    88,    51,    53,    70,    76,    77,    78,     8,
       9,    10,    14,    25,    26,    32,    33,    42,    46,    48,
      81,   103,   104,   105,   106,   107,   108,   109,   111,   112,
     115,    30,    96,    97,    99,   102,    52,    27,    28,    32,
      92,    93,    94,    54,    58,    53,    57,    95,   102,    32,
      30,    70,    78,    54,    54,    54,    54,    53,    53,    58,
       3,    31,    32,    37,    43,    46,    54,    80,    81,   113,
     115,    54,    56,    54,    56,    60,    24,   103,   105,    56,
      60,    30,    97,    32,    98,    52,    55,    57,    32,    92,
       3,    88,   102,    52,    53,    54,    79,    90,    99,    32,
      81,   115,   113,   113,   113,   113,    54,   113,    56,   113,
      56,     4,     5,     6,     7,    17,    18,    19,    20,    21,
      22,    35,    36,    50,    53,    56,   115,   115,    81,   115,
     115,    47,   113,    24,   115,    40,    41,    47,   110,   113,
      53,    57,    93,    55,    59,    52,    92,    52,    90,    55,
      55,    55,    55,    55,    59,   113,   114,   115,    55,   115,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   115,    55,    55,    54,    53,    54,    54,
      54,    53,    53,    32,    55,    53,    53,    53,    11,    15,
      57,    55,    54,    54,    54,    53,    53,   115,    55,    55,
     115,    53,   104,   104,   114,   114,   114,   114,    55,    55,
      12,    13,    16,    55,    55,    55,    53,    53,   104,    53,
      53,    13,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    63,    63,    64,    65,    65,
      66,    67,    68,    68,    69,    70,    70,    70,    71,    71,
      72,    72,    73,    74,    74,    75,    75,    76,    77,    77,
      78,    79,    79,    80,    80,    80,    81,    81,    81,    82,
      82,    83,    84,    84,    85,    86,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    90,    90,    91,    92,    92,
      92,    93,    94,    94,    94,    95,    95,    96,    96,    97,
      98,    98,    99,    99,    99,   100,   100,   101,   102,   102,
     103,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   106,   107,   107,   107,   108,   108,
     109,   110,   110,   111,   111,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   114,
     114,   115,   115
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     1,     2,     1,
       1,     4,     2,     1,     3,     1,     1,     1,     3,     0,
       2,     1,     8,     1,     3,     2,     0,     3,     2,     1,
       6,     2,     1,     6,     6,     6,     3,     3,     3,     4,
       3,     0,     2,     1,     3,     1,     1,     1,     3,     1,
       1,     4,     4,     2,     1,     5,     4,     5,     3,     1,
       0,     2,     1,     1,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     1,     1,     7,     6,     2,     4,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     5,     7,     7,     5,     4,     4,     4,     5,     5,
       5,     3,     3,    10,     8,     8,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     1,     4,     1,     1,     1,     3,     1,
       0,     1,     4
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
#line 1592 "y.tab.c"
    break;

  case 3: /* Program: TypeDefBlock ClassDefBlock GdeclBlock MainBlock  */
#line 51 "task.y"
                                                                                {}
#line 1598 "y.tab.c"
    break;

  case 4: /* Program: TypeDefBlock ClassDefBlock MainBlock  */
#line 52 "task.y"
                                                                        {}
#line 1604 "y.tab.c"
    break;

  case 5: /* TypeDefBlock: TYPE_TKN TypeDefList ENDTYPETKN  */
#line 57 "task.y"
                                {
						headergen();
						fp=fopen("task.xsm","a");
						//fprintf(fp,"PUSH R0\n");//Space for return value
						fprintf(fp,"JMP F0\n");
						fclose(fp);
						

				}
#line 1618 "y.tab.c"
    break;

  case 6: /* TypeDefBlock: %empty  */
#line 66 "task.y"
                {
					TypeTableCreate();
					headergen();
					fp=fopen("task.xsm","a");
					//fprintf(fp,"PUSH R0\n");//Space for return value
					fprintf(fp,"JMP F0\n");
					fclose(fp);
					
				}
#line 1632 "y.tab.c"
    break;

  case 7: /* TYPE_TKN: TYPETKN  */
#line 76 "task.y"
                   {TypeTableCreate();}
#line 1638 "y.tab.c"
    break;

  case 8: /* TypeDefList: TypeDefList TypeDef  */
#line 78 "task.y"
                                    {}
#line 1644 "y.tab.c"
    break;

  case 9: /* TypeDefList: TypeDef  */
#line 79 "task.y"
                        {}
#line 1650 "y.tab.c"
    break;

  case 10: /* Type_name: ID  */
#line 81 "task.y"
                {(yyval.typ) =TInstall((yyvsp[0].name),0,NULL);}
#line 1656 "y.tab.c"
    break;

  case 11: /* TypeDef: Type_name '{' FieldDeclList '}'  */
#line 82 "task.y"
                                                  { 
					(yyval.typ) = (yyvsp[-3].typ);
					(yyval.typ)->fields = (yyvsp[-1].field);
					(yyval.typ)->size = size;
					//print_type($$);
					size=0; }
#line 1667 "y.tab.c"
    break;

  case 12: /* FieldDeclList: FieldDecl FieldDeclList  */
#line 90 "task.y"
                                        {(yyvsp[-1].field)->next=(yyvsp[0].field);
					(yyval.field)=(yyvsp[-1].field);}
#line 1674 "y.tab.c"
    break;

  case 13: /* FieldDeclList: FieldDecl  */
#line 92 "task.y"
                          {(yyval.field) =(yyvsp[0].field);}
#line 1680 "y.tab.c"
    break;

  case 14: /* FieldDecl: TypeName ID ';'  */
#line 95 "task.y"
                                {
					(yyval.field) = Fcreate((yyvsp[-1].name),(yyvsp[-2].name));
					//printf("%s  %s\n",$1,$2);
					++size;
					}
#line 1690 "y.tab.c"
    break;

  case 15: /* TypeName: INT  */
#line 101 "task.y"
                   {(yyval.name)="int";}
#line 1696 "y.tab.c"
    break;

  case 16: /* TypeName: STR  */
#line 102 "task.y"
                   {(yyval.name)="str";}
#line 1702 "y.tab.c"
    break;

  case 17: /* TypeName: ID  */
#line 103 "task.y"
                  {(yyval.name)=(yyvsp[0].name);}
#line 1708 "y.tab.c"
    break;

  case 20: /* ClassDefList: ClassDefList Classdef  */
#line 114 "task.y"
                                        {}
#line 1714 "y.tab.c"
    break;

  case 21: /* ClassDefList: Classdef  */
#line 115 "task.y"
                           {}
#line 1720 "y.tab.c"
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
#line 1736 "y.tab.c"
    break;

  case 23: /* Cname: ID  */
#line 131 "task.y"
                            {Cptr = CInstall((yyvsp[0].name),NULL);}
#line 1742 "y.tab.c"
    break;

  case 24: /* Cname: ID EXTENDS ID  */
#line 132 "task.y"
                                {
					Cptr = CInstall((yyvsp[-2].name),(yyvsp[0].name));
					struct Classtable *paren;
					paren= Cptr->Parentptr;
					Cptr->Fieldcount=paren->Fieldcount;
					cls_fld_idx=paren->Fieldcount;
					Cptr->Methodcount=paren->Methodcount;
					cls_mtd_idx=paren->Methodcount;
					}
#line 1756 "y.tab.c"
    break;

  case 25: /* Fieldlists: Fieldlists Fld  */
#line 143 "task.y"
                                 {}
#line 1762 "y.tab.c"
    break;

  case 27: /* Fld: TypeName ID ';'  */
#line 147 "task.y"
                                   {Class_Finstall(Cptr,(yyvsp[-2].name),(yyvsp[-1].name),cls_fld_idx);
							++cls_fld_idx;
							}
#line 1770 "y.tab.c"
    break;

  case 28: /* MethodDecl: MethodDecl MDecl  */
#line 152 "task.y"
                                   {}
#line 1776 "y.tab.c"
    break;

  case 29: /* MethodDecl: MDecl  */
#line 153 "task.y"
                        {}
#line 1782 "y.tab.c"
    break;

  case 30: /* MDecl: TypeName ID '(' ParamList ')' ';'  */
#line 156 "task.y"
                                                    {
						struct Memberfunclist *met;
						met=NULL;
						if(Cptr->Parentptr!=NULL)
							met=Class_Mlookup(Cptr->Parentptr,(yyvsp[-4].name));

						Class_Minstall(Cptr,(yyvsp[-4].name),TLookup((yyvsp[-5].name)),(yyvsp[-2].par),cls_mtd_idx);
						if(met==NULL)
						++cls_mtd_idx;			
						//print_mthd(Cptr);
						}
#line 1798 "y.tab.c"
    break;

  case 33: /* FieldFunction: SELF '.' IDEN '(' ArgList ')'  */
#line 177 "task.y"
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
						(yyvsp[-3].no)->val= Mtemp->Funcposition;
						(yyvsp[-3].no)->nodetype =  self_meth_node;
						(yyvsp[-3].no)->left=(yyvsp[-1].no);
						(yyvsp[-3].no)->Ctype=Cptr;
						//$$=create_tree(0,TLookup("void"),"self",self_meth_node,NULL,NULL,$3);
						(yyval.no)=(yyvsp[-3].no);
						(yyval.no)->Lentry = LLookup("self");
                        (yyval.no)->type = Mtemp->type;
					}
#line 1824 "y.tab.c"
    break;

  case 34: /* FieldFunction: IDEN '.' IDEN '(' ArgList ')'  */
#line 199 "task.y"
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
						(yyvsp[-3].no)->val= Mtemp->Funcposition;
						(yyvsp[-3].no)->nodetype =  mth_call_node;
						(yyvsp[-3].no)->left=(yyvsp[-1].no);
						(yyval.no)=(yyvsp[-5].no);
						(yyval.no)->Lentry = NULL;
                        (yyval.no)->type = Mtemp->type;
						
					}
#line 1863 "y.tab.c"
    break;

  case 35: /* FieldFunction: FIELD '.' IDEN '(' ArgList ')'  */
#line 234 "task.y"
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
						(yyvsp[-3].no)->val= m->Funcposition;
						(yyvsp[-3].no)->nodetype =  mth_call_node;
						//$$->nodetype=self_meth_node;
						(yyvsp[-3].no)->left=(yyvsp[-1].no);
						(yyval.no)=(yyvsp[-5].no);
						//$$->Lentry = NULL; would be set to self
						//$$->Ctype =m->type
                        (yyval.no)->type = m->type;
					}
#line 1899 "y.tab.c"
    break;

  case 36: /* FIELD: IDEN '.' IDEN  */
#line 271 "task.y"
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
#line 1931 "y.tab.c"
    break;

  case 37: /* FIELD: FIELD '.' IDEN  */
#line 298 "task.y"
                           {  //can't occur in a class 
		  		if((yyval.no)->Ctype!=NULL)
				{
					//print_node($$);
					printf("%s\n",(yyval.no)->Ctype->name);
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
#line 1994 "y.tab.c"
    break;

  case 38: /* FIELD: SELF '.' IDEN  */
#line 358 "task.y"
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
#line 2025 "y.tab.c"
    break;

  case 39: /* GdeclBlock: GNULL_TKN DECL GdeclList ENDDECL  */
#line 405 "task.y"
                                              {
	//print_symbol_table();
	}
#line 2033 "y.tab.c"
    break;

  case 40: /* GdeclBlock: GNULL_TKN DECL ENDDECL  */
#line 408 "task.y"
                          {}
#line 2039 "y.tab.c"
    break;

  case 41: /* GNULL_TKN: %empty  */
#line 410 "task.y"
            {set_bind_addr();}
#line 2045 "y.tab.c"
    break;

  case 42: /* GdeclList: GdeclList GDecl  */
#line 411 "task.y"
                            {}
#line 2051 "y.tab.c"
    break;

  case 43: /* GdeclList: GDecl  */
#line 411 "task.y"
                                      {}
#line 2057 "y.tab.c"
    break;

  case 44: /* GDecl: GType GidList ';'  */
#line 412 "task.y"
                          {}
#line 2063 "y.tab.c"
    break;

  case 45: /* GType: INT  */
#line 413 "task.y"
                                                {currtype=TLookup("int");
								(yyval.typ) =currtype;}
#line 2070 "y.tab.c"
    break;

  case 46: /* GType: STR  */
#line 415 "task.y"
                                                {currtype=TLookup("str");
							 (yyval.typ) =currtype;
						
							}
#line 2079 "y.tab.c"
    break;

  case 47: /* GType: ID  */
#line 419 "task.y"
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
#line 2102 "y.tab.c"
    break;

  case 48: /* GidList: GidList ',' Gid  */
#line 437 "task.y"
                          {}
#line 2108 "y.tab.c"
    break;

  case 49: /* GidList: Gid  */
#line 439 "task.y"
                    {}
#line 2114 "y.tab.c"
    break;

  case 50: /* Gid: ID  */
#line 441 "task.y"
         {GInstall((yyvsp[0].name),currtype,1,NULL,currclass);}
#line 2120 "y.tab.c"
    break;

  case 51: /* Gid: ID '[' NUM ']'  */
#line 442 "task.y"
                      {GInstall((yyvsp[-3].name),currtype,(yyvsp[-1].numb),NULL,currclass);}
#line 2126 "y.tab.c"
    break;

  case 52: /* Gid: ID '(' ParamList ')'  */
#line 443 "task.y"
                            {GInstall((yyvsp[-3].name),currtype,-1,(yyvsp[-1].par),currclass);}
#line 2132 "y.tab.c"
    break;

  case 55: /* Fdef: Ftype_param '{' LdeclBlock Body '}'  */
#line 450 "task.y"
                {
			//codegen
			(yyval.no)= (yyvsp[-1].no);
			//print_lcl_tab();
			//printf("Abstract syntax tree created succesfully\n");
			
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//inorder($$);
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
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
#line 2162 "y.tab.c"
    break;

  case 56: /* Fdef: Ftype_param '{' Body '}'  */
#line 477 "task.y"
                {
			(yyval.no)=(yyvsp[-1].no);
			//printf("Abstract syntax tree created succesfully\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//inorder($$);
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("tree printed done\n");
			func_starter((yyvsp[-3].name));
			i=codegen((yyval.no));
			//codegen
			//deletetree($$);
			//printf("tree deleted\n");
			free_lcl_tab();
			//printf("lcl_tabfreed\n");
		}
#line 2186 "y.tab.c"
    break;

  case 57: /* Ftype_param: Type ID '(' ParamList ')'  */
#line 498 "task.y"
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
#line 2207 "y.tab.c"
    break;

  case 58: /* ParamList: ParamList ',' Param  */
#line 518 "task.y"
                                {PInstall((yyvsp[-2].par),(yyvsp[0].par));
								 (yyval.par) =(yyvsp[-2].par);}
#line 2214 "y.tab.c"
    break;

  case 59: /* ParamList: Param  */
#line 520 "task.y"
                        {(yyval.par) =(yyvsp[0].par);}
#line 2220 "y.tab.c"
    break;

  case 60: /* ParamList: %empty  */
#line 521 "task.y"
                      {(yyval.par)=NULL;}
#line 2226 "y.tab.c"
    break;

  case 61: /* Param: Ptype ID  */
#line 524 "task.y"
                 {(yyval.par) = create_par((yyvsp[0].name),(yyvsp[-1].typ));}
#line 2232 "y.tab.c"
    break;

  case 62: /* Ptype: INT  */
#line 527 "task.y"
                        {(yyval.typ)=TLookup("int"); }
#line 2238 "y.tab.c"
    break;

  case 63: /* Ptype: STR  */
#line 528 "task.y"
                                {(yyval.typ)=TLookup("str"); }
#line 2244 "y.tab.c"
    break;

  case 64: /* Ptype: ID  */
#line 529 "task.y"
                                {(yyval.typ)=TLookup((yyvsp[0].name)); }
#line 2250 "y.tab.c"
    break;

  case 65: /* LdeclBlock: DECL LDecList ENDDECL  */
#line 539 "task.y"
        {
		//printf("lcl_block done\n");
		

	}
#line 2260 "y.tab.c"
    break;

  case 66: /* LdeclBlock: DECL ENDDECL  */
#line 545 "task.y"
         {
		
	 }
#line 2268 "y.tab.c"
    break;

  case 67: /* LDecList: LDecList LDecl  */
#line 549 "task.y"
                          {}
#line 2274 "y.tab.c"
    break;

  case 68: /* LDecList: LDecl  */
#line 549 "task.y"
                                    {}
#line 2280 "y.tab.c"
    break;

  case 69: /* LDecl: Type IdList ';'  */
#line 551 "task.y"
                        {}
#line 2286 "y.tab.c"
    break;

  case 70: /* IdList: IdList ',' ID  */
#line 553 "task.y"
                      {LInstall((yyvsp[0].name),currtype);}
#line 2292 "y.tab.c"
    break;

  case 71: /* IdList: ID  */
#line 554 "task.y"
                     {LInstall((yyvsp[0].name),currtype);}
#line 2298 "y.tab.c"
    break;

  case 72: /* Type: INT  */
#line 558 "task.y"
                                                {currtype=TLookup("int");
								(yyval.typ) =currtype;}
#line 2305 "y.tab.c"
    break;

  case 73: /* Type: STR  */
#line 560 "task.y"
                                                {currtype=TLookup("str");
							 (yyval.typ) =currtype;
						
							}
#line 2314 "y.tab.c"
    break;

  case 74: /* Type: ID  */
#line 564 "task.y"
             {
			currtype = TLookup((yyvsp[0].name));
			if(currtype==NULL)
			{
				printf("type not declared --> %s\n",(yyvsp[0].name));
				exit(1);
			}
			(yyval.typ)=currtype;
			
		
		}
#line 2330 "y.tab.c"
    break;

  case 75: /* MainBlock: Type_main '(' ')' '{' LdeclBlock Body '}'  */
#line 583 "task.y"
        {		
			(yyval.no)=(yyvsp[-1].no);
			//print_lcl_tab();
			//printf("Abstract syntax tree created succesfully\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
		    //inorder($$);
			//printf("------------------------------------------\n");
		 	//printf("------------------------------------------\n");
			//printf("------------------------------------------\n");
			//printf("tree printed done\n");
			//inorder($$);
			//printf("tree printed\n");
			//codegen
			//$$->right->val=1;
			main_starter();
			i=codegen((yyval.no));
			//printf("xsm file generated\n");
			///
			//deletetree($$);
			free_lcl_tab();
	}
#line 2358 "y.tab.c"
    break;

  case 76: /* MainBlock: Type_main '(' ')' '{' Body '}'  */
#line 606 "task.y"
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
#line 2377 "y.tab.c"
    break;

  case 77: /* Type_main: Type MAINFN  */
#line 621 "task.y"
                        {func_= NULL;}
#line 2383 "y.tab.c"
    break;

  case 78: /* Body: PBEGIN Slist Rstmt PEND  */
#line 623 "task.y"
        {
		(yyval.no)=create_tree(0,TLookup("void"),NULL,conn_node,(yyvsp[-2].no),(yyvsp[-1].no),NULL);
	}
#line 2391 "y.tab.c"
    break;

  case 79: /* Body: PBEGIN Rstmt PEND  */
#line 628 "task.y"
        {
		(yyval.no)=(yyvsp[-1].no);
	}
#line 2399 "y.tab.c"
    break;

  case 80: /* Rstmt: RETURN expr ';'  */
#line 633 "task.y"
                        {
				(yyval.no) =create_tree(0,TLookup("void"),NULL,ret_node,(yyvsp[-1].no),NULL,NULL);
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
					if(func_==NULL) //main
					{
						(yyval.no)->val=1;
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

				}
#line 2437 "y.tab.c"
    break;

  case 81: /* Slist: Slist Stmt  */
#line 670 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,conn_node,(yyvsp[-1].no),(yyvsp[0].no),NULL);}
#line 2443 "y.tab.c"
    break;

  case 82: /* Slist: Stmt  */
#line 671 "task.y"
                                {(yyval.no) =(yyvsp[0].no);}
#line 2449 "y.tab.c"
    break;

  case 83: /* Stmt: Assign_stmt  */
#line 673 "task.y"
                  {(yyval.no)=(yyvsp[0].no);}
#line 2455 "y.tab.c"
    break;

  case 84: /* Stmt: Inp_stmt  */
#line 674 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2461 "y.tab.c"
    break;

  case 85: /* Stmt: out_stmt  */
#line 675 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2467 "y.tab.c"
    break;

  case 86: /* Stmt: Ifstmt  */
#line 676 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2473 "y.tab.c"
    break;

  case 87: /* Stmt: Whilestmt  */
#line 677 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2479 "y.tab.c"
    break;

  case 88: /* Stmt: class_stmts  */
#line 678 "task.y"
                      {(yyval.no)=(yyvsp[0].no);}
#line 2485 "y.tab.c"
    break;

  case 89: /* Stmt: BREAK ';'  */
#line 679 "task.y"
                   {(yyval.no)=create_tree(0,TLookup("void"),NULL,break_node,NULL,NULL,NULL);}
#line 2491 "y.tab.c"
    break;

  case 90: /* Stmt: CONTINUE ';'  */
#line 680 "task.y"
                     {(yyval.no)=create_tree(0,TLookup("void"),NULL,continue_node,NULL,NULL,NULL);}
#line 2497 "y.tab.c"
    break;

  case 91: /* Stmt: FREE '(' IDEN ')' ';'  */
#line 682 "task.y"
                            {typecheck((yyvsp[-2].no));(yyval.no)=create_tree(0,TLookup("void"),NULL,free_node,(yyvsp[-2].no),NULL,NULL);}
#line 2503 "y.tab.c"
    break;

  case 92: /* class_stmts: IDEN '=' NEW '(' IDEN ')' ';'  */
#line 686 "task.y"
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
#line 2521 "y.tab.c"
    break;

  case 93: /* class_stmts: FIELD '=' NEW '(' IDEN ')' ';'  */
#line 702 "task.y"
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
#line 2538 "y.tab.c"
    break;

  case 94: /* class_stmts: DELETE '(' FIELD ')' ';'  */
#line 716 "task.y"
                                {
					typecheck((yyvsp[-2].no));
					(yyval.no)=create_tree(0,TLookup("void"),NULL,del_node,(yyvsp[-2].no),NULL,NULL);
				}
#line 2547 "y.tab.c"
    break;

  case 95: /* Assign_stmt: IDEN '=' expr ';'  */
#line 723 "task.y"
                                {typecheck((yyvsp[-3].no));(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 2553 "y.tab.c"
    break;

  case 96: /* Assign_stmt: FIELD '=' expr ';'  */
#line 724 "task.y"
                          {(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 2559 "y.tab.c"
    break;

  case 97: /* Assign_stmt: IDEN '=' Heapstuff ';'  */
#line 725 "task.y"
                             {typecheck((yyvsp[-3].no));(yyval.no)=create_tree(0,TLookup("void"),"=",assg_node,(yyvsp[-3].no),(yyvsp[-1].no),NULL);}
#line 2565 "y.tab.c"
    break;

  case 98: /* Inp_stmt: READ '(' IDEN ')' ';'  */
#line 727 "task.y"
                                {
	typecheck((yyvsp[-2].no));
	(yyval.no)=create_tree(0,TLookup("void"),NULL,read_node,(yyvsp[-2].no),NULL,NULL);
	//printf("%s\n",$3->Gentry->name);
	}
#line 2575 "y.tab.c"
    break;

  case 99: /* Inp_stmt: READ '(' FIELD ')' ';'  */
#line 733 "task.y"
                                {
	//typecheck($3);
	(yyval.no)=create_tree(0,TLookup("void"),NULL,read_node,(yyvsp[-2].no),NULL,NULL);
	//printf("%s\n",$3->Gentry->name);
	}
#line 2585 "y.tab.c"
    break;

  case 100: /* out_stmt: WRITE '(' expr ')' ';'  */
#line 740 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("void"),NULL,write_node,(yyvsp[-2].no),NULL,NULL);}
#line 2591 "y.tab.c"
    break;

  case 101: /* Heapstuff: INITIALIZE '(' ')'  */
#line 743 "task.y"
                             {(yyval.no)=create_tree(0,TLookup("int"),NULL,initia_node,NULL,NULL,NULL);}
#line 2597 "y.tab.c"
    break;

  case 102: /* Heapstuff: ALLOC '(' ')'  */
#line 744 "task.y"
                                    {(yyval.no)=create_tree(0,TLookup("void"),NULL,alloc_node,NULL,NULL,NULL);}
#line 2603 "y.tab.c"
    break;

  case 103: /* Ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 752 "task.y"
                                                      {(yyval.no)=create_tree(0,TLookup("void"),NULL,if_node,(yyvsp[-7].no),(yyvsp[-2].no),(yyvsp[-4].no));}
#line 2609 "y.tab.c"
    break;

  case 104: /* Ifstmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 753 "task.y"
                                            {(yyval.no)=create_tree(0,TLookup("void"),NULL,if_node,(yyvsp[-5].no),NULL,(yyvsp[-2].no));}
#line 2615 "y.tab.c"
    break;

  case 105: /* Whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 756 "task.y"
                                                  {(yyval.no)= create_tree(0,TLookup("void"),NULL,while_node,(yyvsp[-5].no),(yyvsp[-2].no),NULL);}
#line 2621 "y.tab.c"
    break;

  case 106: /* expr: expr PLUS expr  */
#line 759 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"+",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2627 "y.tab.c"
    break;

  case 107: /* expr: expr MINUS expr  */
#line 760 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"-",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2633 "y.tab.c"
    break;

  case 108: /* expr: expr MUL expr  */
#line 761 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"*",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2639 "y.tab.c"
    break;

  case 109: /* expr: expr DIV expr  */
#line 762 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("int"),"/",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2645 "y.tab.c"
    break;

  case 110: /* expr: expr MOD expr  */
#line 763 "task.y"
                        {(yyval.no) = create_tree(0,TLookup("int"),"%",op_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2651 "y.tab.c"
    break;

  case 111: /* expr: expr GT expr  */
#line 764 "task.y"
                      {(yyval.no)=create_tree(0,TLookup("bool"),">",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2657 "y.tab.c"
    break;

  case 112: /* expr: expr LT expr  */
#line 765 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"<",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2663 "y.tab.c"
    break;

  case 113: /* expr: expr GE expr  */
#line 766 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),">=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2669 "y.tab.c"
    break;

  case 114: /* expr: expr LE expr  */
#line 767 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"<=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2675 "y.tab.c"
    break;

  case 115: /* expr: expr EQ expr  */
#line 768 "task.y"
                      {	(yyval.no) =create_tree(0,TLookup("bool"),"==",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2681 "y.tab.c"
    break;

  case 116: /* expr: expr NE expr  */
#line 769 "task.y"
                      {(yyval.no) =create_tree(0,TLookup("bool"),"!=",relop_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2687 "y.tab.c"
    break;

  case 117: /* expr: expr ANDTKN expr  */
#line 770 "task.y"
                          {(yyval.no) =create_tree(0,TLookup("bool"),"&&",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2693 "y.tab.c"
    break;

  case 118: /* expr: expr ORTKN expr  */
#line 771 "task.y"
                         {(yyval.no) =create_tree(0,TLookup("bool"),"||",log_node,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2699 "y.tab.c"
    break;

  case 119: /* expr: NOTTKN expr  */
#line 772 "task.y"
                     {(yyval.no) =create_tree(0,TLookup("bool"),"!",log_node,(yyvsp[0].no),NULL,NULL);}
#line 2705 "y.tab.c"
    break;

  case 120: /* expr: '(' expr ')'  */
#line 773 "task.y"
                                {(yyval.no)=(yyvsp[-1].no);}
#line 2711 "y.tab.c"
    break;

  case 121: /* expr: IDEN  */
#line 774 "task.y"
                                {(yyval.no)=(yyvsp[0].no);typecheck((yyval.no));}
#line 2717 "y.tab.c"
    break;

  case 122: /* expr: NUM  */
#line 775 "task.y"
                                {(yyval.no)=create_tree((yyvsp[0].numb),TLookup("int"),NULL,iconst_node,NULL,NULL,NULL);}
#line 2723 "y.tab.c"
    break;

  case 123: /* expr: MESG  */
#line 776 "task.y"
                                {(yyval.no)=create_tree(0,TLookup("str"),(yyvsp[0].name),sconst_node,NULL,NULL,NULL);}
#line 2729 "y.tab.c"
    break;

  case 124: /* expr: ID '(' ArgList ')'  */
#line 778 "task.y"
                      {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[-3].name),func_node,(yyvsp[-1].no),NULL,NULL);}
#line 2735 "y.tab.c"
    break;

  case 125: /* expr: FIELD  */
#line 779 "task.y"
                {(yyval.no)= (yyvsp[0].no);}
#line 2741 "y.tab.c"
    break;

  case 126: /* expr: FieldFunction  */
#line 780 "task.y"
                       {(yyval.no)=(yyvsp[0].no);}
#line 2747 "y.tab.c"
    break;

  case 127: /* expr: NULLTKN  */
#line 781 "task.y"
                 {(yyval.no)=(yyvsp[0].no);}
#line 2753 "y.tab.c"
    break;

  case 128: /* ArgList: expr ',' ArgList  */
#line 783 "task.y"
                           {(yyvsp[-2].no)->arg =(yyvsp[0].no);(yyval.no)=(yyvsp[-2].no);}
#line 2759 "y.tab.c"
    break;

  case 129: /* ArgList: expr  */
#line 784 "task.y"
               {(yyval.no)=(yyvsp[0].no);(yyval.no)->arg=NULL;}
#line 2765 "y.tab.c"
    break;

  case 130: /* ArgList: %empty  */
#line 785 "task.y"
                  {(yyval.no) =NULL;}
#line 2771 "y.tab.c"
    break;

  case 131: /* IDEN: ID  */
#line 787 "task.y"
          {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[0].name),var_node,NULL,NULL,NULL);}
#line 2777 "y.tab.c"
    break;

  case 132: /* IDEN: ID '[' expr ']'  */
#line 789 "task.y"
                              {(yyval.no)=create_tree(0,TLookup("void"),(yyvsp[-3].name),arr_node,(yyvsp[-1].no),NULL,NULL);}
#line 2783 "y.tab.c"
    break;


#line 2787 "y.tab.c"

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

#line 791 "task.y"

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
