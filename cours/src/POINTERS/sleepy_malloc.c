#include <stdlib.h>
#include <unistd.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s) {
    void *p = NULL;
    int attempts = 0;
    while (attempts < 10) {
        p = malloc(s);
        if (p != NULL) {
            break;
        }
        sleep(5);
        attempts++;
    }
    return p;
}


int main(int argc, char **argv) {
  return 0;
}
