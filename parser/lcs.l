D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			([Ee][+-]?{D}+)
P                       ([Pp][+-]?{D}+)
FS			(f|F|l|L)
IS                      ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%option noyywrap
%option yylineno

%{
  #include <stdio.h>
  #include <stdbool.h>
  #include "lcs.tab.h"

  #include "ulib/Span.h"

  void yyerror(const char *s);
  void comment(void);
  int check_type(void);


  #define YY_USER_ACTION yylval = SpanFromString(yytext); yylloc.first_line = yylloc.last_line = yylineno;

  YY_BUFFER_STATE lexState;
%}

%%
"/*"			{ comment(); }
"//"[^\n]*              { /* consume //-comment */ }


"namespace"	{ return(NAMESPACE); }
"using"   	{ return(USING); }
"class"   	{ return(CLASS); }
"static"   	{ return(STATIC); }
"public"   	{ return(PUBLIC); }
"var"			  { return(AUTO); }
"bool"			{ return(BOOL); }
"break"			{ return(BREAK); }
"case"			{ return(CASE); }
"char"			{ return(CHAR); }
"const"			{ return(CONST); }
"continue"  { return(CONTINUE); }
"default"		{ return(DEFAULT); }
"do"			  { return(DO); }
"double"		{ return(DOUBLE); }
"else"			{ return(ELSE); }
"enum"			{ return(ENUM); }
"float"			{ return(FLOAT); }
"for"			  { return(FOR); }
"goto"			{ return(GOTO); }
"if"			  { return(IF); }
"int"			  { return(INT); }
"long"			{ return(LONG); }
"return"		{ return(RETURN); }
"sizeof"		{ return(SIZEOF); }
"struct"		{ return(STRUCT); }
"switch"		{ return(SWITCH); }
"void"			{ return(VOID); }
"while"			{ return(WHILE); }

"true"			{ return(TRUE); }
"false"			{ return(FALSE); }

{L}({L}|{D})*		{ return(check_type()); }

0[xX]{H}+{IS}?		{ return(CONSTANT); }
0[0-7]*{IS}?		{ return(CONSTANT); }
[1-9]{D}*{IS}?		{ return(CONSTANT); }
L?'(\\.|[^\\'\n])+'	{ return(CONSTANT); }

{D}+{E}{FS}?		{ return(CONSTANT); }
{D}*"."{D}+{E}?{FS}?	{ return(CONSTANT); }
{D}+"."{D}*{E}?{FS}?	{ return(CONSTANT); }
0[xX]{H}+{P}{FS}?	{ return(CONSTANT); }
0[xX]{H}*"."{H}+{P}{FS}?     { return(CONSTANT); }
0[xX]{H}+"."{H}*{P}{FS}?     { return(CONSTANT); }



L?\"(\\.|[^\\"\n])*\"	{ return(STRING_LITERAL); }

"..."			{ return(ELLIPSIS); }
">>="			{ return(RIGHT_ASSIGN); }
"<<="			{ return(LEFT_ASSIGN); }
"+="			{ return(ADD_ASSIGN); }
"-="			{ return(SUB_ASSIGN); }
"*="			{ return(MUL_ASSIGN); }
"/="			{ return(DIV_ASSIGN); }
"%="			{ return(MOD_ASSIGN); }
"&="			{ return(AND_ASSIGN); }
"^="			{ return(XOR_ASSIGN); }
"|="			{ return(OR_ASSIGN); }
">>"			{ return(RIGHT_OP); }
"<<"			{ return(LEFT_OP); }
"++"			{ return(INC_OP); }
"--"			{ return(DEC_OP); }
"->"			{ return(PTR_OP); }
"&&"			{ return(AND_OP); }
"||"			{ return(OR_OP); }
"<="			{ return(LE_OP); }
">="			{ return(GE_OP); }
"=="			{ return(EQ_OP); }
"!="			{ return(NE_OP); }
";"			{ return(';'); }
("{"|"<%")		{ return('{'); }
("}"|"%>")		{ return('}'); }
","			{ return(','); }
":"			{ return(':'); }
"="			{ return('='); }
"("			{ return('('); }
")"			{ return(')'); }
("["|"<:")		{ return('['); }
("]"|":>")		{ return(']'); }
"."			{ return('.'); }
"&"			{ return('&'); }
"!"			{ return('!'); }
"~"			{ return('~'); }
"-"			{ return('-'); }
"+"			{ return('+'); }
"*"			{ return('*'); }
"/"			{ return('/'); }
"%"			{ return('%'); }
"<"			{ return('<'); }
">"			{ return('>'); }
"^"			{ return('^'); }
"|"			{ return('|'); }
"?"			{ return('?'); }

[ \t\v\n\f]		{ }
.			{ /* Add code to complain about unmatched characters */ }

%%

void comment(void)
{
	char c, prev = 0;
  
	while ((c = (char) input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	yyerror("unterminated comment");
}

int check_type(void)
{
	return IDENTIFIER;
}

void set_buffer(Span s) {
    lexState = yy_scan_buffer((char*)s.ptr, (int)s.len);
    //lexState = yy_scan_bytes((char*)s.ptr, (int)s.len);
}
void delete_buffer() {
    yy_delete_buffer(lexState);
}
