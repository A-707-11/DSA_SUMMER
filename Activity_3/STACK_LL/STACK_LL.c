#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "STACK_LL.h"


STACK initStack()
{
	STACK myStack;
	
	myStack.front = NULL;

	return myStack;
}

bool isEmpty(STACK stackH)
{
	return stackH.front == NULL;
}

void push(STACK* stackH, int data)
{
	NODE *temp = malloc(sizeof(NODE));
	
	if(temp != NULL)
	{
		temp->data = data;
		temp->next = stackH->front;
		stackH->front = temp;
	}
	
}

void pop(STACK *stackH)
{
	NODE* temp = stackH->front;
	if(!isEmpty(*stackH))
	{
		stackH->front = stackH->front->next;
	}
	else
	{
		printf("List is Empty, there is nothing to pop");
	}
	free(temp);
}

int peek(STACK stackH)
{
	if(!isEmpty(stackH))
	{
		return stackH.front->data;
	}
	else
	{
		printf("List is Empty, there is nothing to peek");
	}
}

void display(STACK *stackH)
{
	STACK tempStack = initStack();
	
	while(!isEmpty(*stackH))
	{
		push(&tempStack,peek(*stackH));
		printf("%d ", stackH->front->data);
		pop(stackH);
	}
	
	while(!isEmpty(tempStack))
	{
		push(stackH,peek(tempStack));
		pop(&tempStack);
	}
}

void visualize(STACK stackH)
{
	NODE *trav = stackH.front;
	
	for(;trav != NULL; trav = trav->next)
	{
		printf("%d ", trav->data);
	}
}
