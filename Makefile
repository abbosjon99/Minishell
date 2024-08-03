# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:56:58 by akeldiya          #+#    #+#              #
#    Updated: 2024/08/03 16:07:35 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
SRCS = minishell.c \
       builtin.c \
       execute.c \
       redirection.c \
       signal.c \
       utils.c

# Sources and objects
OBJS = $(SRCS:.c=.o)

# Constants
NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline -ldl
RM = rm -f

# Libft settings
INCLULIBFT = -Ilibft
LIBFTFLAGS = $(INCLULIBFT) -Llibft -lft

# Rules
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLULIBFT)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTFLAGS) $(LIBS)

libft:
	make -C libft

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
