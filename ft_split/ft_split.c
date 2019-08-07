#include <stdlib.h>
#include <stdio.h>

static int	is_whtsp(char s)
{
	if ((s >= '\t' && s <= '\r') || s == ' ')
		return (1);
	else 
		return (0);
}

static int	word_count(char *str)
{
	int len;
	
	len = 0;
	while (*str)
	{
		while (is_whtsp(*str) && *str)
			str++;
		if (!(is_whtsp(*str)) && *str)
			len++;
		while (!(is_whtsp(*str)) && *str)
			str++;
	}
	return (len);
}

static int	word_len(char *str)
{
	int len;

	len = 0;
	while (*str && !(is_whtsp(*str)))
	{
		str++;
		len++;
	}
	return (len);
}

static void	cpy(char *arr, char *s2, size_t n)
{
	arr[n] = 0;
	while (n--)
		*arr++ = *s2++;
}

char    **ft_split(char *str)
{
	char **arr;
	int words;
	int wlen;
	char **arr_position;

	if (!(words = word_count(str)))
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	arr_position = arr;
	arr[words] = NULL;
	while (words--)
	{
		while (is_whtsp(*str))
			str++;
		if (!(is_whtsp(*str)) && *str)
		{
			wlen = word_len(str);
			*arr = (char*)malloc(sizeof(char) * (wlen + 1));
			cpy(*arr++, str, wlen);
			str += wlen;
		}
	}
	return (arr_position);
}
