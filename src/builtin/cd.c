/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/22 16:14:20 by akeldiya         ###   ########.fr       */
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
	temp = ft_strjoin(get_curr_path(), "/");
	fixed_path = ft_strjoin(temp, path);
	free_ptr(temp);
	return (fixed_path);
}

// checks if path is absolute or relative
// tries to access and change OLDPWD and PWD
static bool	cd_helper(char *path, t_data *data)
{
	char	*oldpwd;

	oldpwd = get_curr_path();
	path = cd_pathes(path, data);
	if (!path)
		return (false);
	if (chdir(path) != 0)
	{
		if (chdir(path) == EACCES)
			perr_cstm("cd", "permission denied", path, 0);
		else
			perr_cstm("cd", "no such a directory", path, 0);
		free_ptr(path);
		return (false);
	}
	free_ptr(path);
	if (!env_change(ft_strjoin("OLDPWD=", oldpwd), data))
		return (false);
	if (!env_change(ft_strjoin("PWD=", get_curr_path()), data))
		return (false);
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
	{
		if (get_env_val("HOME", data))
			return (cd_helper(get_env_val("HOME", data), data));
		else
			return (true);
	}
	else if (*args && args[1])
	{
		return (perr_cstm("cd", NULL, "too many arguments", 0));
	}
	else
		cd_helper(*args, data);
	return (true);
}
