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
    QUALIDENTIFIER = 261,          /* "qualified identifier"  */
    CONSTANT = 262,                /* "constant"  */
    STRING_LITERAL = 263,          /* "string literal"  */
    SIZEOF = 264,                  /* "sizeof"  */
    INC_OP = 265,                  /* "++"  */
    DEC_OP = 266,                  /* "--"  */
    LEFT_OP = 267,                 /* "<<"  */
    RIGHT_OP = 268,                /* ">>"  */
    LE_OP = 269,                   /* "<="  */
    GE_OP = 270,                   /* ">="  */
    EQ_OP = 271,                   /* "=="  */
    NE_OP = 272,                   /* "!="  */
    AND_OP = 273,                  /* "&&"  */
    OR_OP = 274,                   /* "||"  */
    MUL_ASSIGN = 275,              /* "*="  */
    DIV_ASSIGN = 276,              /* "/="  */
    MOD_ASSIGN = 277,              /* "%="  */
    ADD_ASSIGN = 278,              /* "+="  */
    SUB_ASSIGN = 279,              /* "-="  */
    LEFT_ASSIGN = 280,             /* "<<="  */
    RIGHT_ASSIGN = 281,            /* ">>="  */
    AND_ASSIGN = 282,              /* "&="  */
    XOR_ASSIGN = 283,              /* "^="  */
    OR_ASSIGN = 284,               /* "|="  */
    TYPE_NAME = 285,               /* "type name"  */
    ENUM = 286,                    /* "enum"  */
    CASE = 287,                    /* "case"  */
    DEFAULT = 288,                 /* "default"  */
    IF = 289,                      /* "if"  */
    ELSE = 290,                    /* "else"  */
    SWITCH = 291,                  /* "switch"  */
    WHILE = 292,                   /* "while"  */
    DO = 293,                      /* "do"  */
    FOR = 294,                     /* "for"  */
    GOTO = 295,                    /* "goto"  */
    CONTINUE = 296,                /* "continue"  */
    BREAK = 297,                   /* "break"  */
    RETURN = 298,                  /* "return"  */
    SLICESYM = 299,                /* "[]"  */
    NEW = 300,                     /* "new"  */
    PTYPE = 301,                   /* "primitive type"  */
    CAST = 307,                    /* CAST  */
    NEG = 310,                     /* NEG  */
    PREINCR = 311,                 /* PREINCR  */
    PREDECR = 312,                 /* PREDECR  */
    POSTINCR = 318,                /* POSTINCR  */
    POSTDECR = 319                 /* POSTDECR  */
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
