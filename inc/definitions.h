/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:52:52 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/13 12:05:30 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include <stdbool.h>

typedef enum e_parcer_out
{
	CORRECT,
	WRONG,
	EMPTY,
	ERROR
}	t_parcer_out;

typedef struct s_data
{
	char	*live_input;
	char	*username;
	bool	is_intrctv;
	int		exit_code;
}			t_data;

#endif
