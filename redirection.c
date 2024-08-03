#include "minishell.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void redirect_output(const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}
