%code requires {
  typedef void* yyscan_t;
}

%code top {
  #include "config.h"
  #include "lcs.lex.h"
  #include "ast.h"
  #include "symtable.h"

}

%define locations
%define api.pure
%param { yyscan_t scanner }

%define parse.error detailed
%define parse.trace

%define api.value.type { int }

%define lr.type ielr
%glr-parser
%expect 320

%token NAMESPACE "namespace" USING "using" IDENTIFIER "identifier" CONSTANT "constant" STRING_LITERAL "string literal" SIZEOF "sizeof"
%token INC_OP "++" DEC_OP "--" LEFT_OP "<<" RIGHT_OP ">>" LE_OP "<=" GE_OP ">=" EQ_OP "==" NE_OP "!="
%token AND_OP "&&" OR_OP "||" MUL_ASSIGN "*=" DIV_ASSIGN "/=" MOD_ASSIGN "%=" ADD_ASSIGN "+="
%token SUB_ASSIGN "-=" LEFT_ASSIGN "<<=" RIGHT_ASSIGN ">>=" AND_ASSIGN "&="
%token XOR_ASSIGN "^=" OR_ASSIGN "|=" TYPE_NAME "type name"
%token ENUM "enum"
%token CASE "case" DEFAULT "default" IF "if" ELSE "else" SWITCH "switch" WHILE "while" DO "do" FOR "for" GOTO "goto" CONTINUE "continue" BREAK "break" RETURN "return"

%token NEW "new" CCODE "c code"
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

  #define GETLOC YYLTYPE* loc = yyget_lloc(scanner)
  #define NT(vv,...) vv = CreateNt(Generic, __VA_ARGS__); 
  #define NTT(kind,vv,...) vv = CreateNt(kind, __VA_ARGS__); 
  #define EMPTY(vv) { GETLOC; vv = CreateToken(Token,"",0,loc->first_line,loc->first_column); }
  #define ST(name,sym) AddGSym(scanner, name, sym)
  #define STQ(name,sym) AddGSymQuoted(scanner, name, sym)

  void AddGSym(yyscan_t scanner,int i, SymType t); 
void AddGSymQuoted(yyscan_t scanner,int i, SymType t);
}

%%

translation_unit
  : namespace_decl usings_list decl_or_func_or_code_list {
    NT($$,$1,$2,$3)
    Env* env = yyget_extra(scanner);
    env->startNode = $$;
    }
  ;

namespace_decl
  : %empty {EMPTY($$)}
  | NAMESPACE IDENTIFIER ';' { NT($$,$1,$2,$3) }
  ;

ccode
  : CCODE { NTT(CCode,$$,$1) }
  ;

usings_list
  : %empty {EMPTY($$)}
  | usings_list using_dir { NT($$,$1,$2) }
  ;

using_dir
  : USING IDENTIFIER '.' IDENTIFIER ';' { NTT(Using,$$,$2); ST($2,SymCUsing); }
  | USING IDENTIFIER ';'                { NTT(Using,$$,$2); ST($2,SymUsing);}
  | USING STRING_LITERAL ';'            { NTT(Using,$$,$2); STQ($2,SymQuotedUsing);}
  ;

decl_or_func_or_code_list
  : %empty {EMPTY($$)}
  | decl_or_func_or_code_list decl_or_func_or_code { NT($$,$1,$2) }
  ;

decl_or_func_or_code
  : decl { NTT(GlobalDecl, $$, $1) }
  | func
  | ccode
  ;

type
  : valuetype
  | slicetype
  ;

slicetype
  : valuetype '[' ']' { NT($$,$1,$2,$3) }
  ;

decl
  : valuedecl
  | slicedecl
  | refdecl
  ;

refdecl
  : valuetype refassign refassign_list ';'  { NTT(DeclAssign,$$,$1,$2,$3,$4) }
  ;

refassign_list
  : %empty { EMPTY($$) } 
  | refassign_list ',' refassign { NT($$,$1,$2,$3) }
  ;

