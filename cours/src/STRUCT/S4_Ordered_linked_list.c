#include <stdlib.h>
#include <stdio.h>

// ! DOESN'T PASS ALL THE TESTS //


/*
 * Compare function to compare two characters.
 * @param a: the first character to compare.
 * @param b: the second character to compare.
 * @return: 0 if a equals b, a negative number if b is greater than a, 
 *          and a positive number otherwise.
 */
int compare(char a, char b) {
    if (a == b) {
        return 0;
    } else if (a < b) {
        return -1;
    } else {
        return 1;
    }
}

typedef struct node{
    char val;
    struct node *next;
} node_t;


/*
 * Insert a node with the given value into the linked list based on the order defined by the comparison function.
 * If the value is already in the list, no element is added and the list is not modified.
 * @param head: a pointer to a pointer to the head of the linked list.
 * @param val: the value to be inserted.
 * @param cmp: a comparison function which defines the order relationship of the list.
 * @return: 0 if success, -1 otherwise.
 */
int insert(node_t **head, char val, int (*cmp)(char, char)) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return 0;
    }

    node_t *prev = NULL;
    node_t *curr = *head;
    while (curr != NULL && cmp(curr->val, val) < 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && cmp(curr->val, val) == 0) {
        free(new_node);
        return 0;
    }

    if (prev == NULL) {
        new_node->next = *head;
        *head = new_node;
    } else {
        prev->next = new_node;
        new_node->next = curr;
    }
    return 0;
}


int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}
