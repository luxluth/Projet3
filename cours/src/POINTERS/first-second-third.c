#include <stdio.h>
#include <stdlib.h>

/*
 * You found a hint from the hacker, telling the first parameter is located at
 * the 12th byte after ptr. An int is guaranteed to be 4 bytes long. Write the
 * body of the function first which returns the integer at that position in
 * memory.
 * */
int first(void *ptr) {
    int *p = (int*)((char*)ptr + 12);
    return *p;
}

char second(void *ptr) {
    char *p = (char*)((char*)ptr + 6);
    return *p;
}

int third(void *ptr) {
    int *p = (int*)((char*)ptr + 45);
    return *p;
}



int main(int argc, char **argv) {
  int a = 25;

  return 0;
}
