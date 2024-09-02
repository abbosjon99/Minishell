/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:20:46 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/02 16:44:34 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_username(t_data *data)
{
	(void)data;
	return (getenv("USER"));
}

char	*get_path(void)
{
	return ("/idunno");
}
