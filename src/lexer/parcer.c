/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:37:52 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/21 19:12:02 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	is_all_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (false);
		str++;
	}
	return (true);
}

static bool	quote_matcher(char *str)
{
	char	quote;

	quote = 0;
	while (*str)
	{
		if (*str == '"' || *str == '\'')
		{
			if (quote == 0)
				quote = *str;
			else if (quote == *str)
				quote = 0;
		}
		str++;
	}
	return (quote == 0);
}

void	cmd_split_resoult(t_data *data)
{
	char	**str;

	str = cmd_split(data->live_input);
	while (*str)
	{
		printf("%s\n", *str);
		str++;
	}
}

// If string is null then it means there were an error with readline
// In case of empty string or space we return false
bool	parcer_input_valid(t_data *data)
{
	if (NULL == data->live_input)
		free_n_exit(data, 1);
	if (0 == data->live_input[0] || is_all_space(data->live_input))
	{
		return (free4inline(data, false));
	}
	add_history(data->live_input);
	if (false == quote_matcher(data->live_input))
		printf("Typing error with unclosed quotes!!\n");
	cmd_split_resoult(data);
	return (true);
}
