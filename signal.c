// signal.c
#include "minishell.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

// Signal handler for SIGINT (Ctrl-C)
void handle_sigint(int sig)
{
    if (sig == SIGINT)
    {
        // Print a newline and prompt again
        write(STDOUT_FILENO, "\n", 1);
        // rl_on_new_line() and rl_redisplay() are used with readline to refresh the prompt
        rl_on_new_line();
        rl_redisplay();
    }
}

// Signal handler for SIGQUIT (Ctrl-\)
void handle_sigquit(int sig)
{
    if (sig == SIGQUIT)
    {
        // Default behavior for SIGQUIT (Ctrl-\) can be kept or modified as needed
        // This does nothing in this implementation
        (void)sig; // to avoid unused variable warning
    }
}

// Setup signal handlers
void setup_signals(void)
{
    struct sigaction sa_int;
    struct sigaction sa_quit;

    // Configure SIGINT handler
    sa_int.sa_handler = handle_sigint;
    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_flags = SA_RESTART | SA_SIGINFO;
    if (sigaction(SIGINT, &sa_int, NULL) == -1)
    {
        perror("sigaction SIGINT");
        exit(EXIT_FAILURE);
    }

    // Configure SIGQUIT handler
    sa_quit.sa_handler = handle_sigquit;
    sigemptyset(&sa_quit.sa_mask);
    sa_quit.sa_flags = SA_RESTART | SA_SIGINFO;
    if (sigaction(SIGQUIT, &sa_quit, NULL) == -1)
    {
        perror("sigaction SIGQUIT");
        exit(EXIT_FAILURE);
    }
}
