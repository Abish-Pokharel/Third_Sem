#include <stdio.h>
#include <math.h>
#define f(x) (a3*x*x*x + a2*x*x + a1*x + a0)
float a0, a1, a2, a3;
int main() {
    float x0, x1, x2, y0, y1, E;
    int maxitr, i;
    printf("Enter coefficients a3, a2, a1, and a0: ");
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
    printf("Enter first guess (x0): ");
    scanf("%f", &x0);
    printf("Enter second guess (x1): ");
    scanf("%f", &x1);
    printf("Enter allowed error (E): ");
    scanf("%f", &E);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &maxitr);

    for (i = 1; i <= maxitr; i++) {
        y0 = f(x0);
        y1 = f(x1);
        x2 = x1 - (y1 * (x1 - x0)) / (y1 - y0);
        if (fabs(f(x2)) < E) {
            printf("\nSolution has converged.\n");
            printf("Root of the equation is: %.6f\n", x2);
            return 0;
        }
		x0 = x1;
        x1 = x2;
    }
	printf("\nSolution did not converge within the maximum iterations.\n");
    return 0;
}

