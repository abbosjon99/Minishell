/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 18:47:19 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_curr_path(void)
{
	char	cwd[PATH_MAX];

	return (getcwd(cwd, sizeof(cwd)));
}

// Maybe use getcwd
bool	builtin_pwd(char **args, t_data *data)
{
	char	cwd[PATH_MAX];

	if (!**args || !*args || ft_strcmp(*args, "pwd") != 0)
		return (false);
	ft_printf("%s\n", get_curr_path());
	return (true);
}
