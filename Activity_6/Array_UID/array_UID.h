#ifndef ARRAY_UID
#define ARRAY_UID

#define MAX 20

typedef struct{
	int elem[MAX];
	int count;
}SET;

SET initSet();
void insertElem();
void deleteElem();
SET unionUID();
SET intersectionUID();
void display();

#endif
