/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:09:12 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 22:07:17 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Initializes a data variable with the contents of the environment
// variables inherited from the original shell.
// Returns FALSE on failure, TRUE on success.
static bool	env_init(t_data *data, char **env)
{
	int	i;

	data->env = ft_calloc(env_length(env) + 1, sizeof(data->env));
	if (!data->env)
		return (false);
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])
			return (false);
		i++;
	}
	return (true);
}

//	Copies env file from host to itself, so we can use it for parsing
//	and for execution
//	true - if everything is OK
//	false - Error
bool	data_init(t_data *data, char **env)
{
	g_exit_code = 0;
	if (!env_init(data, env))
		return (perr_cstm("Internal Error", NULL,
				"Initialization of environment values has failed", 0));
	data->rl_input = NULL;
	data->token = NULL;
	data->cmd = NULL;
	return (true);
}

/* init_io:
 *	Initializes a structure with default values to contain
 *	infile and outfile information for a command.
 */
void	init_io(t_command *cmd)
{
	if (!cmd->io_fds)
	{
		cmd->io_fds = malloc(sizeof(cmd->io_fds));
		if (!cmd->io_fds)
			return ;
		cmd->io_fds->infile = NULL;
		cmd->io_fds->outfile = NULL;
		cmd->io_fds->heredoc_delimiter = NULL;
		cmd->io_fds->heredoc_quotes = false;
		cmd->io_fds->fd_in = -1;
		cmd->io_fds->fd_out = -1;
		cmd->io_fds->stdin_backup = -1;
		cmd->io_fds->stdout_backup = -1;
	}
}
