#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float x[10], y[10], logy[10];
    float Sx = 0, Sy = 0, Sxy = 0, Sx2 = 0;
    float a, b, r;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter the value of x and y: \n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
        logy[i] = log(y[i]); // Taking natural logarithm of y
    }

    for (i = 0; i < n; i++) {
        Sx += x[i];
        Sy += logy[i]; // Sum of log(y)
        Sxy += x[i] * logy[i]; // Sum of x * log(y)
        Sx2 += x[i] * x[i]; // Sum of x^2
    }

    // Calculate b and A' (log of A)
    b = ((n * Sxy) - (Sx * Sy)) / ((n * Sx2) - (Sx * Sx));
    r = (Sy / n) - (b * Sx / n);

    // Convert A' back to A
    a = exp(r);

    printf("Fitted exponential curve: y = %.4f * e^(%.4f * x)\n", a, b);
    getchar();
    getchar();

    return 0;
}

