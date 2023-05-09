%code requires {
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
}

%code top {

  #define SPAN_IMPL
  #define BUFFER_IMPL
  #define OS_STDC_IMPL
  #include "ulib/Span.h"
  #include "ulib/Buffer.h"
  #include "ulib/OsStdc.h"

  // Buffers for the header and code files for the generated code. Also for reading and writing the files.
  #define MAXFILESIZE 1024 * 1024
  Byte  _code[MAXFILESIZE], _header[MAXFILESIZE], _infile[MAXFILESIZE];

  // Buffers to write to while parsing a file
  Buffer* code;
  Buffer* header;

  #define P(...) BufferLCopy(code, __VA_ARGS__)
  #define K(v) (char*)SpanTo1KTempString(v)
}

%define api.value.type {Span}

%define parse.error detailed
%locations

%token NAMESPACE "namespace" USING "using" CLASS "class" PUBLIC "public" IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token STATIC AUTO
%token CHAR INT LONG FLOAT DOUBLE CONST VOID
%token BOOL
%token STRUCT ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token TRUE FALSE

%%
compilation_unit
  : namespace_declaration using_directives class_declaration
  ;

namespace_declaration
  : %empty
  | NAMESPACE IDENTIFIER ';'
  ;

using_directive
  : USING IDENTIFIER ';' { P("#include \"", K($2), ".h\"");}

using_directives
  : %empty
  | using_directives using_directive
  ;

class_modifier
  : STATIC
  | PUBLIC  
  ;

class_modifiers
  : %empty
  | class_modifiers class_modifier
  ;

class_declaration
  : %empty
  | class_modifiers CLASS IDENTIFIER '{' class_body '}'

class_body
  : %empty
  | IDENTIFIER
  ;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

/*
void yyerror(const char *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
*/


void
yyerror (char const *s)
{
  fprintf(stderr, "ERROR line %d: %s\n", yylloc.first_line, s);
}

int parse(Buffer* codeBuffer, Buffer* headerBuffer) {
  code = codeBuffer;
  header = headerBuffer;
  return yyparse();
}

int themain(int argc, char* argv[]) {

  int k, index, optind = 0;
  while ((k = getopt (argc, argv, "")) != -1) {

  }

  for (index = ++optind; index < argc; index++) {
    Buffer c    = BufferInit(_code, MAXFILESIZE);
    Buffer h    = BufferInit(_header, MAXFILESIZE);
    Buffer file = BufferInit(_infile, MAXFILESIZE);

    SpanResult sr = OsSlurp(argv[index], MAXFILESIZE, &file);

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

    set_buffer(biggerSpan);
    int ret = parse(&c, &h);
    delete_buffer();
    
    printf("%s:\n", argv[index]);
    OsPrintBuffer(&h);
    OsPrintBuffer(&c);
    puts("");

    if(ret) {
      fprintf(stderr, "%s\n", "Parse error.");
    }
  }

  return 0;
}
