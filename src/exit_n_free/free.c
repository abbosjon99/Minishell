/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:50 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/02 16:33:23 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/definitions.h"
#include "../../inc/minishell.h"

void	free_n_exit(t_data *data, int exit_code)
{
	free_data(data);
	exit(exit_code);
}

// SHOULD CHECK IF I NEED TO FREE USER NAME
void	free_data(t_data *data)
{
	if (data->live_input)
		free(data->live_input);
	if (data->username)
		free(data->username);
}
