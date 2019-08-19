#include <unistd.h>
#include <stdlib.h>

void	print_memory(const void *addr, size_t size);

int		main(void)
{
	char *c;
	char m;

	c = (char*)malloc(sizeof(char) * 1);
	print_memory(&m, 10000000000);
	return (0);
}
