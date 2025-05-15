#include <stdio.h>

#include <math.h>  // Include math library

// Function definition
float f(float x) {
    return 2 * exp(x);
}

int main() {
    float h, x, d;

    printf("Enter the value at which derivative is required: \n");
    scanf("%f", &x);

    printf("Enter increment (h): \n");
    scanf("%f", &h);

    // Backward Difference Formula
    d = (f(x) - f(x - h)) / h;

    printf("Value of Derivative = %f\n", d);
    getchar();
   getchar();


    return 0;
}

