#include <stdio.h>
/**
 * @brief strcat - concatenate two strings
 * @param dest: the destination string
 * @param src: the source string
 * @return: the pointer to the destination string
 * @note: the destination string must have enough space to hold the result
 */
char *strcat(char *dest, const char *src) {
  // p is a pointer to the end of the dest string
  char *p = dest;
  // find the end of the dest string
  // Go to '/0'
  while (*p) {
    // move p to the next character
    p++;
  }
  while (*src) {
    // copy the character from src to dest
    *p++ = *src++;
  }
  // add the null terminator
  *p = '\0';
  return dest;
}

int main(int argc, char *argv[]) {
  char dest[100] = "Hello ";
  char l[100] = "Hello ";
  char src[] = "World!";
  printf("%s + %s = %s \n", l, src, strcat(dest, src));
  return 0;
}
