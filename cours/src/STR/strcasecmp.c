#include <stdio.h>
#include <stdlib.h>

int strcasecmp(const char *s1, const char *s2) {
  // compare the characters of the two strings
  while (*s1 != '\0' && *s2 != '\0') {
    // if the characters are different
    if (*s1 != *s2) {
      // if the character is uppercase
      if (*s1 >= 'A' && *s1 <= 'Z') {
        // if the lowercase version of the character is different
        if (*s1 + 32 != *s2) {
          return *s1 - *s2;
        }
      // if the character is lowercase
      } else if (*s1 >= 'a' && *s1 <= 'z') {
        // if the uppercase version of the character is different
        if (*s1 - 32 != *s2) {
          return *s1 - *s2;
        }
      // if the character is not a letter
      } else {
        return *s1 - *s2;
      }
    }
    // move to the next character
    s1++;
    // move to the next character
    s2++;
  }
  return *s1 - *s2;
}

int main(int argc, char *argv[]) {
  char *s1 = "Hello";
  char *s2 = "hello";
  printf("%d \n", strcasecmp(s1, s2));
  return EXIT_SUCCESS;
}
