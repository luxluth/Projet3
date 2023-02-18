#include <stdio.h>

int absval(int i) { return i < 0 ? -i : i; }

int main(int argc, char *argv[]) {
  printf("%d", absval(-3));
  return 0;
}
