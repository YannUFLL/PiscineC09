# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 12:48:02 by ydumaine          #+#    #+#              #
#    Updated: 2022/02/02 18:07:16 by ydumaine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =  srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

HEADER = ./includes

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = cc

BIBL = ar -rc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADER}

${NAME}:	${OBJS}
			${BIBL} ${NAME} ${OBJS}



all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:     clean           
			${RM} ${NAME}

re:         fclean all          

.PHONY:     all clean fclean re
