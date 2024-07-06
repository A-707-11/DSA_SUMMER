#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "OHheader.h"

void initDictionary(DICTIONARY A) 
{
	int i;
	
    for (i= 0; i < SIZE; i++) 
	{
        A[i] = NULL;
    }
}

void display(DICTIONARY A) 
{
	int i;
	Node *temp;
	
    printf("INDEX\n");
    for (i = 0; i < SIZE;i++) 
	{
		printf("%d -- ", i);
        for (temp = A[i]; temp != NULL; temp = temp->next) 
		{
            printf("[%s,%s]", temp->data.animalName,  temp->data.animalType);
            if(temp->next != NULL)
            {
            	printf(" -> ");
			}
        }
        printf("\n");
    }
}

int hash(char *key) 
{
    int len = strlen(key);
    
	if (len >= 2) 
	{
        return (key[len - 1] + key[len - 2]) % SIZE;
    } else if (len == 1) {
        return key[0] % SIZE;
    } 
	else 
	{
        return 0;
    }
}

bool isMember(DICTIONARY A, Animal data) 
{
    int index = hash(data.animalType);
    Node *temp;
    
    for (temp = A[index]; temp != NULL; temp = temp->next) 
	{
        if (strcmp(temp->data.animalName, data.animalName) == 0 && strcmp(temp->data.animalType, data.animalType) == 0) 
		{
            return true;
        }
    }
    return false;
}

void insert(DICTIONARY *A, Animal data) 
{
	int index = hash(data.animalType);
	Node **trav = &(*A)[index];
	Node *newNode = (Node*)malloc(sizeof(Node));;
	
    if (!isMember(*A, data)) 
	{
        
        
        if (newNode != NULL) 
		{
            newNode->data = data;
    	}
        
        
        if (*trav == NULL || strcmp(newNode->data.animalName, (*trav)->data.animalName) < 0) 
		{
            newNode->next = *trav;
            *trav = newNode;
        } 
		else 
		{
            for (; *trav != NULL && (*trav)->next != NULL && strcmp(newNode->data.animalName, (*trav)->next->data.animalName) > 0; trav = &(*trav)->next) {}
            newNode->next = (*trav)->next;
            (*trav)->next = newNode;
        }
    }
}

void deleteElem(DICTIONARY *A, Animal data) 
{
    int index = hash(data.animalType);
    Node **trav = &(*A)[index];

    for (; *trav != NULL && (strcmp((*trav)->data.animalName, data.animalName) != 0 || strcmp((*trav)->data.animalType, data.animalType) != 0); trav = &(*trav)->next) {}
    
    if (*trav != NULL) 
	{
        Node *temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
}


