#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queueList.h"


QUEUE initQ()
{
	QUEUE myQ;
	myQ.front = NULL;
	myQ.rear = NULL;
	return myQ;
}

void display(QUEUE *myQ)
{
	QUEUE tempQ = initQ();
 	printf("\nDISPLAY: \n");
	while(!isEmpty(myQ))
	{
		printf("%d ", front(*myQ));
		enqueue(&tempQ,front(*myQ));
		dequeue(myQ);
	}

	while(!isEmpty(tempQ))
	{
		enqueue(myQ,front(tempQ));
		dequeue(&tempQ);
	}
	
}

void visualize(QUEUE myQ)
{
	NODE* trav;
	printf("\n\nVISUALIZE: \n");
	for(trav = myQ.front; trav != NULL; trav = trav->next)
	{
		printf("%d", trav->data);
		if(trav->next != NULL)
		{
			printf("->");
		}
	}
}

void enqueue(QUEUE *myQ, int data)
{
	NodePtr temp = malloc(sizeof(NODE));
	
	if(temp != NULL)
	{
		temp->data = data;
		temp->next = NULL;
	}
	
	if(isEmpty(*myQ))
	{
		temp->next = myQ->front;
		myQ->front = temp;
		myQ->rear = temp;
	}
	else
	{
		myQ->rear->next = temp;
		myQ->rear = temp;
	}
}

void dequeue(QUEUE *myQ)
{
	NODE *temp;
	
	if(!isEmpty(*myQ))
	{
		temp = myQ->front;
		myQ->front = myQ->front->next;
		if(myQ->front == NULL)
		{
			myQ->rear = NULL;
		}
		free(temp);
	}
	
}

int front(QUEUE myQ)
{
	return (!isEmpty(myQ)) ?  myQ.front->data : -1;
}

int rear(QUEUE myQ)
{
	return (!isEmpty(myQ))? myQ.rear->data : -1;
}

bool isEmpty(QUEUE myQ)
{
	return (myQ.front == NULL && myQ.rear == NULL)? true:false;
	
}
