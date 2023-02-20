#include <stdlib.h>
#include <stdio.h>
/**
* Structure node
*
* @next: pointer to the next node in the list, NULL if last node_t
* @value: value stored in the node
*/
typedef struct node {
  struct node *next;
  int value;
} node_t;

/**
* Structure list
*
* @first: first node of the list, NULL if list is empty
* @size: number of nodes in the list
*/
typedef struct list {
  struct node *first;
  int size;
} list_t;

/*
* Create a new node containing the value @value.
*
* @value: value stored in the node
* @next : pointer to next node, initialised to NULL.
* @return: returns the pointer to the newly created node, or NULL if an error occured.
*/
node_t *init_node(int value) {
  node_t *new = malloc(sizeof(node_t));
  if (new == NULL) return NULL;
  new->next = NULL;
  new->value = value;
  return new; 
}


void print_list(list_t *list){
  if (list->first == NULL) return;
  
  int iter = 0;

  printf("┌[LIST:%d]\n│\n├─", list->size);
  node_t *current = list->first;
  
  while (current->next != NULL) {
    if (iter == 0) {
      printf("[NODE:%d]\n", current->value);
    } else {
      printf("├─[NODE:%d]\n", current->value);
    }
    iter++;
    current = current->next;
  }
  
  printf("└─[NODE:%d]", current->value);
  printf("\n");

}


/*
* Add a node at the head of the list @list and increment the number of nodes in the list (member `size`)
*
* @l: linked list
* @value: value to add to the list
*
* @return: 0 if success, 1 otherwise
*/
int add_node(list_t *list, int value) {
  if (list == NULL) return 1; // check for invalid arguments

  node_t* new = init_node(value);
  if (new == NULL) return 1; // check for memory allocation failure

  if (list->first == NULL) {
    list->first = new;
  } else {
    node_t *current = list->first;
    new->next = current;
    list->first = new;
  }
  list->size++;
  return 0;
}

int main(int argc, char **argv) {
  node_t* ode = init_node(5);
  if (ode == NULL) return 0; 
  list_t *link_list = malloc(sizeof(list_t));
  link_list->first = ode;
  link_list->size = 1;
  //printf("%d", link_list->first->value);
  add_node(link_list, 4);
  add_node(link_list, 40);
  add_node(link_list, 7);
  add_node(link_list, 18);
  add_node(link_list, 70);
  add_node(link_list, 84);
  print_list(link_list);
  return 0;
}
