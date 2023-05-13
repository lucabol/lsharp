#define SPAN_IMPL
#define BUFFER_IMPL
#define OS_STDC_IMPL
#define AST_IMPL

#include "config.h"
#include "lcs.lex.h"
#include "ast.h"

// Buffers for the header and code files for the generated code. Also for reading and writing the files.
// TODO: need to malloc different ones instead of using same one
Byte  _code[MAXFILESIZE], _header[MAXFILESIZE], _infile[MAXFILESIZE];

void yyerror(YYLTYPE *locp, yyscan_t scanner, char const *msg) {
  Env* env = yyget_extra(scanner);
  fprintf(stderr, "File:%s Line:%i Column:%i %s\n", env->filename, locp->first_line, locp->first_column, msg);
}

void visit(int node, Buffer* c, Buffer* h);

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
    
    Buffer file = BufferInit(_infile, MAXFILESIZE);

    char* filename = argv[index];

    SpanResult sr = OsSlurp(filename, MAXFILESIZE, &file);

    Env env = {
      .startNode = -1,
      .filename = filename
    };

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

    yyscan_t scanner;
    if(yydebug) yyset_debug(1, scanner);

    yylex_init_extra(&env, &scanner);
    YY_BUFFER_STATE state = yy_scan_buffer((char*)biggerSpan.ptr, (int)biggerSpan.len, scanner);
    int ret = yyparse(scanner);
    yy_delete_buffer(state, scanner);
    yylex_destroy(scanner);

    if(env.startNode < 0) {
      puts("Error constructing the parse tree?");
    }

    Buffer c    = BufferInit(_code, MAXFILESIZE);
    Buffer h    = BufferInit(_header, MAXFILESIZE);

    visit(env.startNode, &c, &h);

    OsPrintBuffer(&h);
    OsPrintBuffer(&c);
    
    return ret;
  }

  return 0;
}
