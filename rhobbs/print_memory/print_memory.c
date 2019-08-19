#include <unistd.h>

void	pc(unsigned char c)
{
	write(1, &c, 1);
}

void	ps(char *s)
{
	if (s)
		while(*s)
			write(1, s++, 1);
}

static void	pch(unsigned char c)
{
	char	s[3];
	char	sym[] = "0123456789abcdef";
	int		i;

	i = 2;
	while(i--)
	{
		s[i] = sym[c % 16];
		c /= 16;
	}
	ps(s);
}

void	print_memory(const void *addr, size_t size)
{
	size_t 			temp;
	size_t 			i;
	unsigned char 	*p;
	size_t			k;
	int				x;

	p = (unsigned char*)addr;
	temp = size;
	i = 0;
	while (i < temp)
	{
		if (i != 0 && (i % 2 == 0))
			pc(' ');
		pch(p[i]);
		i++;
		if (i == 16)
		{	
			pc(' ');
			k = 0;
			while (k < 16)
			{
				if (*p > 31 && *p < 127)
					pc(*p);
				else
					pc('.');
				k++;
				p++;
			}
			pc('\n');
			if (temp > 16)
			{
				temp -= 16;
				i = 0;
			}
		}
		else if (i == temp)
		{
			pc(' ');
			x = 16 - temp;
			x = (x * 2) + (x / 2);
			while (x)
			{
				pc(' ');
				x--;
			}
			k = 0;
			while (k < temp)
			{
				if (*p > 31 && *p < 127)
					pc(*p);
				else
					pc('.');
				k++;
				p++;
			}
			pc('\n');
		}
	}
}
