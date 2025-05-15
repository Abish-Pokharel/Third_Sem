#include <stdio.h>

#define MAX 5

typedef struct {
    int data;
    int priority;
} PriorityQueue;

PriorityQueue queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX - 1;
}

void enqueue(int data, int priority) {
    if (isFull()) {
        printf("Queue Overflow....\n");
        return;
    }

    PriorityQueue newElement = {data, priority};

    if (isEmpty()) {
        front = rear = 0;
        queue[rear] = newElement;
    } else {
        int i;
        for (i = rear; i >= front && queue[i].priority > priority; i--) {
            queue[i + 1] = queue[i]; // Shift elements
        }
        queue[i + 1] = newElement;
        rear++;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Dequeued Element: %d with Priority: %d\n", queue[front].data, queue[front].priority);

    if (front == rear) {
        front = rear = -1; // Reset when queue is empty
    } else {
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Priority Queue Elements:\n");
    printf("Data\tPriority\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\t%d\n", queue[i].data, queue[i].priority);
    }
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);
    enqueue(40, 1);
    enqueue(50, 2);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}
