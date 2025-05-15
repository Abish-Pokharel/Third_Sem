#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 10007 // A prime number for better distribution

// Node structure for linked list
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash table structure
typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Hash function
unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert key into hash table
void insert(HashTable* ht, int key) {
    unsigned int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search key in hash table
int search(HashTable* ht, int key) {
    unsigned int index = hash(key);
    Node* current = ht->table[index];
    while (current) {
        if (current->key == key) {
            return 1; // Key found
        }
        current = current->next;
    }
    return 0; // Key not found
}

// Free memory allocated for hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = ht->table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht);
}

int main() {
    HashTable* ht = createHashTable();
    int datasetSize = 100000; // Large dataset size
    int* dataset = (int*)malloc(datasetSize * sizeof(int));

    // Generate random dataset
    srand(time(NULL));
    for (int i = 0; i < datasetSize; i++) {
        dataset[i] = rand();
    }

    // Measure insertion time
    clock_t startInsert = clock();
    for (int i = 0; i < datasetSize; i++) {
        insert(ht, dataset[i]);
    }
    clock_t endInsert = clock();
    double insertTime = (double)(endInsert - startInsert) / CLOCKS_PER_SEC;
    printf("Insertion time: %.6f seconds\n", insertTime);

    // Measure search time
    clock_t startSearch = clock();
    for (int i = 0; i < datasetSize; i++) {
        search(ht, dataset[i]);
    }
    clock_t endSearch = clock();
    double searchTime = (double)(endSearch - startSearch) / CLOCKS_PER_SEC;
    printf("Search time: %.6f seconds\n", searchTime);

    // Free memory
    freeHashTable(ht);
    free(dataset);

    return 0;
}