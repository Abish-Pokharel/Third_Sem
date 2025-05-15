#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Return the index if the key is found
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}