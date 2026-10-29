// Creation and Insertion in Singly Linked List (At the beginning, after a given node, before a
// given node, at the end)

#include <stdio.h>
#include <stdlib.h>

// Define node structure 
struct Node {
    int data;
    struct Node* next;
};

// Create a new node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    printf("Node inserted at the beginning successfully.\n");
}

// Insert at the end
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        printf("List was empty. Node added as the first element.\n");
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Node inserted at the end successfully.\n");
}

// Insert after a given node value
void insertAfterNode(struct Node* head, int key, int data) {
    struct Node* temp = head;

    // Search for the node
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted after %d successfully.\n", key);
}

// Insert before a given node value
void insertBeforeNode(struct Node** head_ref, int key, int data) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the first node itself is the key
    if (temp != NULL && temp->data == key) {
        insertAtBeginning(head_ref, data);
        return;
    }

    // Search for the key node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    struct Node* newNode = createNode(data);
    prev->next = newNode;
    newNode->next = temp;
    printf("Node inserted before %d successfully.\n", key);
}

// Display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Current Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\n===== Singly Linked List Menu =====\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a given node\n");
        printf("3. Insert before a given node\n");
        printf("4. Insert at the end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                displayList(head);
                break;

            case 2:
                printf("Enter the node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfterNode(head, key, data);
                displayList(head);
                break;

            case 3:
                printf("Enter the node value before which to insert: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBeforeNode(&head, key, data);
                displayList(head);
                break;

            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;

            case 5:
                displayList(head);
                break;

            case 6:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
