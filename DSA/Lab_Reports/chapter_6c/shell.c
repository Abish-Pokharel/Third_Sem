#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 10;
    int arr[n];

    // Generate random numbers
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }

    printf("Original array:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}