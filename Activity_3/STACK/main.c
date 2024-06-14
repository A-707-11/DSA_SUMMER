#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	StackArrayList myStack;
		
	initStack(&myStack);
	
	stack_push(&myStack,10);
	stack_push(&myStack,11);
	stack_push(&myStack,14);
	
	display(myStack);
	visualize(myStack);
	
	//GET EVEN
	StackArrayList myStack2 = getEven(&myStack);
	
//	display(myStack2);
	visualize(myStack2);
	
	return 0;
}
