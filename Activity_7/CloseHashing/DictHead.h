#ifndef CLOSE_HASHING
#define CLOSE_HASHING

#include <stdbool.h>


#define SIZE 10
#define MAX 30
#define EMPTY ""
#define DELETED "DELETED"

typedef struct {
    char animalName[MAX];
    char animalType[MAX];
} Animal;

typedef Animal* DICTIONARY[SIZE];


void initDictionary(DICTIONARY A);
void display(DICTIONARY A);
int hash(Animal data);
void insert(DICTIONARY *A, Animal data);
void deleteElem(DICTIONARY *A, Animal data);
bool isMember(DICTIONARY A, Animal data);




#endif
