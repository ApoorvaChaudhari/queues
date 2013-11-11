/*
 *  queues.c
 *  
 *
 *  Created by Apoorva Chaudhari on 6/18/12.
 *  Copyright 2012 Rutgers University. All rights reserved.
 *
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
} Node;

void addq (Node *q, int x, Node **rear, Node **front)
{
	Node * ptr, *ptr_ftr;
	ptr_ftr = *rear;
	
	ptr = (Node *) malloc (sizeof(Node));
	ptr->data = x;
	ptr->next = NULL;
	
	ptr_ftr =  *rear;
	
	if( *rear == NULL)
	{
		*front = ptr;
		*rear = ptr;
	}
	else
	{
		ptr_ftr->next =  ptr;
		*rear = ptr;
	}
}

int deleteq ( Node * q, Node **rear, Node **front)
{
	int x;
	Node * ptr;
	
	if(*front == NULL)
		printf(" Queue is empty\n");
	else
	{
		x = q->data;
		*front = q-> next;
	}
	
	if( *front == NULL)
		*rear = NULL;
	free(ptr);
	
	return x;
}

void display( Node * front)
{
	Node * ptr;
	ptr = front;
	
	while (ptr != NULL)
	{
		printf("%d -->", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
	printf("\n");
}


int main()
{
	Node q;
	Node *front, *rear;
	rear = front = NULL;
	
	addq(&q, 5, &rear, &front);
	//display(q, front);
	addq(&q, 15, &rear, &front);
	display(front);
	display(front);
		
	return 0;
}

