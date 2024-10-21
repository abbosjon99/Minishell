/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:09:12 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 13:49:05 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Initializes a data variable with the contents of the environment
// variables inherited from the original shell.
// Returns FALSE on failure, TRUE on success.
static bool	env_init(t_data *data, char **env)
{
	int		i;

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

/* init_wds:
*	Initializes working directory variables as a safeguard against
*	environment PWD and OLDPWD being unset or otherwise not present
*	in the environment. Used for cd builtin.
*	Returns true if successful, false in case of error.
*/
static bool	dir_init(t_data *data)
{
	char	buff[PATH_MAX];
	char	*wd;

	wd = getcwd(buff, PATH_MAX);
	data->working_dir = ft_strdup(wd);
	if (!data->working_dir)
		return (false);
	if (get_env_var_index(data->env, "OLDPWD") != -1)
	{
		data->old_working_dir = ft_strdup(get_env_var_value(data->env,
					"OLDPWD"));
		if (!data->old_working_dir)
			return (false);
	}
	else
	{
		data->old_working_dir = ft_strdup(wd);
		if (!data->old_working_dir)
			return (false);
	}
	return (true);
}

//	Copies env file from host to itself, so we can use it for parsing
//	and for execution
//	true - if everything is OK
//	false - Error
bool	data_init(t_data *data, char **env)
{
	if (!env_init(data, env) || !dir_init(data))
	{
		ft_printf("Internal error:\n");
		if (!env_init(data, env))
			ft_printf("Initialization of environment values has failed\n");
		if (!dir_init(data))
			ft_printf("Initialization working directories has failed\n");
		return (false);
	}
	data->user_input = NULL;
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
		cmd->io_fds = malloc(sizeof * cmd->io_fds);
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
