/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:10:58 by astachni          #+#    #+#             */
/*   Updated: 2022/11/22 07:55:07 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_str(const char *str, int i, int *tab)
{
	if (!str)
		return (-1);
	while (str[i] && (str[i] != '%' || type_in_char(str[i], tab) == 0))
		write (1, &str[i++], 1);
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s;
	int		*type_tab;
	int		type_index;
	int		i;
	//int		j;

	if (!str)
		return (-1);
	i = 0;
	s = (char *)str;
	//j = 0;
	type_tab = NULL;
	type_tab = type_tab_create(type_tab);
	type_index = find_type(str, type_tab, 0);
	va_start(args, str);
	while (s[i])
	{
		i = print_str(s, i, type_tab);
		if (i == -1)
		{
			free (type_tab);
			va_end(args);
			return (0);
		}
		if (type_tab[type_index] == 's')
		{
			*str++;
			char *s = va_arg(args, char*);
			ft_putstr_fd((char *)s,1);
			i+=2;
		}
	}
	free (type_tab);
	va_end(args);
	return (0);
}
