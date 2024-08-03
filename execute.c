#include "minishell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

void execute_command(char *cmd, char **argv) {
    pid_t pid = fork();
    if (pid == 0) {
        execve(cmd, argv, NULL);
        perror("execve");
        _exit(1);
    } else {
        wait(NULL);
    }
}
