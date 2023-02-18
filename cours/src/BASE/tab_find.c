#include <stdio.h>

int tab_find(int tab[], int len, int elem) {
  int x = 0;
  while (x < len) {
    if (tab[x] == elem) {
      return x;
    }
    x++;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  printf("%d\n", tab_find((int[]){11, 24, 3, 8, 14}, 5, 24));
  return 0;
}
