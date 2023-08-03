#define KB 1024
#define MB KB * KB

#define MAXLEXERS  5         // How many lexers in play at one time 
#define MAXBUFFERS 100       // How many buffers in play at one time 
                         
#define MAXTOKENS   1*MB           // Max number of Tokens
#define MAXNODES    1*MB           // Max number of nodes
#define MAXCHILDREN MAXNODES*3     // Max total number of children among all nodes

#define Die(msg) { TRAP(___ptr msg);}
