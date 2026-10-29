#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create the binary tree recursively
struct Node* createTree() {
    int data;
    struct Node* newNode;

    printf("\nEnter data (-1 for no node): ");
    scanf("%d", &data);

    // Base condition — if user enters -1, return NULL (no node)
    if (data == -1)
        return NULL;

    // Create a new node with the entered data
    newNode = createNode(data);

    printf("\nEnter left child of %d:", data);
    newNode->left = createTree();  // Recursively create left subtree

    printf("\nEnter right child of %d:", data);
    newNode->right = createTree(); // Recursively create right subtree

    return newNode;
}

// Function for Preorder Traversal (Root → Left → Right)
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Function for Inorder Traversal (Left → Root → Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function for Postorder Traversal (Left → Right → Root)
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct Node* root = NULL;

    printf("Binary Tree Creation Program\n");

    // Create the tree
    root = createTree();

    // Display traversals
    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}
