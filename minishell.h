// minishell.h
#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

// Function declarations
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	setup_signals(void);

void	print_error(const char *msg);
void	*safe_malloc(size_t size);
void	change_directory(const char *path);
char	*get_current_directory(void);
void	print_exit_status(int status);

#endif // MINISHELL_H
