#include <stdlib.h>
#include <stdio.h>

// ! DOESN'T PASS ALL THE TESTS ! // 

typedef struct node{
    struct node* next;
    int value;
} node_t;

typedef struct queue{
    struct node* tail;
    int size;
} queue_t;


/*
 * Add @val value at the head of the @q queue
 *
 * @val     : the value to enqueue
 * @q     : the queue
 *
 * @return 0 if no error, -1 otherwise
 *
 * pre : The queue q will always be valid, you don't need to handle the NULL case.
 */
int enqueue(queue_t* q, int val){
    // Allocate memory for the new node
    node_t* new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1; // Error: unable to allocate memory
    }

    // Initialize the new node
    new_node->value = val;
    new_node->next = NULL;

    // Update the tail of the queue
    if (q->tail == NULL) {
        // The queue is empty
        q->tail = new_node;
        q->tail->next = q->tail; // Circular reference to itself
    } else {
        // The queue is not empty
        new_node->next = q->tail->next;
        q->tail->next = new_node;
        q->tail = new_node;
    }

    // Update the size of the queue
    q->size++;

    return 0; // Success
}

/*
 * Remove the node at the tail of the @q queue and return the value of this node
 * @q         : the queue
 * @return     : the value at the tail
 *
 * pre         : The given queue will always be valid, you do not need to handle the NULL case.
 */
int dequeue(queue_t* q){
    if (q->tail == NULL) {
        return -1; // error: the queue is empty
    }
    node_t* head = q->tail->next;
    int value = head->value;
    q->tail->next = head->next;
    free(head);
    q->size--;
    if (q->size == 0) {
        q->tail = NULL;
    }
    return value;
}

int main(int argc, char *argv[]){

    return EXIT_SUCCESS;
}
