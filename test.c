#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'k';
	char	d = 'x';
	void	*p = malloc(9);
	char	*a = "fe";

	//printf("valeur de retour la mienne: %d\n", ft_printf("%s\n"));
	//printf("valeur de retour la vrai: %d\n", printf("%s\n"));
	printf("vrai fonction retourne: %d\n", printf("%p\n", p));
	printf("ma fonction retourne: %d\n", ft_printf("%p\n", p));
	free(p);
}
