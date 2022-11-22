/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <astachni>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:58:18 by astachni          #+#    #+#             */
/*   Updated: 2022/11/22 23:05:45 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	find_type(const char *str, int *tab, size_t start)
{
	size_t	index_str;
	size_t	index_tab;

	if (!str)
		return (-1);
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
	return (-2);
}

int	type_in_char(const char c, int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (c == (const int)tab[i])
			return (-1);
		i++;
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
	return (tab);
}
