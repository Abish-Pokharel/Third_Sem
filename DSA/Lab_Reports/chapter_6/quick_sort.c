#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to generate an array of random integers
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int sizes[] = {5000, 10000, 20000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        int *arr1 = (int *)malloc(size * sizeof(int));
        int *arr2 = (int *)malloc(size * sizeof(int));

        generateRandomArray(arr1, size);
        for (int j = 0; j < size; j++) {
            arr2[j] = arr1[j];
        }

        printf("Array size: %d\n", size);

        clock_t start, end;

        // Measure time for Quick Sort
        start = clock();
        quickSort(arr1, 0, size - 1);
        end = clock();
        printf("Quick Sort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Measure time for Merge Sort
        start = clock();
        mergeSort(arr2, 0, size - 1);
        end = clock();
        printf("Merge Sort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        free(arr1);
        free(arr2);

        printf("\n");
    }

    return 0;
}