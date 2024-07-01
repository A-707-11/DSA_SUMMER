#include <stdio.h>
#include <stdlib.h>
#include "DictHead.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	 DICTIONARY A;
    initDictionary(A);

    Animal a1 = {"Lion", "Mammal"};
    Animal a2 = {"Shark", "Fish"};
    Animal a3 = {"Eagle", "Bird"};
    Animal a4 = {"Parrot", "Bird"};

    insert(&A, a1);
    insert(&A, a2);
    insert(&A, a3);
    insert(&A, a4);

    printf("Before deletion:\n");
    display(A);

    deleteElem(&A, a2);

    printf("\nAfter deletion:\n");
    display(A);

	return 0;
}
