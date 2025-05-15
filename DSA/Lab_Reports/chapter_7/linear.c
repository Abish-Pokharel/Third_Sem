#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 100003 // A large prime number for better distribution

typedef struct {
    int key;
    int value;
} HashItem;

HashItem* hashTable[TABLE_SIZE];

// Initialize the hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert into the hash table using Linear Probing
void insert(int key, int value) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != NULL && hashTable[index]->key != key) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full!\n");
            return;
        }
    }

    if (hashTable[index] == NULL) {
        hashTable[index] = (HashItem*)malloc(sizeof(HashItem));
    }
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

// Search for a key in the hash table
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->value;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;
        }
    }
    return -1; // Key not found
}

// Free the hash table
void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }
}

int main() {
    initHashTable();

    const int DATASET_SIZE = 100000; // Large dataset size
    clock_t start, end;

    // Measure insertion time
    start = clock();
    for (int i = 0; i < DATASET_SIZE; i++) {
        insert(i, i * 10);
    }
    end = clock();
    printf("Insertion Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Measure search time
    start = clock();
    for (int i = 0; i < DATASET_SIZE; i++) {
        search(i);
    }
    end = clock();
    printf("Search Time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    freeHashTable();
    return 0;
}