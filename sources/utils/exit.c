/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:06:38 by mcombeau          #+#    #+#             */
/*   Updated: 2024/10/03 17:21:05 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* exit_shell:
*	Cleanly exits the minishell program by closing all opened
*	fds and freeing all allocated memory.
*/
void	exit_shell(t_data *data, int exno)
{
	if (data)
	{
		if (data->cmd && data->cmd->io_fds)
			;
		free_data(data, true);
	}
	exit(exno);
}