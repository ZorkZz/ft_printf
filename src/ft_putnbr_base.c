/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <astachni>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:28:18 by astachni          #+#    #+#             */
/*   Updated: 2022/11/23 19:38:42 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

unsigned int	base_converter(char *base)
{
	unsigned int	i0;
	unsigned int	i1;

	i0 = 0;
	while (base[i0] != '\0')
	{
		i1 = i0 + 1;
		while (base[i1] != '\0')
		{
			if (base [i0] == '+' || base[i1] == '-')
				return (0);
			if (base[i0] == base [i1])
			{
				return (0);
			}
			i1 ++;
		}
		i0++;
	}
	return (i0);
}

int	ft_recursive(unsigned int nbr, char *base, unsigned int base_nbr, int i)
{
	if (nbr >= 0 && nbr < base_nbr)
	{
		ft_putchar(base[nbr]);
		i++;
	}
	else
	{
		ft_recursive(nbr / base_nbr, base, base_nbr, i);
		ft_putchar(base[nbr % base_nbr]);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_nbr;
	unsigned int	nbr_u;
	int				i;

	i = 0;
	base_nbr = base_converter(base);
	if (base_nbr == 0)
		return (-1);
	else if (base_nbr == 1)
		return (-1);
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr_u = nbr * -1;
		i++;
	}
	else
		nbr_u = nbr;
	i = ft_recursive(nbr_u, base, base_nbr, i);
	return (i);
}
