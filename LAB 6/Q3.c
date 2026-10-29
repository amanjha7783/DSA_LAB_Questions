// Circular Linked List with all cases of insertion and deletion.

#include <stdio.h>
#include <stdlib.h>

// Structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// from the last node (to simplify circular operations)
struct Node* last = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ------------------- INSERTION OPERATIONS -------------------

// Insert at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);

    if (last == NULL) {
        last = newNode;
        last->next = last;  // point to itself
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Inserted %d at the beginning.\n", data);
}

// Insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (last == NULL) {
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("Inserted %d at the end.\n", data);
}

// Insert after a specific node value
void insertAfterValue(int value, int data) {
    if (last == NULL) {
        printf("List is empty. Cannot insert after %d.\n", value);
        return;
    }

    struct Node* temp = last->next;
    do {
        if (temp->data == value) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == last)
                last = newNode; // Update last if inserted after last nodeaqs1

            printf("Inserted %d after %d.\n", data, value);
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    printf("Value %d not found in the list.\n", value); 
}

// Insert before a given node value
void insertBeforeNode(struct Node** head_ref, int key, int data) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the first node itself is the key
    if (temp != NULL && temp->data == key) {
        insertAtBeginning(data);
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


// ------------------- DELETION OPERATIONS -------------------

// Delete from beginning
void deleteAtBeginning() {
    if (last == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node* temp = last->next;

    if (last->next == last) {
        printf("Deleted node with value %d.\n", temp->data);
        free(temp);
        last = NULL;
    } else {
        last->next = temp->next;
        printf("Deleted node with value %d from beginning.\n", temp->data);
        free(temp);
    }
}

// Delete from end
void deleteAtEnd() {
    if (last == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node* temp = last->next;

    // Only one node
    if (last->next == last) {
        printf("Deleted node with value %d.\n", last->data);
        free(last);
        last = NULL;
        return;
    }

    // Find second last node
    while (temp->next != last)
        temp = temp->next;

    temp->next = last->next;
    printf("Deleted node with value %d from end.\n", last->data);
    free(last);
    last = temp;
}

// Delete a specific node by value
void deleteSpecific(int key) {
    if (last == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *current = last->next, *prev = last;

    // If node to delete is the only node
    if (last == last->next && last->data == key) {
        printf("Deleted node with value %d.\n", key);
        free(last);
        last = NULL;
        return;
    }

    // If node to delete is first node
    if (current->data == key) {
        last->next = current->next;
        printf("Deleted node with value %d.\n", key);
        free(current);
        return;
    }

    // Traverse to find the node
    while (current != last && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If node found
    if (current->data == key) {
        prev->next = current->next;
        if (current == last)
            last = prev;
        printf("Deleted node with value %d.\n", key);
        free(current);
    } else {
        printf("Node with value %d not found.\n", key);
    }
}

// ------------------- DISPLAY FUNCTION -------------------

void displayList() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to %d)\n", last->next->data);
}

// ------------------- MAIN FUNCTION -------------------

int main() {
    int choice, data, value;

    while (1) {
        printf("\n===== Circular Linked List Menu =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Given Node\n");
        printf("4. Insert Before a Given Node\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete a Specific Node\n");
        printf("7. Delete at End\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                displayList();
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                displayList();
                break;

            case 3:
                printf("Enter node value after which to insert: ");
                scanf("%d", &value);
                printf("Enter new value to insert: ");
                scanf("%d", &data);
                insertAfterValue(value, data);
                displayList();
                break;

            case 4:
                printf("Enter node value before which to insert: ");
                scanf("%d", &value);
                printf("Enter new value to insert: ");
                scanf("%d", &data);
                insertBeforeNode(&last->next, value, data);
                displayList();
                break;

            case 5:
                deleteAtBeginning();
                displayList();
                break;

            case 6:
                printf("Enter value of node to delete: ");
                scanf("%d", &data);
                deleteSpecific(data);
                displayList();
                break;

            case 7:
                deleteAtEnd();
                displayList();
                break;

            case 8:
                displayList();
                break;

            case 9:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
