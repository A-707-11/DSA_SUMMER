#include <stdio.h>
#include <stdlib.h>
#include "array_UID.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	SET A = initSet();
	SET B = initSet();
	
	insertElem(&A, 10);
	insertElem(&A, 9);
	insertElem(&A, 12);
	insertElem(&A, 23);
	insertElem(&A, 20);
	insertElem(&A, 13);

	
	printf("\nSet A: \n");
	display(A);
	
	insertElem(&B, 9);
	insertElem(&B, 52);
	insertElem(&B, 12);
	insertElem(&B, 36);
	insertElem(&B, 20);
	insertElem(&B, 13);

	
	printf("\n\nSet B: \n");
	display(B);
	
	SET C = unionUID(A,B);
	
	printf("\n\nUNION Set C: \n");
	display(C);
	
	SET D = intersectionUID(A,B);
	printf("\n\nINTERSECTION Set D: \n");
	display(D);
	
	//UNION: {9,10,12,13,20,23,36,52,62}
	//INTERSECTION: {9,12,13,20}
	return 0;
}
