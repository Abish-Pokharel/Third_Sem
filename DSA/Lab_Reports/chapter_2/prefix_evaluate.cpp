// WAP to evaluate prefix expression.

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

# define max 25
int stack[max];
int top = -1;

void push(int val){
    top++;
    stack[top] = val;
}

int pop() {
     return stack[top--];
}

int evaluatePrefix(char exp[]){
    int i, op1, op2, result;
    for( i=strlen(exp)-1; i>=0; i--){
        if(isdigit(exp[i])){
            push(exp[i] - '0');
        }else{
            op1 = pop();
            op2= pop();
            switch(exp[i]){
                case '+' : result = op1 + op2;
                    break;
                case '-' : result = op1 - op2;
                    break;
                case '*' : result = op1 * op2;
                    break;
                case '/' : 
                    if(op2 != 0) {
                        result = op1 / op2;
                    } else {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    break;
                case '^' : result = pow(op1, op2);
                    break;
                default:
                    printf("Error: Invalid operator %c\n", exp[i]);
            }
            push(result);
        }
    }
    return pop();
}

int main(){
    char prefix[max];
    printf("Enter the expression:");
    scanf("%s",prefix);
    printf("Result: %d \n", evaluatePrefix(prefix));
    return 0;
}