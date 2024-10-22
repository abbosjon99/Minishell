/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:06:38 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/22 16:19:20 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Exits the program, but with cleaning everything and closing fds
void	free_exit(t_data *data, int exno)
{
	if (data)
	{
		if (data->cmd && data->cmd->io_fds)
			;
		free_data(data, true);
	}
	exit(exno);
}
