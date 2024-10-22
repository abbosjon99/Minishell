/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:06:11 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 22:09:30 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_exit_code;

//	Initial checking the arguments:
//	-if any error prints error
//	-if -c command is here it will redirect everything to inline mode
static bool	argv_check(t_data *data, int argc, char **argv)
{
	data->is_intrctv = true;
	if (argc > 1)
	{
		data->is_intrctv = false;
		if (ft_strncmp(argv[1], "-c", 3))
			return (ft_printf("Usage: ./minishell -c \"Commands here\"\n")
				&& false);
		else if (argc == 2)
			return (ft_printf("minishell: -c: Option requires an argument\n")
				&& false);
	}
	return (true);
}

static void	print_all_data(t_data *data)
{
	print_token_list(&data->token);
	print_cmd_list(data);
}

/* minishell_interactive:
 *	Runs parsing and execution in interactive mode, i.e. when minishell
 *	is started without arguments and provides a prompt for user input.
 */
void	minishell_interactive(t_data *data)
{
	while (1)
	{
		data->rl_input = readline(PROMPT);
		if (parse_user_input(data) == true)
			execute(data);
		// print_all_data(data);
		free_data(data, false);
	}
}

/* minishell_noninteractive:
 *	Runs parsing and execution in noninteractive mode, i.e. when
 *	minishell is started with the -c option followed by an argument
 *	containing the commands to be executed:
 *		./minishell -c "echo hello | wc -c"
 *	Commands in this mode can be separated by a semicolon, ';' to
 *	indicate sequential execution:
 *		./minishell -c "echo hello; ls"
 *	-> echo hello is the first command run
 *	-> ls is the second
 */
void	minishell_noninteractive(t_data *data, char *arg)
{
	char	**user_inputs;
	int		i;

	user_inputs = ft_split(arg, ';');
	if (!user_inputs)
		exit_shell(data, EXIT_FAILURE);
	i = 0;
	while (user_inputs[i])
	{
		data->rl_input = ft_strdup(user_inputs[i]);
		if (parse_user_input(data) == true)
			execute(data);
		else
			ft_printf("Internal Error !!");
		print_all_data(data);
		i++;
		free_data(data, false);
	}
	free_str_arr(user_inputs);
}

//	main:
//	-checks arguments
//	-initializes all data
//	-runs the program on interactive or non-interactive
//	-exits with cleaning
int	main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (!argv_check(&data, argc, argv) || !data_init(&data, env))
		exit_shell(NULL, EXIT_FAILURE);
	printf("%i\n", g_exit_code);
	if (data.is_intrctv)
		minishell_interactive(&data);
	else
		minishell_noninteractive(&data, argv[2]);
	exit_shell(&data, 0);
	return (0);
}
