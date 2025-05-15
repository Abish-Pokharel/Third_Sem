#include <stdio.h>
#include <math.h>

#define f(x, y) (2 * (x) + (y))

int main() {
    float x, xp, x0, y, y0, h, m1, m2, m3, m4;

    printf("Enter initial values (x0, y0): ");
    scanf("%f %f", &x0, &y0);

   
    printf("Enter x at which function is to be evaluated (xp): ");
    scanf("%f", &xp);

    printf("Enter step size (h): ");
    scanf("%f", &h);

    y = y0;
    x = x0;

    for (x=x0 ; x < xp; x = x+h) {
        m1 = f(x, y);
        m2 = f(x + h / 2, y + (h / 2) * m1);
        m3 = f(x + h / 2, y + (h / 2) * m2);
        m4 = f(x + h, y + h * m3);

        y = y + (h / 6) * (m1 + 2 * m2 + 2 * m3 + m4);
    }

    printf("Function value at x = %.2f is y = %.4f\n", xp, y);
    return 0;
}

