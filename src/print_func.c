/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:47:22 by astachni@st       #+#    #+#             */
/*   Updated: 2022/11/27 23:54:02 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_type(char c, va_list args)
{
	char	*str;
	int		i
	if (c == 's')
		return (ft_putstr_fd((char *)va_arg(args, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	else if (c == 'd' || c == 'i')
	{
		*str = ft_itoa(va_arg(args, int));
		i = ft_putstr_fd(str, 1);
		free(str)
		return (i);
	}
	else if (c == 'u')
	{
		*str = ft_itoa_u(va_arg(args, unsigned int));
		i = ft_putstr_fd(str, 1);
		free(str);
		return (i);
	}
	else if (c == 'x')
	{
		*str = itoa_hex(va_arg(args, int), "0123456789abcdef");
		i = ft_putstr_fd(str, 1);
		free (str);
		return (i);
	}
	else if (c == 'X')
		return (ft_putstr_fd(itoa_hex(va_arg(args, int), "0123456789ABCDEF"), 1));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (ft_putstr_fd(itoa_hex(va_arg(args, int), "0123456789abcdef"), 1) + 2);
	}
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}
