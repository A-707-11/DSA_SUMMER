#ifndef OPEN_HASHING_H
#define OPEN_HASHING_H

#include <stdbool.h>

#define SIZE 10
#define MAX 30

typedef struct {
    char animalName[MAX];
    char animalType[MAX];
}Animal;

typedef struct Node {
    Animal data;
    struct Node *next;
} Node;

typedef Node* DICTIONARY[SIZE];

void initDictionary(DICTIONARY A);
void display(DICTIONARY A);
int hash(char *key);
void insert(DICTIONARY *A, Animal data);
void deleteElem(DICTIONARY *A, Animal data);
bool isMember(DICTIONARY A, Animal data);

#endif
