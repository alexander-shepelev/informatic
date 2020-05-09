#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "LINKEDLIST.h"
#include <stdlib.h>
create_head(list** head, int a)
{
	list* lst = (list*)malloc(sizeof(list));
	lst->value = a;
	lst->next = NULL;
	*head = lst;
}
print(list** head)
{
	list* lst = *head;
	while (lst != NULL)
	{
		printf("%d ", lst->value);
		lst = lst->next;
	}
}
add_first(list** head, int a)
{
	list* lst = (list*)malloc(sizeof(list));
	lst->value = a;
	lst->next = *head;
	*head = lst;
}
add_last(list** head, int a)
{
	list* lst = g_last(head);
	list* P = (list*)malloc(sizeof(list));
	P->value = a;
	P->next = NULL;
	lst->next = P;
}
del_f(list** head)
{
	list* pred = NULL;
	int val;
	pred = (*head);
	val = pred->value;
	(*head) = (*head)->next;
	free(pred);
}
del_la(list** head)
{
	int a = 0;
	list* lst = *head;
	list* buf = *head;
	while (lst != NULL)
	{
		lst = lst->next;
		a++;
	}
	if (a == 1)
	{
		*head = NULL;
	}
	else
	{
		a = a - 2;
		while (a != 0)
		{
			buf = buf->next;
			a--;
		}
		buf->next = NULL;
	}
}
del_N(list** head, int N, int a)
{
	int u;
	int count = 0;
	list* l1 = *head;
	list* next = *head;
	list* pred = *head;
	if (N == 1)
	{
		list* pred = NULL;
		int val;
		pred = (*head);
		val = pred->value;
		(*head) = (*head)->next;
		free(pred);
	}
	else
	{
		while (l1 != NULL)
		{
			l1 = l1->next;
			count++;
		}
		if (count == 0)
		{
			list* lst = (list*)malloc(sizeof(list));
			lst->value = a;
			lst->next = *head;
			*head = NULL;//
		}
		else if (count == 1)
		{
			list* lst = (list*)malloc(sizeof(list));
			lst->value = a;
			lst->next = *head;
			*head = NULL;//
		}
		else if (count < N)
		{
			printf("N bolshe kolichestva chisel v spiske\n");
		}
		else
		{
			N--;
			u = N;
			u--;
			while (N != 0)
			{
				next = next->next;
				N--;
			}
			while (u != 0)
			{
				pred = pred->next;
				u--;
			}
			next = next->next;
			pred->next = next;

		}
	}

}
add_N(list** head, int N, int a)
{
	int u;
	int count = 0;
	list* l1 = *head;
	list* next = *head;
	list* pred = *head;
	if (N == 1)
	{
		list* lst = (list*)malloc(sizeof(list));
		lst->value = a;
		lst->next = *head;
		*head = lst;
	}
	else
	{
		while (l1 != NULL)
		{
			l1 = l1->next;
			count++;
		}
		if (count == 0)
		{
			list* lst = (list*)malloc(sizeof(list));
			lst->value = a;
			lst->next = *head;
			*head = lst;
		}
		else if (count == 1)
		{
			list* lst = (list*)malloc(sizeof(list));
			lst->value = a;
			lst->next = *head;
			*head = lst;
		}
		else if (count < N)
		{
			printf("N bolshe kolichestva chisel v spiske\n");
		}
		else
		{
			N--;
			u = N;
			u--;
			while (N != 0)
			{
				next = next->next;
				N--;
			}
			while (u != 0)
			{
				pred = pred->next;
				u--;
			}
			list* lst = (list*)malloc(sizeof(list));
			lst->value = a;
			lst->next = next;
			pred->next = lst;
		}
	}

}
list* g_last(list** head)
{
	list* lst = *head;
	while (lst->next)
	{
		lst= lst->next;
	}
	return (lst);
}
