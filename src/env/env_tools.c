/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:47:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 21:38:31 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// finds and returns the entire env value
// which is after = sign
char	*get_env_val(char *key, t_data *data)
{
	if (!key)
		return (NULL);
	return (ft_strchr(get_env_var(key, data), '=') + 1);
	return (NULL);
}

// finds and returns the entire env variable
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

// checks if entering key is valid
// if yes returns true
bool	is_valid_env_key(char *key)
{
	int	i;

	i = 0;
	if (ft_isalpha(key[i]) == 0 && key[i] != '_')
		return (false);
	i++;
	while (key[i] && key[i] != '=')
	{
		if (ft_isalnum(key[i]) == 0 && key[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

//	counts and returns the length of env char array
int	env_length(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}
