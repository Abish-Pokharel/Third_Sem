// C program for Cubic Spline Interpolation.
#include <math.h>
#include <stdio.h>
int main() {
    int n, i, j, k;
    float h[10], a, b, c, d, sum, s[10] = {0}, x[10], F[10], f[10],P, m[10][10] = {0}, temp;

    printf("Enter number of points: \n");
    scanf("%d", &n);
    printf("\nEnter all sample points:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &f[i]);
    }
    for (i = n - 1; i > 0; i--) {
        F[i] = (f[i] - f[i - 1]) / (x[i] - x[i - 1]);
        h[i - 1] = x[i] - x[i - 1];
    }

    for (i = 1; i < n - 1; i++) {
        m[i][i] = 2 * (h[i - 1] + h[i]);
        if (i != 1) {
            m[i][i - 1] = h[i - 1];
            m[i - 1][i] = h[i - 1];
        }
        m[i][n - 1] = 6 * (F[i + 1] - F[i]);
    }

    for (i = n - 2; i > 0; i--) {
        sum = 0;
        for (j = i; j < n - 2; j++) {
            sum += m[i][j] * s[j];
        }
        s[i] = (m[i][n - 1] - sum) / m[i][i];
    }

    printf("\nEnter Interpolation point: ");
    scanf("\n%f", &P);

    for (i = 0; i < n - 1; i++) {
        if (x[i] <= P && P <= x[i + 1]) {
            a = (s[i + 1] - s[i]) / (6 * h[i]);
            b = s[i] / 2;
            c = (f[i + 1] - f[i]) / h[i] - (2 * h[i] * s[i] + s[i + 1] * h[i]) / 6;
            d = f[i];

            sum = a * pow((P - x[i]), 3) + b * pow((P - x[i]), 2) + c * (P - x[i]) + d;
        }
    }

    printf("\nCoefficients of sub-intervals are :%f\n%f\n%f\n%f", a, b, c, d);
    printf("\nInterpolated value = %f", sum);
    return 0;
	}

