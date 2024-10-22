/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 21:51:18 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 22:08:59 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

// // Function to check if a command is a built-in
// bool	is_builtin(char *command)
// {
// 	return (!ft_strcmp(command, "echo") || !ft_strcmp(command, "cd")
// 		|| !ft_strcmp(command, "pwd") || !ft_strcmp(command, "env")
// 		|| !ft_strcmp(command, "unset"));
// }

// static bool	builtin_func(t_command *cmd, t_data *data)
// {
// 	if (ft_strcmp(cmd->command, "echo") == 0)
// 		builtin_echo(cmd->args);
// 	else if (ft_strcmp(cmd->command, "pwd") == 0)
// 		builtin_pwd(cmd->args, data);
// 	else if (ft_strcmp(cmd->command, "cd") == 0)
// 		builtin_cd(cmd->args, data);
// 	else if (ft_strcmp(cmd->command, "env") == 0)
// 		builtin_env(cmd->args, data);
// 	else if (ft_strcmp(cmd->command, "unset") == 0)
// 		builtin_unset(cmd->args, data);
// 	return (true);
// }

// bool	execute(t_data *data)
// {
// 	t_command	*cmd;
// 	pid_t		pid;
// 	int			pipe_fd[2];
// 	char		*path;

// 	cmd = data->cmd;
// 	int input_fd = 0; // Input starts from stdin
// 	while (cmd)
// 	{
// 		// Create a pipe if there's a next command
// 		if (cmd->nxt && pipe(pipe_fd) == -1)
// 		{
// 			perror("pipe");
// 			return (false);
// 		}
// 		else // External command
// 		{
// 			pid = fork();
// 			if (pid < 0)
// 			{
// 				perror("fork");
// 				return (false);
// 			}
// 			if (pid == 0) // Child process
// 			{
// 				if (cmd->io_fds && cmd->io_fds->fd_in > 1)
// 				{
// 					dup2(cmd->io_fds->fd_in, STDIN_FILENO);
// 					close(cmd->io_fds->fd_in);
// 				}
// 				else if (input_fd != 0)
// 				{
// 					dup2(input_fd, STDIN_FILENO);
// 					close(input_fd);
// 				}
// 				if (cmd->io_fds && cmd->io_fds->fd_out > 1)
// 				{
// 					dup2(cmd->io_fds->fd_out, STDOUT_FILENO);
// 					close(cmd->io_fds->fd_out);
// 				}
// 				else if (cmd->nxt)
// 				{
// 					close(pipe_fd[0]);
// 					dup2(pipe_fd[1], STDOUT_FILENO);
// 					close(pipe_fd[1]);
// 				}
// 				if (is_builtin(cmd->command))
// 				{
// 					builtin_func(cmd, data);
// 					exit(0);
// 				}
// 				// Execute the external command
// 				path = ft_strjoin("/bin/", cmd->command);
// 				execve(path, cmd->args, data->env);
// 				free(path); // Free the memory allocated by ft_strjoin
// 				perror("execve failed");
// 				exit(EXIT_FAILURE);
// 			}
// 			else // Parent process
// 			{
// 				if (input_fd != 0)
// 					close(input_fd);
// 				if (cmd->nxt)
// 					close(pipe_fd[1]);
// 				input_fd = pipe_fd[0]; // Pass the pipe to the next command
// 				wait(NULL);            // Wait for the child to finish
// 				cmd = cmd->nxt;
// 			}
// 		}
// 	}
// 	return (true);
// }

#include "minishell.h"

bool	is_builtin_env(char *command)
{
	return (!ft_strcmp(command, "cd")
		|| !ft_strcmp(command, "unset") || !ft_strcmp(command, "export"));
}

bool	is_builtin(char *command)
{
	return (!ft_strcmp(command, "echo") || !ft_strcmp(command, "cd")
		|| !ft_strcmp(command, "pwd") || !ft_strcmp(command, "env")
		|| !ft_strcmp(command, "unset") || !ft_strcmp(command, "export"));
}

static bool	builtin_func(t_command *cmd, t_data *data)
{
	if (ft_strcmp(cmd->command, "echo") == 0)
		builtin_echo(cmd->args);
	else if (ft_strcmp(cmd->command, "pwd") == 0)
		builtin_pwd(cmd->args, data);
	else if (ft_strcmp(cmd->command, "cd") == 0)
		builtin_cd(cmd->args, data);
	else if (ft_strcmp(cmd->command, "env") == 0)
		builtin_env(data);
	else if (ft_strcmp(cmd->command, "unset") == 0)
		builtin_unset(cmd->args, data);
	else if (ft_strcmp(cmd->command, "export") == 0)
		builtin_export(cmd->args, data);
	return (true);
}

bool	execute(t_data *data)
{
	t_command	*cmd;
	pid_t		pid;
	int			pipe_fd[2];
	char		*path;
	int			input_fd;

	cmd = data->cmd;
	input_fd = 0;
	while (cmd)
	{
		if (cmd->nxt && pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return (false);
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return (false);
		}
		if (pid == 0)
		{
			if (input_fd != 0)
			{
				dup2(input_fd, STDIN_FILENO);
				close(input_fd);
			}
			if (cmd->nxt)
			{
				close(pipe_fd[0]);
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[1]);
			}
			if (is_builtin(cmd->command))
			{
				if (!cmd->nxt && is_builtin_env(cmd->command))
					exit(0);
				builtin_func(cmd, data);
				exit(0);
			}
			path = ft_strjoin("/bin/", cmd->command);
			execve(path, cmd->args, data->env);
			free(path);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (input_fd != 0)
				close(input_fd);
			if (cmd->nxt)
				close(pipe_fd[1]);
			input_fd = pipe_fd[0];
			if (is_builtin_env(cmd->command))
			{
				builtin_func(cmd, data);
			}
			wait(NULL);
			cmd = cmd->nxt;
		}
	}
	return (true);
}
