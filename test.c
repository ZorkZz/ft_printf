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
	printf("vrai fonction retourne: %d\n", printf("%u%d%s\n", 1, 2, NULL));
	printf("vrai fonction retourne: %d\n", ft_printf("%u%d%s\n", 1, 2, NULL));
	free(p);
}
