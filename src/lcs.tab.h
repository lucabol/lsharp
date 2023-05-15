/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_YY_LCS_TAB_H_INCLUDED
# define YY_YY_LCS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "lcs.y"

  typedef void* yyscan_t;

#line 48 "lcs.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NAMESPACE = 258,               /* "namespace"  */
    USING = 259,                   /* "using"  */
    IDENTIFIER = 260,              /* "identifier"  */
    CONSTANT = 261,                /* "constant"  */
    STRING_LITERAL = 262,          /* "string literal"  */
    SIZEOF = 263,                  /* "sizeof"  */
    INC_OP = 264,                  /* "++"  */
    DEC_OP = 265,                  /* "--"  */
    LEFT_OP = 266,                 /* "<<"  */
    RIGHT_OP = 267,                /* ">>"  */
    LE_OP = 268,                   /* "<="  */
    GE_OP = 269,                   /* ">="  */
    EQ_OP = 270,                   /* "=="  */
    NE_OP = 271,                   /* "!="  */
    AND_OP = 272,                  /* "&&"  */
    OR_OP = 273,                   /* "||"  */
    MUL_ASSIGN = 274,              /* "*="  */
    DIV_ASSIGN = 275,              /* "/="  */
    MOD_ASSIGN = 276,              /* "%="  */
    ADD_ASSIGN = 277,              /* "+="  */
    SUB_ASSIGN = 278,              /* "-="  */
    LEFT_ASSIGN = 279,             /* "<<="  */
    RIGHT_ASSIGN = 280,            /* ">>="  */
    AND_ASSIGN = 281,              /* "&="  */
    XOR_ASSIGN = 282,              /* "^="  */
    OR_ASSIGN = 283,               /* "|="  */
    TYPE_NAME = 284,               /* "type name"  */
    ENUM = 285,                    /* "enum"  */
    CASE = 286,                    /* "case"  */
    DEFAULT = 287,                 /* "default"  */
    IF = 288,                      /* "if"  */
    ELSE = 289,                    /* "else"  */
    SWITCH = 290,                  /* "switch"  */
    WHILE = 291,                   /* "while"  */
    DO = 292,                      /* "do"  */
    FOR = 293,                     /* "for"  */
    GOTO = 294,                    /* "goto"  */
    CONTINUE = 295,                /* "continue"  */
    BREAK = 296,                   /* "break"  */
    RETURN = 297,                  /* "return"  */
    SLICESYM = 298,                /* "[]"  */
    NEW = 299,                     /* "new"  */
    PTYPE = 300,                   /* "primitive type"  */
    CAST = 306,                    /* CAST  */
    NEG = 309,                     /* NEG  */
    PREINCR = 310,                 /* PREINCR  */
    PREDECR = 311,                 /* PREDECR  */
    POSTINCR = 317,                /* POSTINCR  */
    POSTDECR = 318                 /* POSTDECR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  int  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (yyscan_t scanner);

#endif /* !YY_YY_LCS_TAB_H_INCLUDED  */
