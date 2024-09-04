/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:04:25 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/04 16:47:48 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
