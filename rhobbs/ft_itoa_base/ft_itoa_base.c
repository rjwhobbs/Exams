#include <stdlib.h>

static int	num_len(long int v, int base)
{
	int len;

	len = 0;
	while (v >= base)
	{
		v /= base;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa_base(int value, int base)
{
	char 		sym[] = "0123456789ABCDEF";
	int			l;
	long int	v;
	int			sign;
	char		*str;

	str = NULL;
	if (base < 2 || base > 16)
		return (str);
	v = value;
	sign = 1;
	if (v < 0)
	{
		v *= -1;
		if (base == 10)
			sign = -1;
	}
	l = num_len(v, base);
	if (sign == -1)
		l++;
	str = (char*)malloc(sizeof(char) * (l + 1));
	str[l] = 0;
	l--;
	while (l >= 0)
	{
		str[l] = sym[v % base];
		v /= base;
		if (l == 0 && sign == -1)
			str[l] = '-';
		l--;
	}
	return (str);
}
