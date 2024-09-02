/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:37:52 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/02 16:44:12 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/definitions.h"
#include "../../inc/minishell.h"

static bool	is_all_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	return (true);
}

// In case of empty string or space we return false
bool	parcer_input_valid(t_data *data)
{
	if (NULL == data->live_input)
		free_n_exit(data, 1);
	if (0 == data->live_input[0] || is_all_space(data->live_input))
	{
		free(data->live_input);
		return (false);
	}
	add_history(data->live_input);
	return (true);
}
