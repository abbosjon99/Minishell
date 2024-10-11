/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/10 10:56:04 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



// LATER
bool	builtin_cd(char **args, t_data *data)
{
	if (!**args || !*args || ft_strcmp(*args, "cd") != 0)
		return (false);
	args++;
	if (!*args)
	{
		printf("here: ");
		if(!change_env_var(ft_strjoin("PWD=", find_env_var("HOME", data) + 5), data))
			return (false);
		
	}
	else if (*args && args[1])
	{
		printf("cd: too many arguments\n");
		return (false);
	}
	else if (**args == '/')
		chdir(*args);
	else
		chdir(ft_strjoin(data->working_dir, *args));
	return (true);
}
