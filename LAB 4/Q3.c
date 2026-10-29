// Evaluation of Prefix Expression (using stacks) code

#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char exp[]){
    int len = 0;   // length of exp
    while (exp[len] != '\0') {
        len++;
    }

    for (int i = len - 1; i >= 0; i--) {
        char c = exp[i];
 
        if (c == ' ') continue; // skip spaces

        if (c >= '0' && c <= '9') {
            push(c - '0'); // convert char to int
        }
        else {
            int op1 = pop();
            int op2 = pop();

            switch (exp[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 / op2); break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    exit(1);
            }
        }
    }
    return pop();
}

int main() {
    char exp[100];
    printf("Enter the Prefix expression with space: ");
    scanf("%[^\n]", exp); // for taking multiple digit number 

    printf("Prefix Expression: %s\n", exp); 
    printf("Evaluated Result: %d\n", evaluatePrefix(exp));

    return 0;
}