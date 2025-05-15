// WAP to demonstrate circular queue.

#include<stdio.h>
#include<string.h>

#define max 50
int queue[max];
int front = -1, rear = -1;

int isFull(){
    if(front == (rear + 1) % max) {
        return 1; 
    }else {
        return 0;
    }
}
int isEmpty(){
    if(rear == -1) {
        return 1;
    }else {
        return 0;
    }
}

void enqueue(int a){
    if(!isFull()){
        if (isEmpty()) { 
            rear = front = 0;
        }else {
            rear = (rear + 1) % max;
            queue[rear]= a;
        }  
        queue[rear]= a;      
    }else{
        printf("Queue Overflow\n");
    }
}

void dequeue(){
    int d;
    if(!isEmpty()){
        d = queue[front];
        if (front == rear) {  
            front = rear = -1;
        }else {  
            front = (front + 1)% max;
        }
    }else {
        printf("Queue Empty");
    }
}

void display(){
    if(!isEmpty()){
        int  i = front;
        printf("Queue elements: ");
        while (1){
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % max;
        }        
        printf("\n");
    }
    return ;
}

void peekValue(){
    if(isEmpty())
        printf("Queue is empty.");
    else
        printf("Top value is: %d \n",queue[front]);
}

int main(){
    int n, i, data_e;
    printf("Enter the size of queue:");
    scanf("%d",&n);

    for(i = 0; i< n; i++){
        printf("Enter the %d element of queue:", i+1);
        scanf("%d", &data_e);
        enqueue(data_e);
    }
    display();
    peekValue();
    dequeue();
    display();
    enqueue(5);
    display();
    return 0;   
}

