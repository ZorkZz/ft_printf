/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:20:53 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/11/27 21:30:18 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putnbr(int n, int fd)
{
	return (write(fd, &n, 1));
}

int	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n >= -2147483647 && n <= 2147483647)
	{
		if (n < 0)
		{
			ft_putnbr('-', fd);
			n *= -1;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (n < 10)
		{
			ft_putnbr('0' + n, fd);
		}
	}
	return ();
}
