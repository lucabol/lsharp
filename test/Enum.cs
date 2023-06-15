enum TestEnum {
  Dog,
  Rob = 3,
  Job,
}

int main() {
  TestEnum e = Rob;
  return e - 3;
}
