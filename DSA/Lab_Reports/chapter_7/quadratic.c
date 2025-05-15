#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 20100 // Increased by 10,000
#define DATASET_SIZE 20000 // Increased by 10,000

typedef struct {
    int key;
    int value;
} HashItem;

HashItem* hashTable[TABLE_SIZE];

// Initialize the hash table
void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert using Quadratic Probing
void insert(int key, int value) {
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i * i) % TABLE_SIZE] != NULL && i < TABLE_SIZE) {
        i++;
    }

    if (i < TABLE_SIZE) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        hashTable[newIndex] = (HashItem*)malloc(sizeof(HashItem));
        hashTable[newIndex]->key = key;
        hashTable[newIndex]->value = value;
    } else {
        printf("Hash table is full, cannot insert key: %d\n", key);
    }
}

// Search for a key
int search(int key) {
    int index = hashFunction(key);
    int i = 0;

    while (hashTable[(index + i * i) % TABLE_SIZE] != NULL) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex]->key == key) {
            return hashTable[newIndex]->value;
        }
        i++;
    }

    return -1; // Key not found
}

// Free the hash table
void freeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }
}

int main() {
    initializeTable();

    // Generate a large dataset
    int dataset[DATASET_SIZE];
    for (int i = 0; i < DATASET_SIZE; i++) {
        dataset[i] = rand() % (TABLE_SIZE * 10);
    }

    // Measure execution time for insertion
    clock_t start = clock();
    for (int i = 0; i < DATASET_SIZE; i++) {
        insert(dataset[i], i);
    }
    clock_t end = clock();
    double insertionTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for insertion: %f seconds\n", insertionTime);

    // Measure execution time for searching
    start = clock();
    for (int i = 0; i < DATASET_SIZE; i++) {
        search(dataset[i]);
    }
    end = clock();
    double searchTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for searching: %f seconds\n", searchTime);

    freeTable();
    return 0;
}