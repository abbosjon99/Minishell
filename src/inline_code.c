/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inline_code.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:40:09 by akeldiya          #+#    #+#             */
/*   Updated: 2024/08/21 19:31:00 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	inline_code(int argc, char **argv)
{
	if (argc >= 2)
	{
		if (ft_strncmp(argv[1], "-c", 3))
			err_exit("Usage: ./minishell -c \"Commands here\"");
		else if (argc == 2)
			err_exit("minishell: -c: option requires an argument");
		printf("%s\n", argv[2]);
	}
}