/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:06:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/22 16:23:05 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_exit_code;

static void	print_all_data(t_data *data)
{
	print_token_list(&data->token);
	print_cmd_list(data);
}

//	main:
//	-checks arguments
//	-initializes all data
//	-runs the program on interactive or non-interactive
//	-exits with cleaning
//	main loop of our program
int	main(int argc, char **argv, char **env)
{
	t_data	data;

	((void)argc, (void)argv);
	ft_memset(&data, 0, sizeof(t_data));
	if (!data_init(&data, env))
		free_exit(NULL, EXIT_FAILURE);
	while (true)
	{
		if (g_exit_code == 0)
			data.rl_input = readline(PROMPT);
		else
			data.rl_input = readline(ERR_PROMPT);
		if (parse_user_input(&data) == true)
			execute(&data);
		// print_all_data(&data);
		free_data(&data, false);
	}
	free_exit(&data, 0);
	return (0);
}
