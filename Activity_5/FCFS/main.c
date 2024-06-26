#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//UNCOMMENT THE LINE BELOW TO GET PROCESS
	//processArray myP = initProcess();
	QUEUE myQ = initQ();
	processArray sampleP; 
	
	sampleP.count = 3;
	sampleP.data[0] = (processData) {'A',5,5,0,0,0};
	sampleP.data[1] = (processData) {'B',7,6,0,0,0};
	sampleP.data[2] = (processData) {'C',2,8,0,0,0};
	
	display(sampleP);
	fcfs_scheduling(&myQ,&sampleP);
	display(sampleP);
	return 0;
}
