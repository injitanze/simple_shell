#include "alxshell.h"
/**
 * history - Filled file by User Input.
 * @input: Input.
 * Return: -1 Fail and 0 Succes.
 */
int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, n;
	int l = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[l])
			l++;
		n = write(fd, input, l);
		if (n < 0)
			return (-1);
	}
	return (1);
}
/**
 * freeEnv - Free enviroment variable array.
 * @en:  Environment variables.
 * Return: Void.
 */
void freeEnv(char **en)
{
	int n;

	for (n = 0; en[n]; n++)
	{
		free(en[n]);
	}
}
