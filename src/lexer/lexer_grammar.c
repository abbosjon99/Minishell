/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_grammar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:45:35 by zkaroune          #+#    #+#             */
/*   Updated: 2024/10/20 18:02:46 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	consecutive_ops(t_token *token_node)
{
	if (token_node->prev)
	{
		if (token_node->type == PIPE && token_node->prev->type == PIPE)
			return (true);
		if (token_node->type > PIPE && token_node->prev->type > PIPE)
			return (true);
		if (token_node->type == END && token_node->prev->type >= PIPE)
			return (true);
	}
	return (false);
}

int	check_consecutives(t_token **token_lst)
{
	t_token	*temp;

	temp = *token_lst;
	while (temp)
	{
		if (consecutive_ops(temp) == true)
		{
			if (temp->type == END && temp->prev && temp->prev->type > PIPE)
				errmsg("syntax error near unexpected token", "newline", true);
			else if (temp->type == END && temp->prev)
				errmsg("syntax error near unexpected token",
					temp->prev->str, true);
			else
				errmsg("syntax error near unexpected token", temp->str, true);
			return (FAILURE);
		}
		temp = temp->next;
	}
	return (SUCCESS);
}
