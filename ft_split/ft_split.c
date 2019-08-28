#include <stdlib.h>

static int		iswhtsp(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

static int		words(char *s)
{
	int w;

	w = 0;
	if (s)
		while (*s)
		{
			while (iswhtsp(*s) && *s)
				s++;
			if (!(iswhtsp(*s)) && *s)
				w++;
			while (!(iswhtsp(*s)) && *s)
				s++;
		}
	return (w);
}

static int		clen(char *s)
{
	int c;

	c = 0;
	if (s)
		while (*s && !(iswhtsp(*s)))
		{
			s++;
			c++;
		}
	return (c);
}

static void	cpy(char *s1, char *s2, int n)
{
	s1[n] = 0;
	while (n--)
		*s1++ = *s2++;
}

char    **ft_split(char *str)
{
	char **arr;
	char **arr_x;
	int ws;
	int cs;

	ws = words(str);
	if (ws == 0)
	{
		arr = (char**)malloc(sizeof(char*) * 1);
		arr[0] = NULL;
		return (arr);
	}
	arr = (char**)malloc(sizeof(char*) * (ws + 1));
	arr_x = arr;
	arr[ws] = NULL;
	while (ws--)
	{
		while (iswhtsp(*str))
			str++;
		if (!(iswhtsp(*str)) && *str)
		{
			cs = clen(str);
			*arr = (char*)malloc(sizeof(char) * (cs + 1));
			cpy(*arr++, str, cs);
			str += cs;
		}
	}
	*arr = NULL;
	return (arr_x);
}
