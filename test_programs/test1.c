#include <stdio.h>

int bar(int c);

volatile void* __global_ptrauth_device_base;

int foo(int a) {
  int b = 5;
  printf("Hello from foo\n");
  return a + b;
}

int bar(int c) {
  int d = 6;
  printf("Hello from bar\n");
  return d + c;
}

int main() {
  printf("Hello from main\n");
  foo(4);
  bar(3);
  return 0;
}
