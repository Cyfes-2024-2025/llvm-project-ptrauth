int bar(int c);

int test_var = 5;

int foo(int a){
  int b = 5;
  test_var = bar(b);
  return a + b;
}

int bar(int c) {
  int d = 6;
  foo(d + test_var);
  return d + c;
}

int main() {
  foo(4);
  bar(3);
  return 0;
}
