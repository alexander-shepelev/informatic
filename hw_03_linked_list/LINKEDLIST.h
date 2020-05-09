#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
struct list
{
	int value;
	struct list* next;
};
typedef struct list list;
print(list** head);
create_head(list** head, int a);
add_first(list** head, int a);
add_last(list** head, int a);
add_N(list** head, int N, int a);
del_f(list** head);
del_la(list** head);
del_N(list** head, int N, int a);
list* g_last(list** head);
#endif