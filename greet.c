#include <stdio.h>
#include "shell.h"

/**
 * Greet - prints greeting message
 * Return: Return 0 when main runs successfully
 *
 */
void greet(void)
{
	printf("Hello, World!\n");
}

/**
 * main -  runs the greet fucntion when called
 * * @return Returns zero to indicate successful execution.
 */
int main(void)
{
	/* Call the greet() function to print a greeting message */
	greet();
	return (0);
}
