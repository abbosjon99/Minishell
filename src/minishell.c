/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:06:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/02 17:10:38 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

// Initial checking the arguments, if any error prints error
// If -c command is here it will redirect everything to inline mode
static void	argv_check(t_data *data, int argc, char **argv)
{
	if (argc > 1)
	{
		if (ft_strncmp(argv[1], "-c", 3))
			err_exit("Usage: ./minishell -c \"Commands here\"");
		else if (argc == 2)
			err_exit("minishell: -c: Option requires an argument");
		data->is_intrctv = true;
	}
}

// We will handle empty user input
static void	intrctv_shell(t_data *data, char **envp)
{
	(void)*envp;
	while (1)
	{
		signal(SIGINT, signal_handler);
		printf("%s", get_username(data));
		data->live_input = readline("@minishell> ");
		if (NULL == data->live_input)
			return ;
		if (false == parcer_input_valid(data))
			continue ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	argv_check(&data, argc, argv);
	data_init(&data, envp);
	if (data.is_intrctv)
		inline_code(&data, argv[2], envp);
	else
		intrctv_shell(&data, envp);
	free_n_exit(&data, data.exit_code);
}
