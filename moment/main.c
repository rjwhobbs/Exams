#include <stdio.h>
#include <stdlib.h>

char    *moment(unsigned int duration);

int		main(int ac, char *av[])
{
	unsigned int 	x;
	char 			*s;

	if (ac == 2)
	{
		x = atoll(av[1]);
		s = moment(x);
		printf("%s\n", s);
	}
	else 
		printf("Wrong input\n");
	return (0);
}
