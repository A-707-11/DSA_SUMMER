#include <stdio.h>
#include <stdlib.h>
#include "queueList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	QUEUE myQueue = initQ();
	
	printf("\nENQUEUE\n");
	Enqueue(&myQueue,10);
	Enqueue(&myQueue,44);
	Enqueue(&myQueue,33);
	Enqueue(&myQueue,22);
	
	display(myQueue);
	
	printf("\nDEQUEUE\n");
	Dequeue(&myQueue);
	display(myQueue);
	
	printf("\n\nFRONT: %d\n", Front(myQueue));
	printf("REAR: %d\n", Rear(myQueue));
	
	return 0;
}
