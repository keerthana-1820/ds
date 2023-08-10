#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    stack->arr[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initialize(&stack);

    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            continue;
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    return -1;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    gets(expression);

    int result = evaluatePostfix(expression);
    if (result != -1) {
        printf("Result of the postfix expression: %d\n", result);
    }

    return 0;
}

