/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:49 by astachni          #+#    #+#             */
/*   Updated: 2022/11/24 17:24:22 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				print_type(char c, const char *str, ...);
int				*type_tab_create(int *tab);
int				find_type(const char *str, int *tab, size_t start);
int				type_in_char(const char c, int *tab);
int				ft_putchar_fd(char c, int fd);
int				ft_putendl_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
unsigned int	ft_putunbr_fd(unsigned int n, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_base(int nbr, char *base);

#endif
