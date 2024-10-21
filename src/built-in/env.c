/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/10 00:42:43 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtin_env(char **args, t_data *data)
{
	int i;

	i = 0;
	if (!**args || !*args || ft_strcmp(*args, "env") != 0)
		return (false);
	while (data->env && data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	return (true);
}