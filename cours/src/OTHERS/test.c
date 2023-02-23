#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    return (result) ? 1 : 0; // On retourne 1 si l'expression est vraie, 0 sinon
}

// Fonction main qui teste plusieurs expressions de comparaison
int main() {
    int a = 5;
    int b = 7;

    // Test de l'opération d'égalité
    if (test(a, "-eq", b)) {
        printf("%d n'est pas égal à %d\n", a, b);
    } else {
        printf("%d est égal à %d\n", a, b);
    }

    // Test de l'opération de supériorité stricte
    if (test(a, "-gt", b)) {
        printf("%d est strictement inférieur à %d\n", a, b);
    } else {
        printf("%d n'est pas strictement inférieur à %d\n", a, b);
    }

    // Test de l'opération de supériorité ou égalité
    if (test(a, "-ge", b)) {
        printf("%d est inférieur à %d\n", a, b);
    } else {
        printf("%d est supérieur à %d ou %d\n", a, b, a);
    }

    // Test de l'opération d'infériorité stricte
    if (test(a, "-lt", b)) {
        printf("%d est strictement supérieur à %d\n", a, b);
    } else {
        printf("%d n'est pas strictement supérieur à %d\n", a, b);
    }

    // Test de l'opération d'infériorité ou égalité
    if (test(a, "-le", b)) {
        printf("%d est supérieur à %d\n", a, b);
    } else {
        printf("%d est inférieur à %d ou %d\n", a, b, b);
    }

}
