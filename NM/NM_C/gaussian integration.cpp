#include <stdio.h>
#include <math.h>

#define f(x) ((x) * (x) * (x) + 1) // Ensure correct macro expansion

int main() {
    float a, b, x1, x2, v;
    const float z1 = -0.57735, z2 = 0.57735; // Gaussian points

    // User input
    printf("Enter Lower and Upper Limit: ");
    scanf("%f %f", &a, &b);

    // Transform integration limits
    x1 = ((b - a) / 2) * z1 + (b + a) / 2;
    x2 = ((b - a) / 2) * z2 + (b + a) / 2;

    // Gaussian Quadrature Formula
    v = ((b - a) / 2) * (f(x1) + f(x2));

    // Display result
    printf("\nValue of Integration = %.6f\n", v);
	getchar();
   getchar();
    return 0;
}

