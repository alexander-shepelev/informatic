#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>
int main()
{
	double* M = NULL;
	int* buf = NULL;
	int n, m;
	int p;
	int i = 0, imin = 0, imax = 0, j = 0, k = 0;
	double a = 0, b = 0;

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
		if (M[i] == a)
			imin = i;
		if (M[i] == b)
			imax = i;
	}

	for (i = imin; i <= imax; i++)
	{
		printf("%lf ", M[i]);
	}

	while (getchar() != '\n');
	getchar();


	free(M);

	return 0;
}