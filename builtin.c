/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:05:27 by akeldiya          #+#    #+#             */
/*   Updated: 2024/08/21 18:27:14 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	echo_cmd(char **args)
{
	int	newline;

	newline = 1;
	if (args[1] && strcmp(args[1], "-n") == 0)
	{
		newline = 0;
		args++;
	}
	for (int i = 1; args[i]; i++)
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
	}
	if (newline)
		printf("\n");
}
