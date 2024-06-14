#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
	char name[MAX];
	int idNum;
	int age;
}info;

typedef struct node {
	info data;
	struct node *next;
}Node, *NodePtr;

void display();
void insertFirst();
void insertRear();
void insertAt();
void deleteFirst();
void deleteLast();
void deleteAt();

int main ()
{
	NodePtr head = NULL;
	
	info myStudents[10] = {{"Arjoy",2,20101650},
							{"Simon",1,20101650},
							{"John",5,20101650},
							{"Krizia",4,20101650},
							{"Kyle",3,20101650},
							{"Jillian",12,20101650}};
	
	printf("Insert First\n");
	insertFirst(&head,myStudents[0]);
	insertFirst(&head,myStudents[1]);
	insertFirst(&head,myStudents[2]);
	display(head);
	printf("Insert Rear\n");
	insertRear(&head,myStudents[3]);
	display(head);
	printf("Insert At Index [3]\n");
	insertAt(&head, myStudents[4],3);
	display(head);
	printf("Delete First\n");
	deleteFirst(&head);
	display(head);
	printf("Delete Last\n");
	deleteLast(&head);
	display(head);
	printf("Delete At Index [3]\n");
	deleteAt(&head, 3);
	display(head);
	
	return 0;	
}

void display(NodePtr head)
{
	NodePtr trav = head;
	
	for(; trav != NULL; trav = trav->next)
	{
		printf("%s \t%d \t%d\n", trav->data.name, trav->data.age, trav->data.idNum);
	}
	printf("\n----------------------------------\n");
}

void insertFirst(NodePtr* head, info data)
{
	NodePtr temp = malloc(sizeof(Node));
	
	if(temp != NULL)
	{
		temp->data = data;
		temp->next = *head;
		*head = temp;		
	}
	
}

void insertRear(NodePtr* head, info data)
{
	NodePtr* trav = head;
	
	if(*trav != NULL)
	{
		for(; *trav != NULL; trav = &(*trav)->next){}
		
			NodePtr temp = malloc(sizeof(Node));
		
			if(temp != NULL)
			{
				temp->data = data;
				temp->next = *trav;
				*trav = temp;
			}
	
	}
	
}

void insertAt(NodePtr* head, info data, int pos)
{
	NodePtr* trav = head;
	int i = 0;
	
	if(trav != NULL)
	{
		for(;*trav != NULL && i < pos; trav = &(*trav)->next, i++){}
		
		NodePtr temp = malloc(sizeof(Node));
		
		if(temp != NULL)
		{
			temp->data = data;
			temp->next = *trav;
			*trav = temp;
		}
		
	}
	
	
}

void deleteFirst(NodePtr* head)
{
	NodePtr temp;
	
	if(*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	
}

void deleteLast(NodePtr* head)
{
	NodePtr *trav = head;
	NodePtr temp;
	
	if(*head != NULL)
	{
		for(; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
		
		if(*trav != NULL)
		{
			temp = *trav;
			*trav = NULL;
			free(temp);
		}
	}
	
}

void deleteAt(NodePtr* head, int pos)
{
	NodePtr *trav = head;
	NodePtr temp;
	int i = 0;
	
	if(*head != NULL)
	{
		for(;*trav != NULL && i != pos; trav = &(*trav)->next, i++){}
		
		if(*trav != NULL)
		{
			temp = *trav;
			*trav = (*trav)->next;
			free(temp);
		}
	}
}





