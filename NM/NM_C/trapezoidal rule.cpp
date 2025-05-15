#include<stdio.h>

#include<math.h>

// Define a new function
#define f(x) (x*x + 3*x + 1) 

int main(){
    float h, x0, x1, fx0, fx1, v;

    printf("Enter Lower and Upper Limit: \n");
    scanf("%f %f", &x0, &x1);

    h = x1 - x0;
    fx0 = f(x0);
    fx1 = f(x1);
    v = h / 2 * (fx0 + fx1);

    printf("Value of Integration: %f\n", v);


    getchar();
   getchar();
    return 0;
}

