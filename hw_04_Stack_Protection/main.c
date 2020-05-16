#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <string.h>
proverka(const char* str)
{
	struct stack* l = NULL;
	struct stack* head = NULL;
	int len, i, counter=0, counter1;
	len = strlen(str);

	if (str[0] == '(')
		push(&l, str[0]);
	else if (str[0] == ')')
	counter++;
	for (i = 1; i < len; i++)
	{
		if (str[i] == '(')
			push(&l, str[i]);
		else if (str[i] == ')')
		{
			if (empty(&l))
				counter++;
			else
			{
				if (l->value == '(')
					pop(&l);
				else counter++;
			}
		}
	}

	if (empty(&l))
		return (counter);
	else
	{
		counter1 = count(&l);
		counter = counter + counter1;
	}
	return (counter);
}
int main()
{
	char str[50];
	int result;

	while (1)
	{
		printf("vvedite strok:");
		gets_s(str, 50);
		result = proverka(str);
		printf("%d\n", result);
	}

	while (getchar() != '\n');
}