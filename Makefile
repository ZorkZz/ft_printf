# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin@42.fr <astachni>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 20:55:44 by astachni          #+#    #+#              #
#    Updated: 2022/11/22 23:09:39 by marvin@42.f      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = ft_printf.a

SRCS = ft_printf.c src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_putstr_fd.c src/type.c src/ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

%.o: %.c ${HEADER} Makefile
	$(CC) ${CFLAGS}  -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) ${NAME}

re: fclean all

.PHONY:	all clean fclean re