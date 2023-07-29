#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

/* Function prototypes */
void display_prompt(void);
int read_input(char **line);
void parse_command(char *line);
void execute_command(char *command);

#endif /* SHELL_H */

