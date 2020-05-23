#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct node
{
	float data;
	struct node* next;
	struct node* pred;
}node;

typedef struct queue
{
	float data;
	struct node* head;
	struct node* tail;
}queue;

enq(struct queue* queue, const float data);
deq(struct queue* queue);
is_empty(struct queue queue);

#endif 
