#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src) {
  // if src is NULL, return NULL
  if (src == NULL) {
    return NULL;
  }
  // get the length of src
  size_t len = strlen(src);
  // allocate memory for the buffer
  char *buf = malloc(len + 1);
  // if malloc failed, return NULL
  if (buf == NULL) {
    return NULL;
  }
  // copy the content of src to buf
  for (size_t i = 0; i < len; i++) {
    buf[i] = src[i];
  }
  // terminate the string
  buf[len] = '\0';
  // return the buffer
  return buf;
}

int main(int argc, char **argv) {
  // create a string
  char s[] = "Hello World!";
  // copy the string to a buffer
  char *buf = buf_strcpy(s);
  // print the buffer
  printf("The buffer contains \"%s\" \n", buf);
  // free the buffer
  free(buf);
  return EXIT_SUCCESS;
}
