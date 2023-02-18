#include <stdio.h>
#include <stdlib.h>

/*
 * You found a hint from the hacker, telling the first parameter is located at
 * the 12th byte after ptr. An int is guaranteed to be 4 bytes long. Write the
 * body of the function first which returns the integer at that position in
 * memory.
 * */
int first(void *ptr) {
  int at = 11;
  while (at >= 12) {
    *ptr++;
  }
  int res = ptr;
  return res;
}

int main(int argc, char **argv) {
  int a = 25;
  int *p = a;

  printf("%p\n", &p);
}
