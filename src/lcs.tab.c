/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1


/* "%code top" blocks.  */
#line 5 "lcs.y"

  #include "config.h"
  #include "lcs.lex.h"
  #include "ast.h"
  #include "symtable.h"


#line 62 "lcs.tab.c"





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

#include "lcs.tab.h"

/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NAMESPACE = 3,                  /* "namespace"  */
  YYSYMBOL_USING = 4,                      /* "using"  */
  YYSYMBOL_IDENTIFIER = 5,                 /* "identifier"  */
  YYSYMBOL_CONSTANT = 6,                   /* "constant"  */
  YYSYMBOL_STRING_LITERAL = 7,             /* "string literal"  */
  YYSYMBOL_SIZEOF = 8,                     /* "sizeof"  */
  YYSYMBOL_INC_OP = 9,                     /* "++"  */
  YYSYMBOL_DEC_OP = 10,                    /* "--"  */
  YYSYMBOL_LEFT_OP = 11,                   /* "<<"  */
  YYSYMBOL_RIGHT_OP = 12,                  /* ">>"  */
  YYSYMBOL_LE_OP = 13,                     /* "<="  */
  YYSYMBOL_GE_OP = 14,                     /* ">="  */
  YYSYMBOL_EQ_OP = 15,                     /* "=="  */
  YYSYMBOL_NE_OP = 16,                     /* "!="  */
  YYSYMBOL_AND_OP = 17,                    /* "&&"  */
  YYSYMBOL_OR_OP = 18,                     /* "||"  */
  YYSYMBOL_MUL_ASSIGN = 19,                /* "*="  */
  YYSYMBOL_DIV_ASSIGN = 20,                /* "/="  */
  YYSYMBOL_MOD_ASSIGN = 21,                /* "%="  */
  YYSYMBOL_ADD_ASSIGN = 22,                /* "+="  */
  YYSYMBOL_SUB_ASSIGN = 23,                /* "-="  */
  YYSYMBOL_LEFT_ASSIGN = 24,               /* "<<="  */
  YYSYMBOL_RIGHT_ASSIGN = 25,              /* ">>="  */
  YYSYMBOL_AND_ASSIGN = 26,                /* "&="  */
  YYSYMBOL_XOR_ASSIGN = 27,                /* "^="  */
  YYSYMBOL_OR_ASSIGN = 28,                 /* "|="  */
  YYSYMBOL_TYPE_NAME = 29,                 /* "type name"  */
  YYSYMBOL_ENUM = 30,                      /* "enum"  */
  YYSYMBOL_CASE = 31,                      /* "case"  */
  YYSYMBOL_DEFAULT = 32,                   /* "default"  */
  YYSYMBOL_IF = 33,                        /* "if"  */
  YYSYMBOL_ELSE = 34,                      /* "else"  */
  YYSYMBOL_SWITCH = 35,                    /* "switch"  */
  YYSYMBOL_WHILE = 36,                     /* "while"  */
  YYSYMBOL_DO = 37,                        /* "do"  */
  YYSYMBOL_FOR = 38,                       /* "for"  */
  YYSYMBOL_GOTO = 39,                      /* "goto"  */
  YYSYMBOL_CONTINUE = 40,                  /* "continue"  */
  YYSYMBOL_BREAK = 41,                     /* "break"  */
  YYSYMBOL_RETURN = 42,                    /* "return"  */
  YYSYMBOL_NEW = 43,                       /* "new"  */
  YYSYMBOL_CCODE = 44,                     /* "c code"  */
  YYSYMBOL_REFSYM = 45,                    /* ".."  */
  YYSYMBOL_PBLOCK = 46,                    /* "#if .. #endif"  */
  YYSYMBOL_CHRLIT = 47,                    /* "char literal"  */
  YYSYMBOL_PTYPE = 48,                     /* "primitive type"  */
  YYSYMBOL____LEN = 49,                    /* "___len"  */
  YYSYMBOL____PTR = 50,                    /* "___ptr"  */
  YYSYMBOL_STRING = 51,                    /* "String"  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_54_ = 54,                       /* "?:"  */
  YYSYMBOL_55_ = 55,                       /* "|"  */
  YYSYMBOL_56_ = 56,                       /* "^"  */
  YYSYMBOL_57_ = 57,                       /* "&"  */
  YYSYMBOL_58_ = 58,                       /* ">"  */
  YYSYMBOL_59_ = 59,                       /* '<'  */
  YYSYMBOL_60_ = 60,                       /* '-'  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '%'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_CAST = 65,                      /* CAST  */
  YYSYMBOL_66_ = 66,                       /* "!"  */
  YYSYMBOL_67_ = 67,                       /* "~"  */
  YYSYMBOL_NEG = 68,                       /* NEG  */
  YYSYMBOL_PREINCR = 69,                   /* PREINCR  */
  YYSYMBOL_PREDECR = 70,                   /* PREDECR  */
  YYSYMBOL_71_ = 71,                       /* "."  */
  YYSYMBOL_72_ = 72,                       /* "[]"  */
  YYSYMBOL_73_ = 73,                       /* "["  */
  YYSYMBOL_74_ = 74,                       /* "]"  */
  YYSYMBOL_75_ = 75,                       /* "("  */
  YYSYMBOL_76_ = 76,                       /* ")"  */
  YYSYMBOL_POSTINCR = 77,                  /* POSTINCR  */
  YYSYMBOL_POSTDECR = 78,                  /* POSTDECR  */
  YYSYMBOL_79_ = 79,                       /* ';'  */
  YYSYMBOL_80_ = 80,                       /* '.'  */
  YYSYMBOL_81_ = 81,                       /* '['  */
  YYSYMBOL_82_ = 82,                       /* ']'  */
  YYSYMBOL_83_ = 83,                       /* '{'  */
  YYSYMBOL_84_ = 84,                       /* '}'  */
  YYSYMBOL_85_ = 85,                       /* '('  */
  YYSYMBOL_86_ = 86,                       /* ')'  */
  YYSYMBOL_87_ = 87,                       /* '?'  */
  YYSYMBOL_88_ = 88,                       /* ':'  */
  YYSYMBOL_89_ = 89,                       /* '|'  */
  YYSYMBOL_90_ = 90,                       /* '^'  */
  YYSYMBOL_91_ = 91,                       /* '&'  */
  YYSYMBOL_92_ = 92,                       /* '>'  */
  YYSYMBOL_93_ = 93,                       /* '!'  */
  YYSYMBOL_94_ = 94,                       /* '~'  */
  YYSYMBOL_YYACCEPT = 95,                  /* $accept  */
  YYSYMBOL_translation_unit = 96,          /* translation_unit  */
  YYSYMBOL_namespace_decl = 97,            /* namespace_decl  */
  YYSYMBOL_ccode = 98,                     /* ccode  */
  YYSYMBOL_usings_list = 99,               /* usings_list  */
  YYSYMBOL_using_dir = 100,                /* using_dir  */
  YYSYMBOL_decl_or_func_or_code_list = 101, /* decl_or_func_or_code_list  */
  YYSYMBOL_decl_or_func_or_code = 102,     /* decl_or_func_or_code  */
  YYSYMBOL_type = 103,                     /* type  */
  YYSYMBOL_reftype = 104,                  /* reftype  */
  YYSYMBOL_decl = 105,                     /* decl  */
  YYSYMBOL_106_1 = 106,                    /* $@1  */
  YYSYMBOL_enumdecl = 107,                 /* enumdecl  */
  YYSYMBOL_enumdef = 108,                  /* enumdef  */
  YYSYMBOL_ecase_list = 109,               /* ecase_list  */
  YYSYMBOL_ecases = 110,                   /* ecases  */
  YYSYMBOL_ecase = 111,                    /* ecase  */
  YYSYMBOL_refdecl = 112,                  /* refdecl  */
  YYSYMBOL_refassign_list = 113,           /* refassign_list  */
  YYSYMBOL_expr_list_comma = 114,          /* expr_list_comma  */
  YYSYMBOL_refassign = 115,                /* refassign  */
  YYSYMBOL_slicedecl = 116,                /* slicedecl  */
  YYSYMBOL_sliceassign_list = 117,         /* sliceassign_list  */
  YYSYMBOL_sliceassign = 118,              /* sliceassign  */
  YYSYMBOL_valuetype = 119,                /* valuetype  */
  YYSYMBOL_valuedecl = 120,                /* valuedecl  */
  YYSYMBOL_assign_list = 121,              /* assign_list  */
  YYSYMBOL_assign = 122,                   /* assign  */
  YYSYMBOL_func = 123,                     /* func  */
  YYSYMBOL_funccall = 124,                 /* funccall  */
  YYSYMBOL_param_list = 125,               /* param_list  */
  YYSYMBOL_paramdecl = 126,                /* paramdecl  */
  YYSYMBOL_expr_list = 127,                /* expr_list  */
  YYSYMBOL_block = 128,                    /* block  */
  YYSYMBOL_stmts = 129,                    /* stmts  */
  YYSYMBOL_stmt = 130,                     /* stmt  */
  YYSYMBOL_qualidentifier = 131,           /* qualidentifier  */
  YYSYMBOL_expr = 132                      /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;


