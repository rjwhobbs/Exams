/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmamalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 08:46:10 by mmamalek          #+#    #+#             */
/*   Updated: 2019/08/06 11:53:11 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_bzero(char *mem, int len)
{
	while (len-- > 0)
		*mem++ = 0;
}

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	char	bytes[2048];
	char	*stack[2048];
	char	*bptr;
	char	*avptr;
	int		top;

	bptr = bytes;
	avptr = av[1];
	top = 0;
	ft_bzero(bytes, 2048);
	if (ac > 1)
	{
		while (*avptr)
		{
			if (*avptr == '>')
				bptr++;
			else if (*avptr == '<')
			{
				if (bptr > bytes)
					bptr--;
			}
			else if (*avptr == '+')
				(*bptr)++;
			else if (*avptr == '-')
				(*bptr)--;
			else if (*avptr == '.')
				write(1, bptr, 1);
			else if (*avptr == '[')
			{
				stack[top] = avptr;
				top++;
			}
			else if (*avptr == ']' && *bptr != 0)
				avptr = stack[top - 1];
			else if (*avptr == ']' && *bptr == 0)
				top--;
			avptr++;
		}
	}
	printf("%d\n", *bptr);
	write(1, "\n", 1);
	return (0);
}
