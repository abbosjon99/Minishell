# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:56:58 by akeldiya          #+#    #+#              #
#    Updated: 2024/09/04 16:47:27 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
SRCS = src/minishell.c \
		src/built-in/cd.c	src/built-in/echo.c	src/built-in/env.c \
		src/built-in/exit.c	src/built-in/export.c	src/built-in/pwd.c \
		src/built-in/unset.c \
		src/exit_n_free/error_exit.c	src/exit_n_free/free.c \
		src/inline_code.c	src/data_init.c \
		src/lexer/parcer.c \
		src/utils/get_variables.c \
		src/execute/execute.c \
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