/* Unqualified %code blocks.  */
#line 54 "lcs.y"

  void yyerror(YYLTYPE *locp, yyscan_t scanner, char const *msg);

  #define GETLOC YYLTYPE* loc = yyget_lloc(scanner)
  #define NT(vv,...) vv = CreateNt(Generic, __VA_ARGS__); 
  #define NTT(kind,vv,...) vv = CreateNt(kind, __VA_ARGS__); 
  #define EMPTY(vv) { GETLOC; vv = CreateToken(Empty,"",0,loc->first_line,loc->first_column); }
  #define ST(name,sym) AddGSym(scanner, name, sym)
  #define STQ(name,sym) AddGSymQuoted(scanner, name, sym)

  void AddGSym(yyscan_t scanner,int i, SymKind t); 
  void AddGSymQuoted(yyscan_t scanner,int i, SymKind t);

#line 259 "lcs.tab.c"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
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

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2421

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325

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
       2,     2,     2,    93,     2,     2,     2,    62,    91,     2,
      85,    86,    63,    61,    52,    60,    80,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,    79,
      59,    53,    92,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    82,    90,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    89,    84,    94,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    54,    55,    56,
      57,    58,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    79,    80,    84,    88,    89,    93,    94,
      95,    99,   100,   104,   105,   106,   107,   108,   112,   113,
     117,   121,   122,   123,   124,   124,   128,   132,   136,   137,
     138,   142,   143,   147,   148,   153,   157,   158,   162,   163,
     167,   168,   169,   170,   171,   172,   176,   180,   181,   185,
     186,   187,   188,   189,   190,   194,   195,   196,   197,   201,
     202,   206,   207,   210,   211,   215,   216,   220,   221,   225,
     226,   227,   231,   232,   233,   234,   238,   239,   240,   244,
     248,   249,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   267,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321
};
#endif

