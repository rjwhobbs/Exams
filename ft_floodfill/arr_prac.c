#include <stdio.h>
#include "t_point.h"
#include <stdlib.h>
#include <string.h>

char	**area_maker(char **tab, t_point size)
{
	char **area;
	char **a_position;

	area = (char**)malloc(sizeof(char*) * (size.y + 1));
	a_position = area;
	area[size.y] = NULL;
	while (*tab)
		*area++ = *tab++;
	return (a_position);
}
void	filler(char c, char **tab, t_point size, int x, int y)
{
	if (tab[y - 1][x - 1] == c)
	{
		tab[y - 1][x - 1] = 'F';
		if (x > 1)
			filler(c, tab, size, x - 1, y);
		if (x < size.x)
			filler(c, tab, size, x + 1, y);
		if (y > 1)
			filler(c, tab, size, x, y - 1);
		if (y < size.y)
			filler(c, tab, size, x, y + 1);
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;

	if (begin.y > 0 && begin.x > 0 && begin.y <= size.y && begin.x <= size.x)
	{
		c = tab[begin.y - 1][begin.x - 1];
		filler(c, tab, size, begin.x, begin.y);
	}
}

int	main(int ac, char *av[])
{
	char 		**area;
	t_point		size;
	t_point		begin;
	int 		i;

	av++;
	size.x = atoi(*av);
	av++;
	size.y = atoi(*av);
	av++;
	begin.x = atoi(*av);
	av++;
	begin.y = atoi(*av);
	av++;
	area = area_maker(av, size);
	printf("Before fill:\n");
	i = ac;
	i = 0;
	while (area[i])
		printf("%s\n", area[i++]);
	i = 0;
	printf("After fill:\n");
	flood_fill(area, size, begin);
	while (area[i])
		printf("%s\n", area[i++]);
	return (0);
}
