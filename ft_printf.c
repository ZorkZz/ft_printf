/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:41:41 by astachni@st       #+#    #+#             */
/*   Updated: 2022/11/27 20:43:51 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	verify_char(const char c)
{
	if (c == 's' || c == 'c' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || \
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		len_str;

	len_str = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[len_str])
	{
		if (verify_char(str[len_str + 1]) == 0 && str[len_str] == '%')
			len_str++;
		else if (str[len_str] != '%')
			count += write(1, &str[len_str], 1);
		else if (str[len_str] == '%')
			count += print_type(str[++len_str], args);
		len_str++;
		if (count == -1)
			return (-1);
	}
	va_end(args);
	return (count);
}
