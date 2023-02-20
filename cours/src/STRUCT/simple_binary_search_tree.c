#include <stdlib.h>
#include <stdio.h>

/*
* Node has a value, @value, and two children, @left and @right.
* All the children of @left and itself have a smaller value than the node and all the children of @right and itself have a larger value than node
*/
typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;

/*
* binary tree as the following:
*/
typedef struct bt{
    struct node* root;
} bt_t;

/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value){
    if (tree == NULL){ return 0; }
    node_t* current = tree->root;
    while(current != NULL){
        if(current->value == value){
            return 1;
        }
        if(current->value > value){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    bt_t* tree = malloc(sizeof(bt_t));
    tree->root = malloc(sizeof(node_t));
    tree->root->value = 5;
    tree->root->left = malloc(sizeof(node_t));
    tree->root->left->value = 3;
    tree->root->left->left = NULL;
    tree->root->left->right = NULL;
    tree->root->right = malloc(sizeof(node_t));
    tree->root->right->value = 7;
    tree->root->right->left = NULL;
    tree->root->right->right = NULL;
    
    printf("%d\n", contains(tree, 3));
    printf("%d\n", contains(tree, 5));
    printf("%d\n", contains(tree, 7));
    printf("%d\n", contains(tree, 1));
    printf("%d\n", contains(tree, 6));
    printf("%d\n", contains(tree, 8));

  return 0;
}
