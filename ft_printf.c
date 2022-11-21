/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:10:58 by astachni          #+#    #+#             */
/*   Updated: 2022/11/22 00:22:10 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_str(const char *str, int i, int *tab)
{
	if (!str)
		return (-1);
	while (str[i] && str[i] != '%' && type_in_char(str[i], tab) == 0)
		write (1, &str[i++], 1);
	return (i + 2);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		*type_tab;
	int		type_index;
	int		i;
	int		j;

	if (!str)
		return (-1);
	i = 0;
	j = 0;
	type_tab = NULL;
	type_tab = type_tab_create(type_tab);
	type_index = find_type(str, type_tab, 0);
	va_start(args, str);
	while (str[i])
	{
		i = print_str(str, i, type_tab);
		if (choose_type(type_tab, type_index, args, str, j) == 0)
			j++;
	}
	return (0);
}
