#include <stdint.h>

int bar(int c);

uint64_t __global_ptrauth_device_base = 0x10;

int foo(int a){
  int b = 5;
  return a + b;
}

int bar(int c) {
  int d = 6;
  return d + c;
}

int main() {
  foo(4);
  bar(3);
  return 0;
}
