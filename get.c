#include "alxshell.h"

/**
* getline_ - Read input by User from Stdin.
* Return: Input.
*/
char *getline_()
{
int n, buffsize = BUFSIZE, bu;
char co = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (n = 0; co != EOF && co != '\n'; n++)
	{
		fflush(stdin);
		bu = read(STDIN_FILENO, &co, 1);
		if (bu == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[n] = co;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (n >= buffsize)
		{
			buff = realloc_(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[n] = '\0';
	hash(buff);
	return (buff);
}

/**
 * hash - Remove everything after #
 * @buff: input;
 * Return:void.
 */
void hash(char *buff)
{
	int n;

		for (n = 0; buff[n] != '\0'; n++)
		{
			if (buff[n] == '#')
			{
			buff[n] = '\0';
			break;
			}
	}
}
