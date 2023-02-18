#include <stdio.h>
#include <stdlib.h>


size_t strlen(const char* s) {
  size_t len = 0;
  while (*s++ != '\0') {
    len++;
  }
  return len;
}


int main(int argc, char *argv[]) {
  char s[] = "Hello World!";
  printf("The length of \"%s\" is %zu \n", s, strlen(s));
  return EXIT_SUCCESS;
}
