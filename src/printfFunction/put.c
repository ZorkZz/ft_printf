/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:57:55 by astachni          #+#    #+#             */
/*   Updated: 2022/11/21 22:36:20 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	choose_type(int *type_tab, int type_index, va_list args)
{
	char	*n;

	if (!type_tab || !args)
		return (-1);
	n = va_arg(args, char *);
	if (type_tab[type_index] == 's')
		ft_putendl_fd(n, 1);
	return (0);
}