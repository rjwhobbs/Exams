#include <unistd.h>
#include <stdio.h>

static int		iswhtsp(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else 
		return (0);
}

static int		ft_strlen(char *s)
{
	int len;

	len = 0;
	if (s)
		while (*s++)
			len++;
	return (len);
}

void	ft_putstr(char const *s)
{
	if (s)
		while (*s && !(iswhtsp(*s)))
			write(1, s++, 1);
}

void	space(void)
{
	write(1, " ", 1);
}

void	rev(char *s)
{
	int 	len;
	char	*p;
	int		i;
	int		wlen;

	len = ft_strlen(s);
	if (len == 0)
		return ;
	p = s + len;
	wlen = 1;
	i = 1;
	while (i)
	{
		i = 0;
		if (iswhtsp(*p) || !*p)
			p--;
		while (&s[i] != p)
			i++;
		if (i > 0)
		{
			wlen = i;
			while (!(iswhtsp(*p)) && wlen)
			{
				p--;
				wlen--;
			}
		}
		if (iswhtsp(*p))
		{
			ft_putstr(p + 1);
			space();
		}
		else
		{
			ft_putstr(p);
			break;
		}
	}
}


int		main(int ac, char *av[])
{
	if (ac == 2)
		rev(av[1]);
	write(1, "\n", 1);
	return (0);
}
