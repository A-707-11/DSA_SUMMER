#ifndef STACK_ARRAY
#define STACK_ARRAY

#include <stdbool.h>

#define MAX 10

typedef struct {
	int data[MAX];
	int top;
} StackArrayList;

void initStack(StackArrayList *s);

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);

StackArrayList getEven(StackArrayList *s);

void display(StackArrayList s);
void visualize(StackArrayList s);

//get all even place in a new stack and remove from old stack

#endif
