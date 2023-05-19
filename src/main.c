#define SPAN_IMPL
#define BUFFER_IMPL
#define OS_STDC_IMPL
#define AST_IMPL
#define HASH_IMPL
#define SYMTABLE_IMPL

#include "ulib/Hash.h"
#include "config.h"
#include "lcs.lex.h"
#include "ast.h"
#include "visit.h"
#include "symtable.h"

// Buffers for the header and code files for the generated code. Also for reading and writing the files.
// TODO: need to malloc different ones instead of using same one
Byte  _code[MAXFILESIZE], _header[MAXFILESIZE], _infile[MAXFILESIZE], _errors[MAXERRORBUF];

void yyerror(YYLTYPE *locp, yyscan_t scanner, char const *msg) {
  Env* env = yyget_extra(scanner);
  fprintf(stderr, " %s %i:%i: error: %s\n", env->filename, locp->first_line, locp->first_column, msg);
}

Span buildFileName(Byte* buffer, int len, char* path, char* dir, char* ext) {
  
    Buffer btmp = BufferInit(buffer, len);
    SpanResult sr = {0};

    Span bname = SpanExtractFileName('/', SpanFromString(path));
    if(dir[strlen(dir) - 1] == '/') 
      sr = BufferSCopy(0, &btmp, dir, (char*)SpanTo1KTempString(bname), ext);
    else
      sr = BufferSCopy(0, &btmp, dir, "/", (char*)SpanTo1KTempString(bname), ext);

    if(sr.error) {
      fputs(sr.error, stderr);
      exit(1);
    }
    return sr.data;
}

void printBuffer(char* tempDirValue, Span targetFile, Buffer* b) {
  
    if(tempDirValue) {
      char* err = OsFlush((char*)SpanTo1KTempString(targetFile), BufferToSpan(b));
      if(err) {
        fputs(err, stderr);
        exit(1);
      }
    } else {
      OsPrintBuffer(b);
    }
}

void cpreamble(Buffer* b, Span inclName) {
  BufferSLCopy(0,b, "#include \"", (char*)SpanTo1KTempString(inclName), "\"");
}
void hpreamble(Buffer* b) {
  BufferSLCopy(0,b, "#include <stdint.h>\n#include <stdbool.h>");
}

int themain(int argc, char* argv[]) {

  int k, index;
  char* tempDirValue = "/tmp";

  Byte _cmd[MAXCMDLINE];
  Buffer cmd = BufferInit(_cmd, MAXCMDLINE);
  BufferSCopy(' ', &cmd, COMP);
  BufferSCopy(' ', &cmd, CFLAGS);

  while ((k = getopt (argc, argv, "gOco:pdt:")) != -1) {
    switch(k) {
      case 'd':
        yydebug = 1;
        break;
      case 't':
        tempDirValue = optarg;
        break;
      case 'p':
        tempDirValue = NULL;
        break;
      case 'g':
        BufferSCopy(' ', &cmd, " ", OPT_g);
        break;
      case 'O':
        BufferSCopy(' ', &cmd, " ", OPT_O);
        break;
      case 'c':
        BufferSCopy(' ', &cmd, " ", OPT_c);
        break;
      case 'o':
        BufferSCopy(' ', &cmd, " ", OPT_o, optarg);
        break;
      default:
        abort();
    }
  }

  for (index = optind; index < argc; index++) {
    
    SymInit();
    AstInit();

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

    yylex_init_extra(&env, &scanner);
    if(yydebug) yyset_debug(1, scanner);

    YY_BUFFER_STATE state = yy_scan_buffer((char*)biggerSpan.ptr, (int)biggerSpan.len, scanner);
    int ret = yyparse(scanner);
    yy_delete_buffer(state, scanner);
    yylex_destroy(scanner);

    if(ret != 0) { // Error in syntactic analysis (parsing)
      return ret;
    }

    Buffer c    = BufferInit(_code, MAXFILESIZE);
    Buffer h    = BufferInit(_header, MAXFILESIZE);
    Buffer e    = BufferInit(_errors, MAXERRORBUF);

    Byte hbuf[512];
    Byte cbuf[512];
    Span hname = buildFileName(hbuf, sizeof(hbuf), filename, tempDirValue, ".h");
    Span cname = buildFileName(cbuf, sizeof(cbuf),filename, tempDirValue, ".c");
    Span nsp   = SpanExtractFileName('/', SpanFromString(filename));

    Context ctx = { .c = &c, .h = &h, .e = &e, .filename = filename, .name_space = nsp };

    hpreamble(&h);
    cpreamble(&c, hname);

    visit(env.startNode, &ctx);
    if(ctx.e->index) { // Errors in semantic analysis
      OsPrintBuffer(ctx.e);
      return -2;
    }

    printBuffer(tempDirValue, hname, &h);
    printBuffer(tempDirValue, cname, &c);
    
    if(tempDirValue) {
      BufferMCopy(' ', &cmd, cname);
    }
  }


  if(tempDirValue) {
    char* scmd = (char*)SpanTo1KTempString(BufferToSpan(&cmd));
    return system(scmd);
  }

  return 0;
}
