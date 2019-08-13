#include <stdio.h>
#include <stdlib.h>

int		isprime(unsigned long int n)
{
	unsigned long int 	i;
	int					w;

	i = 5;
	w = 2;
	if (n == 1)
		return (0);
	if (n == 2)
		return (1);
	if (n == 3)
		return (1);
	if (n % 2 == 0)
		return (0);
	if (n % 3 == 0)
		return (0);

	while ((i * i) <= n)
	{
		if (n % i == 0)
			return (0);
		i = i + w;
		w = 6 - w;
	}
	return (1);
}

int		prime_indexer(int i)
{
	i++;
	while (i)
	{
		if (isprime(i))
			return (i);
		else
			i++;
	}
	return (0);
}

void	fprime(int n)
{
	int i;

	i = 2;
	if (isprime(n))
	{
		printf ("%d\n", n);
		return ;
	}
	while (i < n)
	{
		if (n % i == 0)
		{
			printf("%d*", i);
			n /= i;
		}
		else
			i = prime_indexer(i);
	}
	printf("%d\n", n);
}

int		main(int ac, char *av[])
{
	int n;

	n = 0;
	if (ac == 2)
	{
		n = atoi(av[1]);
		fprime(n);
	}
	else
		printf("\n");
	return (0);
}
