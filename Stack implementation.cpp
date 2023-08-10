#include <stdio.h>
#include <stdbool.h>
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
        printf("%d pushed onto the stack.\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow - cannot pop!\n");
    } else {
        int poppedValue = stack[top--];
        printf("%d popped from the stack.\n", poppedValue);
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty - cannot peek!\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    pop();
    pop();
    pop();

    printf("Top element: %d\n", peek());

    return 0;
}
