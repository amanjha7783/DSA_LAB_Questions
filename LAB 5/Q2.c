// 2.Circular queue with menu-based operations Enqueue, Dequeue, and Display.

#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert element
void enqueue(int data) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("\nQueue Overflow! Cannot insert %d\n", data);
        return;
    }
    if (front == -1) { // First element
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0; // Wrap around
    } else {
        rear++;
    }
    queue[rear] = data;
    printf("\nInserted %d into the queue\n", data);
}

// Function to delete element
void dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow! Nothing to delete\n");
        return;
    }
    printf("\nDeleted element: %d\n", queue[front]);
    if (front == rear) { // Queue has only one element
        front = -1;
        rear = -1;
    } else if (front == MAX - 1) {
        front = 0; // Wrap around
    } else {
        front++;
    }
}

// Function to display queue elements
void display() {
    if (front == -1) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nQueue elements are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n---- Circular Queue Menu ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