refassign
  : IDENTIFIER '[' '*' ']'                            { NTT(RefAssign,$$,$1,$2,$4) }
  | IDENTIFIER '[' '*' ']' '=' '{' expr_list '}'      { NTT(RefAssign,$$,$1,$2,$4,$5,$6,$7,$8) }
  | IDENTIFIER '[' '*' ']' '=' STRING_LITERAL         { NTT(RefAssign,$$,$1,$2,$4,$5,$6) }
  | IDENTIFIER '[' '*' ']' '=' IDENTIFIER             { NTT(RefAssign,$$,$1,$2,$4,$5,$6) }
  ;

slicedecl
  : valuetype sliceassign sliceassign_list ';'  { NTT(DeclAssign,$$,$1,$2,$3,$4) }
  ;

sliceassign_list
  : %empty {EMPTY($$) } 
  | sliceassign_list ',' sliceassign { NT($$,$1,$2,$3) }
  ;

sliceassign
  : IDENTIFIER '[' ']'                            { NTT(SliceAssign,$$,$1,$2,$3) }
  | IDENTIFIER '[' expr ']'                       { NTT(SliceAssign,$$,$1,$2,$3,$4) }
  | IDENTIFIER '[' expr ']' '=' '{' expr_list '}' { NTT(SliceAssign,$$,$1,$2,$3,$4,$5,$6,$7,$8) }
  | IDENTIFIER '[' ']' '=' '{' expr_list '}'      { NTT(SliceAssign,$$,$1,$2,$3,$4,$5,$6,$7) }
  | IDENTIFIER '[' ']' '=' STRING_LITERAL         { NTT(SliceAssign,$$,$1,$2,$3,$4,$5) }
  ;

valuetype
  : PTYPE { $$ = CreateToken(PrimitiveType, NodeName[$1] , NodeLen[$1], yylloc.first_line, yylloc.first_column); }
  | TYPE_NAME
  | PTYPE '*' { GETLOC; yyerror(loc, scanner, POINTERS);}
  ;

valuedecl
  : valuetype assign assign_list ';' { NTT(DeclAssign,$$,$1,$2,$3,$4) }
  ;

assign_list
  : %empty {EMPTY($$)}
  | assign_list ',' assign { NT($$,$1,$2,$3) }

assign
  : IDENTIFIER          { NTT(Assign,$$,$1) }
  | IDENTIFIER '=' expr { NTT(Assign,$$,$1,$2,$3) }
  ;

func
  : type IDENTIFIER '(' param_list ')' block { NTT(FuncDef,$$,$1,$2,$3,$4,$5,$6); ST($2,SymLocalFunc); }
  ;

funccall
  : IDENTIFIER '(' expr_list ')' { NT($$,$1,$2,$3,$4) }
  | qualidentifier '(' expr_list ')' { NT($$,$1,$2,$3,$4) }
  ;

param_list
  : %empty {EMPTY($$)}
  | paramdecl
  | param_list ',' paramdecl { NT($$,$1,$2,$3) }
  ;

paramdecl
  : type IDENTIFIER         { NT($$,$1,$2) }
  | type IDENTIFIER '[' ']' { NT($$,$1,$2,$3,$4) }
  ;

expr_list
  : %empty {EMPTY($$)}
  | expr
  | expr_list ',' expr { NT($$,$1,$2,$3) }
  ;

block
  : '{' stmts '}' { NTT(Block, $$,$1,$2,$3) }
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
  | FOR '(' expr_list ';' expr_list ';' expr_list ')' block { NTT(WithLine,$$,$1,$2,$3,$4,$5,$6,$7,$8,$9) }
  | RETURN expr ';' { NTT(WithLine,$$,$1,$2,$3) }
  | IF '(' expr ')' block ELSE block { NTT(WithLine,$$,$1,$2,$3,$4,$5,$6,$7) }
  | ccode
  ;

qualidentifier
  : IDENTIFIER '.' IDENTIFIER { NTT(QualIdentifier,$$,$1,$2,$3) }
  ;

