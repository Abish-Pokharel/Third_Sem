#include <stdio.h>


int main() {
    int n, i, j, k, p;
    float pivot, term, a[10][11];

    printf("Enter Dimension of System of equations\n");
    scanf("%d", &n);

    printf("Enter coefficients Augmented Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for (k = 0; k < n; k++) {
        pivot = a[k][k];

        // Normalization of the pivot row
        for (p = 0; p < n + 1; p++) {
            a[k][p] = a[k][p] / pivot;
        }

        // Make other rows zero
        for (i = 0; i < n; i++) {
            if (i != k) {
                term = a[i][k];
                for (j = 0; j < n + 1; j++) {
                    a[i][j] = a[i][j] - a[k][j] * term;
                }
            }
        }
    }

    // Display Solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, a[i][n]);
    }

      getchar();
    getchar();
    return 0;
}

