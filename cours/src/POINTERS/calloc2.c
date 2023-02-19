#include <stdio.h>
#include <stdlib.h>

/*
Dans cette implémentation, nous commençons par calculer le nombre total d'octets à allouer (nmemb * size) et appelons malloc() pour allouer cet espace de mémoire. Si l'allocation réussit, nous parcourons ensuite chaque octet de la mémoire allouée et nous l'initialisons à zéro.

La variable p est un pointeur de type char qui pointe vers le début de la zone de mémoire allouée. Nous utilisons une boucle pour itérer sur chaque octet de la mémoire allouée, en commençant par p[0] et en continuant jusqu'à p[total_size - 1].

Enfin, nous renvoyons le pointeur vers la mémoire allouée. Si l'allocation a échoué, nous renvoyons un pointeur nul, tout comme calloc().

Il est important de noter que cette implémentation est moins efficace que l'implémentation de calloc() standard, car elle doit itérer sur chaque octet de la mémoire allouée et l'initialiser à zéro. Par conséquent, cette implémentation peut être plus lente que calloc() dans certaines situations. Cependant, elle peut être utile dans des cas où calloc() n'est pas disponible ou ne convient pas pour une raison quelconque.
*/

void *calloc2(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);
    if (ptr != NULL) {
        char *p = ptr;
        for (size_t i = 0; i < total_size; i++) {
            p[i] = 0;
        }
    }
    return ptr;
}


int main(int argc, char **argv) {
  return 0;
}
