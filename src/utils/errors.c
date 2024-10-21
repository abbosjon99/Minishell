/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:06:15 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 17:12:59 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// custom str join function needed to another functions
static char	*str_join(char *str, char *add)
{
	char	*tmp;

	if (!add)
		return (str);
	if (!str)
		return (ft_strdup(add));
	tmp = str;
	str = ft_strjoin(tmp, add);
	free_ptr(tmp);
	return (str);
}

/* add_detail_quotes:
*	Checks whether to add quotes around the error detail:
*	i.e. "unset: `@': not a valid identifier"
*	Returns true if the command is export or unset,
*	false if not.
*/
static bool	add_detail_quotes(char *command)
{
	if (ft_strncmp(command, "export", 7) == 0
		|| ft_strncmp(command, "unset", 6) == 0)
		return (true);
	return (false);
}

// Prints error message on fd[2] to similar to perror
// returns error value
int	cstm_perr(char *command, char *err_msg, char *err_arg, int ret_val)
{
	char	*msg;
	bool	detail_quotes;

	detail_quotes = add_detail_quotes(command);
	msg = ft_strdup("minishell: ");
	if (command != NULL)
	{
		msg = str_join(msg, command);
		msg = str_join(msg, ": ");
	}
	if (err_msg != NULL)
	{
		if (detail_quotes)
			msg = str_join(msg, "`");
		msg = str_join(msg, err_msg);
		if (detail_quotes)
			msg = str_join(msg, "'");
		msg = str_join(msg, ": ");
	}
	msg = str_join(msg, err_arg);
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
	return (ret_val);
}

/* errmsg:
*	Prints an error message that is unrelated to a specific command.
*	Used in parsing phase for syntax errors.
*/
void	errmsg(char *errmsg, char *detail, int quotes)
{
	char	*msg;

	msg = ft_strdup("minishell: ");
	msg = str_join(msg, errmsg);
	if (quotes)
		msg = str_join(msg, " `");
	else
		msg = str_join(msg, ": ");
	msg = str_join(msg, detail);
	if (quotes)
		msg = str_join(msg, "'");
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
}
