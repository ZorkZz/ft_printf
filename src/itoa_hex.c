/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:38:08 by astachni@st       #+#    #+#             */
/*   Updated: 2022/11/27 23:52:49 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static int	nbr(int n)
{
	int	i;

	i = 0;
	while (n > 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*itoa_hex(size_t n, char *base)
{
	char	*result;
	int		len;


	if (!base)
		return (0);
	len = nbr(n);
	result = malloc((len + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[len + 1] = 0;
	while (n >= 16)
	{
		result[len--] = base[n % 16];
		n /= 16;
	}
	result[len--] = base[n % 16];
	return (result);
}
