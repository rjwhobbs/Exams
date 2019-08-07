#include <stdio.h>
#include <stdlib.h>

char    **ft_split(char *str);

/*static int	is_whtsp(char s)
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
}*/

int	main(int ac, char *av[])
{
	char **str;
	if (ac == 2)
	{
		str = ft_split("      \v\v\v\f\v\v can        you\n print     \n\n\r\t this \t\t ergoiergoiergoijergoiergoienrgoienrgoienrgoin");
		while (*str)
			printf("%s\n", *str++);
	}
	else
		printf("Wrong input");
	return (0);
}
