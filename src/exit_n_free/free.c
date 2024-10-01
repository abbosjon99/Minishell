/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:50 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/06 21:01:41 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/definitions.h"
#include "../../inc/minishell.h"

// frees data after every line commands
// and returns the result
int	free4inline(t_data *data, int result)
{
	if (data->live_input)
		free(data->live_input);
	return (result);
}

void	free_n_exit(t_data *data, int exit_code)
{
	free_data(data);
	exit(exit_code);
}

// SHOULD CHECK IF I NEED TO FREE USER NAME
// frees the data before exit
void	free_data(t_data *data)
{
	free4inline(data, 0);
	// if (data->username)
	// 	free(data->username);
}
