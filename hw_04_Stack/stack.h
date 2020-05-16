#ifndef STACK_H
#define STACK_H

typedef struct stack {
	char value;
	struct stack* next;
}stack;

push(struct stack** head, const char str);
char pop(struct stack** head);
empty(struct stack** head);

#endif