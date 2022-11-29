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

static int	print_int(int number)
{
	char	*str;
	int		i;

	str = ft_itoa(number);
	i = ft_putstr_fd(str, 1);
	free(str);
	return (i);
}

static int	print_unsign(unsigned int number)
{
	char	*str;
	int		i;

	str = ft_itoa(number);
	i = ft_putstr_fd(str, 1);
	free(str);
	return (i);
}


static int	print_hexa(int number, char *base)
{
	char	*str;
	int		i;

	str = itoa_hex(number, base);
	i = ft_putstr_fd(str, 1);
	free (str);
	return (i);
}

int	print_type(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr_fd((char *)va_arg(args, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), 1));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsign(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hexa(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (print_hexa(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (print_hexa(va_arg(args, int), "0123456789abcdef") + 2);
	}
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}
