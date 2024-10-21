/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:47:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 17:56:00 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	counts and returns the length of env char array
int	env_length(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

// finds and returns the env value
char	*get_env_var(char *key, t_data *data)
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
