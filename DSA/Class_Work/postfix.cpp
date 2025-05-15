//#include<stdio.h>
//#include<ctype.h>
//#include<string.h>
//#define max 20
//
//int stack[max];
//int top = -1;
//
//int pop() {
//    return stack[top--];
//}
//void push(int value) {
//    stack[++top] = value;
//}
//int main(){
//    int i, length;
//    char exp[max];
//    printf("Enter a postfix expression: ");
//    fgets(exp, max, stdin);
//    exp[strcspn(exp, "\n")] = '\0';
//    length = strlen(exp);
//    for (i = 0 ; i < length; i++){
//         if (exp[i] == ' ') 
//            continue;
//        if (isdigit(exp[i])) {
//            push(exp[i] - '0');
//        } else {
//            int op2 = pop();
//            int op1 = pop();
//            switch (exp[i]) {
//                case '+': 
//                    push(op1 + op2); 
//                    break;
//                case '-': 
//                    push(op1 - op2); 
//                    break;
//                case '*': 
//                    push(op1 * op2); 
//                    break;
//                case '/': 
//                    push(op1 / op2); 
//                    break;
//            }
//        }
//    }
//    printf("The result is: %d\n", stack[top]);
//    return 0;
//}




#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main() {
    int gd = DETECT, gm;
    float shy;
    
    initgraph(&gd, &gm, NULL);
    
    printf("Enter the shear factor shy along y-axis: ");
    scanf("%f", &shy);

    line(150, 50, 250, 50);
    line(250, 50, 250, 150);
    line(250, 150, 150, 150);
    line(150, 150, 150, 50);

    printf("Y-shear\n");

    setcolor(12);
    line(150, (50 + 150 * shy), 250, (50 + 250 * shy));
    line(250, (50 + 250 * shy), 250, (150 + 250 * shy));
    line(250, (150 + 250 * shy), 150, (150 + 150 * shy));
    line(150, (150 + 150 * shy), 150, (50 + 150 * shy));

    getch();
    closegraph();
    return 0;
}
