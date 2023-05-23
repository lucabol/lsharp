`int* kp;`

int main() {
  `
    int k = 0;
    kp = &k;
    int j = *kp; 
  `
  return j;
}
