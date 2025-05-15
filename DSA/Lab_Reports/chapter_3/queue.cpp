// WAP to demonstrate queue. Users have to insert the Max size of the queue 
// and while enqueue and dequeue users have to provide data manually. (not hard code). 
// Explain the algorithm of dequeue and enqueue.

#include<stdio.h>
#include<string.h>

#define max 50
int queue[max] ;
int front = -1, rear = -1;

int isFull(){
    if(rear == max -1) {
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
        if (front == -1) { 
            front = 0;
        }
        rear = rear + 1;
        queue[rear]= a;
    }else{
        printf("Queue Overflow\n");
    }
}

void dequeue(){
    int d;
    if(!isEmpty()){
        d = queue[front];
        front ++;
        if (front > rear) {  
            front = -1;
            rear = -1;
        }
    }else {
        printf("Queue Empty");
    }
}

void display(){
    if(!isEmpty()){
        printf("Queue elements: ");
        for(int i = front; i <= rear; i++ ){
            printf("%d ", queue[i]);
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
    int n, i, data_e, data_d;
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
    return 0;   
}

