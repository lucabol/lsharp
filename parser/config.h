#define POINTERS  yyerror("You can't use pointers. Use indexed slices instead.");
#define STORAGE   yyerror("You can't use storage class specifiers (typedef, extern, static, auto, register).");
#define SIGNINT   yyerror("You can't use signed/unsigned. Use the type directly instad (int/uint, byte/sbyte, short/ushort, long/ulong)");
#define UNIONE     yyerror("You can't use unions. Use structs instead.");
#define TYPEQUAL     yyerror("You can't use type qualifiers.");
