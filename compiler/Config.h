#define MAXLEXERS 1 // How many lexers in play at one time 

// Tokens
#define TokIdentifier 0
#define TokKeyword    1
#define TokChar       2

#define Die(msg) { TRAP(___ptr msg);}
