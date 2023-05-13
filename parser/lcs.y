%code requires {
  #include "ulib/Span.h"

  typedef void* yyscan_t;
}

%code top {
  #include "config.h"
  #include "lcs.lex.h"

  // Current namespace, used to generate mangled function names as namespace_funcname
  Span namespace;

  #define StL(...) BufferSLCopy(' ', code, __VA_ARGS__)
  #define St(...)  BufferSCopy(' ', code, __VA_ARGS__)
  #define Sp(...) BufferMCopy(' ', code, __VA_ARGS__)
  #define SpL(...) BufferMLCopy(' ', code, __VA_ARGS__)
  #define K(v) (char*)SpanTo1KTempString(v)

  #define NT(...) CreateSymbolA(SPAN0, (int[]) {__VA_ARGS__, -1})
  #define T(name,...) CreateSymbolA(name, (int[]) {__VA_ARGS__, -1})
}
%code {
  void yyerror(YYLTYPE *locp, yyscan_t scanner, char const *msg);
}

%define locations
%define api.pure
%param { yyscan_t scanner }

%define parse.error detailed
%define parse.trace

%define api.value.type { int }

%define lr.type ielr
%glr-parser
%expect 2

%token NAMESPACE "namespace" USING "using" IDENTIFIER "identifier" CONSTANT "constant" STRING_LITERAL "string literal" SIZEOF "sizeof"
%token INC_OP "++" DEC_OP "--" LEFT_OP "<<" RIGHT_OP ">>" LE_OP "<=" GE_OP ">=" EQ_OP "==" NE_OP "!="
%token AND_OP "&&" OR_OP "||" MUL_ASSIGN "*=" DIV_ASSIGN "/=" MOD_ASSIGN "%=" ADD_ASSIGN "+="
%token SUB_ASSIGN "-=" LEFT_ASSIGN "<<=" RIGHT_ASSIGN ">>=" AND_ASSIGN "&="
%token XOR_ASSIGN "^=" OR_ASSIGN "|=" TYPE_NAME "type name"
%token ENUM "enum"
%token CASE "case" DEFAULT "default" IF "if" ELSE "else" SWITCH "switch" WHILE "while" DO "do" FOR "for" GOTO "goto" CONTINUE "continue" BREAK "break" RETURN "return"

%token SLICESYM "[]" NEW "new"

%left ','
%right '=' "+=" "-=" "*=" ">>=" "<<=" "&=" "^=" "|="
%right "?:"
%left "||"
%left "&&"
%left "|"
%left "^"
%left "&"
%left "==" "!="
%left ">" ">=" "<=" '<'
%left ">>" "<<"
%left '-' '+' '%'
%left '*' '/'
%right "sizeof" CAST "!" "~" NEG PREINCR PREDECR
%left "." "[]" "[" "]" "(" ")" POSTINCR POSTDECR

%%

translation_unit
  : namespace_decl usings_list decl_or_func_list
  ;

namespace_decl
  : %empty
  | NAMESPACE IDENTIFIER ';'
  ;

usings_list
  : %empty
  | usings_list using_dir
  ;

using_dir
  : USING IDENTIFIER ';'
  ;

decl_or_func_list
  : %empty
  | decl_or_func_list decl_or_func
  ;

decl_or_func
  : decl
  | func
  ;

type
  : valuetype
  | slicetype
  ;

valuetype
  : IDENTIFIER
  | TYPE_NAME
  ;

slicetype
  : valuetype SLICESYM
  | valuetype '[' expr_list ']'
  ;

decl
  : valuedecl
  | slicedecl
  ;

valuedecl
  : valuetype IDENTIFIER ';'
  | valuetype assign assign_list ';'
  ;

slicedecl
  : slicetype IDENTIFIER ';'
  | valuetype IDENTIFIER '[' expr ']' ';'
  | slicetype sliceassign sliceassign_list ';'
  ;

sliceassign_list
  : %empty
  | sliceassign_list ',' sliceassign
  ;

sliceassign
  : IDENTIFIER '=' '{' expr_list '}'
  | IDENTIFIER '=' "new" valuetype '[' expr ']'
  ;

assign_list
  : %empty
  | assign_list ',' assign

assign
  : IDENTIFIER '=' expr
  ;

func
  : type IDENTIFIER '(' param_list ')' block
  ;

funccall
  : IDENTIFIER '(' expr_list ')'
  ;

param_list
  : %empty
  | paramdecl
  | param_list ',' paramdecl
  ;

paramdecl
  : type IDENTIFIER
  ;

expr_list
  : %empty
  | expr
  | expr_list ',' expr
  ;

block
  : '{' stmts '}'
  ;

stmts
  : %empty
  | stmts stmt
  ;

stmt
  : ';'
  | block
  | decl
  | expr ';'
  | WHILE '(' expr ')' block
  | RETURN expr ';'
  | IF '(' expr ')' block ELSE block
  ;

expr
  : CONSTANT
  | IDENTIFIER
  | assign
  | funccall
  | '(' expr ')'
  | expr '+' expr
  | expr '-' expr
  | expr '*' expr
  | expr '/' expr
  | expr '%' expr
  | expr ">>" expr
  | expr "<<" expr
  | expr "<=" expr
  | expr ">=" expr
  | expr ">" expr
  | expr '<' expr
  | expr "==" expr
  | expr "!=" expr
  | expr "&" expr
  | expr "|" expr
  | expr "^" expr
  | expr "&&" expr
  | expr "||" expr
  | '-' expr %prec NEG
  | '+' expr %prec NEG
  ;

%%
