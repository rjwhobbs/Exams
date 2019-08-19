#include "t_point.h"

void	filler(char c, char **tab, t_point size, int y, int x)
{
	if (tab[y][x] == c && tab[y][x] != 'F')
	{
		tab[y][x] = 'F';
		if (x < (size.x - 1))
			filler(c, tab, size, y, x + 1);
		if (x > 0)
			filler(c, tab, size, y, x - 1);
		if (y < (size.y - 1))
			filler(c, tab, size, y + 1, x);
		if (y > 0)
			filler(c, tab, size, y - 1, x);
	}
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;

	if (begin.y >= 0 && begin.y < size.y && begin.x >= 0 && begin.x < size.x)
	{
		c = tab[begin.y][begin.x];
		filler(c, tab, size, begin.y, begin.x);
	}
}
