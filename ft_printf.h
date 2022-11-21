/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:49 by astachni          #+#    #+#             */
/*   Updated: 2022/11/22 00:13:41 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "src/libft1/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		*type_tab_create(int *tab);
int		find_type(const char *str, int *tab, size_t start);
int		choose_type(int *type_tab, int type_index, va_list args, const char *s, int i);
int     type_in_char(const char c, int *tab);

#endif
