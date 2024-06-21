#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "STACK_LL.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	STACK A = initStack();
	

	push(&A,10);
	push(&A,11);
	push(&A,22);
	push(&A,33);
	

	printf("\nDISPLAY: \n");
	display(&A);
	printf("\nVISUALIZATION: \n");
	visualize(A);
	
	printf("\n\nAFTER POP: \n");
	pop(&A);
	printf("DISPLAY: \n");
	display(&A);
	printf("\nVISUALIZATION: \n");
	visualize(A);
	return 0;
}
