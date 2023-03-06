#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

typedef struct point {
    int x;
    int y;
    int z;
} point_t;

int save(point_t *pt, int size, char *filename) {
    int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        // error opening the file
        return -1;
    }

    // calculate the total size of the array in bytes
    int total_size = size * sizeof(point_t);

    // extend the size of the file to hold the entire array
    if (ftruncate(fd, total_size) == -1) {
        // error extending the size of the file
        close(fd);
        return -6;
    }

    // map the file into memory
    point_t *map = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        // error mapping the file
        close(fd);
        return -3;
    }

    // copy the array into the memory-mapped file
    memcpy(map, pt, total_size);

    // sync the changes made to the memory-mapped file back to the file on disk
    if (msync(map, total_size, MS_SYNC) == -1) {
        // error syncing the memory-mapped file
        munmap(map, total_size);
        close(fd);
        return -5;
    }

    // unmap the file from memory
    if (munmap(map, total_size) == -1) {
        // error unmapping the file
        close(fd);
        return -4;
    }

    // close the file
    if (close(fd) == -1) {
        // error closing the file
        return -2;
    }

    return 0;
}

int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}
