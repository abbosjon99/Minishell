/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akeldiya <akeldiya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:05:49 by akeldiya          #+#    #+#             */
/*   Updated: 2024/08/11 18:11:51 by akeldiya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <string.h>
# include <string.h>
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

#endif
