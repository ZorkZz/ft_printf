/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:47:22 by astachni@st       #+#    #+#             */
/*   Updated: 2022/11/27 21:29:28 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_type(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr_fd((char *)va_arg(args, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd((int)va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunbr_fd((unsigned int)va_arg(args, unsigned int), 1));
	else if (c == 'x')
		return (ft_putnbr_base((int)va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base((int)va_arg(args, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putvoid(va_arg(args, void *), "0123456789abcdef"));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}
