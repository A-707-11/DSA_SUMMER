#include <stdio.h>
#include <stdlib.h>
#include "queueList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	QUEUE myQueue = initQ();
	
	printf("\nENQUEUE\n");
	enqueue(&myQueue,10);
	enqueue(&myQueue,44);
	enqueue(&myQueue,33);
	enqueue(&myQueue,22);
	
	display(&myQueue);
	visualize(myQueue);
	
	printf("\n\nFRONT: %d\n", front(myQueue));
	printf("REAR: %d\n", rear(myQueue));
	
	printf("\n\nAFTER DEQUEUE: \n");
	dequeue(&myQueue);

	display(&myQueue);
	visualize(myQueue);
	
	printf("\n\nFRONT: %d\n", front(myQueue));
	printf("REAR: %d\n", rear(myQueue));
	
	return 0;
}
