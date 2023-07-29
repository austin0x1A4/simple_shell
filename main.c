#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;

    while (1)
    {
        display_prompt();
        if (read_input(&line) == -1)
        {
            printf("\n"); // Print a newline before exiting on Ctrl+D
            free(line);
            break;
        }

        parse_command(line);
        execute_command(line);

        free(line);
    }

    return 0;
}

