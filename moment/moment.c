#include <stdlib.h>

void	zero_this_mofo(char *s, unsigned int n)
{
	while (n--)
		s[n] = 0;
}

int		num_len(unsigned int n)
{
	int i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

void	numbers(unsigned int n, char *s, unsigned int index)
{
	unsigned int	i;

	i = index - 1;
	if (n > 9)
	{
		numbers(n / 10, s, i);
		numbers(n % 10, s, i + 1);
	}
	else
		s[i] = n + '0';
}

void	str_maker(char *s1, unsigned int index, char *s2, char *s3)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[i])
	{
		s1[i + index] = s2[i];
		i++;
	}
	while (s3[j])
	{
		s1[i + index] = s3[j++];
		i++;
	}
}

char    *moment(unsigned int duration)
{
	char	*str;
	char	sec[] = " second";
	char 	min[] = " minute";
	char	hour[] = " hour";
	char 	day[] = " day";
	char 	mon[] = " month";
	char 	ago[] = " ago.";
	char 	s_ago[] = "s ago.";
	int 	nlen;

	str = (char*)malloc(sizeof(char) * 20);
	zero_this_mofo(str, 20);
	if (duration >= 0 && duration <= 59)
	{
		nlen = num_len(duration);
		numbers(duration, str, nlen);
		if (duration == 1)
			str_maker(str, nlen, sec, ago);
		else
			str_maker(str, nlen, sec, s_ago);
	}
	else if (duration >= 60 && duration <= 3599)
	{
		nlen = num_len(duration / 60);
		numbers(duration / 60, str, nlen);
		if (duration / 60 == 1)
			str_maker(str, nlen, min, ago);
		else
			str_maker(str, nlen, min, s_ago);
	}
	else if (duration >= 3600 && duration <= 86399)
	{
		nlen = num_len(duration / 3600);
		numbers(duration / 3600, str, nlen);
		if (duration / 3600 == 1)
			str_maker(str, nlen, hour, ago);
		else
			str_maker(str, nlen, hour, s_ago);
	}
	else if (duration >= 86400 && duration <= 2591999)
	{
		nlen = num_len(duration / 86400);
		numbers(duration / 86400, str, nlen);
		if (duration / 86400 == 1)
			str_maker(str, nlen, day, ago);
		else
			str_maker(str, nlen, day, s_ago);
	}
	else if (duration >= 2592000)
	{
		nlen = num_len(duration / 2592000);
		numbers(duration / 2592000, str, nlen);
		if (duration / 2592000 == 1)
			str_maker(str, nlen, mon, ago);
		else
			str_maker(str, nlen, mon, s_ago);
	}
	return (str);
}
