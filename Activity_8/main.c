#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	NodeType *root = NULL;
	
	Product prod1 = {"Apple", 1.99, 100, {15, 8, 2024}};
    Product prod2 = {"Banana", 0.99, 150, {20, 7, 2023}};
    Product prod3 = {"Cherry", 2.99, 200, {10, 6, 2025}};
    Product prod4 = {"Date", 3.99, 75, {25, 12, 2023}};
    Product prod5 = {"Elderberry", 4.99, 50, {5, 9, 2024}};

    addElement(&root, prod1);
    addElement(&root, prod2);
    addElement(&root, prod3);
    addElement(&root, prod4);
    addElement(&root, prod5);

    printf("\nBFS Traversal:\n\n");
    travBFS(root);

    printf("\nPrefix DFS Traversal:\n\n");
    prefixDFS(root);

    printf("\nPostfix DFS Traversal:\n\n");
    postfixDFS(root);

    printf("\nInfix DFS Traversal:\n\n");
    infixDFS(root);
    
    printf("\nAfter Deletion:\n\n");
    deleteElement(&root, prod1);
    travBFS(root);
	return 0;
}
