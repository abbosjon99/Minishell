/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:05:55 by mcombeau          #+#    #+#             */
/*   Updated: 2024/10/03 17:20:08 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* free_data:
*	Frees all of the data used to run a command. If clear_history is true,
*	frees the environment and the command history before returning.
*/
void	free_data(t_data *data, bool clear_history)
{
	if (data && data->user_input)
	{
		free_ptr(data->user_input);
		data->user_input = NULL;
	}
	if (data && data->token)
		lstclear_token(&data->token, &free_ptr);
	if (data && data->cmd)
		lst_clear_cmd(&data->cmd, &free_ptr);
	if (clear_history == true)
	{
		if (data && data->working_dir)
			free_ptr(data->working_dir);
		if (data && data->old_working_dir)
			free_ptr(data->old_working_dir);
		if (data && data->env)
			free_str_tab(data->env);
		rl_clear_history();
	}
}


/* free_str_tab:
*	Frees an array of strings.
*/
void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

/* free_ptr:
*	Frees a pointer of any type if it is not NULL and sets it to NULL.
*	This avoids accidental double-frees.
*/
void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
