#include <stdio.h>
#include "t_point.h"
#include <stdlib.h>
#include "../libft/libft.h"
//void  flood_fill(char **tab, t_point size, t_point begin);

char	**make_area(char **tab, t_point size)
{
	char **arr;
	char **arr_position;
	int i;

	i = 0;
	arr = (char**)malloc(sizeof(char*) * (size.y + 1));
	arr[size.y] = NULL;
	arr_position = arr;
	while (size.y--)
	{
		i = 0;
		*arr = (char*)malloc(sizeof(char) * (size.x + 1));
		(*arr)[size.x] = 0;
		printf("XXX\n");
		while (*tab[i])
		{
			(*arr)[i] = (*tab)[i];
			i++;
		}
		arr++;
		tab++;
	}
	return (arr_position);
}

void	print_tab(char **tab)
{
	while (*tab)
	{
		printf("%s\n", *tab);
		tab++;
	}
}

int main(int ac, char *av[])
{
	t_point size = {8, 5};
	char **area;

	char *zone[] = 
	{
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	area = make_area(zone, size);
	print_tab(area);
	
	return (0);
}
