#include <stdio.h>

int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int i, j, k, n;
    float v = 0, p, xp, x[10], fx[10], bd[10], h, s;

    printf("Enter the number of points: \n");
    scanf("%d", &n);

    printf("Enter the value at which interpolated value is needed: \n");
    scanf("%f", &xp);

    for (i = 0; i < n; i++) {
        printf("Enter the value of x and fx at i = %d\n", i);
        scanf("%f%f", &x[i], &fx[i]);
    }

    h = x[1] - x[0];
    s = (xp - x[n - 1]) / h;

    for (i = 0; i < n; i++) {
        bd[i] = fx[i];
    }

    for (i = 1; i < n; i++) {
        for (j = n - 1; j >= i; j--) {
            bd[j] = bd[j] - bd[j - 1];
        }
    }

    v = bd[n - 1];

    for (i = 1; i < n; i++) {
        p = 1;
        for (k = 0; k < i; k++) {
            p *= (s + k);
        }
        v += (bd[n - 1 - i] * p) / fact(i);
    }

    printf("Interpolated value = %f\n", v);

    getchar(); // Pause the console
    getchar(); // Wait for user input before closing

    return 0;
}

