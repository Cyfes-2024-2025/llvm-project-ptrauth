int bar(int c);

int foo(int a){
  int b = 5;
  bar(b);
  return a + b;
}

int bar(int c) {
  int d = 6;
  foo(d);
  return d + c;
}

int main() {
  foo(4);
  bar(3);
  return 0;
}
