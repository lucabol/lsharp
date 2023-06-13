#define Max 100

int Idx = 0;

String[] Data[Max];
int[]    Index[Max];

int Init(String buffer) {
  if(Idx >= Max) {
    return -1;
  }

  Data [Idx] = buffer;
  Index[Idx] = 0;
  return Idx++;
}
