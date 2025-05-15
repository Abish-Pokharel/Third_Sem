#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j, k;
    float sum, a[10][10], u[10][10], l[10][10];

    printf("Enter Dimension of Matrix:\n");
    scanf("%d", &n);

    printf("Enter Elements of Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Initialize L and U matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            l[i][j] = (i == j) ? 1 : 0;  // Identity matrix for L
            u[i][j] = 0; // Initialize U as zero
        }
    }

    // Compute Elements of L and U matrix
    for (j = 0; j < n; j++) {
        // Compute U matrix
        for (i = 0; i <= j; i++) {
            sum = 0;
            for (k = 0; k < i; k++) {
                sum += l[i][k] * u[k][j];
            }
            u[i][j] = a[i][j] - sum;
        }

        // Compute L matrix
        for (i = j + 1; i < n; i++) {
            sum = 0;
            for (k = 0; k < j; k++) {
                sum += l[i][k] * u[k][j];
            }
            l[i][j] = (a[i][j] - sum) / u[j][j];
        }
    }

    // Print L matrix
    printf("\n********** L Matrix **********\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%.2f", l[i][j]);
        }
        printf("\n");
    }

    // Print U matrix
    printf("\n********** U Matrix **********\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("\t%.2f", u[i][j]);
        }
        printf("\n");
    }
      getchar();
    getchar();
    return 0;
}

