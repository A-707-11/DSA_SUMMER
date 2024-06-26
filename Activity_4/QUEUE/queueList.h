#ifndef QUEUE_LIST
#define QUEUE_LIST

#include <stdbool.h>

typedef struct node{
	int data;
	struct node* next;
}NODE, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}QUEUE;

QUEUE initQ();
void display();
void visualize();
void enqueue();
void dequeue();
int front();
int rear();
bool isEmpty();

#endif
