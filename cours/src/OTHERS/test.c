#include <stdio.h>
#include <stdlib.h>

// Définition des fonctions pour les opérations de comparaison
int equals(int a, int b) { return a == b; }
int greater_than(int a, int b) { return a > b; }
int greater_than_or_equal(int a, int b) { return a >= b; }
int less_than(int a, int b) { return a < b; }
int less_than_or_equal(int a, int b) { return a <= b; }
int not_equals(int a, int b) { return a != b; }

// Définition de la fonction test qui évalue une expression de comparaison
// à l'aide d'une des fonctions de comparaison définies ci-dessus
int test(int a, char* op, int b) {
    int result = 0;
    if (op[0] == '-') op++; // On ignore le "-" initial des opérations de comparaison
    switch (op[0]) {
        case 'e': result = equals(a, b); break;
        case 'g': result = (op[1] == 't') ? greater_than(a, b) : greater_than_or_equal(a, b); break;
        case 'l': result = (op[1] == 't') ? less_than(a, b) : less_than_or_equal(a, b); break;
        case 'n': result = not_equals(a, b); break;
        default: printf("Opérateur non reconnu : %s\n", op); exit(1);
    }
    return (result) == 1? 0 : 1;
}

int main(int argc, char *argv[])
{
    int res = test(atoi(argv[1]), argv[2], atoi(argv[3]));
    return res;
}
