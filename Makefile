# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:56:58 by akeldiya          #+#    #+#              #
#    Updated: 2024/10/10 09:30:04 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
# Files
SRC		= 	main.c \
			utils.c \
			utils/init_data.c \
			utils/exit.c \
			utils/error.c \
			utils/cleanup.c \
			utils/env_tools.c \
			env/env.c \
			env/env_set.c \
			lexer/parse_user_input.c \
			lexer/tokenization.c \
			lexer/tokenization_utils.c \
			lexer/check_if_var.c \
			lexer/lexer_grammar.c \
			lexer/token_lst_utils.c \
			lexer/token_lst_utils_2.c \
			expansion/var_expander.c \
			expansion/var_expander_utils.c \
			expansion/identify_var.c \
			expansion/quotes_handler.c \
			expansion/quotes_remover.c \
			expansion/recover_value.c \
			expansion/replace_var.c \
			parser/create_commands.c \
			parser/parse_word.c \
			parser/fill_args_echo.c \
			parser/fill_args_echo_utils.c \
			parser/fill_args_default.c \
			parser/parse_input.c \
			parser/parse_trunc.c \
			parser/parse_append.c \
			parser/parse_heredoc.c \
			parser/parse_heredoc_utils.c \
			parser/parse_pipe.c \
			parser/cmd_lst_utils.c \
			parser/cmd_lst_utils_cleanup.c \
			built-in/export.c \
			built-in/unset.c \
			built-in/cd.c \
			built-in/env.c \
			built-in/pwd.c \
			built-in/echo.c \
			built-in/exit.c \
			execute/execute.c \
			debug.c \

# Build files and directories
SRC_PATH = ./sources/
INC_PATH = ./includes/

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Sources and objects
OBJS = $(SRCS:.c=.o)

# Constants
NAME = minishell
CC = gcc
CFLAGS = -g #-Wall -Wextra -Werror
LIBS = -l readline
RM = rm -f

# Libft settings
LIBFT_PATH = ./libft/
LIBFT = ./libft/libft.a
INC_LIBFT = -I $(INC_PATH) -I $(LIBFT_PATH)

# Rules
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_LIBFT)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIBFT) $(LIBFT) $(LIBS)

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
