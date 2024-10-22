/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 21:59:11 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtin_echo(char **args)
{
	bool	newline;

	newline = true;
	if (!**args || !*args || ft_strcmp(*args, "echo") != 0)
		return (false);
	args++;
	if (*args && ft_strcmp(*args, "-n") == 0)
	{
		args++;
		newline = false;
	}
	while (*args)
	{
		ft_printf("%s", *args);
		args++;
		if (*args)
			ft_printf(" ");
	}
	if (newline)
		ft_printf("\n");
	return (true);
}
