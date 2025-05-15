#include <stdio.h>

#include <math.h>

#define f(x) (sin(x)) 

int main() {
    float x0, x1, h, v;
    float fx0, fx1, fx_mid;

    printf("Enter Lower and Upper Limit (in radians): \n");
    scanf("%f %f", &x0, &x1);

    h = (x1 - x0) / 2.0;

    fx0 = f(x0);
    fx1 = f(x1);
    fx_mid = f(x0 + h);

    v = (h / 3) * (fx0 + 4 * fx_mid + fx1);

    printf("Value of Integration: %f\n", v);

   getchar();
   getchar();
    return 0;
}

