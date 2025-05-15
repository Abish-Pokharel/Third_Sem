#include<stdio.h>

int factorial(int x){
    if (x == 0){
        return 1;
    } else{
        return x * factorial(x-1);
    }
}

int main(){
    int n, result;
    printf("Enter any number:");
    scanf("%d", &n);
    result = factorial(n);
    printf("The factorial is: %d", result);
return 0;
}