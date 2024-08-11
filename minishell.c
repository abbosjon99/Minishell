/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:06:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/08/11 18:06:19 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(void)
{
	char	*input;

	signal(SIGINT, signal_handler);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (*input)
			add_history(input);
		// Parse and execute the command here
		// ...
		free(input);
	}
	return (0);
}
