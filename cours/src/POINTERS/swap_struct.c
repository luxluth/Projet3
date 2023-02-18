#include <stdio.h>
#include <stdlib.h>

struct fract_t {
  int num;
  int denum;
};

void swap(struct fract_t *a, struct fract_t *b) {
  struct fract_t temp = *a;
  *a = *b;
  *b = temp;
}

int main(int argc, char **argv) {
  struct fract_t a = {1, 2};
  struct fract_t b = {3, 4};
  printf("a = %d/%d, b = %d/%d \n", a.num, a.denum, b.num, b.denum);
  swap(&a, &b);
  printf("a = %d/%d, b = %d/%d \n", a.num, a.denum, b.num, b.denum);
  return EXIT_SUCCESS;
}
