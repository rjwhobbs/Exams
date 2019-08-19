#include <unistd.h>
#include <stdio.h>

void	print_memory(const void *addr, size_t size);

int		main(void)
{
	char c;

	c = 'c';
	print_memory(&c, 100000);
	return (0);
}
