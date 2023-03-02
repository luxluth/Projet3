#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// cmp_func
int cmp_func(uint8_t (*a)(uint8_t), uint8_t (*b)(uint8_t)) {
    
    for (uint8_t i = 0; i < UINT8_MAX; i++) {
        if (a(i) != b(i)) return 0;
    }

    return 1;
}



int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}
