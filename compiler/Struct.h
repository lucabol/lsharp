#define StructDef1(N,t1,n1) t1[] n1[N]; int Idx = 0
#define StructDef2(N,t1,n1,t2,n2) StructDef1(N,t1,n1); t2[] n2[N]
#define StructDef3(N,t1,n1,t2,n2,t3,n3) StructDef2(N,t1,n1,t2,n2); t3[] n3[N]
#define StructDef4(N,t1,n1,t2,n2,t3,n3,t4,n4) StructDef3(N,t1,n1,t2,n2,t3,n3); t4[] n4[N]
#define StructDef5(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5) StructDef4(N,t1,n1,t2,n2,t3,n3,t4,n4); t5[] n5[N]
#define StructDef6(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6) StructDef5(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5); t6[] n6[N]
#define StructDef7(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6,t7,n7) StructDef6(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6); t7[] n7[N]


#define New1(N,t1,n1) int _New(t1 _##n1) { if(Idx >= N) { \
  Die("Too many objects");} \
  n1[Idx] = _##n1; \
  return Idx++;}

#define New2(N,t1,n1,t2,n2) int _New(t1 _##n1, t2 _##n2) { if(Idx >= N) { \
  Die("Too many objects");} \
  n1[Idx] = _##n1; \
  n2[Idx] = _##n2; \
  return Idx++;}

#define New3(N,t1,n1,t2,n2,t3,n3) int _New(t1 _##n1, t2 _##n2, t3 _##n3) { if(Idx >= N) { \
  Die("Too many objects");} \
  n1[Idx] = _##n1; \
  n2[Idx] = _##n2; \
  n3[Idx] = _##n3; \
  return Idx++;}

#define New4(N,t1,n1,t2,n2,t3,n3,t4,n4) int _New(t1 _##n1,t2 _##n2,t3 _##n3,t4 _##n4) { if(Idx >= N) { \
  Die("Too many objects");} \
  n1[Idx] = _##n1; \
  n2[Idx] = _##n2; \
  n3[Idx] = _##n3; \
  n4[Idx] = _##n4; \
  return Idx++;}

#define New5(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5) int _New(t1 _##n1,t2 _##n2,t3 _##n3,t4 _##n4,t5 _##n5) { if(Idx >= N) { \
  Die("Too many objects");} \
  n1[Idx] = _##n1; \
  n2[Idx] = _##n2; \
  n3[Idx] = _##n3; \
  n4[Idx] = _##n4; \
  n5[Idx] = _##n5; \
  return Idx++;}

#define New6(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6) int _New(t1 _##n1,t2 _##n2,t3 _##n3,t4 _##n4,t5 _##n5,t6 _##n6) { if(Idx >= N) { \
  Die("Too many objects");} \
  n1[Idx] = _##n1; \
  n2[Idx] = _##n2; \
  n3[Idx] = _##n3; \
  n4[Idx] = _##n4; \
  n5[Idx] = _##n5; \
  n6[Idx] = _##n6; \
  return Idx++;}

#define New7(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6,t7,n7) int _New(t1 _##n1,t2 _##n2,t3 _##n3,t4 _##n4,t5 _##n5,t6 _##n6, t7 _##n7) { if(Idx >= N) { \
  Die("Too many objects");} \
  n1[Idx] = _##n1; \
  n2[Idx] = _##n2; \
  n3[Idx] = _##n3; \
  n4[Idx] = _##n4; \
  n5[Idx] = _##n5; \
  n6[Idx] = _##n6; \
  n7[Idx] = _##n7; \
  return Idx++;}

#define Struct1(N,t1,n1) StructDef1(N,t1,n1); New1(N,t1,n1)
#define Struct2(N,t1,n1,t2,n2) StructDef2(N,t1,n1,t2,n2); New2(N,t1,n1,t2,n2)
#define Struct3(N,t1,n1,t2,n2,t3,n3) StructDef3(N,t1,n1,t2,n2,t3,n3); New3(N,t1,n1,t2,n2,t3,n3)
#define Struct4(N,t1,n1,t2,n2,t3,n3,t4,n4) StructDef4(N,t1,n1,t2,n2,t3,n3,t4,n4); New4(N,t1,n1,t2,n2,t3,n3,t4,n4)
#define Struct5(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5) StructDef5(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5); New5(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5)
#define Struct6(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6) StructDef6(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6); New6(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6)
#define Struct7(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6,t7,n7) StructDef7(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6,t7,n7); New7(N,t1,n1,t2,n2,t3,n3,t4,n4,t5,n5,t6,n6,t7,n7)
