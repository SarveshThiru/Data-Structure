#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

// Hash table structure
struct HashTable {
    int data[SIZE];
    bool occupied[SIZE];
};

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Initialize hash table
void initHashTable(struct HashTable* table) {
    for (int i = 0; i < SIZE; i++) {
        table->data[i] = -1;  // Initialize slots with -1
        table->occupied[i] = false;
    }
}

// Insert an element into hash table
void insert(struct HashTable* table, int key) {
    int index = hash(key);

    while (table->occupied[index]) {
        index = (index + 1) % SIZE;  // Linear probing
    }

    table->data[index] = key;
    table->occupied[index] = true;
}

// Search for an element in hash table
int search(struct HashTable* table, int key) {
    int index = hash(key);

    while (table->occupied[index]) {
        if (table->data[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;  // Linear probing
    }

    return -1;  // Element not found
}

int main() {
    struct HashTable hashTable;
    initHashTable(&hashTable);

    int elements[] = {12, 25, 37, 11, 21, 34, 18, 46, 59, 77};

    for (int i = 0; i < SIZE; i++) {
        insert(&hashTable, elements[i]);
    }

    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable.occupied[i]) {
            printf("Index %d: %d\n", i, hashTable.data[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }

    int searchKey = 34;
    int searchIndex = search(&hashTable, searchKey);
    if (searchIndex != -1) {
        printf("\nElement %d found at index %d\n", searchKey, searchIndex);
    } else {
        printf("\nElement %d not found\n", searchKey);
    }

    return 0;
}
