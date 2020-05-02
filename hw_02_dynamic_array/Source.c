#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <malloc.h>
int main()
{
	double* M = NULL;
	double a, b, eps = 0.0001;
	int m;
	int i, j, count = 0;

	printf("m=");
	scanf("%d", &m);
	printf("a=");
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);

	M = (double*)malloc(m * sizeof(double));
	for (i = 0; i < m; i++)
	{
		scanf("%lf", &M[i]);
	}
	for (i = 0; i < m; i++)
	{
		if ((*(M + i) >= (a - eps)) && (*(M + i) <= (b + eps)))
		{
			*(M + count) = *(M + i);
			count++;
		}
	}
	M = (double*)realloc(M, count * sizeof(double));
	for (j = 0; j < count; j++)
	{
		printf("%.4lf", *(M + j));
		printf("\n");
	}
	while (getchar() != '\n');
	getchar();

	free(M);

	return 0;
}