/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:58:18 by astachni          #+#    #+#             */
/*   Updated: 2022/11/21 21:45:00 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	find_type(const char *str, int *tab, size_t start)
{
	size_t	index_str;
	size_t	index_tab;

	index_str = start;
	while (str[index_str])
	{
		index_tab = 0;
		while (tab[index_tab])
		{
			if ((const char)tab[index_tab] == str[index_str] && \
				str[index_str - 1] == '%')
				return (index_tab);
			index_tab++;
		}
		index_str++;
	}
	return (0);
}

int	*type_tab_create(int *tab)
{
	tab = malloc(9 * sizeof(int));
	if (!tab)
		return (0);
	tab[0] = 'c';
	tab[1] = 's';
	tab[2] = 'p';
	tab[3] = 'd';
	tab[4] = 'i';
	tab[5] = 'u';
	tab[6] = 'x';
	tab[7] = 'X';
	tab[8] = '%';
	return(tab);
}
