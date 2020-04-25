#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	int* a = NULL;
	int* b = NULL;
	int* buf = NULL;
	int n, m, k, k1, i, j, count = 0, layer = 0, sch = 0, c = 0;
	printf("vvedite razmer matricu: ");
	scanf("%d %d", &n, &m);
	printf("vvedite kolichestvo chisel, dlya zapolneniya: ");
	scanf("%d", &k);

	a = (int*)malloc(n * m * sizeof(int));
	b = (int*)malloc(k * sizeof(int));
	if (a == NULL)
		return 1;
	if (b == NULL)
		return 1;

	printf("chisla v zapolnenii: ");
	for (i = 0; i < k; i++)
		scanf("%d", &b[i]);

	buf = (int*)realloc(b, n * m * sizeof(int));
	if (buf == NULL)
	{
		free(b);
		return 1;
	}
	b = buf;
	k1 = k;
	k = n * m;
	if (n * m > k1)
		for (i = k1; i < k; i++)
		{
			if (sch < k1 - 1)
			{
				b[i] = b[i - 1] - 1;
				sch++;
			}
			else
			{
				b[i] = b[i - 1] + 1;
				sch++;
			}
			if (sch == 2 * k1 - 2)
				sch = 0;
		}
	while (count < k)
	{
		if (count >= k) break;
		for (i = layer; i < m - layer; i++)
		{
			*(a + layer * m + i) = b[count];
			count++;
		}
		if (count >= k) break;
		for (i = layer + 1; i < n - layer; i++)
		{
			*(a + i * m + m - layer - 1) = b[count];
			count++;
		}
		if (count >= k) break;
		for (i = m - layer - 1; i > layer; i--)
		{
			*(a + (n - layer - 1) * m + i - 1) = b[count];
			count++;
		}
		if (count >= k) break;
		for (i = n - layer - 2; i > layer; i--)
		{
			*(a + i * m + layer) = b[count];
			count++;
		}
		layer++;
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d ", *(a + i * m + j));
		printf("\n");
	}
	free(a);
	free(b);
	while (getchar() != '\n');
	getchar();

}