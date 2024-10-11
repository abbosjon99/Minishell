/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:51:18 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/10 21:41:47 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	execute(t_data *data)
{
	t_command	*cmd;
	pid_t		pid;
	int			input_fd;
	int			pipe_fd[2];

	input_fd = 0;
	cmd = data->cmd;
	while (cmd)
	{
		if (cmd->next && pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return (1);
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return (false);
		}
		if (pid == 0)
		{
			if (cmd->io_fds && cmd->io_fds->fd_in > 1)
			{
				dup2(cmd->io_fds->fd_in, STDIN_FILENO);
				close(cmd->io_fds->fd_in);
			}
			else if (input_fd != 0)
			{
				dup2(input_fd, STDIN_FILENO);
				close(input_fd);
			}
			if (cmd->io_fds && cmd->io_fds->fd_out > 1)
			{
				dup2(cmd->io_fds->fd_out, STDOUT_FILENO);
				close(cmd->io_fds->fd_out);
			}
			else if (cmd->next)
			{
				close(pipe_fd[0]);
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[1]);
			}
			if (ft_strcmp(cmd->command, "echo") == 0)
			{
				builtin_echo(cmd->args);
				exit(0);
			}
			else if (ft_strcmp(cmd->command, "pwd") == 0)
			{
				builtin_pwd(cmd->args, data);
				exit(0);
			}
			else if (ft_strcmp(cmd->command, "cd") == 0)
			{
				builtin_cd(cmd->args, data);
				exit(0);
			}
			else if (ft_strcmp(cmd->command, "env") == 0)
			{
				builtin_env(cmd->args, data);
				exit(0);
			}
			else if (ft_strcmp(cmd->command, "unset") == 0)
			{
				builtin_unset(cmd->args, data);
				exit(0);
			}
			else if (execve(ft_strjoin("/bin/", cmd->command), cmd->args,
					data->env) == -1)
			{
				perror("execve failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (input_fd != 0)
				close(input_fd);
			if (cmd->next)
				close(pipe_fd[1]);
			input_fd = pipe_fd[0];
			wait(NULL);
			cmd = cmd->next;
		}
	}
	return (true);
}
