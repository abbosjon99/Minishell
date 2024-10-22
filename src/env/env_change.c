/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:51:06 by zkaroune          #+#    #+#             */
/*   Updated: 2024/10/22 16:13:58 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// remove the env var
bool	remove_env_var(char *key, t_data *data)
{
	char	*buffer;
	int		i;

	i = 0;
	if (!key || !data->env)
		return (false);
	buffer = get_env_var(key, data);
	if (buffer)
	{
		while (data->env[i] != buffer)
			i++;
		free(data->env[i]);
		data->env[i] = data->env[i + 1];
		while (data->env[i + 1])
		{
			data->env[i] = data->env[i + 1];
			i++;
		}
		data->env[i] = NULL;
	}
	return (true);
}

// finds and changes the env var
static bool	change_env_var(char *key, t_data *data)
{
	char	*target;
	char	**env;

	if (!key || !data->env)
		return (false);
	env = data->env;
	target = get_env_var(key, data);
	if (target)
	{
		while (*env != target)
			env++;
		free_ptr(target);
		*env = ft_strdup(key);
		if (*env)
		{
			env = NULL;
			return (true);
		}
	}
	env = NULL;
	return (false);
}

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
bool	env_change(char *var, t_data *data)
{
	if (get_env_var(var, data))
	{
		if (!change_env_var(var, data))
			return (false);
	}
	else
		return (export_adder(var, data));
}
