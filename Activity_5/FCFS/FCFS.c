#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

processArray initProcess()
{
	processArray A;
	int i, prcs;
	
	printf("\n\nEnter the number of Process: ");
	scanf("%d", prcs);
	
	for(i=0;i<prcs;i++)
	{
		A.data[i].et = -1;
		A.data[i].tt = -1;
		A.data[i].wt = -1;
			
		printf("Enter Process ID", A.data[i].processID);
		scanf("%c", &A.data[i].processID);
		printf("Enter Arrival Time", A.data[i].at);
		scanf("%d", &A.data[i].at);
		printf("Enter Burst Time", A.data[i].bt);
		scanf("%d", &A.data[i].bt);
		A.count++;
	}

	return A;
}

QUEUE initQ()
{
	QUEUE A;
	
	A.front = NULL;
	A.rear = NULL;
	
	return A;
}

bool isEmpty(QUEUE A)
{
	return (A.front == NULL && A.rear == NULL);
}

void fcfs_enqueue(QUEUE *A, processData B)
{
	prcsPtrNode newNode = malloc(sizeof(processNode));
	
	if(newNode != NULL)
	{
		newNode->data = B;
		newNode->next = NULL;
	}
	
	if(isEmpty(*A))
	{
		A->front = newNode;
		A->rear = newNode;
	}
	else
	{
		A->rear->next = newNode;
		A->rear = newNode;
	}
	
}

void fcfs_dequeue(QUEUE *A)
{
	prcsPtrNode temp;
	
	if(!isEmpty(*A))
	{
		temp = A->front;
		A->front = A->front->next;
		if(A->front == NULL)
		{
			A->rear = NULL;
		}
		free(temp);
	}
}

void fcfs_scheduling(QUEUE *A, processArray *B)
{
	int i, j;
	processData temp;
	
	for(i=0;i<MAX;i++)
	{
		for(j=i+1;j<MAX-1;j++)
		{
			if(B->data[j].at > B->data[j + 1].at)
			{
				temp = B->data[i];
				B->data[i] = B->data[j];
				B->data[j] = temp;	
			}
		}
	}
	
	
	
	
}





