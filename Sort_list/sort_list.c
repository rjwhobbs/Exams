#include "list.h"

t_list  *sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list 	*start;
	int		temp;

	start = lst;
	while (start->next)
	{
		if (!(cmp(start->data, start->next->data)))
		{
			temp = start->next->data;
			start->next->data = start->data;
			start->data = temp;
			start = lst;
		}
		else
			start = start->next;
	}
	return (lst);
}
