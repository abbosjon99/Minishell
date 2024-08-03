# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 21:58:46 by akeldiya          #+#    #+#              #
#    Updated: 2024/05/03 19:45:47 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

FUNCTIONS = ft_printf.c ft_putch.c ft_putst.c ft_putdi.c ft_putu.c\
	ft_putxx.c ft_putp.c
OBJECTS = $(FUNCTIONS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY:  all clean fclean re

