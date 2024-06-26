#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

processArray initProcess()
{
	processArray A;
	int i, prcs;
	
	printf("\n\nEnter the number of Process: ");
	scanf("%d", &prcs);
	fflush(stdin);
	
	for(i=0;i<prcs;i++)
	{
		A.data[i].et = 0;
		A.data[i].tt = 0;
		A.data[i].wt = 0;
			
		printf("Enter Process ID: ", A.data[i].processID);
		scanf("%c", &A.data[i].processID);
		printf("Enter Arrival Time: ", A.data[i].at);
		scanf("%d", &A.data[i].at);
		printf("Enter Burst Time: ", A.data[i].bt);
		scanf("%d", &A.data[i].bt);
		fflush(stdin);
		printf("\n");
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

void display(processArray A)
{
	int i;
	printf("\n\n-------------------------------------------\n\n");
	printf("%s %3s %3s %3s %3s %3s\n", "Process", "AT", "BT", "ET", "WT", "TT");
	for(i=0;i<A.count;i++)
	{
		printf("%4c %5d %3d %3d %3d %3d\n", A.data[i].processID, A.data[i].at, A.data[i].bt, A.data[i].et, A.data[i].wt, A.data[i].tt);
	}
}

bool isEmpty(QUEUE A)
{
	return (A.front == NULL && A.rear == NULL);
}

processData front(QUEUE A)
{
	return A.front->data;
}

processData rear(QUEUE A)
{
	return A.rear->data;
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
    int currentTime = 0;
    processData currentProcess;
    
    for (i = 0; i < B->count - 1; i++) 
	{
        for (j = i + 1; j < B->count; j++) 
		{
            if (B->data[i].at > B->data[j].at) 
			{
                processData temp = B->data[i];
                B->data[i] = B->data[j];
                B->data[j] = temp;
            }
        }
    }
    
    for (i = 0; i < B->count; i++) 
	{
        fcfs_enqueue(A, B->data[i]);
    }

    while (!isEmpty(*A)) 
	{
    	currentProcess = front(*A);
        fcfs_dequeue(A);

        if (currentTime < currentProcess.at) 
		{
            currentTime = currentProcess.at;
        }

        currentProcess.et = currentTime + currentProcess.bt;
        currentProcess.wt = currentTime - currentProcess.at;
        currentProcess.tt = currentProcess.et - currentProcess.at;

        currentTime += currentProcess.bt;

        
        for (i = 0; i < B->count; i++) 
		{
            if (B->data[i].processID == currentProcess.processID) 
			{
                B->data[i] = currentProcess;
                break;
            }
        }
    }
}





