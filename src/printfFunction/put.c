/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:57:55 by astachni          #+#    #+#             */
/*   Updated: 2022/11/22 00:06:41 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	choose_type(int *type_tab, int type_index, va_list args, const char *s, int i)
{
	char	*n;

	(void)s;
	if (!type_tab || !args)
		return (-1);

	n = va_arg(args, char *);
	if (type_tab[type_index] == 's' && i)
	ft_putstr_fd(n, 1);
	return (0);
}