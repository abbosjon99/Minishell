# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 11:38:04 by akeldiya          #+#    #+#              #
#    Updated: 2024/05/03 21:51:17 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# List of source files for libft
FUNCTIONS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c get_next_line_utils.c

PRINTF_DIR = ft_printf

# Convert source file names to object file names
OBJECTS = $(FUNCTIONS:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Archiver
AR = ar rcs

# Remove command
RM = rm -f

# Compile rule for libft source files
.c.o:
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Build rule for libft.a
$(NAME): ft_printf $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

ft_printf:
	make -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/ft_printf.a .
	mv ft_printf.a $(NAME)

all: $(NAME)

clean:
	make clean -C ft_printf
	$(RM) $(OBJECTS)

fclean: clean
	make fclean -C ft_printf
	$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY:  all clean fclean re ft_printf

