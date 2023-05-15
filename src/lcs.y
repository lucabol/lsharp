%code requires {
  typedef void* yyscan_t;
}

%code top {
  #include "config.h"
  #include "lcs.lex.h"
  #include "ast.h"
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
%token PTYPE "primitive type"

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

%code {
  void yyerror(YYLTYPE *locp, yyscan_t scanner, char const *msg);

  #define NT(vv,...) vv = CreateNt(Generic, __VA_ARGS__); 
  #define NTT(kind,vv,...) vv = CreateNt(kind, __VA_ARGS__); 
  #define EMPTY(vv) { YYLTYPE* loc = yyget_lloc(scanner); vv = CreateToken(Token,"",0,loc->first_line,loc->first_column); }
}

%%

translation_unit
  : namespace_decl usings_list decl_or_func_list {
    NT($$,$1,$2,$3)
    Env* env = yyget_extra(scanner);
    env->startNode = $$;
    }
  ;

namespace_decl
  : %empty {EMPTY($$)}
  | NAMESPACE IDENTIFIER ';' { NT($$,$1,$2,$3) }
  ;

usings_list
  : %empty {EMPTY($$)}
  | usings_list using_dir { NT($$,$1,$2) }
  ;

using_dir
  : USING IDENTIFIER ';' { NT($$,$1,$2,$3) }
  ;

decl_or_func_list
  : %empty {EMPTY($$)}
  | decl_or_func_list decl_or_func { NT($$,$1,$2) }
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
  : PTYPE { $$ = CreateToken(PrimitiveType, NodeName[$1] , NodeLen[$1], yylloc.first_line, yylloc.first_column); }
  | IDENTIFIER 
  | TYPE_NAME
  ;

slicetype
  : valuetype SLICESYM { NT($$,$1,$2) }
  | valuetype '[' expr_list ']' { NT($$,$1,$2,$3,$4) }
  ;

decl
  : valuedecl
  | slicedecl
  ;

valuedecl
  : valuetype IDENTIFIER ';' { NT($$,$1,$2,$3) }
  | valuetype assign assign_list ';' { NT($$,$1,$2,$3,$4) }
  ;

slicedecl
  : slicetype IDENTIFIER ';' { NT($$,$1,$2,$3) }
  | valuetype IDENTIFIER '[' expr ']' ';' { NT($$,$1,$2,$3,$4,$5,$6) }
  | slicetype sliceassign sliceassign_list ';' { NT($$,$1,$2,$3,$4) }
  ;

sliceassign_list
  : %empty {EMPTY($$)}
  | sliceassign_list ',' sliceassign { NT($$,$1,$2,$3) }
  ;

sliceassign
  : IDENTIFIER '=' '{' expr_list '}' { NT($$,$1,$2,$3,$4,$5) }
  | IDENTIFIER '=' "new" valuetype '[' expr ']' { NT($$,$1,$2,$3,$4,$5,$6,$7) }
  | IDENTIFIER '=' expr { NT($$,$1,$2,$3) }
  ;

assign_list
  : %empty {EMPTY($$)}
  | assign_list ',' assign { NT($$,$1,$2,$3) }

assign
  : IDENTIFIER '=' expr { NT($$,$1,$2,$3) }
  ;

func
  : type IDENTIFIER '(' param_list ')' block { NT($$,$1,$2,$3,$4,$5,$6) }
  ;

funccall
  : IDENTIFIER '(' expr_list ')' { NT($$,$1,$2,$3,$4) }
  ;

param_list
  : %empty {EMPTY($$)}
  | paramdecl
  | param_list ',' paramdecl { NT($$,$1,$2,$3) }
  ;

paramdecl
  : type IDENTIFIER { NT($$,$1,$2) }
  ;

expr_list
  : %empty {EMPTY($$)}
  | expr
  | expr_list ',' expr { NT($$,$1,$2,$3) }
  ;

block
  : '{' stmts '}' { NT($$,$1,$2,$3) }
  ;

stmts
  : %empty {EMPTY($$)}
  | stmts stmt { NT($$,$1,$2) }
  ;

stmt
  : ';' { NTT(WithLine,$$,$1); }
  | block { NTT(WithLine,$$,$1); }
  | decl { NTT(WithLine,$$,$1); }
  | expr ';' { NTT(WithLine,$$,$1, $2); }
  | WHILE '(' expr ')' block { NTT(WithLine,$$,$1,$2,$3,$4,$5) }
  | RETURN expr ';' { NTT(WithLine,$$,$1,$2,$3) }
  | IF '(' expr ')' block ELSE block { NTT(WithLine,$$,$1,$2,$3,$4,$5,$6,$7) }
  ;

expr
  : CONSTANT
  | STRING_LITERAL
  | IDENTIFIER
  | assign
  | funccall
  | '(' expr ')' { NT($$,$1,$2,$3) }
  | expr '+' expr { NT($$,$1,$2,$3) }
  | expr '-' expr { NT($$,$1,$2,$3) }
  | expr '*' expr { NT($$,$1,$2,$3) }
  | expr '/' expr { NT($$,$1,$2,$3) }
  | expr '%' expr { NT($$,$1,$2,$3) }
  | expr ">>" expr { NT($$,$1,$2,$3) }
  | expr "<<" expr { NT($$,$1,$2,$3) }
  | expr "<=" expr { NT($$,$1,$2,$3) }
  | expr ">=" expr { NT($$,$1,$2,$3) }
  | expr ">" expr { NT($$,$1,$2,$3) }
  | expr '<' expr { NT($$,$1,$2,$3) }
  | expr "==" expr { NT($$,$1,$2,$3) }
  | expr "!=" expr { NT($$,$1,$2,$3) }
  | expr "&" expr { NT($$,$1,$2,$3) }
  | expr "|" expr { NT($$,$1,$2,$3) }
  | expr "^" expr { NT($$,$1,$2,$3) }
  | expr "&&" expr { NT($$,$1,$2,$3) }
  | expr "||" expr { NT($$,$1,$2,$3) }
  | '-' expr %prec NEG { NT($$,$1,$2) }
  | '+' expr %prec NEG { NT($$,$1,$2) }
  ;

%%
