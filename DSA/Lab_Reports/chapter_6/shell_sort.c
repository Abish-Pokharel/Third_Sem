#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to implement Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to print the first and last few elements of an array
void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < 5 && i < n; i++) {
        printf("%d ", arr[i]);
    }
    if (n > 10) {
        printf("... ");
        for (int i = n - 5; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("]\n");
}

int main() {
    int n = 10000;  // Array size
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));

    // Generate random numbers for testing
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr1[i] = arr2[i] = rand() % 10000;
    }

    printf("Original Array: ");
    printArray(arr1, n);

    clock_t start, end;
    double time_taken;
    
    // Shell Sort Execution
    start = clock();
    shellSort(arr1, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted Array using Shell Sort: ");
    printArray(arr1, n);
    printf("Shell Sort Execution Time: %f seconds\n\n", time_taken);

    // Bubble Sort Execution
    start = clock();
    bubbleSort(arr2, n);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted Array using Bubble Sort: ");
    printArray(arr2, n);
    printf("Bubble Sort Execution Time: %f seconds\n", time_taken);

    free(arr1);
    free(arr2);
    return 0;
}

