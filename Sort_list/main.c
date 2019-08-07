#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_list  *sort_list(t_list* lst, int (*cmp)(int, int));

int ascending(int a, int b)
{
    return (a <= b);
}

int main(int ac, char *av[])
{
	t_list	*list;
	t_list	*start;
	t_list	*start_p;
	int 	i;
	unsigned int x;

	start = NULL;
	i = atoi(av[1]);
	sranddev();
	while (i--)
	{
		list = (t_list*)malloc(sizeof(t_list));
		list->data = rand();
		list->next = start;
		start = list;
	}
	start_p = start;
	printf("Before sort:\n");
	while (start)
	{
		printf("a%d\n", start->data);
		start = start->next;
	}
	printf("XXX\n");
	start = start_p;
	start = sort_list(start, ascending);
	printf("After sort:\n");
	while (start)
	{
		printf("%d\n", start->data);
		start = start->next;
	}
	return (0);
}
