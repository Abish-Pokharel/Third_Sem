/*      ALGORITHM FOR PUSH OPERATION
1. Start
2. Check for stack overflow as
        if top = SIZE - 1 then
            print "Stack overflow" and exit the program
        else
            increase top by 1 as
            set, top = top + 1
3. Read element to be inserted say 'data'
4. Set, stack[top] = data
5. Stop



        ALGORITHM FOR PUSH OPERATION
1. Start
2. Check for stack underflow condition as
        if top = SIZE - 1 then
            print "Stack is empty" and exit the program
        else
            set a variable 'data' to store top element
                data = stack[top]
            remove element by decreamenting top by 1
            set, top = top -1
3. Print 'data' as deleted item fromthe stack
4. go to 2
5. Stop


	LINEAR QUEUE

// 		ALGORITHM FOR INSERTION (ENQUQUE)

Declare queue[MAXSIZE], initialize front = 0, rear = -1

1. Start
2. If rear = MAXSIZE -1 ?
	print 'Queue is full "
	else 
	setrear = rear + 1
	queue[rear] = data
3. Stop




// 		ALGORITHM FOR DELETION (DEQUQUE)

1. Start
2. If rear = 1 ?
	print 'Queue is empty "
	else 
	queue[front] = data
	front ++
3. Print "data" as deleted element
4. Stop


*/







#include <stdio.h>  
#define MAXSIZE 10

int stack[MAXSIZE];  
int top = -1;
int isempty()
{
if(top == -1)
return 1;
else
return 0;
}
int isfull()
{
if(top == MAXSIZE - 1)
return 1;
else
return 0;
}
void peek()
{
	if(isempty())
		 printf("Stack is empty.\n");
	else
		printf("Element at top: %d. \n",stack[top]);
		
}
void pop()
{
int data;  
	if(isempty())
	printf("Stack is empty");
else
{
	data = stack[top]; 
	 top = top - 1;
	printf("Popped element: %d. \n",data);
}

}
void push(int data)
{
if(isfull())
	printf("Stack is full.\n");
else
{
	top = top + 1;  
	stack[top] = data;
}
}
void display()
{
	if(isempty()) 
		printf("Stack is empty");

	else
	{
		for(int i = top; i>=0;i--)
        {

			printf("%d\n",stack[i]);
        }
	}

}
int main()
{
push(3);
push(5);
push(9);
push(1);
push(12);
push(15);
peek();
pop();
pop();
peek();
display();

}


