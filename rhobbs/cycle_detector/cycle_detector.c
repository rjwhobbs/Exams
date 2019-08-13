#include "list.h"
#include <stdlib.h>

int        cycle_detector(const t_list *list)
{
	int i;
	int k;
	const t_list	*start;
	t_list	*a;
	t_list	*b;

	if (list == NULL)
		return (0);
	if (list->next == NULL)
		return (0);
	start = list;
	a = (t_list*)start;
	b = (t_list*)start;
	i = 0;
	k = 0;
	while (a)
	{
		b = (t_list*)start;
		if (a->next != b)
			i++;
		if (i)
		{
			if (a->next == NULL)
				return (0);
			a = a->next;
			k = i;
			while (k--)
			{
				if (a->next == NULL)
					return (0);
				else if (a->next == b)
					return (1);
				if (b->next == NULL)
					return (0);
				b = b->next;
			}
		}
	}
	return (0);
}
