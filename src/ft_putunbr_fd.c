/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:20:53 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/11/27 21:28:41 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putnbr(unsigned int n, int fd)
{
	return (write(fd, &n, 1));
}

unsigned int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putnbr('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putunbr_fd(n / 10, fd);
		i += ft_putunbr_fd(n % 10, fd);
	}
	else if (n < 10)
	{
		i += ft_putnbr('0' + n, fd);
	}
	return (i);
}
