#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>


push(struct stack** head, const char str)
{
	struct stack* l = (struct stack*)malloc(sizeof(struct stack));
	l->value = str;
	l->next = *head;
	*head = l;
}

char pop(struct stack** head)
{
	if (*head == NULL)
		return 0;
	else
	{
		struct stack* l = NULL;
		struct stack* Q = NULL;
		Q = *head;
		char result = Q->value;
		*head = Q->next;
		l = *head;
		return result;
	}
}

empty(struct stack** head)
{
	if (*head != NULL)
		return 0;
	else
		return 1;
}
int count(stack** head)
{
	int count = 0;
	if (*head == NULL)
		return 0;
	else
	{
		stack* l = NULL;
		l = *head;
		while (l->next)
		{
			count++;
			l = l->next;
		}
		count++;
	}
	return (count);
}
