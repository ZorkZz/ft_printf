# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 20:55:44 by astachni          #+#    #+#              #
#    Updated: 2022/11/22 07:23:41 by astachni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = ft_printf.a

SRCS = ft_printf.c ./src/printfFunction/type.c ./src/printfFunction/put.c

OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

%.o: %.c ${HEADER} Makefile
	$(CC)  -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) ${NAME}

re: fclean all

.PHONY:	all clean fclean re