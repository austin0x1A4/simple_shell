#include <stdio.h>
#include "shell.h"

/**
 * @brief Function to greet the user with "Hello, World!"
 */
void greet(void)
{
	/* Print the greeting message */
	printf("Hello, World!\n");
}

/**
 * @brief The main function.
 *
 * @return Returns zero to indicate successful execution.
 */
int main(void)
{
    /* Call the greet() function to print a greeting message */
    greet();
    return (0);
}

