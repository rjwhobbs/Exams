#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(s1);
	i = 0;
	if (!s1 || !(dup = (char*)malloc(sizeof(*dup) * (len + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void		str_filler(int l, int mod, int num, char *str)
{
	if (l >= 0)
	{
		str[l] = mod + '0';
		num /= 10;
		str_filler(--l, num % 10, num, str);
	}
}

static int	len(int n)
{
	int l;

	l = 0;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	l++;
	return (l);
}

char		*ft_itoa(int nbr)
{
	char			*s;
	int				sign;
	int				l;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = nbr;
	if (nbr < 0)
		nbr *= -1;
	l = len(nbr);
	if (sign < 0)
		l += 1;
	if (!(s = (char*)malloc(sizeof(*s) * (l + 1))))
		return (NULL);
	s[l] = '\0';
	str_filler(--l, nbr % 10, nbr, s);
	if (sign < 0)
		s[0] = '-';
	return (s);
}
