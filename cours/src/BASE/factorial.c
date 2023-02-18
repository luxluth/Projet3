#include <stdio.h>
#include <stdlib.h>

size_t factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return factorial(n - 1) * n;
}

int main(int argc, char *argv[]) {
  printf("%zu\n", factorial(80));
  return 0;
}
