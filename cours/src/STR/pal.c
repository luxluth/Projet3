#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief pal - checks if a string is a palindrome
 * @param str: the string to check
 * @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
 * @note: a palindrome is a string that is the same forwards and backwards.
 **/
int pal(char *str) {
  // if str is NULL
  if (str == NULL) {
    // return -1
    return -1;
  }
  // i is a pointer to the beginning of the string
  char *i = str;
  // j is a pointer to the end of the string
  char *j = str + strlen(str) - 1;
  // kayak is a palindrome and "kay a k" is a palindrome so we need to ignore spaces
  while (i < j) {
    // if the character at i is a space
    if (*i == ' ') {
      // move i to the next character
      i++;
      // continue to the next iteration of the loop
      continue;
    }
    // if the character at j is a space
    if (*j == ' ') {
      // move j to the previous character
      j--;
      // continue to the next iteration of the loop
      continue;
    }
    // if the character at i is not the same as the character at j
    if (*i != *j) {
      // return false (0)
      return 0;
    }
    // move i to the next character
    i++;
    // move j to the previous character
    j--;
  }

  // return true (1)
  return 1;
}


int main(int argc, char *argv[]) {
  char *str = "racecar";
  printf("%d \n", pal(str));
  char *l = "kay a k";
  printf("%d \n", pal(l));
  return EXIT_SUCCESS;
}
