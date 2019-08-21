#include <unistd.h>
#include <stdlib.h>

#define SIZE 2096

static void	pc(unsigned char c)
{
	write(1, &c, 1);
}

static void	zero_this_mofo(unsigned char *arr, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
		arr[i++] = 0;
}

int		main(int ac, char *av[])
{
	unsigned char		mem[SIZE + 1];
	unsigned char		*ptr;
	int					check;

	zero_this_mofo(mem, SIZE + 1);
	ptr = mem;
	av++;
	check = 0;
	if (ac == 2)
	{
		while (**av)
		{
			if (**av == '.')
				pc(*ptr);
			else if (**av == '+')
				*ptr += 1;
			else if (**av == '-')
				*ptr -= 1;
			else if (**av == '>')
				ptr++;
			else if (**av == '<')
				ptr--;
			else if (**av == '[' && *ptr == 0)
			{
				check++;
				while (check)
				{
					(*av)++;
					if (**av == '[')
						check++;
					else if (**av == ']')
						check--;
				}
			}
			else if (**av == ']' && *ptr != 0)
			{
				check++;
				while (check)
				{
					(*av)--;
					if (**av == ']')
						check++;
					else if (**av == '[')
						check--;
				}
			}
			(*av)++;
		}
	}
	else
		pc('\n');
	return (0);
}
