#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);  // Compare integers
}


// Function for Sequential Search
int sequentialSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;  // Return index if key is found
        }
    }
    return -1;  // Return -1 if key is not found
}

// Function for Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;  // Return index if key is found
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Return -1 if key is not found
}

// Function to compare the efficiency of searches
void compareSearches() {
    int size = 100000;  // Increase the array size to 100,000 to see a noticeable difference
    int arr[size];
    int key = rand() % size;  // Random key to search for

    // Initialize array with random numbers
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }

    // Measure Sequential Search on unsorted array (perform multiple iterations for better timing)
    clock_t start = clock();
    for (int i = 0; i < 100; i++) {  // Perform the search 100 times to average the time
        sequentialSearch(arr, size, key);
    }
    clock_t end = clock();
    double timeSequentialUnsorted = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Sort the array for Binary Search
    qsort(arr, size, sizeof(int), compare);

    // Measure Sequential Search on sorted array (perform multiple iterations for better timing)
    start = clock();
    for (int i = 0; i < 100; i++) {
        sequentialSearch(arr, size, key);
    }
    end = clock();
    double timeSequentialSorted = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Measure Binary Search on sorted array (perform multiple iterations for better timing)
    start = clock();
    for (int i = 0; i < 100; i++) {
        binarySearch(arr, 0, size - 1, key);
    }
    end = clock();
    double timeBinarySorted = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("Time taken by Sequential Search (unsorted array): %f seconds\n", timeSequentialUnsorted);
    printf("Time taken by Sequential Search (sorted array): %f seconds\n", timeSequentialSorted);
    printf("Time taken by Binary Search (sorted array): %f seconds\n", timeBinarySorted);
}

// Comparison function for qsort

int main() {
    srand(time(0)); // Seed for random number generation
    compareSearches();  // Compare search methods
    return 0;
}
