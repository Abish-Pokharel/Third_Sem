// #include <stdio.h>

// int fibonacci(int n) {
//     if (n == 0) return 0; 
//     if (n == 1) return 1;
//     return fibonacci(n - 1) + fibonacci(n - 2); 
// }

// int main() {
//     int terms = 10; 
//     printf("Fibonacci series: ");
//     for (int i = 0; i < terms; ++i) {
//         printf("%d ", fibonacci(i));
//     }
//     printf("\n");
//     return 0;
// }
  


//   TOWER OF HANOI

// #include <stdio.h>
// void towerOfHanoi(int n, char from, char to, char aux) {
//     if (n == 1) {
//         printf("Move disk 1 from %c to %c\n", from, to);
//         return;
//     }
//     towerOfHanoi(n - 1, from, aux, to);
//     printf("Move disk %d from %c to %c\n", n, from, to);
//     towerOfHanoi(n - 1, aux, to, from);
// }

// int main() {
//     towerOfHanoi(3, 'A', 'C', 'B'); // Example with 3 disks
//     return 0;
// }



// GCD USING RECURSION
#include <stdio.h>
int gcd(int a , int b){
    int GCD;
    if (a == b)
        return a;
    else    
        GCD = gcd (b , a % b);
        return GCD;
}
int main(){
    int x = 6, y = 7;
    printf ("GCD : %d", gcd(x, y));
}