#define YYPACT_NINF (-152)
#define YYTABLE_NINF (-145)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    19,    47,  -152,   -15,  -152,    61,  -152,    20,  -152,
     195,   -18,    57,     3,  -152,    67,  -152,  -152,    75,  -152,
    -152,  -152,    38,   152,  -152,   -20,  -152,  -152,  -152,   164,
    -152,  -152,   178,  -152,   185,  -152,   -40,   192,   118,  -152,
     114,   121,    -1,  -152,  -152,   203,   158,  -152,  -152,   133,
     318,   208,  -152,   209,   208,  -152,    35,   318,    91,   134,
    -152,   318,    92,    94,  -152,    -4,  -152,  -152,   318,   318,
    -152,   318,   318,   318,   318,   248,   318,   318,   318,  -152,
    -152,   -69,  1217,   216,    48,  -152,  -152,   -42,  -152,   179,
     150,   183,   188,   -37,   182,  -152,   318,  -152,   160,   516,
     247,  -152,   221,   106,  1301,   178,  -152,  -152,   318,   318,
      50,    58,    64,   364,   419,   970,    96,   572,  1316,  1400,
    1415,   318,   318,  -152,  -152,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     191,   193,   208,   181,   318,  -152,  -152,   209,   181,   318,
     189,   214,  1301,  -152,  -152,   222,   628,   203,  -152,  -152,
     404,   -32,   318,  -152,   460,   -31,  2284,  2298,   102,  2211,
    2127,  2192,  1182,   886,  1499,  1514,  1598,  1613,  1697,  1712,
    2225,   343,  2314,  2320,  1076,  2329,   684,  1796,  1811,  1895,
    1910,   187,   194,  -152,  -152,  -152,  1301,  -152,  -152,   740,
    -152,   318,    43,   225,  -152,   318,   227,   318,  -152,  1994,
     318,   233,  -152,   318,  -152,  -152,   200,   318,  1301,    95,
    -152,   318,  -152,   204,   796,   318,   852,   318,  2009,    36,
     205,   215,   217,   311,  -152,  -152,   908,   207,  -152,  -152,
    -152,    46,   992,  1013,   -26,   318,  -152,  2093,  -152,  2108,
     236,   318,   318,   318,  -152,  1097,  -152,  -152,  -152,    83,
    1118,  1202,   107,  -152,  -152,   181,   181,   318,   267,  -152,
     116,   181,   318,  -152,   -29,   181,  -152
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     6,     0,     1,    11,     4,     0,     7,
       2,     0,     0,     0,    56,     0,     5,    17,    55,    57,
      15,    12,     0,    19,    13,     0,    22,    16,    23,    18,
      21,    14,     0,     9,     0,    10,     0,     0,     0,    58,
       0,     0,     0,    36,    25,     0,    63,    61,    61,     0,
       0,    69,    93,    28,    69,    20,     0,     0,     0,     0,
      47,     0,     0,     0,     8,    96,    94,    95,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,   144,
      97,    98,    26,     0,     0,    19,    18,     0,    70,    33,
       0,    29,    31,     0,    43,    41,    76,    42,     0,     0,
       0,    35,     0,     0,    64,     0,    59,    60,     0,    76,
     139,   140,   107,   108,   135,   136,     0,     0,   141,   137,
     138,     0,    76,   142,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    72,     0,     0,     0,    27,    30,     0,     0,     0,
       0,    38,    77,    45,    37,    49,     0,     0,    46,    62,
       0,     0,     0,   100,     0,     0,   122,   121,   117,   118,
     115,   116,   111,   110,   103,   104,   106,   102,   105,   101,
     120,   124,   123,   125,   126,   127,     0,   112,   113,   114,
     119,     0,     0,    71,    80,    66,    34,    32,    65,     0,
      40,    39,     0,    50,    48,     0,   130,     0,    67,   128,
       0,   133,    68,     0,    75,    73,     0,     0,    78,     0,
      53,    76,    54,     0,     0,     0,     0,     0,   109,    96,
       0,     0,     0,     0,    82,    79,    92,     0,    84,    83,
      81,    98,     0,     0,     0,    76,   131,   129,   134,   132,
       0,     0,     0,    76,    89,     0,    85,    44,    52,     0,
       0,     0,     0,    88,    51,     0,     0,    76,    90,    86,
       0,     0,    76,    91,     0,     0,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -152,  -152,  -152,    -7,  -152,  -152,  -152,  -152,    -9,    -6,
      78,  -152,  -152,  -152,  -152,   148,  -152,  -152,  -152,  -152,
     210,  -152,  -152,   140,    -8,  -152,   263,    27,  -152,   -51,
     259,   167,  -103,  -151,  -152,  -152,   -10,   -39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    79,     6,     9,    10,    21,    84,    85,
      24,    25,    26,    27,    90,    91,    92,    28,    58,   160,
      43,    44,   103,    60,    86,    30,    62,    48,    31,    80,
      87,    88,   161,   205,   226,   250,    81,   162
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    22,    29,    20,    23,    97,   171,   208,    36,    14,
     152,    82,   121,    50,     1,   152,   122,    45,    99,   175,
     217,   217,   104,   217,     4,    11,   217,    12,    18,   110,
     111,    19,   112,   113,   114,   115,   117,   118,   119,   120,
      94,   260,    95,    40,   153,    51,    98,     5,   229,   158,
     230,    46,    56,   151,   218,   222,    47,   285,   268,   123,
     124,    33,    34,   166,     7,     8,   116,   123,   124,   170,
     134,   135,    38,   123,   124,   249,    37,   108,   134,   135,
      57,   109,   174,    37,   134,   135,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   123,   124,   125,   126,   206,    37,   108,    96,    41,
     209,   109,   134,   135,   278,   279,   231,   121,   254,    41,
     283,   122,   169,   219,   286,   217,    35,   145,    39,   146,
     147,   148,   149,   100,   105,   145,   105,   146,   147,   148,
     149,   145,   269,   146,   147,   148,   149,    42,   167,   217,
     272,   232,   140,   141,   142,   143,   144,   274,   217,    46,
     101,   106,   228,   107,   280,    37,   234,    41,   228,   284,
     109,   236,   172,    46,   238,   168,   277,   252,   253,   145,
      49,   146,   147,   148,   149,   282,   257,    52,   259,    54,
      13,    53,    98,    55,   265,   239,    66,    67,    59,    68,
      69,    61,    64,    83,    89,   102,   251,   247,    29,   246,
      23,   150,   270,   271,    14,    15,    65,    66,    67,    14,
      68,    69,   154,   240,   155,   156,   241,    14,   242,    16,
     157,    17,   243,    18,    16,   122,    19,    70,    18,    71,
      72,    19,    42,    65,    66,    67,    18,    68,    69,    19,
      73,    74,    37,   159,   204,    16,   211,   109,    70,   224,
      71,    72,   201,   210,   202,   212,   225,    14,   233,   244,
     235,    73,    74,   204,   245,    75,   237,   255,    41,    50,
     261,    76,    16,    77,    78,    70,    18,    71,    72,    19,
     262,   281,   263,   165,   248,   207,    75,   214,    73,    74,
     164,    63,    76,    93,    77,    78,    65,    66,    67,   203,
      68,    69,     0,    65,    66,    67,     0,    68,    69,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,    76,
       0,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,     0,    16,     0,     0,    70,     0,
      71,    72,    16,   134,   135,    70,     0,    71,    72,     0,
       0,    73,    74,   123,   124,     0,     0,     0,    73,    74,
       0,     0,     0,     0,   134,   135,     0,     0,     0,     0,
     264,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,     0,    76,    75,    77,    78,   143,   144,     0,    76,
       0,    77,    78,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   123,   124,
     145,     0,   146,   147,   148,   149,     0,     0,     0,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,   215,
       0,   145,     0,   146,   147,   148,   149,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,   216,     0,     0,     0,
       0,   145,     0,   146,   147,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   145,     0,   146,   147,
     148,   149,     0,   138,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,   221,     0,     0,     0,     0,   145,     0,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,   163,     0,
       0,     0,     0,   145,     0,   146,   147,   148,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,   173,   145,
       0,   146,   147,   148,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
     213,     0,     0,     0,     0,   145,     0,   146,   147,   148,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,   145,   223,   146,   147,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,   227,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,   256,     0,
       0,     0,     0,   145,     0,   146,   147,   148,   149,     0,
       0,     0,     0,     0,     0,   123,   124,   125,   126,   127,
     128,   129,   130,   131,     0,   138,   134,   135,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   -92,   -92,  -144,
    -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,  -144,
    -144,  -144,     0,     0,   258,     0,     0,     0,     0,   145,
       0,   146,   147,   148,   149,   139,   140,   141,   142,   143,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -144,     0,     0,     0,     0,     0,  -144,   -92,   -92,
    -144,  -144,  -144,   145,     0,   146,   147,   148,   149,   123,
     124,     0,     0,     0,     0,     0,     0,   -92,     0,     0,
     134,   135,     0,     0,     0,  -144,     0,  -144,  -144,   -92,
    -144,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,     0,   146,
     147,   148,   149,     0,     0,     0,   138,     0,     0,     0,
       0,   266,   139,   140,   141,   142,   143,   144,     0,   145,
       0,   146,   147,   148,   149,   123,   124,     0,     0,     0,
       0,     0,     0,     0,     0,   267,   134,   135,     0,     0,
     145,     0,   146,   147,   148,   149,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   139,   140,   141,   142,
     143,   144,     0,   145,     0,   146,   147,   148,   149,     0,
       0,   138,     0,     0,     0,     0,   273,   139,   140,   141,
     142,   143,   144,     0,   145,     0,   146,   147,   148,   149,
       0,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,   134,   135,   275,   145,     0,   146,   147,   148,
     149,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   139,   140,   141,   142,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,     0,     0,   145,
     138,   146,   147,   148,   149,     0,   139,   140,   141,   142,
     143,   144,     0,     0,     0,     0,     0,     0,   276,   145,
       0,   146,   147,   148,   149,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,   146,   147,   148,   149,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,     0,     0,     0,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,     0,     0,     0,     0,     0,     0,     0,   145,     0,
     146,   147,   148,   149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,   149,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   144,     0,     0,     0,   138,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
       0,     0,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,   149,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   145,     0,   146,   147,   148,   149,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,     0,     0,     0,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,   146,   147,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,   146,   147,   148,   149,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,     0,     0,     0,   138,     0,     0,     0,
       0,     0,   139,   140,   141,   142,   143,   144,     0,     0,
       0,     0,     0,     0,     0,   145,     0,   146,   147,   148,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,   146,   147,   148,   149,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   139,   140,   141,   142,
     143,   144,     0,     0,     0,   138,     0,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,     0,     0,     0,
       0,     0,     0,     0,   145,     0,   146,   147,   148,   149,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
       0,   146,   147,   148,   149,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,     0,     0,     0,   138,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,     0,     0,     0,     0,
       0,     0,     0,   145,     0,   146,   147,   148,   149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   145,     0,
     146,   147,   148,   149,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,     0,
       0,     0,     0,     0,   139,   140,   141,   142,   143,   144,
       0,     0,     0,   138,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   144,     0,     0,     0,     0,     0,
       0,     0,   145,     0,   146,   147,   148,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   145,     0,   146,
     147,   148,   149,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,     0,
       0,     0,   138,     0,     0,     0,     0,     0,   139,   140,
     141,   142,   143,   144,     0,     0,     0,     0,     0,     0,
       0,   145,     0,   146,   147,   148,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,   146,   147,
     148,   149,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,     0,   123,   124,   125,   126,
     127,   128,     0,     0,     0,     0,   138,   134,   135,     0,
       0,     0,   139,   140,   141,   142,   143,   144,     0,     0,
       0,   138,     0,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,     0,     0,     0,     0,     0,     0,     0,
     145,     0,   146,   147,   148,   149,   139,   140,   141,   142,
     143,   144,     0,     0,     0,   145,     0,   146,   147,   148,
     149,   123,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,   134,   135,   145,     0,   146,   147,   148,   149,
     123,   124,   125,   126,     0,     0,     0,     0,     0,     0,
       0,   134,   135,     0,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,     0,   134,   135,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   141,   142,   143,   144,     0,     0,     0,   145,
       0,   146,   147,   148,   149,   140,   141,   142,   143,   144,
       0,     0,     0,   123,   124,     0,     0,     0,   145,     0,
     146,   147,   148,   149,   134,   135,     0,   123,   124,     0,
       0,     0,   145,     0,   146,   147,   148,   149,   134,   135,
       0,     0,     0,   123,   124,     0,     0,     0,     0,   123,
     124,     0,     0,     0,   134,   135,     0,     0,   123,   124,
     134,   135,     0,     0,   140,   141,   142,   143,   144,   134,
     135,     0,     0,     0,     0,     0,     0,     0,   140,   141,
     142,   143,   144,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,   146,   147,   148,   149,   143,   144,     0,
       0,     0,     0,   143,   144,   145,     0,   146,   147,   148,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,     0,   146,   147,   148,   149,   145,     0,   146,
     147,   148,   149,     0,     0,     0,   145,     0,   146,   147,
     148,   149
};

