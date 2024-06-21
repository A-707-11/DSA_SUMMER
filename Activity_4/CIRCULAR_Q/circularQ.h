#ifndef CIRCULAR_Q
#define CURCULAR_Q

#include <stdbool.h>

#define MAX 10

typedef struct{
	int data[MAX];
	int front;
	int rear;
}CircularQ;

CircularQ initQ();
void dequeue();
void enqueue();
bool isEmpty();
bool isFull();
void displayQ();
void visualizeQ();

#endif
