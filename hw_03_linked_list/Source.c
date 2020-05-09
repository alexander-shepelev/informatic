#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "LINKEDLIST.h"
#include <stdlib.h>
int main()
{
	int a, menu = -1;
	list* lst = NULL;
	printf("Enter first number: ");
	scanf("%d", &a);
	create_head(&lst, a);
	while (menu != 0)
	{
		printf("1 - list\n");
		printf("2 - add first\n");
		printf("3 - add last\n");
		printf("4 - add N\n");
		printf("5 - del first\n");
		printf("6 - del last\n");
		printf("7 - del N\n");
		printf("0 - Exit\n");
		scanf("%d", &menu);
		if (menu == 1)
		{
			if (lst == NULL)
				printf("Empty\n");
			else
			{
				printf("num list: ");
				print(&lst);
				printf("\n");
			}
		}
		else if (menu == 2)
		{
			int b;
			printf("vvedite nomer: ");
			scanf("%d", &b);
			add_first(&lst, b);
			printf("dobavleno\n");
		}
		else if (menu == 3)
		{
			int c;
			printf("vvedite nomer: ");
			scanf("%d", &c);
			add_last(&lst, c);
			printf("dobavleno\n");
		}
		else if (menu == 4)
		{
			int d, N;
			printf("vvedite nomer positions: ");
			scanf("%d %d", &N, &d);
			add_N(&lst, N, d);
			printf("dobavleno\n");
		}
		else if (menu == 5)
		{
			del_f(&lst);
			printf("delete\n");
		}
		else if (menu == 6)
		{
			del_la(&lst);
			printf("delete\n");
		}
		else if (menu == 7)
		{
			int N;
			printf("vvedite nomer positions: ");
			scanf("%d", &N);
			del_N(&lst, N, a);
			printf("udaleno\n");
		}
	else if (menu == 0)
		{
			printf("\n");
		}
		else
		{
			printf("Wrong nomera\n");
		}
	}
	printf("stop\n");
	return 0;
}