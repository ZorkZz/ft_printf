/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin@42.fr <astachni>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:15:28 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/11/19 20:34:39 by marvin@42.f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr(int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static int	is_neg(char *str, int isneg, int len)
{
	if (isneg == 1)
		str[0] = '-';
	else
		len--;
	return (len);
}

static char	*int_min(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = malloc(12 * sizeof(char));
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = 0;
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		len;

	neg = 0;
	if (int_min(n) != NULL)
		return (int_min(n));
	if (n < 0)
	{
		n *= -1;
		neg = 1;
	}
	len = nbr(n);
	str = malloc((len + (1 + neg)) * sizeof(char));
	if (!str)
		return (NULL);
	str[len + neg] = 0;
	len = is_neg(str, neg, len);
	while (n >= 10)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	str[len--] = n + '0';
	return (str);
}
