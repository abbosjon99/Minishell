/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:34:07 by akeldiya          #+#    #+#             */
/*   Updated: 2024/10/10 11:19:50 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Maybe use getcwd
bool	builtin_pwd(char **args, t_data *data)
{
	if (!**args || !*args || ft_strcmp(*args, "pwd") != 0)
		return (false);
	ft_printf("%s\n", find_env_var("PWD", data) + 4);
	return (true);
}
