/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:37:52 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/04 12:14:12 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/definitions.h"
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
	return (true);
}
