// A program to read n numbers and to find the sum and average of those numbers.

#include<stdio.h>
int main()
{
    int n, i, arr[10];
    float sum = 0, avg;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the element (%d): ", i+1);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }
    avg = sum / n;
    printf("The sum of the elements is: %f\n", sum);
    printf("The average of the elements is: %f\n", avg);
    return 0;
}