#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'k';
	char	d = 'x';
	void	*p = malloc(9);
	printf("vrai fonction %c\n", c);
	ft_printf("ma fonction %c\n", c);
	free(p);
}
