#include <stdio.h>

#include <math.h>

#define PI 3.1415
#define f(x) 2*(x)*(x)+1 // Function definition

int main() {
    float angle, h, x, d;

   printf("Enter the value at which derivative is required: \n");
    scanf("%f", &x);

    printf("Enter increment h: \n");
    scanf("%f", &h);


    // Central Difference Formula
    d = (f(x + h) - f(x - h)) / (2 * h);

    printf("Value of Derivative = %f\n", d);
    getchar();
   getchar();

    return 0;
}

