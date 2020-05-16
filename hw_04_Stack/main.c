#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <string.h>
proverka(const char* str)
{
	struct stack* l = NULL;
	struct stack* head = NULL;
	int len, i;
	len = strlen(str);

	if (str[0] == '(')
		push(&l, str[0]);
	else if (str[0] == ')')
		return 0;
	if (str[0] == '{')
		push(&l, str[0]);
	else if (str[0] == '}')
		return 0;
	if (str[0] == '[')
		push(&l, str[0]);
	else if (str[0] == ']')
		return 0;
	for (i = 1; i < len; i++)
	{
		if (str[i] == '(')
			push(&l, str[i]);
		else if (str[i] == ')')
		{
			if (empty(&l))
				return 0;
			else
			{
				if (l->value == '(')
					pop(&l);
				else return 0;
			}
		}
		if (str[i] == '[')
			push(&l, str[i]);
		else if (str[i] == ']')
		{
			if (empty(&l))
				return 0;
			else
			{
				if (l->value == '[')
					pop(&l);
				else return 0;
			}
		}
		if (str[i] == '{')
			push(&l, str[i]);
		else if (str[i] == '}')
		{
			if (empty(&l))
				return 0;
			else
			{
				if (l->value == '{')
					pop(&l);
				else return 0;
			}
		}
	}

	if (empty(&l))
		return 1;
	else return 0;
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
		if (result)
			puts("good");
		else puts("bad");
	}

	while (getchar() != '\n');
}