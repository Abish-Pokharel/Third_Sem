#include <stdio.h>
#include <math.h>

// Define functions f1 and f2
#define f1(x, y, z) (z)
#define f2(x, y, z) (6 * (x))

int main() {
    float xa, xb, ya, yb, z0, x, h, xp, sol, error, E;
    float V[3], g[3], ny, nz;
    int i;

    // Input boundary conditions
    printf("Enter Boundary Conditions (xa, ya, xb, yb): ");
    scanf("%f %f %f %f", &xa, &ya, &xb, &yb);

    // Input the x value where function is required
    printf("Enter x at which value is required (xp): ");
    scanf("%f", &xp);

    // Input step size
    printf("Enter the step size (h): ");
    scanf("%f", &h);

    // Input accuracy limit
    printf("Enter accuracy limit (E): ");
    scanf("%f", &E);

    x = xa;
    V[1] = ya;
    g[1] = (yb - ya) / (xb - xa);  // Initial guess

    printf("g1 = %f\n", g[1]);

    while (x < xb) {
        ny = V[1] + (f1(x, V[1], g[1])) * h;
        nz = g[1] + (f2(x, V[1], g[1])) * h;
        x = x + h;
        V[1] = ny;
        g[1] = nz;

        if (x == xp) 
            sol = V[1];
    }

    V[1] = V[1];

    if (V[1] < yb)
        g[2] = g[1] = 2 * g[1];
    else
        g[2] = g[1] = (1.0 / 2.0) * g[1];

    // Iterative shooting method loop
    while (1) {
        x = xa;
        V[2] = ya;
        g[2] = g[1] - ((V[2] - yb) / (V[2] - V[1])) * (g[2] - g[1]);

        while (x < xb) {
            ny = V[2] + (f1(x, V[2], g[2])) * h;
            nz = g[2] + (f2(x, V[2], g[2])) * h;
            x = x + h;
            V[2] = ny;
            g[2] = nz;

            if (x == xp) 
                sol = V[2];
        }

        error = fabs(V[2] - yb) / yb;
        V[1] = V[2];
        g[1] = g[2];

        if (error < E) {
            printf("y(%.2f) = %.4f\n", xp, sol);
            break;
        }
    }
    return 0;
}

