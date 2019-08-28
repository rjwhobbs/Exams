#include <unistd.h>

static void	rev(char *s)
{
	int i;
	char t;

	i = 0;
	while(i < 16)
	{
		t = s[31 - i];
		s[31 - i] = s[i];
		s[i] = t;
		i++;
	}
}

static void ps(char *s)
{
	if (s)
		while (*s)
			write(1, s++, 1);
}

static void pb(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (i == 8 || i == 17 || i == 26 || i == 35)
			write (1, " ", 1);
		else
			write(1, s++, 1);
		i++;
	}
}

static int isop(char o)
{
	if (o >= 97 && o <= 122)
		return (1);
	else
		return (0);
}

int		main(int ac, char **av)
{
	char bits[] = "00000000000000000000000000000000";
	char inv[] = "Invalid Option";
	char ops[] = "options: abcdefghijklmnopqrstuvwxyz";

	if (ac > 1)
	{
		av++;
		while (*av)
		{
			if (**av == '-' && (*av)[1])
			{
				(*av)++;
				while (**av)
				{
					if (**av == 'h')
					{
						ps(ops);
						ps("\n");
						return (0);
					}
					if (isop(**av))
						bits[**av - 97] = '1';
					else if (!(isop(**av)))
					{
						ps(inv);
						ps("\n");
						return (0);
					}
					(*av)++;
				}
			}
			else
			{
				ps(inv);
				ps("\n");
				return (0);
			}
			if (!**av)
				av++;
		}
		rev(bits);
		pb(bits);
		ps("\n");
		return (0);
	}
	else
	{
		ps(ops);
		ps("\n");
	}
	return (0);
}

