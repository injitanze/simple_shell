#include "alxshell.h"

/**
 * shell_prompt - Display Shell Prompt.
 */
void shell_prompt(void)
{
	PRINTER("$ ");
}
/**
 * printError - Display error based on command and how many time shell looped.
 * @input: Input.
 * @counter: counter.
 * @argv: argument name.
 * Return: Void.
 */
void printError(char *input, int counter, char **argv)
{
	char *h;

	PRINTER(argv[0]);
	PRINTER(": ");
	h  = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
