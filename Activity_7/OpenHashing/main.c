#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "OHheader.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	DICTIONARY myDict;
    initDictionary(myDict);

    Animal a1 = {"Lion", "Mammal"};
    Animal a2 = {"Shark", "Fish"};
    Animal a3 = {"Eagle", "Bird"};
    Animal a4 = {"Tiger", "Mammal"};
    Animal a5 = {"Parrot", "Bird"};

    insert(&myDict, a1);
    insert(&myDict, a2);
    insert(&myDict, a3);
    insert(&myDict, a4);
    insert(&myDict, a5);

    display(myDict);

    deleteElem(&myDict, a3);
    printf("\nAfter deleting Eagle:\n");
    display(myDict);

	return 0;
}
