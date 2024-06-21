#include <stdio.h>
#include <stdlib.h>
#include "circularQ.h"

CircularQ initQ()
{
	CircularQ myQ;
	myQ.front = 0;
	myQ.rear = MAX-1;
	
	return myQ;
}

void dequeue(CircularQ* myQ)
{
	if(!isEmpty(myQ))
	{
		myQ->front = (myQ->front+1)%MAX;	
	}
	
}

void enqueue(CircularQ* myQ, int data)
{
	if(!isFull(myQ))
	{
		myQ->rear = (myQ->rear + 1)%MAX;
		myQ->data[myQ->rear] = data;
	}
}

bool isEmpty(CircularQ myQ)
{
	return (myQ.rear+1)%MAX == myQ.front;
}

bool isFull(CircularQ myQ)
{
	return (myQ.rear+2)%MAX == myQ.front;
}

void displayQ(CircularQ *myQ)
{
	CircularQ tempQ = initQ();
	
	while(!isEmpty(*myQ))
	{
		printf("%d\n", myQ->data[myQ->front]);
		enqueue(&tempQ,myQ->data[myQ->front]);
		dequeue(myQ);
	}
	
	while(!isEmpty(tempQ))
	{
		enqueue(myQ,tempQ.data[tempQ.front]);
		dequeue(&tempQ);
	}
	
}

void visualizeQ(CircularQ myQ)
{
	int i, j;
	
	printf("INDEX	DATA\n");
	for(i = 0; i <= MAX; i++)
	{
		printf("%d\n",i, myQ.data[i]);
		if(i == myQ.front)
		{
			for(j = myQ.front; j <= myQ.rear; j = (j+1)%MAX)
			{
				printf("%d %d\n",i, myQ.data[i]);
			}	
		}
		
	}
	
	
}
