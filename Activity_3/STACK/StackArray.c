#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s)
{
	s->top = -1;
}

bool stack_push(StackArrayList *s, int elem)
{
	s->data[++s->top] = elem;
	return true;
}

bool stack_pop(StackArrayList *s)
{
	s->top--;
	return true;	
}

int stack_peek(StackArrayList s)
{
	return s.top;
}

StackArrayList getEven(StackArrayList *s)
{
	StackArrayList evenStack;
	StackArrayList oddStack;
	
	initStack(&oddStack);
	initStack(&evenStack);

	while(s->top != -1)
	{
		if(s->data[s->top]%2==0)
		{
			stack_push(&evenStack,s->data[stack_peek(*s)]);
			stack_pop(s);
		}
		else
		{
			stack_push(&oddStack,s->data[s->top]);
			stack_pop(s);
		}
	}
	
	return evenStack;
}

void display(StackArrayList s)
{
	StackArrayList newStack;
	
	initStack(&newStack);
	
	printf("\n");
	while(s.top != -1)
	{
		stack_push(&newStack, s.data[s.top]);
		stack_pop(&s);
		printf("%d ", newStack.data[stack_peek(newStack)]);
	}
	
	while(newStack.top != -1)
	{
		stack_push(&s, newStack.data[s.top]);
		stack_pop(&newStack);
	}	
				
}

void visualize(StackArrayList s)
{
	int i;
	
	printf("\nINDEX	VALUE\n");
	for(i = 0; i <= s.top; i++)
	{
		if(i != s.top)
		{
			printf("%2d	%3d\n", i, s.data[i]);
		}
		else{
			printf("%2d	%3d", i, s.data[i]);
			printf("  ----->  TOP");
		}
	}
}
