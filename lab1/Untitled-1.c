/*
function that performs a binary search on a BST

*/
#include <stdio.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    int search_value = 50;
    struct Node* result = search(root, search_value);
    if (result != NULL)
        printf("%d is found in the tree\n", search_value);
    else
        printf("%d is not found in the tree\n", search_value);
    return 0;
}


/*
This example uses a struct Node that defines the node of a BST, 
it has an integer data, and two pointers to its left and right children.

The insert function takes a root node and an integer data and then 
it puts the data in its correct position in the tree, it checks if the value is less than the root, if it is, it goes to the left child, if it's greater it goes to the right child.

The search function takes a root node and an integer 
data, it compares the data with the value of each node it traverses, if it's less than the node's value it goes to the left child and if it's greater it goes to the right child, if it finds the data it returns the node, 
if it doesn't find the data it returns NULL.

The main function creates an empty tree and then it 
inserts some values to it, then it calls the search 
function and checks if the value is found in the tree or not.
*/