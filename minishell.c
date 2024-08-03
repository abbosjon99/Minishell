#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\n");
        rl_on_new_line();
        rl_redisplay();
    }
}

int main() {
    char *input;

    signal(SIGINT, signal_handler);

    while (1) {
        input = readline("minishell> ");
        if (!input)
            break;

        if (*input)
            add_history(input);

        // Parse and execute the command here
        // ...

        free(input);
    }

    return 0;
}
