// Deletion in Singly Linked List (At the beginning, a specific, at the end)

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (for initial list creation)
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete from beginning
void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    printf("Node with value %d deleted from beginning.\n", temp->data);
    free(temp);
}

// Delete a specific node (by value)
void deleteSpecific(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head_ref, *prev = NULL;

    // If head node holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        printf("Node with value %d deleted from the list.\n", key);
        free(temp);
        return;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not found
    if (temp == NULL) {
        printf("Node with value %d not found in the list.\n", key);
        return;
    }

    // Unlink and delete
    prev->next = temp->next;
    printf("Node with value %d deleted from the list.\n", key);
    free(temp);
}

// Delete from end
void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // If only one node
    if (temp->next == NULL) {
        printf("Node with value %d deleted from end.\n", temp->data);
        free(temp);
        *head_ref = NULL;
        return;
    }

    // Traverse till the second last node
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Node with value %d deleted from end.\n", temp->data);
    free(temp);
    prev->next = NULL;
}

// Display linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Current Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\n===== Singly Linked List Deletion Menu =====\n");
        printf("1. Create list (Insert at end)\n");
        printf("2. Delete at beginning\n");
        printf("3. Delete a specific node\n");
        printf("4. Delete at end\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;

            case 2:
                deleteAtBeginning(&head);
                displayList(head);
                break;

            case 3:
                printf("Enter value of node to delete: ");
                scanf("%d", &data);
                deleteSpecific(&head, data);
                displayList(head);
                break;

            case 4:
                deleteAtEnd(&head);
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
