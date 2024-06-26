#ifndef FCFS
#define FCFS

#include <stdbool.h>

#define MAX 20

typedef struct{
	char processID;
	int at;
	int bt;
	int et;
	int wt;
	int tt;
}processData;

typedef struct{
	processData data[MAX];
	int count;
}processArray;

typedef struct processNode{
	processData data;
	struct processNode *next;
}processNode, *prcsPtrNode;

typedef struct{
	prcsPtrNode front;
	prcsPtrNode rear;
}QUEUE;

processArray initProcess();
QUEUE initQ();
void display();
bool isEmpty();
processData front();
processData rear();
void fcfs_enqueue();
void fcfs_dequeue();
void fcfs_scheduling();


#endif
