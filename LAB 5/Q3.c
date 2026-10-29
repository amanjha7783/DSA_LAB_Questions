// Priority Queue with menu-based operations Enqueue, Dequeue, and Display.

#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORITY 5   
#define MAX_SIZE 5       

int queue[MAX_PRIORITY][MAX_SIZE]; 
int front[MAX_PRIORITY];          
int rear[MAX_PRIORITY];          

// Initialize all queues
void initialize() {
    for (int i = 0; i < MAX_PRIORITY; i++) {
        front[i] = -1;
        rear[i] = -1;
    }
}

// Enqueue an element in the specific priority queue
void enqueue(int value, int priority) {
    if (priority < 0 || priority >= MAX_PRIORITY) {
        printf("\nInvalid priority! Please enter between 0 and %d.\n", MAX_PRIORITY - 1);
        return;
    }

    if (rear[priority] == MAX_SIZE - 1) {
        printf("\nQueue Overflow at priority %d! Cannot insert %d\n", priority, value);
        return;
    }

    if (front[priority] == -1)
        front[priority] = 0;

    rear[priority]++;
    queue[priority][rear[priority]] = value;

    printf("\nInserted %d at priority level %d\n", value, priority);
}

// Dequeue element (from highest priority available)
void dequeue() {
    int i;
    for (i = MAX_PRIORITY - 1; i >= 0; i--) {
        if (front[i] != -1) { // Non-empty queue found
            printf("\nDeleted element: %d (from priority %d)\n", queue[i][front[i]], i);
            front[i]++;

            // Reset when queue becomes empty
            if (front[i] > rear[i]) {
                front[i] = rear[i] = -1;
            }
            return;
        }
    }
    printf("\nAll queues are empty. Nothing to delete.\n");
}

// Display all queues
void display() {
    for (int i = MAX_PRIORITY - 1; i >= 0; i--) {
        printf("\nPriority %d Queue: ", i);
        if (front[i] == -1)
            printf("Empty");
        else {
            for (int j = front[i]; j <= rear[i]; j++) {
                printf("%d ", queue[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int choice, value, priority;

    initialize();

    while (1) {
        printf("\n---- Multi-Level Priority Queue Menu ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter priority (0-%d): ", MAX_PRIORITY - 1);
                scanf("%d", &priority);
                enqueue(value, priority);
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
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
