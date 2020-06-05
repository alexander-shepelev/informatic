#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

enq(struct queue** head, struct queue** tail, struct node* value)
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->next = NULL;
	q->tree = value;
	if ((*head == NULL) && (*tail == NULL))
		*head = q;
	else
		(*tail)->next = q;
	*tail = q;
}

struct node* deq(struct queue** head, struct queue** tail)
{
	struct node* res;
	res = (*head)->tree;
	struct queue* old;
	old = *head;
	*head = (*head)->next;
	if (*head == NULL)
		*tail = NULL;
	free(old);
	return res;
}

add(struct node** root, int new_value)
{
	if (*root == NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->data = new_value;
		(*root)->l = NULL;
		(*root)->r = NULL;
	}
	else
	{
		if (new_value > (*root)->data)
			add(&(*root)->r, new_value);
		else
			add(&(*root)->l, new_value);
	}
}

BFS(struct node* root)
{
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enq(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;

		while (head != NULL)
		{
			struct node* value;
			value = deq(&head, &tail);
			if (value == NULL) {
				printf("empty!\n");  return 0;
			}
			if (value->l)
				enq(&new_head, &new_tail, value->l);
			if (value->r)
				enq(&new_head, &new_tail, value->r);
			printf("%d ", value->data);
		}
		printf("\n");
		head = new_head;
		tail = new_tail;
	}
	return 0;
}

DFS(struct node* root)
{
	if (root == NULL)
	{
		printf("empty!");
		return 0;
	}

	printf("%d ", root->data);
	if (root->l != NULL)
		DFS(root->l);
	if (root->r != NULL)
		DFS(root->r);
	return 0;
}


len(struct node* root, const int num)
{
	int k = 0;
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enq(&head, &tail, root);

	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;

		while (head != NULL)
		{
			struct node* value;
			value = deq(&head, &tail);
			if (value == NULL)
			{
				printf("empty!\n");
				return 0;
			}

			if (value->data == num)
			{
				printf("Level = %d\n", k);
				return 0;
			}

			if (value->l)
				enq(&new_head, &new_tail, value->l);
			if (value->r)
				enq(&new_head, &new_tail, value->r);
		}
		k++;
		head = new_head;
		tail = new_tail;
	}
	printf("net elementa\n");
	return 0;
}
summa(struct node* root)
{
	int summa=0;
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enq(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;

		while (head != NULL)
		{
			struct node* value;
			value = deq(&head, &tail);
			if (value == NULL) 
			{
				printf("empty!\n");  return 0;
			}
			if ((value->l) || (value->r))
			{
				if (value->l)
					enq(&new_head, &new_tail, value->l);
				if (value->r)
					enq(&new_head, &new_tail, value->r);
			}
			else
			{
				summa = summa + value->data;
			}
		}
		head = new_head;
		tail = new_tail;
	}
	printf("summa = %d\n", summa);
	return 0;
}