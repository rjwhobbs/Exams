#include "../libft/libft.h"
#include <stdio.h>

int		ft_list_size(t_list *begin_list)
{
	t_list	*temp;
	int		len;

	len = 0;
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

int	main(int ac, char *av[])
{
	t_list	*list;
	t_list	*begin;
	t_list 	*start_position;
	int		x;
	int 	len;

	x = 0;
	len = 0;
	begin = NULL;
	while (x < 109000999)
	{
		list = ft_lstnew(&x, 4);
		ft_lstadd(&begin, list);
		x++;
	}
	//start_position = begin;
	/*while (begin)
	{
		ft_putnbr(*(int*)begin->content);
		ft_nl();
		begin = begin->next;
	}*/
	//begin = start_position;
	ft_putstr("List size: ");
	ft_putnbr(ft_list_size(begin));
	ft_nl();
	
	/*while (begin)
	{
		ft_putnbr(*(int*)begin->content);
		ft_nl();
		begin = begin->next;
	}*/

	return (0);
}

