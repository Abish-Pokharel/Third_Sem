#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int customerIDs[] = {8001033, 8001021, 8001025, 8001023, 8001024, 8001022};
    int n = sizeof(customerIDs) / sizeof(customerIDs[0]);
    printf("Original CustomerIDs: ");
    printArray(customerIDs, n);
    insertionSort(customerIDs, n);
    printf("Sorted CustomerIDs: ");
    printArray(customerIDs, n);

    return 0;
}