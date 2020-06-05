#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tree.h"

int main()
{
	struct node* root = NULL;
	int menu = -1, value, i;
	while (menu != 0)
	{
		printf("1 - dobavte \n");
		printf("2 - shirina \n");
		printf("3 - glubina \n");
		printf("4 - poisk \n");
		printf("5 - summa\n");
		printf("0 - Exit \n");
		printf("vvedite: ");
		scanf("%d", &menu);
		if (menu == 1)
		{
			printf("your number: ");
			scanf("%d", &value);
			add(&root, value);
		}
		else if (menu == 2)
		{
			BFS(root);
		}
		else if (menu == 3)
		{
			DFS(root);
			printf("\n");
		}
		else if (menu == 4)
		{
			printf("your number: ");
			scanf("%d", &value);
			len(root, value);
		}
		else if (menu == 5)
		{
			summa(root);
		}
		else if (menu == 0)
		{
			printf("\n");
		}
		else
		{
			printf("Wrong number\n");
		}
	}
	while (getchar() != '\n');
	getchar();
}