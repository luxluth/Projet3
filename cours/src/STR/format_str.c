#include <stdio.h>

void format_str(char *buffer, unsigned int d, char *name, char initial) {
  sprintf(buffer, "Mister %s %c. has %d eggs", name, initial, d);
  printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
  return 0;
}
