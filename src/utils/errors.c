/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:06:15 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 13:15:47 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* join_strs:
*	Joins two strings together, freeing the previous string.
*	Returns the new concatenated string. Or NULL if an error occured.
*/
char	*join_strs(char *str, char *add)
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

/* errmsg_cmd:
*	Prints an error message to the standard error, prefixed with the
*	program name.
*	Returns with the specified error number.
*/
int	errmsg_cmd(char *command, char *detail, char *error_message, int error_nb)
{
	char	*msg;
	bool	detail_quotes;

	detail_quotes = add_detail_quotes(command);
	msg = ft_strdup("minishell: ");
	if (command != NULL)
	{
		msg = join_strs(msg, command);
		msg = join_strs(msg, ": ");
	}
	if (detail != NULL)
	{
		if (detail_quotes)
			msg = join_strs(msg, "`");
		msg = join_strs(msg, detail);
		if (detail_quotes)
			msg = join_strs(msg, "'");
		msg = join_strs(msg, ": ");
	}
	msg = join_strs(msg, error_message);
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
	return (error_nb);
}

/* errmsg:
*	Prints an error message that is unrelated to a specific command.
*	Used in parsing phase for syntax errors.
*/
void	errmsg(char *errmsg, char *detail, int quotes)
{
	char	*msg;

	msg = ft_strdup("minishell: ");
	msg = join_strs(msg, errmsg);
	if (quotes)
		msg = join_strs(msg, " `");
	else
		msg = join_strs(msg, ": ");
	msg = join_strs(msg, detail);
	if (quotes)
		msg = join_strs(msg, "'");
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
}
