#include <stdio.h>

// Factorial function
int fact(int n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    int n, i, j, k;
    float val = 0, xp, x[10], fx[10], bd[10], h, s, term1, term2, prev = 0;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    printf("Enter values of x and f(x):\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &fx[i]);
    }

    printf("Enter the value at which derivative is needed: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    s = (xp - x[n - 1]) / h;

    // Copy function values
    for (i = 0; i < n; i++) {
        bd[i] = fx[i];
    }

    // Compute backward differences
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            bd[j] = (bd[j] - bd[j - 1]);
        }
    }

    // Compute derivative using backward difference formula
    val = bd[n - 1];
    for (i = 2; i < n; i++) {
        term1 = 1;
        for (k = 2; k <= i; k++) {
            term1 = term1 * (s + k - 2);
        }
        term2 = (s + i - 1) * prev;
        prev = (term1 + term2);
        val = val + (bd[n - i] * prev) / fact(i);
    }

    val = val / h;

    printf("Value of First Derivative = %.6f\n", val);

	getchar();
	getchar();
    return 0;
}

