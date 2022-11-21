/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:10:58 by astachni          #+#    #+#             */
/*   Updated: 2022/11/21 20:17:36 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(int nb, ...)
{
	va_list	arg;
	size_t	i;

	// if (!str)
	// 	return (-1);
	va_start(arg, nb);
	while (nb > 0)
	{
		int n = va_arg(arg, int);
		printf("%d\n", n);
		nb--;
	}
}
