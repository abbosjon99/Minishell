// utils.c
#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to print an error message and exit
void print_error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to safely allocate memory and handle allocation errors
void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        print_error("malloc failed");
    }
    return ptr;
}

// Function to change the current directory and handle errors
void change_directory(const char *path)
{
    if (chdir(path) != 0)
    {
        perror("cd");
    }
}

// Function to get the current working directory and handle errors
char *get_current_directory(void)
{
    char *buf;
    size_t size = 1024;

    buf = (char *)safe_malloc(size);
    while (getcwd(buf, size) == NULL)
    {
        if (errno == ERANGE)
        {
            size *= 2;
            buf = (char *)realloc(buf, size);
            if (buf == NULL)
            {
                print_error("realloc failed");
            }
        }
        else
        {
            print_error("getcwd failed");
        }
    }
    return buf;
}

// Function to print an exit status
void print_exit_status(int status)
{
    printf("Exit status: %d\n", status);
}
