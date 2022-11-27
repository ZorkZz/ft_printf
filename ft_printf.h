/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:04:49 by astachni          #+#    #+#             */
/*   Updated: 2022/11/27 23:52:58 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				print_type(char c, va_list args);
int				verify_char(const char c);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putvoid(void	*nbr, char	*base);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
char			*itoa_hex(size_t n, char *base);
char			*ft_strdup(const char *src);

#endif
