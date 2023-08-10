#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* insertBegin(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
        return NULL;
    }

    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertBegin(head, 3);
    head = insertBegin(head, 2);
    head = insertBegin(head, 1);
    display(head);

    head = insertEnd(head, 4);
    head = insertEnd(head, 5);
    display(head);

    head = deleteNode(head, 3);
    head = deleteNode(head, 1);
    display(head);

    return 0;
}
 