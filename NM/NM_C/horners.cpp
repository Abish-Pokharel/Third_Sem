#include<stdio.h>
#include<conio.h>
#define p(x)(a[4]*x*x*x*x+a[3]*x*x*x+a[2]*x*x+a[1]*x+a[0])
float a[100], b[100];
int main()
{
    float x;
    int n, i;

    // Prompt for degree of polynomial
    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    // Prompt for coefficients
    printf("Enter coefficients of dividend polynomial:\n");
    for (i = n; i >= 0; i--)
        scanf("%f", &a[i]);

    // Prompt for value of x
    printf("Enter the value at which polynomial to be evaluated: ");
    scanf("%f", &x);

    // Synthetic division for evaluation
    b[n] = a[n];
    while (n > 0) {
        b[n - 1] = a[n - 1] + b[n] * x;
        n--;
    }

    // Display the result
    printf("Value of polynomial p(%f) = %f", x, b[0]);
    getch();
    return 0;
}

