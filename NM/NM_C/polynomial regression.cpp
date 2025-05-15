#include <stdio.h>
#include <math.h>

int main() {
    int i, j, k, m, n;
    float a[20][20], b[20], z[21], x[20], fx[20];
    float sum, pivot, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);
    printf("Enter degree of polynomial to be fitted: ");
    scanf("%d", &m);
    
    printf("Enter data points (xi, fx(i)): \n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &fx[i]);
    }

    // Forming Normal Equations
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= m; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += pow(x[k], i + j);
            }
            a[i][j] = sum;
        }
    }

    // RHS vector
    for (i = 0; i <= m; i++) {
        sum = 0;
        for (k = 0; k < n; k++) {
            sum += fx[k] * pow(x[k], i);
        }
        b[i] = sum;
    }

    // Gaussian Elimination
    for (k = 0; k <= m - 1; k++) {
        pivot = a[k][k];
        if (fabs(pivot) < 0.000001) {
            printf("Method failed\n");
            return 1;
        }
        for (i = k + 1; i <= m; i++) {
            term = a[i][k] / pivot;
            for (j = 0; j <= m; j++) {
                a[i][j] -= a[k][j] * term;
            }
            b[i] -= b[k] * term;
        }
    }

    // Back-substitution
    z[m] = b[m] / a[m][m];
    for (i = m - 1; i >= 0; i--) {
        sum = 0;
        for (j = i + 1; j <= m; j++) {
            sum += a[i][j] * z[j];
        }
        z[i] = (b[i] - sum) / a[i][i];
    }

    // Printing the polynomial equation
    printf("The polynomial of regression is: \n");
    printf("y = %.4f", z[0]);  // Print constant term

    for (i = 1; i <= m; i++) {
        if (z[i] >= 0)
            printf(" + %.4fx^%d", z[i], i);
        else
            printf(" - %.4fx^%d", -z[i], i);
    }

    printf("\n");
    getchar();
    getchar();

    return 0;
}

