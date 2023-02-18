#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j) {
  int temp = *i;
  *i = *j;
  *j = temp;
}

int main(int argc, char **argv) {
  int i = 1;
  int j = 2;
  printf("i = %d, j = %d \n", i, j);
  swap(&i, &j);
  printf("i = %d, j = %d \n", i, j);
  return EXIT_SUCCESS;
}
