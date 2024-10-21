/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 19:22:50 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	export_adder(char *str, t_data *data)
{
	char	**new_env;
	char	**dest;
	char	**src;

	new_env = ft_calloc(env_length(data->env) + 2, sizeof(data->env));
	if (!new_env)
		return (false);
	dest = new_env;
	src = data->env;
	while (*src)
	{
		*dest = ft_strdup(*src);
		if (!*dest)
			return (free_str_arr(new_env));
		dest++;
		src++;
	}
	*dest = ft_strdup(str);
	if (!*dest)
		return (free_str_arr(new_env));
	dest[1] = NULL;
	free_str_arr(data->env);
	data->env = new_env;
	return (true);
}

// addes or replaces variable in env
bool	add_rem_env(char *var, t_data *data)
{
	if (get_env_var(var, data))
	{
		if (!change_env_var(var, data))
			return (false);
	}
	else
		return (export_adder(var, data));
}

bool	builtin_export(char **args, t_data *data)
{
	char	**temp;

	if (!**args || !*args || ft_strcmp(*args, "export") != 0)
		return (false);
	args++;
	if (!*args)
		return (builtin_env(data));
	while (*args)
	{
		add_rem_env(*args, data);
		args++;
	}
	return (true);
}
