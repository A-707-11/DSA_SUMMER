#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

typedef struct{
	NODE* front;
}STACK;

STACK initStack();
bool isEmpty();
void push();
void pop();
int peek();
void display();
void visualize();


#endif
