#include <stdio.h>
int findLargest(int arr[], int n, int max) {
    if (n == 0) {
        return max;
    }
    if (arr[n-1] > max) {
        max = arr[n-1];
    }
    return findLargest(arr, n-1, max);
}

int main() {
    int arr[] = {11, 55, 33, 57, 27, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int largest = findLargest(arr, n, arr[0]);
    printf("Elements of array are: \n");
    for(int i = 0; i< n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\nThe largest element in the array is: %d\n", largest);
    return 0;
}