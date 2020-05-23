#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

enq(struct queue* queue, const float data)
{
	struct node* U = (struct node*)malloc(sizeof(struct node));
	U->data = data;
	U->pred = queue->tail;
	U->next = NULL;

	if (queue->tail == NULL)
		queue->head = U;
	else
		queue->tail->next = U;
	queue->tail = U;
}

deq(struct queue* queue)
{
	struct node* U = queue->head;
	queue->head = queue->head->next;
	free(U);
	if (queue->head == NULL)
	{
		queue->tail = NULL;
	}
	else
		queue->head->pred = NULL;
}

is_empty(struct queue queue)
{
	if (queue.head == NULL)
		return 0;
	else return 1;
}