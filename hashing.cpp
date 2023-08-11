#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Structure to represent an element in the hash table
struct HashElement {
    int key;
    int value;
};

// Function to create a new hash element
struct HashElement* createHashElement(int key, int value) {
    struct HashElement* newElement = (struct HashElement*)malloc(sizeof(struct HashElement));
    newElement->key = key;
    newElement->value = value;
    return newElement;
}

// Function to compute the hash index using a simple modulo operation
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a hash element into the hash table
void insert(struct HashElement* table[], int key, int value) {
    int index = hashFunction(key);

    while (table[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }

    table[index] = createHashElement(key, value);
}

// Function to retrieve a value from the hash table
int search(struct HashElement* table[], int key) {
    int index = hashFunction(key);

    while (table[index] != NULL) {
        if (table[index]->key == key) {
            return table[index]->value;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return -1; // Not found
}

int main() {
    struct HashElement* hashTable[TABLE_SIZE] = {NULL};

    insert(hashTable, 5, 50);
    insert(hashTable, 25, 250);
    insert(hashTable, 15, 150);
    insert(hashTable, 35, 350);
    insert(hashTable, 45, 450);

    printf("Value at key 25: %d\n", search(hashTable, 25));
    printf("Value at key 15: %d\n", search(hashTable, 15));
    printf("Value at key 50: %d\n", search(hashTable, 50));

    return 0;
}

