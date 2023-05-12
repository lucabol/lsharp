D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%option noyywrap
%option yylineno
%option fast

%{
  #include <stdio.h>
  #include <stdbool.h>
  #include "lcs.tab.h"

  #include "ulib/Span.h"

  void yyerror(const char *s);
  void comment(void);
  int check_type(void);


  YY_BUFFER_STATE lexState;

  void count();
%}

%%

"/*"			{ comment(); }
"//".*    { /* consume //-comment */ }

"namespace"	{ return(NAMESPACE); }
"using"			{ return(USING); }
"break"			{ return(BREAK); }
"case"			{ return(CASE); }
"continue"	{ return(CONTINUE); }
"default"		{ return(DEFAULT); }
"do"			  { return(DO); }
"else"			{ return(ELSE); }
"enum"			{ return(ENUM); }
"for"			  { return(FOR); }
"goto"			{ return(GOTO); }
"if"			  { return(IF); }
"return"		{ return(RETURN); }
"sizeof"		{ return(SIZEOF); }
"switch"		{ return(SWITCH); }
"while"			{ return(WHILE); }

"[]"        { return(SLICESYM); }

{L}({L}|{D})*		  { return(check_type()); }

0[xX]{H}+{IS}?		{ return(CONSTANT); }
0{D}+{IS}?		    { return(CONSTANT); }
{D}+{IS}?		      { return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ return(CONSTANT); }

{D}+{E}{FS}?		        { return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ return(STRING_LITERAL); }

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
"&&"			{ return(AND_OP); }
"||"			{ return(OR_OP); }
"<="			{ return(LE_OP); }
">="			{ return(GE_OP); }
"=="			{ return(EQ_OP); }
"!="			{ return(NE_OP); }

[ \t\v\n\f] {} // Ignore spaces

.			    { return(yytext[0]); }
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
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/
	return(IDENTIFIER);
}

void set_buffer(Span s) {
    lexState = yy_scan_buffer((char*)s.ptr, (int)s.len);

    yylineno = 1;
}

void delete_buffer() {
    yy_delete_buffer(lexState);
}
