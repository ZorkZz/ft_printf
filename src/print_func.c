/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:47:22 by astachni@st       #+#    #+#             */
/*   Updated: 2022/11/24 17:35:08 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_type(char c, const char *str, ...)
{
	va_list	args;
	int		p;

	p = 0;
	va_start(args, str);
	if (c == 's')
		return (ft_putstr_fd((char *)va_arg(args, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	else if (c == 'p' || c == 'x')
	{
		if (c == 'p')
			p = ft_putstr_fd("0x", 1);
		return (p + ft_putnbr_base((int)va_arg(args, int), "0123456789abcdef"));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd((int)va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putnbr_fd((unsigned int)va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_putnbr_base((int)va_arg(args, int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}