// Infix to Prefix Conversion in C

#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// length of string
int stringLength(char exp[]) {
    int i = 0;
    while (exp[i] != '\0') {
        i++;
    }
    return i;
}

int isAlphaNumeric(char c) {
    if ((c >= 'A' && c <= 'Z') || 
        (c >= 'a' && c <= 'z') || 
        (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// Reverse String
void reverseAndSwap(char exp[]) {
    int n = stringLength(exp);
    int i;
    for (i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }

    for (i = 0; i < n; i++) {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

// Convert Infix → Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    int len = stringLength(infix);

    for (i = 0; i < len; i++) {
        char c = infix[i];

        if (isAlphaNumeric(c)) {
            postfix[k++] = c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } 
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                if (c == '^' && precedence(peek()) == precedence(c))
                    break; // right-associative for ^
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

// Manual Copy Function 
void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

//Infix → Prefix Conversion 
void infixToPrefix(char infix[], char prefix[]) {
    char postfix[MAX];
    reverseAndSwap(infix);          // Step 1: reverse + swap brackets
    infixToPostfix(infix, postfix); // Step 2: convert reversed infix → postfix
    reverseAndSwap(postfix);        // Step 3: reverse postfix → prefix
    copyString(prefix, postfix);    // Step 4: store final prefix
}

//Main
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
