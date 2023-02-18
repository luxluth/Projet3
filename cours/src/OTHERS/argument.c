#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i += 2) {
    printf("%s", argv[i]);
    if (i + 2 < argc) {
      printf(" ");
    }
  }
  printf("\n");
  return EXIT_SUCCESS;
}
