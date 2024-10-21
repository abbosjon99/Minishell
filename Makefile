# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 19:56:58 by akeldiya          #+#    #+#              #
#    Updated: 2024/10/21 13:38:33 by akeldiya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
SRC	= 	minishell.c \
		env/env.c \
		env/env_set.c \
		env/env_tools.c \
		lexer/parse_user_input.c \
		lexer/tokenization.c \
		lexer/tokenization_utils.c \
		lexer/check_if_var.c \
		lexer/lexer_grammar.c \
		lexer/token_lst_utils.c \
		lexer/token_lst_utils_2.c \
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
		expander/var_expander.c \
		expander/var_expander_utils.c \
		expander/identify_var.c \
		expander/quotes_handler.c \
		expander/quotes_remover.c \
		expander/recover_value.c \
		expander/replace_var.c \
		builtin/export.c \
		builtin/unset.c \
		builtin/cd.c \
		builtin/env.c \
		builtin/pwd.c \
		builtin/echo.c \
		builtin/exit.c \
		execute/execute.c \
		utils.c \
		utils/data_init.c \
		utils/exit.c \
		utils/errors.c \
		utils/cleanup.c \
		debug.c \

# Paths to add prefix
SRC_PATH = ./src/
INC_PATH = ./inc/

SRCS	= $(addprefix $(SRC_PATH), $(SRC))

# Sources and objects
OBJS = $(SRCS:.c=.o)

# Constants
NAME = minishell
CC = gcc
CFLAGS =  -g #-Wall -Wextra -Werror
LIBS = -lreadline -ldl
RM = rm -f

# Libft settings
LIBFT_PATH = ./libs/libft/
LIBFT = ./libs/libft/libft.a
INC_LIBFT = -I $(INC_PATH) -I $(LIBFT_PATH)

# Rules
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_LIBFT)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIBFT) $(LIBFT) $(LIBS)

libft:
	make -C libs/libft

clean:
	make clean -C  libs/libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C  libs/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
