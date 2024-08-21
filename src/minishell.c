/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:06:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/08/21 19:30:27 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

// int	main(int argc, char **argv, char **env)
int	main(int argc, char **argv)
{
	char	*input;

	if (argc > 1)
	{
		inline_code(argc, argv);
	}
	signal(SIGINT, signal_handler);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (*input)
			add_history(input);

		free(input);
	}
	return (0);
}
