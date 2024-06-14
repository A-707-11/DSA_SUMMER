#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queueList.h"


QUEUE initQ()
{
	QUEUE myQ;
	myQ.front = NULL;
	myQ.rear = NULL;
	printf("Initialazation Successfull\n");
	return myQ;
}

void display(QUEUE myQ)
{
	NODE* trav;
	for(trav = myQ.front; trav != NULL; trav = trav->next)
	{
		printf("%d", trav->data);
		if(trav->next != NULL)
		{
			printf("->");
		}
	}
}

void Enqueue(QUEUE *myQ, int data)
{
	NodePtr temp = malloc(sizeof(NODE));
	
	if(temp != NULL)
	{
		temp->data = data;
	}
	
	if(isEmpty(myQ))
	{
		temp->next = myQ->front;
		myQ->front = temp;
		myQ->rear = temp;
	}
	else
	{
		myQ->rear->next = temp;
		temp->next = NULL;
		myQ->rear = temp;
	}
}
void Dequeue(QUEUE *myQ)
{
	NODE *temp;
	
	if(!isEmpty(myQ))
	{
		temp = myQ->front;
		myQ->front = myQ->front->next;
		if(myQ->front == NULL)
		{
			myQ->rear == NULL;
		}
		free(temp);
	}
	
}

int Front(QUEUE myQ)
{
	
	return (!isEmpty(myQ)) ?  myQ.front->data : -1;
}

int Rear(QUEUE myQ)
{
	return (!isEmpty(myQ))? myQ.rear->data : -1;
}

bool isEmpty(QUEUE myQ)
{
	return (myQ.front == NULL && myQ.rear == NULL);
	
}
