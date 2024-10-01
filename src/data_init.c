/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:23:27 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/02 17:09:34 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool data_init(t_data *data, char **argv)
{
	(void)*argv;
	data->username=getenv("USER");
	data->exit_code = 0;
	return(true);
}
