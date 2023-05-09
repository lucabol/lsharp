/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LCS_TAB_H_INCLUDED
# define YY_YY_LCS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "lcs.y"

  #include <stdio.h>
  #include <math.h>
  #include <stdbool.h>

  #include "ulib/Span.h"
  #include "ulib/Buffer.h"
  #include "ulib/OsStdc.h"
  #include "ulib/OptGet.h"

  int yylex (void);
  void yyerror (char const *);

  // Sets and delete the buffer from which to parse the code.
  void set_buffer(Span s);
  void delete_buffer(void);

#line 67 "lcs.tab.h"

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
    CLASS = 260,                   /* "class"  */
    PUBLIC = 261,                  /* "public"  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    CONSTANT = 263,                /* CONSTANT  */
    STRING_LITERAL = 264,          /* STRING_LITERAL  */
    SIZEOF = 265,                  /* SIZEOF  */
    PTR_OP = 266,                  /* PTR_OP  */
    INC_OP = 267,                  /* INC_OP  */
    DEC_OP = 268,                  /* DEC_OP  */
    LEFT_OP = 269,                 /* LEFT_OP  */
    RIGHT_OP = 270,                /* RIGHT_OP  */
    LE_OP = 271,                   /* LE_OP  */
    GE_OP = 272,                   /* GE_OP  */
    EQ_OP = 273,                   /* EQ_OP  */
    NE_OP = 274,                   /* NE_OP  */
    AND_OP = 275,                  /* AND_OP  */
    OR_OP = 276,                   /* OR_OP  */
    MUL_ASSIGN = 277,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 278,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 279,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 280,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 281,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 282,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 283,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 284,              /* AND_ASSIGN  */
    XOR_ASSIGN = 285,              /* XOR_ASSIGN  */
    OR_ASSIGN = 286,               /* OR_ASSIGN  */
    TYPE_NAME = 287,               /* TYPE_NAME  */
    STATIC = 288,                  /* STATIC  */
    AUTO = 289,                    /* AUTO  */
    CHAR = 290,                    /* CHAR  */
    INT = 291,                     /* INT  */
    LONG = 292,                    /* LONG  */
    FLOAT = 293,                   /* FLOAT  */
    DOUBLE = 294,                  /* DOUBLE  */
    CONST = 295,                   /* CONST  */
    VOID = 296,                    /* VOID  */
    BOOL = 297,                    /* BOOL  */
    STRUCT = 298,                  /* STRUCT  */
    ENUM = 299,                    /* ENUM  */
    ELLIPSIS = 300,                /* ELLIPSIS  */
    CASE = 301,                    /* CASE  */
    DEFAULT = 302,                 /* DEFAULT  */
    IF = 303,                      /* IF  */
    ELSE = 304,                    /* ELSE  */
    SWITCH = 305,                  /* SWITCH  */
    WHILE = 306,                   /* WHILE  */
    DO = 307,                      /* DO  */
    FOR = 308,                     /* FOR  */
    GOTO = 309,                    /* GOTO  */
    CONTINUE = 310,                /* CONTINUE  */
    BREAK = 311,                   /* BREAK  */
    RETURN = 312,                  /* RETURN  */
    TRUE = 313,                    /* TRUE  */
    FALSE = 314                    /* FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef Span YYSTYPE;
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


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_LCS_TAB_H_INCLUDED  */
