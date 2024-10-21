/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 19:06:02 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtin_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env && data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	return (true);
}