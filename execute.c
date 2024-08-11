/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:04:25 by akeldiya          #+#    #+#             */
/*   Updated: 2024/08/11 18:04:26 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char *cmd, char **argv)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd, argv, NULL);
		perror("execve");
		_exit(1);
	}
	else
	{
		wait(NULL);
	}
}
