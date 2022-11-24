/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:41:41 by astachni@st       #+#    #+#             */
/*   Updated: 2022/11/24 17:35:00 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		len_str;

	len_str = 0;
	count = 0;
	va_start(args, str);
	if (!write(0, " ", 0))
		return (-1);
	while (str[len_str])
	{
		if (str[len_str] != '%')
			count += write(1, &str[len_str], 1);
		else if (str[len_str] == '%')
			count += print_type(str[++len_str], str, va_arg(args, char *));
		len_str++;
	}
	return (count);
}
