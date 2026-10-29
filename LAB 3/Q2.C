//  Stack with menu-based operations: Create, Push, Pop, Peek, and Display.

#include <stdio.h>
#define MAX 100

int stack[100], top = -1;

void createStack() {
    top = -1;
    printf("\nStack Created Successfully!\n");
}

void push(int value) {
    if (top == MAX - 1) {
        printf("\nStack Full, Cannot push %d\n", value);
    } else {
        top = top + 1;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Empty, Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top = top - 1;
    }
}

void peek() {
    if (top == -1) {
        printf("\nStack is Empty\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is Empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Create Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peek\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createStack();
                break;
            case 2:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 3:
                pop();
                break;
            case 4:
                peek();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }
}
