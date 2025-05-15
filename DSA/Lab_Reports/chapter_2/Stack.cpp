#include<stdio.h>
#include<conio.h>

#define MAXSIZE 5

int stack[MAXSIZE];
int top = -1 ;


int isEmpty(){
    if (top == -1){
        return 1;
    } else {
        return 0;
    }
}
int isFull(){
    if(top == MAXSIZE - 1)
        return 1;
    else
        return 0;
}
void peekValue(){
    if(isEmpty())
        printf("Stack is empty.");
    else
        printf("Top value is: %d \n",stack[top]);
}
void push( int data ){
    if(isFull())
        printf("Stack is full.");
    else
        top = top + 1;
        stack[top] = data;        
}
void pop(){
    int data;
    if(isEmpty())
        printf("Stack is empty.");
    else
        data = stack[top];
        top = top - 1;
        printf("Popped value: %d\n", data);
}

void display() {
    if (isEmpty())
        printf("Stack is empty.\n");
    else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int data;
    for(int i = 0; i < MAXSIZE; i++){
        printf("Enter the element (%d) to push: ", i+1);
        scanf("%d", &data);
        push(data);
    }
    peekValue();
    display();
    pop();
    display();
}