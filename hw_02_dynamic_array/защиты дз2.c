#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* q = NULL;
	int* e = NULL;
	int i, j = 0, a, b, n, counter = 0;
	printf("Enter number: \n");
	scanf("%d", &n);
	printf("vvedite a: \n");
	scanf("%d", &a);
	printf("vvedite b: \n"); 
	scanf("%d", &b);
	q = (int*)malloc(n * sizeof(int));
	e = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &q[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (((*(q+i))>=a) && ((*(q+i))<=b))
		{
			*(e + j) = *(q + i);
			j++;
			counter++;
		}

	}
	e = (int*)realloc(e, counter * sizeof(int));
	for (j = 0; j < counter; j++)
	{
		printf("%d ", *(e + j));
	}
	return 0;
}