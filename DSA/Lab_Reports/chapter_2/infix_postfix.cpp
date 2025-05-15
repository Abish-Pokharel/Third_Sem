#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char data) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char data;

    while (infix[i] != '\0') {
        data = infix[i];
        if (isalnum(data)) {
            postfix[j++] = data;
        } else if (data == '(') {
            push(data);
        } else if (data == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(data)) {
                postfix[j++] = pop();
            }
            push(data);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
