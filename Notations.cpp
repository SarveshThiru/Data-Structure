#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

bool isFull() {
    return top == MAX_SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow - cannot push!\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow - cannot pop!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int evaluatePostfix(char *expression) {
    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int operand2 = pop();
            int operand1 = pop();
            
            switch (expression[i]) {
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}
