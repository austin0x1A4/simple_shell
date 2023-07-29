#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

void display_prompt(void)
{
    printf("#cisfun$ "); // The shell prompt
}

int read_input(char **line)
{
    ssize_t bufsize = 0;
    return getline(line, &bufsize, stdin);
}

void parse_command(char *line)
{
    // Remove the newline character from the end of the line
    line[strcspn(line, "\n")] = '\0';

    // Add your logic for handling the user's command here
    printf("Command received: %s\n", line);
}

void execute_command(char *command)
{
    // Replace this with your actual implementation of executing the command
    printf("Executing: %s\n", command);
}

