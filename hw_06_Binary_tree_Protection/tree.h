#ifndef _TREE_H
#define _TREE_H

typedef struct node
{
	int data;
	struct node* l;
	struct node* r;
}node;

typedef struct queue
{
	struct queue* next;
	struct node* tree;
}queue;

add(struct node** root, int new_value);
DFS(struct node* node);
enq(struct queue** head, struct queue** tail, struct node* value);
struct node* deq(struct queue** head, struct queue** tail);
BFS(struct node* root);
len(struct node* root, const int num);
summa(struct node* root);
#endif 
