D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%option noyywrap
%option fast

%option reentrant bison-bridge bison-locations
%option extra-type="Env*"
%option header-file="lcs.lex.h"

%x IN_COMMENT

%{
  #include "config.h"
  #include "ast.h"

  int check_type(void);


#define YY_USER_ACTION \
    *yylval = CreateToken(yytext, yyleng); \
    yylloc->first_line = yylloc->last_line; \
    yylloc->first_column = yylloc->last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc->last_line++; \
            yylloc->last_column = 0; \
        } \
        else { \
            yylloc->last_column++; \
        } \
    }

%}

%%

<INITIAL>{
  "/*"              BEGIN(IN_COMMENT);
}
<IN_COMMENT>{
  "*/"      BEGIN(INITIAL);
  [^*]+   // eat comment in chunks
  "*"       // eat the lone star
}

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

"new"       { return(NEW); }

"[]"        { return(SLICESYM); }

{L}({L}|{D})*		  { return(check_type()); }

0[xX]{H}+{IS}?		{ return(CONSTANT); }
{D}+{IS}?		      { return(CONSTANT); }

{D}+{E}{FS}?		        { return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ return(STRING_LITERAL); }

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
