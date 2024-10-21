/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:47:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/20 13:36:03 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// finds and returns the env
char	*find_env_var(char *key, t_data *data)
{
	char	**env;
	int		i;
	int		j;

	env = data->env;
	if (!key || !env)
		return (NULL);
	j = 0;
	while (env[j])
	{
		i = 0;
		while (key[i] && env[j][i] && (key[i] == env[j][i]))
		{
			if (env[j][i] == '=')
				return (env[j]);
			i++;
		}
		if (env[j][i] == '=' && key[i] == 0)
			return (env[j]);
		j++;
	}
	return (NULL);
}

// finds and changes the env var
bool	change_env_var(char *key, t_data *data)
{
	char	*target;

	if (!key || !data->env)
		return (false);
	target = find_env_var(key, data);
	if (target)
	{
		free(target);
		target = ft_strdup(key);
		if (target)
			return (true);
	}
	return (false);
}

// remove the env var
bool	remove_env_var(char *key, t_data *data)
{
	char	*buffer;
	int		i;

	i = 0;
	if (!key || !data->env)
		return (false);
	buffer = find_env_var(key, data);
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
