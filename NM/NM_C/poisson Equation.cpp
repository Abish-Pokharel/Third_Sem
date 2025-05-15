#include <stdio.h>
#include <math.h>

#define MAX 10  // Maximum grid size

int main() {
    int n, i, j, k;
    float sum, error, E[MAX], a[MAX][MAX], b[MAX], new_x[MAX], old_x[MAX];
    
    printf("Enter the dimension of plate (n,n): ");
    scanf("%d", &n);

    printf("Enter temperatures at left, right, top, and bottom: ");
    float tL, tR, tT, tB;
    scanf("%f %f %f %f", &tL, &tR, &tT, &tB);
    
    // Initialize coefficient matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = (i == j) ? -4 : 0;
            if (j == i - 1 || j == i + 1)
                a[i][j] = 1;
        }
    }
    
    // Initialize right-hand side vector
    for (i = 0; i < n; i++) {
        b[i] = 0;
    }
    
    // Apply boundary conditions
    k = 0;
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            if (i - 1 == 0)
                b[k] -= tL;
            if (i + 1 == n - 1)
                b[k] -= tR;
            if (j - 1 == 0)
                b[k] -= tB;
            if (j + 1 == n - 1)
                b[k] -= tT;
            k++;
        }
    }
    
    // Accuracy limit
    printf("Enter accuracy limit: ");
    scanf("%f", &error);
    
    // Initialize guess values
    for (i = 0; i < n; i++) {
        old_x[i] = 0;
    }
    
    // Iterative calculation using Gauss-Seidel Method
    while (1) {
        for (i = 0; i < n; i++) {
            sum = b[i];
            for (j = 0; j < n; j++) {
                if (i != j)
                    sum -= a[i][j] * old_x[j];
            }
            new_x[i] = sum / a[i][i];
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
        }
        
        // Check if error is within the limit
        int converged = 1;
        for (i = 0; i < n; i++) {
            if (E[i] > error) {
                converged = 0;
                break;
            }
        }
        
        if (converged) 
            break;
        
        for (i = 0; i < n; i++)
            old_x[i] = new_x[i];
    }
    
    // Output solution
    printf("Solution:\n");
    for (i = 0; i < n; i++)
        printf("x[%d] = %.6f\n", i, new_x[i]);
    
    return 0;
}

