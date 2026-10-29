// 1. Parenthesis Checker. 

#include<stdio.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0'; // stack empty
    } else {
        return stack[top--];    
    }
}

// Function to check matching pairs
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check balanced parentheses
void checkParenthesis(char exp[]) {
    int i;
    top = -1; 

    for (i = 0; i < strlen(exp); i++) { 
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
            printf("Pushed %c onto stack\n", exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                printf("Stack empty, no matching opening bracket for %c\n", exp[i]);
                printf("Expression is not balanced.\n");
                return;
            }
            char popped = pop();
            printf("Popped %c from stack\n", popped);
            if (!isMatchingPair(popped, exp[i])) {
                printf("Mismatched pair: %c and %c\n", popped, exp[i]);
                printf("Expression is not balanced.\n");
                return;
            }
        }
    }

    if (top == -1) {
        printf("Expression is balanced.\n");
    } else {
        printf("Stack not empty, unmatched opening brackets remain.\n");
        printf("Expression is not balanced.\n");
    }
}

int main() {
    char exp[MAX];

    printf("Enter an expression: ");
    scanf("%s", exp); // read expression

    printf("\n--- Parenthesis Checking Process ---\n");
    checkParenthesis(exp);

    return 0;
}
