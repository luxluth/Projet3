#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct node {
    struct node *next;
    int hash;
    int id;
    char name[20];
    char buffer[100];
    unsigned int timestamp;
    char acl;
    short flow;
    char *parent;
    void *fifo;
};

/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head){
    if (head == NULL) return NULL;
    struct node *cp_head = malloc(sizeof(struct node));
    if (cp_head == NULL) return NULL;
    memcpy(cp_head, head, sizeof(struct node));
    cp_head->next = NULL;
    struct node *cp_pos = cp_head;
    struct node *current = head;
    while (current->next != NULL && current->next->next != NULL) {
        cp_pos->next = malloc(sizeof(struct node));
        if (cp_pos->next == NULL) return NULL;
        memcpy(cp_pos->next, current->next->next, sizeof(struct node));

        cp_pos->next->next = NULL;
        current = current->next->next;
        cp_pos = cp_pos->next;
    }

    return cp_head;
}

int main(int argc, char *argv[]){

    return EXIT_SUCCESS;
}