expr
  : CONSTANT
  | STRING_LITERAL
  | IDENTIFIER
  | funccall
  | qualidentifier
  | '(' expr ')'           %dprec 1 { NT($$,$1,$2,$3) }
  | expr '=' expr          %dprec 1 { NT($$,$1,$2,$3) }
  | expr ADD_ASSIGN expr   %dprec 1 { NT($$,$1,$2,$3) }
  | expr MUL_ASSIGN expr   %dprec 1 { NT($$,$1,$2,$3) }
  | expr DIV_ASSIGN expr   %dprec 1 { NT($$,$1,$2,$3) }
  | expr SUB_ASSIGN expr   %dprec 1 { NT($$,$1,$2,$3) }
  | expr MOD_ASSIGN expr   %dprec 1 { NT($$,$1,$2,$3) }
  | expr '?' expr ':' expr %dprec 2 { NT($$,$1,$2,$3,$4,$5) }
  | expr "||" expr         %dprec 3 { NT($$,$1,$2,$3) }
  | expr "&&" expr         %dprec 4 { NT($$,$1,$2,$3) }
  | expr "|" expr          %dprec 5 { NT($$,$1,$2,$3) }
  | expr "^" expr          %dprec 6 { NT($$,$1,$2,$3) }
  | expr "&" expr          %dprec 7 { NT($$,$1,$2,$3) }
  | expr "==" expr         %dprec 8 { NT($$,$1,$2,$3) }
  | expr "!=" expr         %dprec 8 { NT($$,$1,$2,$3) }
  | expr "<=" expr         %dprec 9 { NT($$,$1,$2,$3) }
  | expr ">=" expr         %dprec 9 { NT($$,$1,$2,$3) }
  | expr ">" expr          %dprec 9 { NT($$,$1,$2,$3) }
  | expr '<' expr          %dprec 9 { NT($$,$1,$2,$3) }
  | expr ">>" expr         %dprec 10 { NT($$,$1,$2,$3) }
  | expr "<<" expr         %dprec 10 { NT($$,$1,$2,$3) }
  | expr '+' expr          %dprec 11 { NT($$,$1,$2,$3) }
  | expr '-' expr          %dprec 11 { NT($$,$1,$2,$3) }
  | expr '%' expr          %dprec 11 { NT($$,$1,$2,$3) }
  | expr '*' expr          %dprec 12 { NT($$,$1,$2,$3) }
  | expr '/' expr          %dprec 12 { NT($$,$1,$2,$3) }
  | '(' type ')' expr      %dprec 13 { NT($$,$1,$2,$3,$4) }
  | IDENTIFIER '[' expr ']' %dprec 13 { NT($$,$1,$2,$3,$4) }
  | qualidentifier '[' expr ']' %dprec 13 { NT($$,$1,$2,$3,$4) }
  | '-' expr %prec NEG     %dprec 13 { NT($$,$1,$2) }
  | '+' expr %prec NEG     %dprec 13 { NT($$,$1,$2) }
  | '!' expr %prec '!'     %dprec 13 { NT($$,$1,$2) }
  | '~' expr %prec '~'     %dprec 13 { NT($$,$1,$2) }
  | "++" expr %prec PREINCR %dprec 13 { NT($$,$1,$2) }
  | "--" expr %prec PREDECR %dprec 13 { NT($$,$1,$2) }
  | '&' expr                %dprec 13 { GETLOC; yyerror(loc, scanner, REFERENCES);}
  | expr "++" %prec POSTINCR %dprec 13 { NT($$,$1,$2) }
  | expr"--"  %prec POSTDECR %dprec 13 { NT($$,$1,$2) }
  ;

%%

void AddGSym(yyscan_t scanner,int i, SymType t) {
  Span s = SPAN((Byte*)NodeName[i], NodeLen[i]);
  SymGAdd(s, t);
}
void AddGSymQuoted(yyscan_t scanner,int i, SymType t) {
  Span sq = SPAN((Byte*)NodeName[i], NodeLen[i]);
  Span s  = SPAN(sq.ptr + 1, sq.len - 2);
  SymGAdd(s, t);
}
