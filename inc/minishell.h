/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:30:42 by akeldiya          #+#    #+#             */
/*   Updated: 2024/09/21 19:03:56 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "definitions.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// Function declarations
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	setup_signals(void);

void	print_error(const char *msg);
void	*safe_malloc(size_t size);
void	change_directory(const char *path);
char	*get_current_directory(void);
void	print_exit_status(int status);
void	inline_code(t_data *data, char *code, char **envp);
void	err_exit(char *str);
void	free_data(t_data *data);
void	free_n_exit(t_data *data, int exit_code);
int		free4inline(t_data *data, int result);

char	*get_path(void);
char	*get_username(t_data *data);
char	**cmd_split(char const *s);

bool	data_init(t_data *data, char **argv);
bool	parcer_input_valid(t_data *data);

#endif
