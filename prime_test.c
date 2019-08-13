#include "../libft/libft.h"

int ft_isprime(int n)
{
    long int i;
    long int w;

    if (n == 2)
        return (1);
    if (n == 3)
        return (1);
    if ((n % 2) == 0)
        return (0);
    if ((n % 3) == 0)
        return (0);

	i = 5;
	w = 2;

    while ((i * i) <= n)
	{ 
        if ((n % i) == 0)
            return (0);
		i += w;
        w = 6 - w;
	}
    return (1);
}

int main(int ac, char **av)
{
	int i;

	i = ft_atoi(av[1]);
	if (ft_isprime(i))
		ft_putendl("is prime");
	else
		ft_putendl("is not prime");
	return (0);
}