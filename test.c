#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'k';
	char	d = 'x';
	void	*p = malloc(9);
	printf ("%d", printf("vrai fonction %c\n"));
	ft_printf("ma fonction %c\n", d);
	free(p);
}
