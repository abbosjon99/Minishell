# 42 Minishell Project - README

## Table of Contents
1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Supported Commands](#supported-commands)
6. [Bonus Features](#bonus-features)
7. [Testing](#testing)
8. [Common Issues](#common-issues)
9. [Credits](#credits)

---

## Project Overview

The **Minishell** project is about building a simple shell, similar to **bash**, as part of the 42 curriculum. The goal is to understand how command-line interpreters work, focusing on processes, pipes, redirection, and signals. This project also provides a strong understanding of file descriptors, environment variables, and the use of the readline library.

Minishell will handle a set of basic commands, including redirection, pipes, and some built-in shell commands, while also managing signals like `Ctrl+C` and `Ctrl+D`.

## Features

- **Prompt Display**: Continuously shows a prompt when waiting for input.
- **Execution of Commands**: Executes external commands and built-in functions.
- **Redirection**: Supports input/output redirection (`<`, `>`, `>>`, `<<`).
- **Pipes**: Supports piping (`|`) between commands.
- **Environment Variables**: Handles environment variables (`$`), including `$?`.
- **Signals Handling**: Correctly handles `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` in interactive mode.
- **Built-in Commands**: Implements basic built-ins like `cd`, `echo`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Memory Management**: Ensures no memory leaks, except in cases involving the `readline()` function.

## Installation

### Prerequisites

- **C Compiler**: GCC or any modern C compiler.
- **Libraries**: Readline library (`libreadline`) and standard Unix libraries (e.g., `unistd.h`, `fcntl.h`).

### Steps

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/your-repo/minishell.git
    cd minishell
    ```

2. **Compile the Project**:
    The project includes a `Makefile` for compiling the code.
    ```bash
    make
    ```

3. **Run the Shell**:
    After compiling, you can launch the shell with:
    ```bash
    ./minishell
    ```

## Usage

Once the shell is running, you can start typing commands similar to a Unix shell.

### Examples:

- **Run a Command**:
    ```bash
    ls -la
    ```
- **Redirection**:
    ```bash
    echo "Hello" > output.txt
    ```
- **Piping**:
    ```bash
    ls | grep minishell
    ```
- **Environment Variables**:
    ```bash
    echo $USER
    ```

To exit the shell:
```bash
exit
```

## Supported Commands

### Built-in Commands

- **`echo`**: Prints arguments to the terminal, supporting the `-n` option.
    ```bash
    echo -n Hello World
    ```
- **`cd`**: Changes the current working directory.
    ```bash
    cd /path/to/directory
    ```
- **`pwd`**: Prints the current working directory.
    ```bash
    pwd
    ```
- **`export`**: Sets environment variables.
    ```bash
    export VAR=value
    ```
- **`unset`**: Removes environment variables.
    ```bash
    unset VAR
    ```
- **`env`**: Displays the environment variables.
    ```bash
    env
    ```
- **`exit`**: Exits the shell.
    ```bash
    exit
    ```

### External Commands

All external commands that are present in your system’s `$PATH` can be executed, like:
```bash
ls, cat, grep, etc.
```

## Bonus Features

If you successfully complete the mandatory part, you can implement the following bonus features:

- **Logical Operators (`&&` and `||`)**: Execute commands based on the success/failure of previous commands.
    ```bash
    command1 && command2
    command1 || command2
    ```
- **Parenthesis for Priorities**: Handle command groupings.
    ```bash
    (command1 && command2) || command3
    ```
- **Wildcards (`*`)**: Allow file name expansion for commands.
    ```bash
    ls *.c
    ```

## Testing

To test your **Minishell**, compare its behavior against **bash** for the supported features:
- Test commands with pipes, redirection, and built-in commands.
- Check handling of signals (`Ctrl+C`, `Ctrl+D`).
- Validate memory management by ensuring no memory leaks using tools like `valgrind`.

## Common Issues

- **Segmentation Faults**: Ensure all pointers are properly initialized and free memory where necessary.
- **Memory Leaks**: Use tools like `valgrind` to check for any leaks in your code (except for those caused by `readline()`).
- **Signal Handling**: Make sure `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` work as expected.
- **Redirections and Pipes**: Ensure redirection of input/output and pipes are handled correctly.

## Credits

This project was developed as part of the curriculum at **42**. Special thanks to the 42 community and peer evaluators for their support.
