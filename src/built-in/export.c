/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 11:19:30 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	error_clean(char **str)
{
	char	**tmp;

	tmp = str;
	if (!str)
		return (false);
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(str);
	return (false);
}

static bool	export_adder(char *str, t_data *data)
{
	char	**new_env;
	char	**dest;
	char	**src;

	new_env = (char **)malloc(sizeof(char *) * (env_var_count(data->env) + 2));
	if (!new_env)
		return (false);
	dest = new_env;
	src = data->env;
	while (*src)
	{
		*dest = ft_strdup(*src);
		if (!*dest)
			return (error_clean(new_env));
		dest++;
		src++;
	}
	*dest = ft_strdup(str);
	if (!*dest)
		return (error_clean(new_env));
	dest++;
	*dest = NULL;
	error_clean(data->env);
	data->env = new_env;
	return (true);
}

bool	builtin_export(char **args, t_data *data)
{
	char	**temp;

	if (!**args || !*args || ft_strcmp(*args, "export") != 0)
		return (false);
	args++;
	while (*args)
	{
		if (find_env_var(*args, data))
		{
			if (!change_env_var(*args, data))
				return (false);
		}
		else
			return (export_adder(*args, data));
		args++;
	}
	return (true);
}
