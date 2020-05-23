#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

srednee(const int k)
{
	int i = 0;
	float summa = 0;
	int dlina = 0;
	float value;

	struct queue queue;
	queue.head = NULL;
	queue.tail = NULL;
	struct node* q = NULL;

	scanf("%f", &value);

	enq(&queue, value);
	q = queue.head;
	summa = summa + q->data;
	dlina++;
	printf("=>%.2f\n", summa / dlina);
	scanf("%f", &value);
	while (value != -1)
	{
		if (dlina != k)
		{
			enq(&queue, value);
			q = q->next;
			summa = summa + q->data;
			dlina++;
			printf("=>%.2f\n", summa / dlina);
		}
		else
		{
			q = queue.head;
			summa = summa - q->data;
			deq(&queue);
			enq(&queue, value);
			q = queue.tail;
			summa = summa - q->data;
			printf("=>%.2f\n", summa / dlina);
		}
		scanf("%f", &value);
	}
	printf("\n");
}

int main()
{
	int k;
	printf("k:");
	scanf("%d", &k);

	srednee(k);

	while (getchar() != '\n');
}