/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:52:52 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/22 22:38:47 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <stdbool.h>

typedef enum e_token_type
{
	COMMAND,
	VAR,
	PIPE,
	INFILE,
	OUTFILE,
	ERRFILE,
	HEREDOC
}						t_token_type;

typedef struct s_token
{
	char				*str;
	t_token_type		type;
	struct s_token		*prev;
	struct s_token		*next;
}						t_token;

// typedef struct s_command
// {
// 	char				*command;
// 	char				*path;
// 	char				**args;
// 	bool				pipe_output;
// 	int					*pipe_fd;
// 	t_io_fds			*io_fds;
// 	struct s_command	*next;
// 	struct s_command	*prev;
// }						t_command;

typedef struct s_data
{
	char				*live_input;
	char				*username;
	bool				is_intrctv;
	t_token				**tokens;
	int					exit_code;
}						t_data;

typedef enum e_parcer_out
{
	CORRECT,
	WRONG,
	EMPTY,
	ERROR
}						t_parcer_out;

#endif
