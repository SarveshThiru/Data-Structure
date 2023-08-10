#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full - Overflow!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty - Underflow!\n");
        return -1;
    } else {
        int dequeuedValue = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return dequeuedValue;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty - Underflow!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
	printf("Dequeued element: %d\n", dequeue());
    display();

    return 0;
}
