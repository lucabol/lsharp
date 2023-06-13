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

// Generated from xxd from libinc.h
#include "libinc.c"


// Buffers for the header and code files for the generated code. Also for reading and writing the files.
// TODO: need to malloc different ones instead of using same one
Byte  _code[MAXFILESIZE], _header[MAXFILESIZE], _arrays[MAXSPANBUF], _spans[MAXSPANBUF], _infile[MAXFILESIZE], _errors[MAXERRORBUF];

inline void
die(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  abort();
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
void hpreamble(Buffer* b, Span inclName) {
  Span filename = SpanExtractFileName('/', inclName);
  Span up = Span1KToUpper(filename);

  BufferMLCopy(0, b, S("#ifndef "), up, S("_H"));
  BufferMLCopy(0, b, S("#define "), up, S("_H"), S("\n"));

  Span libheader = SPAN(__libinc_h, __libinc_h_len);
  BufferMLCopy(0, b, libheader);
}
void hpostamble(Buffer* b) {
  BufferSLCopy(0,b, "\n#endif");
}

int themain(int argc, char* argv[]) {

  int k, index;
  char* tempDirValue = "/tmp";

  // Build preprocessor command
  Byte _cppcmd[MAXCMDLINE];
  Buffer cppcmd = BufferInit(_cppcmd, MAXCMDLINE);
  BufferSCopy(' ', &cppcmd, CPP);
  BufferSCopy(' ', &cppcmd, CPPFLAGS);

  // Build compiler command
  Byte _cmd[MAXCMDLINE];
  Buffer cmd = BufferInit(_cmd, MAXCMDLINE);
  BufferSCopy(' ', &cmd, COMP);
  BufferSCopy(' ', &cmd, CFLAGS);

  // Process command line options
  while ((k = getopt (argc, argv, "gOco:pdt:")) != -1) {
    switch(k) {
      case 'd': // Debug parser
        yydebug = 1;
        break;
      case 't': // Select temporary directory for c files (/tmp is default)
        tempDirValue = optarg;
        break;
      case 'p': // Show into console (does it work??)
        tempDirValue = NULL;
        break;
      case 'g': // Compile with debug symbols
        BufferSCopy(' ', &cmd, " ", OPT_g);
        break;
      case 'O': // Compile optimized
        BufferSCopy(' ', &cmd, " ", OPT_O);
        break;
      case 'c': // Compile to object file (don't look for main)
        BufferSCopy(' ', &cmd, " ", OPT_c);
        break;
      case 'o': // Specifiy name of resulting executable
        BufferSCopy(' ', &cmd, " ", OPT_o, optarg);
        break;
      default:
        abort();
    }
  }

  for (index = optind; index < argc; index++) {
    
    char* filename = argv[index];

    // Run preprocessor on input file generating a filename.i file to pass to gcc
    // I need to run the preprocessor before the compiler because the macros should be defined
    // in my language, not in the C language. The latter would be the case if I run the preprocessor
    // after I have transpiled from my language to C.
    Byte cppbuf[512];
    Span cppname = buildFileName(cppbuf, sizeof(cppbuf), filename, tempDirValue, ".i");

    Size savedBuf = cppcmd.index;
    // This is very brittle. It removes some lines that the preprocessor inserts.
    // Using -P has the strange side effect of removing newlines from the file.
    BufferMCopy(' ', &cppcmd, SpanFromString(filename), S("| sed '/^#/d' > "), cppname);
    char* scmd = (char*)SpanTo1KTempString(BufferToSpan(&cppcmd));
    int cppResult = system(scmd);
    if(cppResult) {
      die("Error running the preprocessor");
    }
    cppcmd.index = savedBuf;
    
    Buffer file = BufferInit(_infile, MAXFILESIZE);
    Buffer e    = BufferInit(_errors, MAXERRORBUF);

    SymInit();
    AstInit();

    Env env = {
      .startNode = -1,
      .filename = filename,
      .e = &e,
    };

    char* preprocFileName = (char*)SpanTo1KTempString(cppname);
    SpanResult sr = OsSlurp(preprocFileName, MAXFILESIZE, &file);
    if(sr.error) {
      die(sr.error);
    }
    // For flex, you need to add two 0 bytes at the end of the buffer to avoid copying the data.
    if(sr.data.len > MAXFILESIZE - 2) {
      die("File too big.");
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

    if(env.e->index || ret) { // Errors in syntactic analys. Should we not exit here and do semantic analysis?
      OsPrintBuffer(env.e);
      return 1;
    }
    Buffer c    = BufferInit(_code, MAXFILESIZE);
    Buffer h    = BufferInit(_header, MAXFILESIZE);

    Buffer arrays    = BufferInit(_arrays, MAXSPANBUF);
    Buffer spans     = BufferInit(_spans, MAXSPANBUF);

    Byte hbuf  [512];
    Byte cbuf  [512];

    Span hname   = buildFileName(hbuf,   sizeof(hbuf), filename, tempDirValue, ".h");
    Span cname   = buildFileName(cbuf,   sizeof(cbuf),filename, tempDirValue, ".c");

    Span nsp     = SpanExtractFileName('/', SpanFromString(filename));

    Context ctx = { .c = &c, .h = &h, .e = &e, .arrays = &arrays, .spans = &spans,
                    .filename = filename, .name_space = nsp };

    hpreamble(&h, hname);
    cpreamble(&c, hname);

    visit(env.startNode, &ctx);
    if(ctx.e->index) { // Errors in semantic analysis.
      OsPrintBuffer(ctx.e);
      return 1;
    }

    hpostamble(&h);

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
