%code requires {
  #include <stdio.h>
  #include <math.h>
  #include <stdbool.h>

  #include "ulib/Span.h"
  #include "ulib/Buffer.h"
  #include "ulib/OsStdc.h"
  #include "ulib/OptGet.h"

  #include "config.h"
  #include "ast.h"

  int yylex (void);
  void yyerror (char const *);

  // Sets and delete the buffer from which to parse the code.
  void set_buffer(Span s);
  void delete_buffer(void);
}

%code top {

  #define SPAN_IMPL
  #define BUFFER_IMPL
  #define OS_STDC_IMPL
  #define AST_IMPL

  #include "ulib/Span.h"
  #include "ulib/Buffer.h"
  #include "ulib/OsStdc.h"
  #include "ast.h"

  // Buffers for the header and code files for the generated code. Also for reading and writing the files.
  Byte  _code[MAXFILESIZE], _header[MAXFILESIZE], _infile[MAXFILESIZE];

  // Buffers to write to while parsing a file
  Buffer* code;
  Buffer* header;

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

%define lr.type ielr
%define parse.error detailed
%define parse.trace
%define api.value.type { int }
%glr-parser

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

#include <stdio.h>

extern char yytext[];
extern int yylineno;

static char* filename;

void
yyerror (char const *s)
{
  printf("%s:Line: %i %s\n", filename, yylineno, s);
}

int parse(Buffer* codeBuffer, Buffer* headerBuffer) {
  code = codeBuffer;
  header = headerBuffer;
  return yyparse();
}

int themain(int argc, char* argv[]) {

  int k, index;
  while ((k = getopt (argc, argv, "d")) != -1) {
    switch(k) {
      case 'd':
        yydebug = 1;
        break;
      default:
        abort();
    }
  }

  for (index = optind; index < argc; index++) {
    Buffer c    = BufferInit(_code, MAXFILESIZE);
    Buffer h    = BufferInit(_header, MAXFILESIZE);
    Buffer file = BufferInit(_infile, MAXFILESIZE);

    filename = argv[index];

    SpanResult sr = OsSlurp(filename, MAXFILESIZE, &file);

    if(sr.error) {
      fprintf(stderr, "%s\n", sr.error);
      return -1;
    }
    // For flex, you need to add two 0 bytes at the end of the buffer to avoid copying the data.
    if(sr.data.len > MAXFILESIZE - 2) {
      fprintf(stderr, "%s\n", "File too big.");
      return -1;
    }
    Span biggerSpan = SPAN(sr.data.ptr, sr.data.len + 2);
    biggerSpan.ptr[biggerSpan.len - 2] = 0;
    biggerSpan.ptr[biggerSpan.len - 1] = 0;

    printf("%s\n", "----------");
    printf("%s:\n", filename);
    printf("%s\n\n", "----------");

    set_buffer(biggerSpan);
    int ret = parse(&c, &h);
    delete_buffer();
    
    OsPrintBuffer(&h);
    OsPrintBuffer(&c);
    puts("");

    if(ret) {
      fprintf(stderr, "%s\n", "Parse error.");
    }
  }

  return 0;
}
