#include <stdio.h>
#include <stdlib.h>
#include "array_UID.h"

#include <stdbool.h>

SET initSet()
{
	SET mySet;
	int i;
	
	for(i=0;i<MAX;i++)
	{
		mySet.elem[i] = 0;
	}
	
	mySet.count = 0;
	return mySet;
}

void insertElem(SET *A,int data)
{
	int i, flag = false;
	
	for(i = 0; i < MAX; i++)
	{
		if(A->elem[i] == data)
		{
			flag = true;
		}
	}
	
	if(flag == false)
	{
		A->elem[A->count++] = data;	
	} else {
		printf("Data %d Already in SET", data);
	}
}

void deleteElem(SET *A, int data)
{
	int i, j;
	int flag = false;
	
	for(i=0;i<MAX;i++)
	{
		if(A->elem[i] == data)
		{
			flag = true;
			for(j=i;j<MAX;j++)
			{
				
					A->elem[j] = A->elem[j+1];	
			}
		}
	}
	
	
	if(flag == false)
	{
		printf("\n\nData %d not Found\n\n", data);
	}
	else
	{
		A->count--;
	}
	
}

SET unionUID(SET a, SET b)
{
	int i, j, flag = false;
	SET unionSET = initSet();
	
	for(i=0;i<a.count;i++)
	{
		unionSET.elem[unionSET.count++] = a.elem[i];		
	}
	
	for(i=0;i<b.count;i++)
	{
		for(j=0;j<unionSET.count;j++)
		{
			if(unionSET.elem[j] == b.elem[i])
			{
				flag = true;	
				break;
			}	
		}
		if(!flag)
		{
			unionSET.elem[unionSET.count++] = b.elem[i];
		}
		flag = false;
	}

	return unionSET;
}

SET intersectionUID(SET a, SET b)
{
	int i, j;
	SET intersectSET = initSet();
	
	for(i=0;i<a.count;i++)
	{
		for(j=0;j<b.count;j++)
		{
			if(a.elem[i] == b.elem[j])
			{
				intersectSET.elem[intersectSET.count++] = a.elem[i];
			}	
		}
	}
	
	return intersectSET;
}

void display(SET A)
{
	int i;
	
	for(i=0;i<A.count;i++)
	{
		printf("%d ", A.elem[i]);
	}
}
