/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:10:58 by astachni          #+#    #+#             */
/*   Updated: 2022/11/21 22:21:41 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	//char	*n;
	int		*type_tab;
	int		type_index;

	if (!str)
		return (-1);
	type_tab = NULL;
	type_tab = type_tab_create(type_tab);
	type_index = find_type(str, type_tab, 0);
	va_start(args, str);
	//n = va_arg(args, char *);
	choose_type(type_tab, type_index, args);
	return (0);
}
