/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:49 by astachni          #+#    #+#             */
/*   Updated: 2022/11/21 22:18:05 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "src/libft1/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		*type_tab_create(int *tab);
int		find_type(const char *str, int *tab, size_t start);
int		choose_type(int *type_tab, int type_index, va_list args);

#endif
