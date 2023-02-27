#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char *name;
};

int pop(struct node **head, char *result){
    if (head == NULL) return 1;
    struct node *temp = *head; // temporary pointer to the top element of the stack
    *head = temp->next; // move the head of the stack to the next element
    strncpy(result, temp->name, strlen(temp->name) + 1); // copy the name of the popped element to result
    free(temp->name); // free the memory allocated for the name of the popped element
    free(temp); // free the memory allocated for the popped element
    return 0; // success
}


int push(struct node **head, const char *value){
    if (head == NULL) return 1;
    struct node *new_node = malloc(sizeof(struct node)); // allocate memory for the new element
    if(new_node == NULL) return 1;
    new_node->name = malloc(strlen(value) + 1); // allocate memory for the name of the new element
    if(new_node->name == NULL){ // check if memory allocation failed
        free(new_node); // free the memory allocated for the new element
        return 1; // error: memory allocation failed
    }
    strncpy(new_node->name, value, strlen(value) + 1); // copy the name of the new element
    new_node->next = *head; // make the new element the new head of the stack
    *head = new_node; // update the head of the stack
    return 0; // success
}

int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}
