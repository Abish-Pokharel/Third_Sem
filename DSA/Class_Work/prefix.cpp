#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 20

int stack[max];
int top = -1;

int pop() {
    return stack[top--];
}
void push(int value) {
    stack[++top] = value;
}
int main(){
    int i, length;
    char exp[max];
    printf("Enter a prefix expression: ");
    fgets(exp, max, stdin);
    length = strlen(exp);
    for (i = length -1; i>=0; i--){
         if (exp[i] == ' ') 
            continue;
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (exp[i]) {
                case '+': 
                    push(op1 + op2); 
                    break;
                case '-': 
                    push(op1 - op2); 
                    break;
                case '*': 
                    push(op1 * op2); 
                    break;
                case '/': 
                    push(op1 / op2); 
                    break;
            }
        }
    }
    printf("The result is: %d\n", stack[top]);
    return 0;
}