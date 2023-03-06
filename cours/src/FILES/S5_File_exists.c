#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int file_exists(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    close(fd);
    return 0;
}


int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}
