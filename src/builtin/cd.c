/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/21 18:14:31 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// tries to make absolut path over values
static char	*cd_pathes(char *path, t_data *data)
{
	char	*fixed_path;
	char	*temp;

	if (!path)
		return (NULL);
	if (*path == '/')
		return (ft_strdup(path));
	temp = ft_strjoin(get_env_var("PWD", data) + 4, "/");
	fixed_path = ft_strjoin(temp, path);
	free_ptr(temp);
	return (fixed_path);
}

// checks if path is absolute or relative
// tries to access and change OLDPWD and PWD
static bool	cd_helper(char *path, t_data *data)
{
	path = cd_pathes(path, data);
	if (!path)
		return (false);
	if (chdir(path) != 0)
	{
		if (chdir(path) == EACCES)
			cstm_perr("cd", "permission denied", path, 0);
		else
			cstm_perr("cd", "no such a directory", path, 0);
		free_ptr(path);
		return (false);
	}
	if (!change_env_var(ft_strjoin("OLD", get_env_var("PWD", data)), data))
		return (false);
	if (!change_env_var(ft_strjoin("PWD=", path), data))
		return (false);
	free(path);
	return (true);
}

// Implementation of cd function
// - checks if argument count is OK
// - checks if user isdoing cd with no arg
// - runs helper function to change dirs
bool	builtin_cd(char **args, t_data *data)
{
	if (!**args || !*args || ft_strcmp(*args, "cd") != 0)
		return (false);
	args++;
	if (!*args)
		return (cd_helper(get_env_var("HOME", data) + 5, data));
	else if (*args && args[1])
	{
		printf("cd: too many arguments\n");
		return (false);
	}
	else
		cd_helper(*args, data);
	return (true);
}
