/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:26:14 by mcombeau          #+#    #+#             */
/*   Updated: 2024/10/03 17:02:28 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	var_exists(t_data *data, char *var)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], var, len) == 0)
			return (0);
		i++;
	}
	return (1);
}

static char	*search_env_var(t_data *data, char *var)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], var, len) == 0)
			break ;
		i++;
	}
	str = ft_strdup(data->env[i] + len);
	return (str);
}

char	*recover_val(t_token *token, char *str, t_data *data)
{
	char	*value;
	char	*var;

	var = identify_var(str);
	if (var && var_exists(data, var) == 0)
	{
		if (token != NULL)
			token->var_exists = true;
		value = search_env_var(data, var);
	}
	else if (var && var[0] == '?' && var[1] == '=')
		value = ft_itoa(0);
	else
		value = NULL;
	free_ptr(var);
	return (value);
}