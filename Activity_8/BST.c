#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BST.h"

// Queue functions
void initQueue(QueueType *q) 
{
    q->front = q->rear = NULL;
}

int isEmpty(QueueType *q) 
{
    return q->front == NULL;
}

void enqueue(QueueType *q, NodePtr treeNode) 
{
    QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(QueueNode));
    if (newNode != NULL) 
	{
        newNode->treeNode = treeNode;
        newNode->next = NULL;
        if (q->rear == NULL) 
		{
            q->front = q->rear = newNode;
        } else {
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

NodePtr dequeue(QueueType *q) 
{
    if (isEmpty(q)) {
        return NULL;
    } else {
        QueueNodePtr temp = q->front;
        NodePtr treeNode = temp->treeNode;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return treeNode;
    }
}

// BST functions
void addElement(NodeType **head, Product data) 
{
    NodePtr *trav = head;
    NodePtr newNode = malloc(sizeof(NodeType));
    
    if (newNode != NULL) 
	{
        newNode->item = data;
        newNode->left = newNode->right = NULL;
        for (; *trav != NULL && strcmp(data.prodName, (*trav)->item.prodName) != 0;) 
		{
            trav = (strcmp(data.prodName, (*trav)->item.prodName) > 0) ? &(*trav)->right : &(*trav)->left;
        }
        if (*trav == NULL) 
		{
            *trav = newNode;
        }
    }
}

void deleteElement(NodeType **head, Product data)
{
    NodePtr *trav = head;
    NodePtr temp;
    
    for (; *trav != NULL && strcmp(data.prodName, (*trav)->item.prodName) != 0;) 
	{
        trav = (strcmp(data.prodName, (*trav)->item.prodName) > 0) ? &(*trav)->right : &(*trav)->left;
    }
    
    if (*trav != NULL)
	{
        if ((*trav)->left == NULL) 
		{
            temp = *trav;
            *trav = (*trav)->right;
        } else if ((*trav)->right == NULL) {
            temp = *trav;
            *trav = (*trav)->left;
        } 
		else 
		{
            // GET predecessor/successor
            // predecessor
            NodePtr *pred = &(*trav)->left;
            for (; (*pred)->right != NULL; pred = &(*pred)->right) {}
            (*trav)->item = (*pred)->item;
            temp = *pred;
            *pred = (*pred)->left;
        }
        free(temp);
    }
}

void travBFS(NodeType *head) 
{
    if (head == NULL) return;
    
    QueueType queue;
    initQueue(&queue);
    
    enqueue(&queue, head);
    
    while (!isEmpty(&queue)) 
	{
        NodeType *current = dequeue(&queue);
        printf("%s\n", current->item.prodName);
        
        if (current->left != NULL) enqueue(&queue, current->left);
        if (current->right != NULL) enqueue(&queue, current->right);
    }
}


void prefixDFS(NodeType* head)
{
    if (head != NULL)
    {
    	printf("%s\n", head->item.prodName);
    	prefixDFS(head->left);
    	prefixDFS(head->right);	
	} 
}

void postfixDFS(NodeType* head)
{
    if (head != NULL)
    {
    	postfixDFS(head->left);
    	postfixDFS(head->right);
    	printf("%s\n", head->item.prodName);
	}
}

void infixDFS(NodeType* head)
{
    if (head != NULL)
    {
    	infixDFS(head->left);
    	printf("%s\n", head->item.prodName);
    	infixDFS(head->right);
	}

}