static const yytype_int16 yycheck[] =
{
      10,    10,    10,    10,    10,    56,   109,   158,     5,    29,
      52,    50,    81,    53,     3,    52,    85,    25,    57,   122,
      52,    52,    61,    52,     5,     5,    52,     7,    48,    68,
      69,    51,    71,    72,    73,    74,    75,    76,    77,    78,
       5,     5,     7,     5,    86,    85,    56,     0,     5,    86,
       7,     5,    53,     5,    86,    86,    29,    86,    84,     9,
      10,    79,    80,   102,    79,     4,    75,     9,    10,   108,
      20,    21,     5,     9,    10,   226,    80,    81,    20,    21,
      81,    85,   121,    80,    20,    21,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,     9,    10,    11,    12,   154,    80,    81,    83,    81,
     159,    85,    20,    21,   275,   276,    83,    81,   231,    81,
     281,    85,   105,   172,   285,    52,    79,    87,    63,    89,
      90,    91,    92,    52,    52,    87,    52,    89,    90,    91,
      92,    87,   255,    89,    90,    91,    92,     5,    52,    52,
     263,   212,    60,    61,    62,    63,    64,    84,    52,     5,
      79,    79,   211,    79,   277,    80,   215,    81,   217,   282,
      85,   220,    86,     5,   223,    79,    79,   226,   227,    87,
       5,    89,    90,    91,    92,    79,   235,     5,   237,    85,
       5,    83,   212,    82,   243,     5,     6,     7,     5,     9,
      10,    53,    79,     5,     5,    81,   226,   226,   226,   226,
     226,     5,   261,   262,    29,    30,     5,     6,     7,    29,
       9,    10,    53,    33,    84,    52,    36,    29,    38,    44,
      52,    46,    42,    48,    44,    85,    51,    47,    48,    49,
      50,    51,     5,     5,     6,     7,    48,     9,    10,    51,
      60,    61,    80,    81,    83,    44,    52,    85,    47,    82,
      49,    50,    81,    84,    81,    53,    82,    29,    53,    79,
      53,    60,    61,    83,    84,    85,    53,    83,    81,    53,
      85,    91,    44,    93,    94,    47,    48,    49,    50,    51,
      85,    34,    85,    82,   226,   157,    85,   167,    60,    61,
     100,    48,    91,    54,    93,    94,     5,     6,     7,   152,
       9,    10,    -1,     5,     6,     7,    -1,     9,    10,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    -1,    44,    -1,    -1,    47,    -1,
      49,    50,    44,    20,    21,    47,    -1,    49,    50,    -1,
      -1,    60,    61,     9,    10,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    91,    85,    93,    94,    63,    64,    -1,    91,
      -1,    93,    94,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     9,    10,
      87,    -1,    89,    90,    91,    92,    -1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    87,    -1,    89,    90,    91,    92,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    82,    -1,    -1,    -1,
      -1,    87,    -1,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    87,    -1,    89,    90,
      91,    92,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    87,    -1,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      82,    -1,    -1,    -1,    -1,    87,    -1,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    88,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    82,    -1,
      -1,    -1,    -1,    87,    -1,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    53,    20,    21,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    82,    -1,    -1,    -1,    -1,    87,
      -1,    89,    90,    91,    92,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    87,    -1,    89,    90,    91,    92,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      20,    21,    -1,    -1,    -1,    87,    -1,    89,    90,    91,
      92,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    79,    59,    60,    61,    62,    63,    64,    -1,    87,
      -1,    89,    90,    91,    92,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    20,    21,    -1,    -1,
      87,    -1,    89,    90,    91,    92,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    87,    -1,    89,    90,    91,    92,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    79,    59,    60,    61,
      62,    63,    64,    -1,    87,    -1,    89,    90,    91,    92,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    86,    87,    -1,    89,    90,    91,
      92,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    -1,    -1,    87,
      53,    89,    90,    91,    92,    -1,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    89,    90,    91,    92,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      89,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    89,    90,    91,    92,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    89,    90,    91,    92,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    90,    91,    92,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    89,    90,    91,    92,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    89,    90,    91,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    89,    90,    91,    92,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    89,    90,    91,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      89,    90,    91,    92,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,
      90,    91,    92,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    90,
      91,    92,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    53,    20,    21,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    89,    90,    91,    92,    59,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    87,    -1,    89,    90,    91,
      92,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    21,    87,    -1,    89,    90,    91,    92,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    87,
      -1,    89,    90,    91,    92,    60,    61,    62,    63,    64,
      -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    87,    -1,
      89,    90,    91,    92,    20,    21,    -1,     9,    10,    -1,
      -1,    -1,    87,    -1,    89,    90,    91,    92,    20,    21,
      -1,    -1,    -1,     9,    10,    -1,    -1,    -1,    -1,     9,
      10,    -1,    -1,    -1,    20,    21,    -1,    -1,     9,    10,
      20,    21,    -1,    -1,    60,    61,    62,    63,    64,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    90,    91,    92,    63,    64,    -1,
      -1,    -1,    -1,    63,    64,    87,    -1,    89,    90,    91,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    90,    91,    92,    87,    -1,    89,
      90,    91,    92,    -1,    -1,    -1,    87,    -1,    89,    90,
      91,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    96,    97,     5,     0,    99,    79,     4,   100,
     101,     5,     7,     5,    29,    30,    44,    46,    48,    51,
      98,   102,   103,   104,   105,   106,   107,   108,   112,   119,
     120,   123,   131,    79,    80,    79,     5,    80,     5,    63,
       5,    81,     5,   115,   116,   119,     5,   122,   122,     5,
      53,    85,     5,    83,    85,    82,    53,    81,   113,     5,
     118,    53,   121,   121,    79,     5,     6,     7,     9,    10,
      47,    49,    50,    60,    61,    85,    91,    93,    94,    98,
     124,   131,   132,     5,   103,   104,   119,   125,   126,     5,
     109,   110,   111,   125,     5,     7,    83,   124,   131,   132,
      52,    79,    81,   117,   132,    52,    79,    79,    81,    85,
     132,   132,   132,   132,   132,   132,   103,   132,   132,   132,
     132,    81,    85,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    53,    59,
      60,    61,    62,    63,    64,    87,    89,    90,    91,    92,
       5,     5,    52,    86,    53,    84,    52,    52,    86,    81,
     114,   127,   132,    82,   115,    82,   132,    52,    79,   122,
     132,   127,    86,    86,   132,   127,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,    81,    81,   126,    83,   128,   132,   110,   128,   132,
      84,    52,    53,    82,   118,    45,    82,    52,    86,   132,
      45,    82,    86,    88,    82,    82,   129,    45,   132,     5,
       7,    83,   124,    53,   132,    53,   132,    53,   132,     5,
      33,    36,    38,    42,    79,    84,    98,   103,   105,   128,
     130,   131,   132,   132,   127,    83,    82,   132,    82,   132,
       5,    85,    85,    85,    79,   132,    79,    82,    84,   127,
     132,   132,   127,    79,    84,    86,    86,    79,   128,   128,
     127,    34,    79,   128,   127,    86,   128
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    97,    97,    98,    99,    99,   100,   100,
     100,   101,   101,   102,   102,   102,   102,   102,   103,   103,
     104,   105,   105,   105,   106,   105,   107,   108,   109,   109,
     109,   110,   110,   111,   111,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   116,   117,   117,   118,
     118,   118,   118,   118,   118,   119,   119,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   125,   126,   126,   126,   126,   127,   127,   127,   128,
     129,   129,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     3,     1,     0,     2,     5,     3,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     0,     2,     4,     5,     0,     1,
       2,     1,     3,     1,     3,     4,     0,     3,     1,     2,
       5,     3,     3,     3,     8,     4,     4,     0,     3,     3,
       4,     8,     7,     5,     5,     1,     1,     1,     2,     4,
       4,     0,     3,     1,     3,     6,     6,     4,     4,     0,
       1,     3,     2,     4,     2,     4,     0,     1,     3,     3,
       0,     2,     1,     1,     1,     2,     5,     9,     3,     2,
       5,     7,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     6,
       4,     6,     6,     4,     6,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       3,     4,     5,     6,     7,     8,     8,     9,     9,     9,
       9,    10,    10,    11,    11,    11,    12,    12,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,    10
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int16 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      25,     0,     0,     0,     0,     0,     0,    41,    43,     0,
      27,    29,     0,    59,    61,     0,     0,     0,    45,    47,
       0,    11,     0,     0,    63,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   329,   331,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   333,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    33,
      35,    37,    39,     0,     0,    49,     0,    51,    53,    55,
      57,    67,     0,    69,    71,    73,    75,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   337,
       0,   339,   341,   343,   345,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,   999,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     3,     0,     0,     5,     0,  1001,     0,
       0,  1003,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     941,     0,     0,     0,     0,     0,   997,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   635,   637,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   639,   641,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    95,    97,
     643,     0,   645,   647,   649,   651,     0,     0,     0,    99,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,    87,    89,    91,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   103,     0,   105,   107,
     109,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   419,   421,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   423,   425,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1059,  1061,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1063,  1065,
       0,     0,     0,   427,     0,   429,   431,   433,   435,   113,
     115,     0,     0,     0,     0,     0,     0,  1067,     0,     0,
     117,   119,     0,     0,     0,     0,     0,     0,     0,  1069,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,   123,
     125,   127,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   689,   691,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   693,   695,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   697,     0,   699,   701,   703,   705,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,   403,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   405,   407,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   409,
       0,   411,   413,   415,   417,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   155,   157,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,     0,     0,   163,   165,   167,   169,   171,
     173,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,   177,   179,   181,   183,   185,
     187,   189,   191,   193,   195,   197,   199,   201,   203,   205,
     207,   209,   211,   213,   239,   241,   243,   245,   247,   249,
     251,   253,   255,   257,   259,   261,   263,   265,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   215,     0,     0,     0,     0,     0,   217,
     219,   221,   223,   225,   227,     0,     0,     0,   269,     0,
       0,     0,     0,     0,   271,   273,   275,   277,   279,   281,
       0,     0,     0,     0,     0,     0,     0,   229,     0,   231,
     233,   235,   237,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,     0,   285,   287,   289,   291,   437,   439,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   441,
     443,     0,     0,   455,   457,   459,   461,   463,   465,   467,
     469,   471,   473,   475,   477,   479,   481,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,   487,   489,   491,   493,   495,   497,     0,
       0,     0,     0,     0,     0,     0,   445,     0,   447,   449,
     451,   453,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   499,     0,   501,   503,   505,   507,   509,   511,   513,
     515,   517,   519,   521,   523,   525,   527,   529,   531,   533,
     535,   537,   563,   565,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   567,   569,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,   541,   543,   545,
     547,   549,   551,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   553,     0,   555,   557,   559,
     561,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     571,     0,   573,   575,   577,   579,   581,   583,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   585,   587,     0,
       0,   599,   601,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   603,   605,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   589,     0,   591,   593,   595,   597,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   607,
       0,   609,   611,   613,   615,   725,   727,   729,   731,   733,
     735,   737,   739,   741,   743,   745,   747,   749,   751,   753,
     779,   781,   783,   785,   787,   789,   791,   793,   795,   797,
     799,   801,   803,   805,   807,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   755,
       0,     0,     0,     0,     0,   757,   759,   761,   763,   765,
     767,     0,     0,     0,   809,     0,     0,     0,     0,     0,
     811,   813,   815,   817,   819,   821,     0,     0,     0,     0,
       0,     0,     0,   769,     0,   771,   773,   775,   777,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   823,     0,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851,   853,   855,   857,   859,   861,   887,
     889,   891,   893,   895,   897,   899,   901,   903,   905,   907,
     909,   911,   913,   915,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   863,     0,
       0,     0,     0,     0,   865,   867,   869,   871,   873,   875,
       0,     0,     0,   917,     0,     0,     0,     0,     0,   919,
     921,   923,   925,   927,   929,     0,     0,     0,     0,     0,
       0,     0,   877,     0,   879,   881,   883,   885,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   931,     0,   933,
     935,   937,   939,   943,   945,   947,   949,   951,   953,   955,
     957,   959,   961,   963,   965,   967,   969,   971,  1005,  1007,
    1009,  1011,  1013,  1015,  1017,  1019,  1021,  1023,  1025,  1027,
    1029,  1031,  1033,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   973,     0,     0,
       0,     0,     0,   975,   977,   979,   981,   983,   985,     0,
       0,     0,  1035,     0,     0,     0,     0,     0,  1037,  1039,
    1041,  1043,  1045,  1047,     0,     0,     0,     0,     0,     0,
       0,   987,     0,   989,   991,   993,   995,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1049,     0,  1051,  1053,
    1055,  1057,  1071,  1073,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1075,  1077,     0,     0,  1089,  1091,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1093,  1095,
       0,     0,     0,     0,     0,     0,   365,   367,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   369,   371,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1079,     0,  1081,  1083,  1085,  1087,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1097,     0,  1099,  1101,  1103,
    1105,   383,   385,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   387,   389,   373,     0,   375,   377,   379,   381,
     347,   349,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   351,   353,     0,   617,   619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   621,   623,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   391,
       0,   393,   395,   397,   399,     0,     0,     0,     0,     0,
       0,     0,     0,   293,   295,     0,     0,     0,   355,     0,
     357,   359,   361,   363,   297,   299,     0,   311,   313,     0,
       0,     0,   625,     0,   627,   629,   631,   633,   315,   317,
       0,     0,     0,   653,   655,     0,     0,     0,     0,   671,
     673,     0,     0,     0,   657,   659,     0,     0,   707,   709,
     675,   677,     0,     0,     0,     0,     0,     0,     0,   711,
     713,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   301,     0,   303,   305,   307,   309,     0,     0,     0,
       0,     0,     0,     0,     0,   319,     0,   321,   323,   325,
     327,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   661,     0,   663,   665,   667,   669,   679,     0,   681,
     683,   685,   687,     0,     0,     0,   715,     0,   717,   719,
     721,   723
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    24,     0,    24,     0,    24,     0,    19,     0,    18,
       0,    96,     0,    98,     0,    26,     0,    26,     0,    26,
       0,    31,     0,   139,     0,   139,     0,   139,     0,   139,
       0,   139,     0,   139,     0,   139,     0,   139,     0,   139,
       0,   140,     0,   140,     0,   140,     0,   140,     0,   140,
       0,   140,     0,   140,     0,   140,     0,   140,     0,   107,
       0,   107,     0,   107,     0,   107,     0,   107,     0,   107,
       0,   107,     0,   107,     0,   107,     0,   108,     0,   108,
       0,   108,     0,   108,     0,   108,     0,   108,     0,   108,
       0,   108,     0,   108,     0,   135,     0,   135,     0,   135,
       0,   135,     0,   135,     0,   135,     0,   135,     0,   135,
       0,   135,     0,   136,     0,   136,     0,   136,     0,   136,
       0,   136,     0,   136,     0,   136,     0,   136,     0,   136,
       0,   141,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   141,     0,   141,     0,   141,
       0,   141,     0,   141,     0,   137,     0,   137,     0,   137,
       0,   137,     0,   137,     0,   137,     0,   137,     0,   137,
       0,   137,     0,   137,     0,   137,     0,   137,     0,   137,
       0,   137,     0,   137,     0,   137,     0,   137,     0,   137,
       0,   137,     0,   137,     0,   137,     0,   137,     0,   137,
       0,   137,     0,   137,     0,   137,     0,   137,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   138,     0,   138,     0,   138,     0,   138,
       0,   138,     0,   122,     0,   122,     0,   122,     0,   122,
       0,   122,     0,   122,     0,   122,     0,   122,     0,   122,
       0,   121,     0,   121,     0,   121,     0,   121,     0,   121,
       0,   121,     0,   121,     0,   121,     0,   121,     0,   117,
       0,   117,     0,   117,     0,   117,     0,   117,     0,   117,
       0,   117,     0,   117,     0,   117,     0,   118,     0,   118,
       0,   118,     0,   118,     0,   118,     0,   118,     0,   118,
       0,   118,     0,   118,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   115,     0,   115,     0,   115,     0,   115,
       0,   115,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   116,     0,   116,     0,   116,     0,   116,     0,   116,
       0,   111,     0,   111,     0,   111,     0,   111,     0,   111,
       0,   111,     0,   111,     0,   111,     0,   111,     0,   110,
       0,   110,     0,   110,     0,   110,     0,   110,     0,   110,
       0,   110,     0,   110,     0,   110,     0,   103,     0,   103,
       0,   103,     0,   103,     0,   103,     0,   103,     0,   103,
       0,   103,     0,   103,     0,   104,     0,   104,     0,   104,
       0,   104,     0,   104,     0,   104,     0,   104,     0,   104,
       0,   104,     0,   104,     0,   104,     0,   104,     0,   104,
       0,   104,     0,   104,     0,   104,     0,   104,     0,   104,
       0,   104,     0,   104,     0,   104,     0,   104,     0,   104,
       0,   104,     0,   104,     0,   104,     0,   104,     0,   106,
       0,   106,     0,   106,     0,   106,     0,   106,     0,   106,
       0,   106,     0,   106,     0,   106,     0,   106,     0,   106,
       0,   106,     0,   106,     0,   106,     0,   106,     0,   106,
       0,   106,     0,   106,     0,   106,     0,   106,     0,   106,
       0,   106,     0,   106,     0,   106,     0,   106,     0,   106,
       0,   106,     0,   102,     0,   102,     0,   102,     0,   102,
       0,   102,     0,   102,     0,   102,     0,   102,     0,   102,
       0,   105,     0,   105,     0,   105,     0,   105,     0,   105,
       0,   105,     0,   105,     0,   105,     0,   105,     0,   101,
       0,   101,     0,   101,     0,   101,     0,   101,     0,   101,
       0,   101,     0,   101,     0,   101,     0,   120,     0,   120,
       0,   120,     0,   120,     0,   120,     0,   120,     0,   120,
       0,   120,     0,   120,     0,   124,     0,   124,     0,   124,
       0,   124,     0,   124,     0,   124,     0,   124,     0,   124,
       0,   124,     0,   123,     0,   123,     0,   123,     0,   123,
       0,   123,     0,   123,     0,   123,     0,   123,     0,   123,
       0,   125,     0,   125,     0,   125,     0,   125,     0,   125,
       0,   125,     0,   125,     0,   125,     0,   125,     0,   126,
       0,   126,     0,   126,     0,   126,     0,   126,     0,   126,
       0,   126,     0,   126,     0,   126,     0,   127,     0,   127,
       0,   127,     0,   127,     0,   127,     0,   127,     0,   127,
       0,   127,     0,   127,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   112,
       0,   112,     0,   112,     0,   112,     0,   112,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   113,     0,   113,     0,   113,     0,   113,
       0,   113,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   114,     0,   114,
       0,   114,     0,   114,     0,   114,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   119,     0,   119,     0,   119,     0,   119,     0,   119,
       0,   130,     0,   128,     0,   128,     0,   128,     0,   128,
       0,   128,     0,   128,     0,   128,     0,   128,     0,   128,
       0,   128,     0,   128,     0,   128,     0,   128,     0,   128,
       0,   128,     0,   128,     0,   128,     0,   128,     0,   128,
       0,   128,     0,   128,     0,   128,     0,   128,     0,   128,
       0,   128,     0,   128,     0,   128,     0,   133,     0,    24,
       0,    24,     0,    24,     0,   109,     0,   109,     0,   109,
       0,   109,     0,   109,     0,   109,     0,   109,     0,   109,
       0,   109,     0,   109,     0,   109,     0,   109,     0,   109,
       0,   109,     0,   109,     0,   109,     0,   109,     0,   109,
       0,   109,     0,   109,     0,   109,     0,   109,     0,   109,
       0,   109,     0,   109,     0,   109,     0,   109,     0,   144,
       0,   144,     0,   144,     0,   144,     0,   144,     0,   144,
       0,   129,     0,   129,     0,   129,     0,   129,     0,   129,
       0,   129,     0,   129,     0,   129,     0,   129,     0,   132,
       0,   132,     0,   132,     0,   132,     0,   132,     0,   132,
       0,   132,     0,   132,     0,   132,     0
};


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, yyscan_t scanner, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, scanner, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "namespace", "using",
  "identifier", "constant", "string literal", "sizeof", "++", "--", "<<",
  ">>", "<=", ">=", "==", "!=", "&&", "||", "*=", "/=", "%=", "+=", "-=",
  "<<=", ">>=", "&=", "^=", "|=", "type name", "enum", "case", "default",
  "if", "else", "switch", "while", "do", "for", "goto", "continue",
  "break", "return", "new", "c code", "..", "#if .. #endif",
  "char literal", "primitive type", "___len", "___ptr", "String", "','",
  "'='", "?:", "|", "^", "&", ">", "'<'", "'-'", "'+'", "'%'", "'*'",
  "'/'", "CAST", "!", "~", "NEG", "PREINCR", "PREDECR", ".", "[]", "[",
  "]", "(", ")", "POSTINCR", "POSTDECR", "';'", "'.'", "'['", "']'", "'{'",
  "'}'", "'('", "')'", "'?'", "':'", "'|'", "'^'", "'&'", "'>'", "'!'",
  "'~'", "$accept", "translation_unit", "namespace_decl", "ccode",
  "usings_list", "using_dir", "decl_or_func_or_code_list",
  "decl_or_func_or_code", "type", "reftype", "decl", "$@1", "enumdecl",
  "enumdef", "ecase_list", "ecases", "ecase", "refdecl", "refassign_list",
  "expr_list_comma", "refassign", "slicedecl", "sliceassign_list",
  "sliceassign", "valuetype", "valuedecl", "assign_list", "assign", "func",
  "funccall", "param_list", "paramdecl", "expr_list", "block", "stmts",
  "stmt", "qualidentifier", "expr", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, scanner);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value, Location, scanner);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, yyscan_t scanner);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp, yyGLRStack* yystackp, yyscan_t scanner)
{
  yysymbol_kind_t yytoken;
  YY_USE (scanner);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex (&yylval, &yylloc, scanner);
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, yyscan_t scanner)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yylocp);
  YY_USE (scanner);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, scanner, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule, scanner));
  switch (yyrule)
    {
  case 2: /* translation_unit: namespace_decl usings_list decl_or_func_or_code_list  */
#line 71 "lcs.y"
                                                         {
    NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval)
    Env* env = yyget_extra(scanner);
    env->startNode = (*yyvalp);
    }
