#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DictHead.h"

void initDictionary(DICTIONARY A) 
{
	int i;
	
    for (i = 0; i < SIZE; i++) 
	{
        A[i] = (Animal*)malloc(sizeof(Animal));
        strcpy(A[i]->animalName, EMPTY);
        strcpy(A[i]->animalType, EMPTY);
    }
}

void display(DICTIONARY A) 
{
	
	int i;
	
    printf("INDEX\tNAME\tTYPE\n");
    for (i = 0; i < SIZE; i++) 
	{
        if (strcmp(A[i]->animalName, EMPTY) != 0 && strcmp(A[i]->animalName, DELETED) != 0) 
		{
            printf("%3d\t%s\t%s\n", i, A[i]->animalName, A[i]->animalType);
        }
    }
}

int hash(Animal data) 
{
    int len = strlen(data.animalType);
    
	if (len >= 2) 
	{
        return (data.animalType[len - 1] + data.animalType[len - 2]) % SIZE;
    } else if (len == 1) {
        return data.animalType[0] % SIZE;
    } else {
        return 0;
    }
}

bool isMember(DICTIONARY A, Animal data) 
{
	
	int i;
	
    for (i = 0; i < SIZE; i++) 
	{
        if (strcmp(A[i]->animalName, data.animalName) == 0 && strcmp(A[i]->animalType, data.animalType) == 0) 
		{
            return true;
        }
    }
    return false;
}

void insert(DICTIONARY *A, Animal data) 
{
	int i;
	
    if (!isMember(*A, data)) 
	{
        int i;
        for (i = hash(data); strcmp((*A)[i]->animalName, EMPTY) != 0 && strcmp((*A)[i]->animalName, DELETED) != 0; i = (i + 1) % SIZE) {}
        
		strcpy((*A)[i]->animalName, data.animalName);
        strcpy((*A)[i]->animalType, data.animalType);
    }
}

void deleteElem(DICTIONARY *A, Animal data) 
{
	int i;
	
    if (isMember(*A, data)) 
	{
        for (i = hash(data); strcmp((*A)[i]->animalName, data.animalName) != 0; i = (i + 1) % SIZE) {}
        strcpy((*A)[i]->animalName, DELETED);
        strcpy((*A)[i]->animalType, DELETED);
    }
}

