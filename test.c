#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'k';
	char	d = 'x';
	void	*p = malloc(9);
	char	*a = "fe";

	printf("valeur de retour la mienne: %d\n", ft_printf("%s%%%%%%%%%%%%%%%%%p\n", a, p));
	printf("valeur de retour vrai: %d\n", ft_printf("%s%%%%%%%%%%%%%%%%%p\n", a, p));
	free(p);
}
