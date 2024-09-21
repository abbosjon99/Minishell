/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:52:52 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/21 19:10:46 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <stdbool.h>

// typedef struct s_prompt
// {
// 	t_list	*cmds;
// 	char	**envp;
// 	pid_t	pid;
// }			t_prompt;

// typedef struct s_mini
// {
// 	char	**full_cmd;
// 	char	*full_path;
// 	int		infile;
// 	int		outfile;
// }			t_mini;

typedef struct s_data
{
	char	*live_input;
	char	*username;
	bool	is_intrctv;
	int		exit_code;
}			t_data;

typedef enum e_parcer_out
{
	CORRECT,
	WRONG,
	EMPTY,
	ERROR
}			t_parcer_out;

#endif
