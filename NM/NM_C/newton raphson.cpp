#include <stdio.h>
#include <math.h>

#define f(x) (a3*x*x*x + a2*x*x + a1*x + a0)
#define fD(x) (3*a3*x*x + 2*a2*x + a1)

float a0, a1, a2, a3;

int main() {
    float x0, x1, fx0, fdx0, E, Er;
    int i = 0;  
    
    printf("Enter coefficients a3, a2, a1, and a0: ");
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);  

    printf("Enter initial guess: ");
    scanf("%f", &x0);  
    
    printf("Enter E(Error allowed): ");
    scanf("%f", &E );
    
    while (1) {
        fx0 = f(x0);          
        fdx0 = fD(x0);      
        
        if (fdx0 == 0) {
            printf("Derivative is zero, stopping iteration to prevent division by zero.\n");
            break;
        }

        x1 = x0 - fx0 / fdx0;  
        Er = fabs((x1 - x0) / x1);  
        if (Er < E) {  
            printf("Root: %f\n", x1);
            break;
        }

        x0 = x1;  
        i++;  

        if (i == 50) {  
            printf("Maximum iterations reached.\n");
            break;
        }
    }

    return 0;
}

