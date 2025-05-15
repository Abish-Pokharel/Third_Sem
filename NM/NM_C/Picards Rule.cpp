#include<stdio.h>

#include<math.h>

#define y1(x) exp(x) + pow(x,2) - 3*x
#define y2(x) 1 + x + pow(x,2)/2 + pow(x,3)/6 + pow(x,2) - 3*x
#define y3(x) 1 + x + pow(x,2)/2 + pow(x,3)/6 + pow(x,4)/24 + pow(x,2) - 3*x

int main(){
    float x, x0, y0, y;

    printf("Enter initial values of x and y: \n");
    scanf("%f %f", &x0, &y0);

    printf("Enter x at which function is to be evaluated: \n");
    scanf("%f", &x);

    y = y0;
    y = y0 + y1(x);
    y = y0 + y2(x);
    y = y0 + y3(x);

    printf("Function Value at x = %f is %f\n", x, y);
	getchar();
   getchar();
    return 0;
}

