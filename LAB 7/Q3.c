#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
  
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to create a binary tree
struct Node* createTree() {
    int data;
    struct Node* newNode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    // Base case — if user enters -1, return NULL
    if (data == -1)
        return NULL;

    // Create a new node with entered data
    newNode = createNode(data);

    // Recursively create left and right children
    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();

    return newNode;
}

// Main function
int main() {
    struct Node* root = NULL;

    printf(" Binary Tree Creation\n");

    root = createTree();

    printf("\nBinary tree created successfully!\n");
    return 0;
}
