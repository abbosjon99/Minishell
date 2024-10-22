/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 21:55:46 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtin_export(char **args, t_data *data)
{
	char	**temp;

	if (!**args || !*args || ft_strcmp(*args, "export") != 0)
		return (false);
	args++;
	if (!*args)
		return (builtin_env(data));
	if (!is_valid_env_key(*args))
		return (perr_cstm("export", *args, "not a valid identifier", 0));
	while (*args)
	{
		if (!ft_strchr(*args, '=') && args++)
			continue ;
		env_change(*args, data);
		args++;
	}
	return (true);
}
