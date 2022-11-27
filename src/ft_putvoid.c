/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:08:06 by astachni@st       #+#    #+#             */
/*   Updated: 2022/11/27 20:27:44 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	base_converter_void(char *base)
{
	size_t	i0;
	size_t	i1;

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

int	ft_recursive_void(uintptr_t nbr, char *base, size_t base_nbr, size_t i)
{
	if (nbr >= 0 && nbr < base_nbr)
	{
		ft_putchar_fd(base[nbr], 1);
		i++;
	}
	else
	{
		ft_recursive_void(nbr / base_nbr, base, base_nbr, i);
		ft_putchar_fd(base[nbr % base_nbr], 1);
		i++;
	}
	return (i);
}

int	ft_putvoid(void	*nbr, char	*base)
{
	uintptr_t	nb;
	size_t		count;
	size_t		base_nbr;

	nb = (uintptr_t)nbr;
	base_nbr = base_converter_void(base);
	count = 0;
	count = write(1, "0x", 2);
	count = ft_recursive_void(nb, base, base_nbr, count);
	return ((int)count);
}
