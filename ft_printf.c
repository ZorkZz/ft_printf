/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <astachni>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:10:58 by astachni          #+#    #+#             */
/*   Updated: 2022/11/22 23:25:53 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_str(const char *str, int i, int *tab)
{
	if (!str)
		return (-1);
	while (str[i] && (str[i] != '%' || type_in_char(str[i], tab) == 0))
		write (1, &str[i++], 1);
	if (str[i] == '\0')
		return (-1);
	return (i);
}

static int	print_var(int i, char letter, char *str, ...)
{
	va_list	args;

	va_start(args, str);
	(void)str;
	if (letter == 's')
		ft_putstr_fd ((char *)va_arg (args, char *), 1);
	else if (letter == 'c')
		ft_putchar_fd((char)va_arg (args, int), 1);
	else if (letter == 'd' || letter == 'i')
		ft_putnbr_fd((int)va_arg (args, int), 1);
	else if (letter == 'u')
		ft_putnbr_fd((unsigned int)va_arg (args, unsigned int), 1);
	else if (letter == 'p')
	{
		write (1, "0x", 2);
		ft_putnbr_base ((int)va_arg(args, int), "0123456789abcdef");
	}
	else if (letter == 'x')
		ft_putnbr_base((int)va_arg(args, int), "0123456789abcdef");
	else if (letter == 'X')
		ft_putnbr_base((int)va_arg(args, int), "0123456789ABCDEF");
	else if (letter == '%')
		ft_putchar_fd('%', 1);
	va_end(args);
	return (i += 2);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s;
	int		*type_tab;
	int		type_index;
	int		i;

	if (!str)
		return (-1);
	i = 0;
	s = (char *)str;
	type_tab = NULL;
	type_tab = type_tab_create(type_tab);
	type_index = find_type(str, type_tab, 0);
	va_start(args, str);
	while (s[i])
	{
		type_index = find_type(str, type_tab, i);
		i = print_str(s, i, type_tab);
		if (i == -1)
			break ;
		i = print_var (i, type_tab[type_index], s, va_arg (args, char *));
	}
	free (type_tab);
	va_end(args);
	return (i >= 0);
}
