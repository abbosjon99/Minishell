/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/10 21:42:41 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtin_unset(char **args, t_data *data)
{
	bool	result;

	result = true;
	if (!**args || !*args || ft_strcmp(*args, "unset") != 0)
		return (false);
	args++;
	while (*args)
	{
		if (!remove_env_var(*args, data))
			result = false;
		args++;
	}
	return (result);
}
