/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:52:52 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 19:07:57 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <stdbool.h>

// ----------------------------------------------------------------------------
//								GLOBAL VARIABLE	
// ----------------------------------------------------------------------------

extern int	g_exit_code;

// ----------------------------------------------------------------------------
//								STRUCTURES
// ----------------------------------------------------------------------------
typedef struct s_token
{
	char				*str;
	char				*str_backup;
	bool				var_exists;
	int					type;
	int					status;
	bool				join;
	struct s_token		*prev;
	struct s_token		*next;
}						t_token;
typedef struct s_io_fds
{
	char				*infile;
	char				*outfile;
	char				*heredoc_delimiter;
	bool				heredoc_quotes;
	int					fd_in;
	int					fd_out;
	int					stdin_backup;
	int					stdout_backup;
}						t_io_fds;
typedef struct s_command
{
	char				*command;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_io_fds			*io_fds;
	struct s_command	*next;
	struct s_command	*prev;
}						t_command;

typedef struct s_data
{
	bool				is_intrctv;
	t_token				*token;
	char				*user_input;
	char				**env;
	t_command			*cmd;
}						t_data;

// ----------------------------------------------------------------------------
//									ENUMS
// ----------------------------------------------------------------------------

enum					e_token_types
{
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	TRUNC,
	HEREDOC,
	APPEND,
	END
};

enum					e_quoting_status
{
	DEFAULT,
	SQUOTE,
	DQUOTE
};

// ----------------------------------------------------------------------------
//								DEFINITIONS
// ----------------------------------------------------------------------------

# define PROMPT "•\001\033[1;92m\002 Minishell>$ \001\033[0;97m\002"
# define ERROR_PROMPT "\001\033[1;91m\002•\001\033[1;92m\002 \
Minishell>$ \001\033[0;97m\002"

# define HEREDOC_NAME "/tmp/.minishell_heredoc_"

# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

# define SUCCESS 0
# define FAILURE 1

#endif