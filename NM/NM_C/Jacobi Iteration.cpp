#include <stdio.h>
#include <math.h>

int main() {
    int i, j, n, converged;
    float sum, error, E[10], a[10][10], b[10], new_x[10], old_x[10];

    printf("Enter Dimension of System of Equations: \n");
    scanf("%d", &n);

    printf("Enter Coefficients (Row-wise):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter RHS Vector:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &b[i]);
    }

    printf("Enter Accuracy Limit:\n");
    scanf("%f", &error);

    // Initialize x values to 0
    for (i = 0; i < n; i++) {
        old_x[i] = 0;
    }

    while (1) {
        converged = 1;  // Assume convergence

        for (i = 0; i < n; i++) {
            sum = b[i];

            for (j = 0; j < n; j++) {
                if (i != j) {
                    sum -= a[i][j] * old_x[j];
                }
            }

            new_x[i] = sum / a[i][i];  // Jacobi update
            
            // Compute relative error
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);

            // If any error is above the threshold, we have not yet converged
            if (E[i] > error) {
                converged = 0;
            }
        }

        // Copy new_x to old_x for next iteration
        for (i = 0; i < n; i++) {
            old_x[i] = new_x[i];
        }

        // If converged, exit the loop
        if (converged) {
            break;
        }
    }

    // Display the solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %6.4f\n", i + 1, new_x[i]);
    }
      getchar();
    getchar();
    return 0;
}