#line 2256 "lcs.tab.c"
    break;

  case 3: /* namespace_decl: %empty  */
#line 79 "lcs.y"
           {EMPTY((*yyvalp))}
#line 2262 "lcs.tab.c"
    break;

  case 4: /* namespace_decl: "namespace" "identifier" ';'  */
#line 80 "lcs.y"
                             { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2268 "lcs.tab.c"
    break;

  case 5: /* ccode: "c code"  */
#line 84 "lcs.y"
          { NTT(CCode,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2274 "lcs.tab.c"
    break;

  case 6: /* usings_list: %empty  */
#line 88 "lcs.y"
           {EMPTY((*yyvalp))}
#line 2280 "lcs.tab.c"
    break;

  case 7: /* usings_list: usings_list using_dir  */
#line 89 "lcs.y"
                          { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2286 "lcs.tab.c"
    break;

  case 8: /* using_dir: "using" "identifier" '.' "identifier" ';'  */
#line 93 "lcs.y"
                                        { NTT(Using,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval); ST(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,SymCUsing); }
#line 2292 "lcs.tab.c"
    break;

  case 9: /* using_dir: "using" "identifier" ';'  */
#line 94 "lcs.y"
                                        { NTT(Using,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); ST(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,SymUsing);}
#line 2298 "lcs.tab.c"
    break;

  case 10: /* using_dir: "using" "string literal" ';'  */
#line 95 "lcs.y"
                                        { NTT(Using,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval); STQ(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,SymQuotedUsing);}
#line 2304 "lcs.tab.c"
    break;

  case 11: /* decl_or_func_or_code_list: %empty  */
#line 99 "lcs.y"
           {EMPTY((*yyvalp))}
#line 2310 "lcs.tab.c"
    break;

  case 12: /* decl_or_func_or_code_list: decl_or_func_or_code_list decl_or_func_or_code  */
#line 100 "lcs.y"
                                                   { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2316 "lcs.tab.c"
    break;

  case 13: /* decl_or_func_or_code: decl  */
#line 104 "lcs.y"
         { NTT(GlobalDecl, (*yyvalp), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2322 "lcs.tab.c"
    break;

  case 16: /* decl_or_func_or_code: enumdef  */
#line 107 "lcs.y"
             { NTT(GlobalDecl, (*yyvalp), YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2328 "lcs.tab.c"
    break;

  case 20: /* reftype: type '[' ']'  */
#line 117 "lcs.y"
                 { NTT(RefType,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2334 "lcs.tab.c"
    break;

  case 24:
    if (! (
#line 124 "lcs.y"
      false )) YYERROR;
#line 2341 "lcs.tab.c"
    break;

  case 25: /* decl: $@1 slicedecl  */
#line 124 "lcs.y"
                           { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2347 "lcs.tab.c"
    break;

  case 26: /* enumdecl: "identifier" "identifier" '=' expr  */
#line 128 "lcs.y"
                                   { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2353 "lcs.tab.c"
    break;

  case 27: /* enumdef: "enum" "identifier" '{' ecase_list '}'  */
#line 132 "lcs.y"
                                       { NTT(Enum, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval)}
#line 2359 "lcs.tab.c"
    break;

  case 28: /* ecase_list: %empty  */
#line 136 "lcs.y"
           { EMPTY((*yyvalp)) }
#line 2365 "lcs.tab.c"
    break;

  case 32: /* ecases: ecase ',' ecases  */
#line 143 "lcs.y"
                      { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2371 "lcs.tab.c"
    break;

  case 34: /* ecase: "identifier" '=' expr  */
#line 148 "lcs.y"
                        { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2377 "lcs.tab.c"
    break;

  case 35: /* refdecl: reftype refassign refassign_list ';'  */
#line 153 "lcs.y"
                                          { NTT(RefDeclAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2383 "lcs.tab.c"
    break;

  case 36: /* refassign_list: %empty  */
#line 157 "lcs.y"
           { EMPTY((*yyvalp)) }
#line 2389 "lcs.tab.c"
    break;

  case 37: /* refassign_list: refassign_list ',' refassign  */
#line 158 "lcs.y"
                                 { NTT(RefAssignCommas,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2395 "lcs.tab.c"
    break;

  case 39: /* expr_list_comma: expr_list ','  */
#line 163 "lcs.y"
                  { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2401 "lcs.tab.c"
    break;

  case 40: /* refassign: "identifier" '=' '{' expr_list_comma '}'  */
#line 167 "lcs.y"
                                                { NTT(RefAssignList,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2407 "lcs.tab.c"
    break;

  case 41: /* refassign: "identifier" '=' "string literal"  */
#line 168 "lcs.y"
                                          { NTT(RefAssignStr,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2413 "lcs.tab.c"
    break;

  case 42: /* refassign: "identifier" '=' funccall  */
#line 169 "lcs.y"
                                          { NTT(RefAssignFunc,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2419 "lcs.tab.c"
    break;

  case 43: /* refassign: "identifier" '=' "identifier"  */
#line 170 "lcs.y"
                                          { NTT(RefAssignFunc,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2425 "lcs.tab.c"
    break;

  case 44: /* refassign: "identifier" '=' "identifier" '[' expr ".." expr ']'  */
#line 171 "lcs.y"
                                                         { NTT(RefAssignId,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2431 "lcs.tab.c"
    break;

  case 45: /* refassign: "identifier" '[' expr ']'  */
#line 172 "lcs.y"
                                          { NTT(RefAssignConst,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2437 "lcs.tab.c"
    break;

  case 46: /* slicedecl: valuetype sliceassign sliceassign_list ';'  */
#line 176 "lcs.y"
                                                { NTT(DeclAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2443 "lcs.tab.c"
    break;

  case 47: /* sliceassign_list: %empty  */
#line 180 "lcs.y"
           {EMPTY((*yyvalp)) }
#line 2449 "lcs.tab.c"
    break;

  case 48: /* sliceassign_list: sliceassign_list ',' sliceassign  */
#line 181 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2455 "lcs.tab.c"
    break;

  case 49: /* sliceassign: "identifier" '[' ']'  */
#line 185 "lcs.y"
                                                  { NTT(SliceAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2461 "lcs.tab.c"
    break;

  case 50: /* sliceassign: "identifier" '[' expr ']'  */
#line 186 "lcs.y"
                                                  { NTT(SliceAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2467 "lcs.tab.c"
    break;

  case 51: /* sliceassign: "identifier" '[' expr ']' '=' '{' expr_list '}'  */
#line 187 "lcs.y"
                                                  { NTT(SliceAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2473 "lcs.tab.c"
    break;

  case 52: /* sliceassign: "identifier" '[' ']' '=' '{' expr_list '}'  */
#line 188 "lcs.y"
                                                  { NTT(SliceAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2479 "lcs.tab.c"
    break;

  case 53: /* sliceassign: "identifier" '[' ']' '=' "string literal"  */
#line 189 "lcs.y"
                                                  { NTT(SliceAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2485 "lcs.tab.c"
    break;

  case 54: /* sliceassign: "identifier" '[' ']' '=' funccall  */
#line 190 "lcs.y"
                                                  { NTT(SliceAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2491 "lcs.tab.c"
    break;

  case 55: /* valuetype: "primitive type"  */
#line 194 "lcs.y"
          { (*yyvalp) = CreateToken(PrimitiveType, NodeName[YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval] , NodeLen[YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval], yylloc.first_line, yylloc.first_column); }
#line 2497 "lcs.tab.c"
    break;

  case 58: /* valuetype: "primitive type" '*'  */
#line 197 "lcs.y"
              { GETLOC; yyerror(loc, scanner, POINTERS);}
#line 2503 "lcs.tab.c"
    break;

  case 59: /* valuedecl: valuetype assign assign_list ';'  */
#line 201 "lcs.y"
                                     { NTT(DeclAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2509 "lcs.tab.c"
    break;

  case 60: /* valuedecl: qualidentifier assign assign_list ';'  */
#line 202 "lcs.y"
                                          { NTT(DeclAssign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2515 "lcs.tab.c"
    break;

  case 61: /* assign_list: %empty  */
#line 206 "lcs.y"
           {EMPTY((*yyvalp))}
#line 2521 "lcs.tab.c"
    break;

  case 62: /* assign_list: assign_list ',' assign  */
#line 207 "lcs.y"
                           { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2527 "lcs.tab.c"
    break;

  case 63: /* assign: "identifier"  */
#line 210 "lcs.y"
                        { NTT(Assign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2533 "lcs.tab.c"
    break;

  case 64: /* assign: "identifier" '=' expr  */
#line 211 "lcs.y"
                        { NTT(Assign,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2539 "lcs.tab.c"
    break;

  case 65: /* func: type "identifier" '(' param_list ')' block  */
#line 215 "lcs.y"
                                                   { NTT(FuncDef,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); ST(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,SymLocalFunc); }
#line 2545 "lcs.tab.c"
    break;

  case 66: /* func: "identifier" "identifier" '(' param_list ')' block  */
#line 216 "lcs.y"
                                                   { NTT(FuncDef,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); ST(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,SymLocalFunc); }
#line 2551 "lcs.tab.c"
    break;

  case 67: /* funccall: "identifier" '(' expr_list ')'  */
#line 220 "lcs.y"
                                 { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2557 "lcs.tab.c"
    break;

  case 68: /* funccall: qualidentifier '(' expr_list ')'  */
#line 221 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2563 "lcs.tab.c"
    break;

  case 69: /* param_list: %empty  */
#line 225 "lcs.y"
           {EMPTY((*yyvalp))}
#line 2569 "lcs.tab.c"
    break;

  case 71: /* param_list: param_list ',' paramdecl  */
#line 227 "lcs.y"
                             { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2575 "lcs.tab.c"
    break;

  case 72: /* paramdecl: type "identifier"  */
#line 231 "lcs.y"
                                  { NTT(ParamDef,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2581 "lcs.tab.c"
    break;

  case 73: /* paramdecl: type "identifier" '[' ']'  */
#line 232 "lcs.y"
                                  { NTT(ParamRefDef,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2587 "lcs.tab.c"
    break;

  case 74: /* paramdecl: "identifier" "identifier"  */
#line 233 "lcs.y"
                                  { NTT(ParamDef,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2593 "lcs.tab.c"
    break;

  case 75: /* paramdecl: "identifier" "identifier" '[' ']'  */
#line 234 "lcs.y"
                                  { NTT(ParamRefDef,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2599 "lcs.tab.c"
    break;

  case 76: /* expr_list: %empty  */
#line 238 "lcs.y"
           {EMPTY((*yyvalp))}
#line 2605 "lcs.tab.c"
    break;

  case 78: /* expr_list: expr_list ',' expr  */
#line 240 "lcs.y"
                       { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2611 "lcs.tab.c"
    break;

  case 79: /* block: '{' stmts '}'  */
#line 244 "lcs.y"
                  { NTT(Block, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2617 "lcs.tab.c"
    break;

  case 80: /* stmts: %empty  */
#line 248 "lcs.y"
           {EMPTY((*yyvalp))}
#line 2623 "lcs.tab.c"
    break;

  case 81: /* stmts: stmts stmt  */
#line 249 "lcs.y"
               { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2629 "lcs.tab.c"
    break;

  case 82: /* stmt: ';'  */
#line 253 "lcs.y"
        { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 2635 "lcs.tab.c"
    break;

  case 83: /* stmt: block  */
#line 254 "lcs.y"
          { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 2641 "lcs.tab.c"
    break;

  case 84: /* stmt: decl  */
#line 255 "lcs.y"
         { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 2647 "lcs.tab.c"
    break;

  case 85: /* stmt: expr ';'  */
#line 256 "lcs.y"
             { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval, YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval); }
#line 2653 "lcs.tab.c"
    break;

  case 86: /* stmt: "while" '(' expr ')' block  */
#line 257 "lcs.y"
                             { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2659 "lcs.tab.c"
    break;

  case 87: /* stmt: "for" '(' expr_list ';' expr_list ';' expr_list ')' block  */
#line 258 "lcs.y"
                                                            { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2665 "lcs.tab.c"
    break;

  case 88: /* stmt: "return" expr ';'  */
#line 259 "lcs.y"
                    { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2671 "lcs.tab.c"
    break;

  case 89: /* stmt: "return" ';'  */
#line 260 "lcs.y"
               { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2677 "lcs.tab.c"
    break;

  case 90: /* stmt: "if" '(' expr ')' block  */
#line 261 "lcs.y"
                          { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2683 "lcs.tab.c"
    break;

  case 91: /* stmt: "if" '(' expr ')' block "else" block  */
#line 262 "lcs.y"
                                     { NTT(WithLine,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2689 "lcs.tab.c"
    break;

  case 93: /* qualidentifier: "identifier" '.' "identifier"  */
#line 267 "lcs.y"
                              { NTT(QualIdentifier,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2695 "lcs.tab.c"
    break;

  case 95: /* expr: "string literal"  */
#line 272 "lcs.y"
                   { NTT(String,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2701 "lcs.tab.c"
    break;

  case 100: /* expr: '(' expr ')'  */
#line 277 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2707 "lcs.tab.c"
    break;

  case 101: /* expr: expr '=' expr  */
#line 278 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2713 "lcs.tab.c"
    break;

  case 102: /* expr: expr "+=" expr  */
#line 279 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2719 "lcs.tab.c"
    break;

  case 103: /* expr: expr "*=" expr  */
#line 280 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2725 "lcs.tab.c"
    break;

  case 104: /* expr: expr "/=" expr  */
#line 281 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2731 "lcs.tab.c"
    break;

  case 105: /* expr: expr "-=" expr  */
#line 282 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2737 "lcs.tab.c"
    break;

  case 106: /* expr: expr "%=" expr  */
#line 283 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2743 "lcs.tab.c"
    break;

  case 107: /* expr: "___len" expr  */
#line 284 "lcs.y"
                                    { NTT(RefOp, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2749 "lcs.tab.c"
    break;

  case 108: /* expr: "___ptr" expr  */
#line 285 "lcs.y"
                                    { NTT(RefOp, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2755 "lcs.tab.c"
    break;

  case 109: /* expr: expr '?' expr ':' expr  */
#line 286 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2761 "lcs.tab.c"
    break;

  case 110: /* expr: expr "||" expr  */
#line 287 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2767 "lcs.tab.c"
    break;

  case 111: /* expr: expr "&&" expr  */
#line 288 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2773 "lcs.tab.c"
    break;

  case 112: /* expr: expr '|' expr  */
#line 289 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2779 "lcs.tab.c"
    break;

  case 113: /* expr: expr '^' expr  */
#line 290 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2785 "lcs.tab.c"
    break;

  case 114: /* expr: expr '&' expr  */
#line 291 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2791 "lcs.tab.c"
    break;

  case 115: /* expr: expr "==" expr  */
#line 292 "lcs.y"
                                    { NTT(BinOp, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2797 "lcs.tab.c"
    break;

  case 116: /* expr: expr "!=" expr  */
#line 293 "lcs.y"
                                    { NTT(BinOp, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2803 "lcs.tab.c"
    break;

  case 117: /* expr: expr "<=" expr  */
#line 294 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2809 "lcs.tab.c"
    break;

  case 118: /* expr: expr ">=" expr  */
#line 295 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2815 "lcs.tab.c"
    break;

  case 119: /* expr: expr '>' expr  */
#line 296 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2821 "lcs.tab.c"
    break;

  case 120: /* expr: expr '<' expr  */
#line 297 "lcs.y"
                                    { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2827 "lcs.tab.c"
    break;

  case 121: /* expr: expr ">>" expr  */
#line 298 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2833 "lcs.tab.c"
    break;

  case 122: /* expr: expr "<<" expr  */
#line 299 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2839 "lcs.tab.c"
    break;

  case 123: /* expr: expr '+' expr  */
#line 300 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2845 "lcs.tab.c"
    break;

  case 124: /* expr: expr '-' expr  */
#line 301 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2851 "lcs.tab.c"
    break;

  case 125: /* expr: expr '%' expr  */
#line 302 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2857 "lcs.tab.c"
    break;

  case 126: /* expr: expr '*' expr  */
#line 303 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2863 "lcs.tab.c"
    break;

  case 127: /* expr: expr '/' expr  */
#line 304 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2869 "lcs.tab.c"
    break;

  case 128: /* expr: '(' type ')' expr  */
#line 305 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2875 "lcs.tab.c"
    break;

  case 129: /* expr: "identifier" '[' expr ']' '=' expr  */
#line 306 "lcs.y"
                                                      { NTT(IndexerS, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2881 "lcs.tab.c"
    break;

  case 130: /* expr: "identifier" '[' expr ']'  */
#line 307 "lcs.y"
                                                      { NTT(Indexer, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2887 "lcs.tab.c"
    break;

  case 131: /* expr: "identifier" '[' expr ".." expr ']'  */
#line 308 "lcs.y"
                                                      { NTT(RefSlice,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2893 "lcs.tab.c"
    break;

  case 132: /* expr: qualidentifier '[' expr ']' '=' expr  */
#line 309 "lcs.y"
                                                      { NTT(IndexerS, (*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2899 "lcs.tab.c"
    break;

  case 133: /* expr: qualidentifier '[' expr ']'  */
#line 310 "lcs.y"
                                                      { NTT(Indexer,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2905 "lcs.tab.c"
    break;

  case 134: /* expr: qualidentifier '[' expr ".." expr ']'  */
#line 311 "lcs.y"
                                                      { NTT(RefSlice,(*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2911 "lcs.tab.c"
    break;

  case 135: /* expr: '-' expr  */
#line 312 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2917 "lcs.tab.c"
    break;

  case 136: /* expr: '+' expr  */
#line 313 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2923 "lcs.tab.c"
    break;

  case 137: /* expr: '!' expr  */
#line 314 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2929 "lcs.tab.c"
    break;

  case 138: /* expr: '~' expr  */
#line 315 "lcs.y"
                                     { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2935 "lcs.tab.c"
    break;

  case 139: /* expr: "++" expr  */
#line 316 "lcs.y"
                                      { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2941 "lcs.tab.c"
    break;

  case 140: /* expr: "--" expr  */
#line 317 "lcs.y"
                                      { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2947 "lcs.tab.c"
    break;

  case 141: /* expr: '&' expr  */
#line 318 "lcs.y"
                                      { GETLOC; yyerror(loc, scanner, REFERENCES);}
#line 2953 "lcs.tab.c"
    break;

  case 142: /* expr: expr "++"  */
#line 319 "lcs.y"
                                       { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2959 "lcs.tab.c"
    break;

  case 143: /* expr: expr "--"  */
#line 320 "lcs.y"
                                        { NT((*yyvalp),YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval,YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval) }
#line 2965 "lcs.tab.c"
    break;


#line 2969 "lcs.tab.c"

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yyscan_t scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, yyscan_t scanner)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval, &yys->yyloc, scanner);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, scanner);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, yyscan_t scanner)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , scanner);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, yyscan_t scanner)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp, yylocp, scanner);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp, yylocp, scanner);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval, yyscan_t scanner)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval, &yyloc, scanner);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval, &yyloc);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yyscan_t scanner);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, yyscan_t scanner)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, scanner));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, scanner));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, yyscan_t scanner)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, scanner);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, scanner);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp, yylocp, scanner);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, yyscan_t scanner)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (yylocp, scanner, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, yyscan_t scanner)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, scanner);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, scanner);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yyscan_t scanner)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, scanner);
              return yyreportAmbiguity (yybest, yyp, yylocp, scanner);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, scanner);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other, &yydummy, scanner);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval, yylocp, scanner);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, scanner);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, yyscan_t scanner)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , scanner));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn, YYLTYPE *yylocp, yyscan_t scanner)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], scanner);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], scanner);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, scanner));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], scanner);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
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
  if (yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp, yyscan_t scanner)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yystrlen (yysymbol_name (yyarg[yyi]));
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (&yylloc, scanner, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, scanner, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, yyscan_t scanner)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, scanner, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, scanner);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, scanner);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, &yylloc, scanner, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, scanner);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, scanner, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, scanner);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, scanner));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, scanner);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack, scanner);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, scanner));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, scanner));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, scanner, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, scanner));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, scanner);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, scanner));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, scanner);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (&yylloc, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, scanner);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, scanner);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc




#line 324 "lcs.y"


void AddGSym(yyscan_t scanner,int i, SymKind t) {
  Span s = SPAN((Byte*)NodeName[i], NodeLen[i]);
  SymGAdd(s, t, SPAN0);
}
void AddGSymQuoted(yyscan_t scanner,int i, SymKind t) {
  Span sq = SPAN((Byte*)NodeName[i], NodeLen[i]);
  Span s  = SPAN(sq.ptr + 1, sq.len - 2);
  SymGAdd(s, t, SPAN0);
}
