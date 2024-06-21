#include <stdio.h>
#include <stdlib.h>
#include "circularQ.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	CircularQ myQueue = initQ();
//	printf("%d ", myQueue.front);
	enqueue(&myQueue,11);
//	printf("%d", myQueue.rear);
	enqueue(&myQueue,22);
	enqueue(&myQueue,33);
	enqueue(&myQueue,44);
	enqueue(&myQueue,55);
	enqueue(&myQueue,66);
	enqueue(&myQueue,77);
	enqueue(&myQueue,88);
	enqueue(&myQueue,99);
	dequeue(&myQueue);
	dequeue(&myQueue);
	
	displayQ(&myQueue);
	//visualizeQ(myQueue);

	return 0;
}
