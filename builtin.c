#include "minishell.h"
#include <stdio.h>
#include <unistd.h>

void echo_cmd(char **args) {
    int newline = 1;
    if (args[1] && strcmp(args[1], "-n") == 0) {
        newline = 0;
        args++;
    }
    for (int i = 1; args[i]; i++) {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" ");
    }
    if (newline)
        printf("\n");
}
