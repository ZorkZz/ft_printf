#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'k';
	char	d = 'x';
	void	*p = malloc(9);
	char	*a = "fe";

	//printf("valeur de retour la mienne: %d\n", ft_printf("%s\n"));
	//printf("valeur de retour la vrai: %d\n", printf("%s\n"));
	printf("vrai fonction retourne: %d\n", printf("%d\n", -10));
	printf("ma fonction retourne: %d\n", ft_printf("%d\n", -10));
	free(p);
}