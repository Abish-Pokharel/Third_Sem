// #include <stdio.h>

// int factorial(int n) {
//     if (n == 0) return 1; 
//     return n * factorial(n - 1); 
// }

// int main() {
//     int num = 5; 
//     printf("Factorial of %d = %d\n", num, factorial(num));
//     return 0;
// }



#include <stdio.h>
int factorial(int n, int a)
{
    if (n == 0)
        return a;
    else
        return factorial(n - 1, n * a); // Tail recursion
}
int main()
{
    int n, a = 1;
    printf("Enter value of n:");
    scanf("%d", &n);
    printf("Factorial = %d", factorial(n, a));
    return 0;
}