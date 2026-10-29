// 1. Linear queue with menu-based operations: Enqueue, Dequeue, and Display. 

#include <stdio.h>
#include <stdlib.h>
#define MAX 5  // Maximum size of queue 

int queue[MAX];
int front = -1, rear = -1;

// add  element
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert %d\n", data);
        return;
    }
    if (front == -1)  // first element
        front = 0;
    rear++;
    queue[rear] = data;
    printf("\nInserted %d into the queue\n", data);
}

// remove element
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty, nothing to delete\n");
        return;
    }
    printf("\nDeleted element: %d\n", queue[front]);
    front++;
}

// display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n---- Linear Queue Menu ----\n");
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
