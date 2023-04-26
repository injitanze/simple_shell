#include<simshell.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
* fhstrtok - print "$" first line
* @str: string parameter
* Return: array of string
*/

char **fhstrtok(char *str)
{
	char **ars, *par;
	int a = 0;
	int j = 0;

	ars = malloc(8 * "sizeof"(char);
	if (ars == NULL)
		{
			perror("can not allocate space");
				exit(1)
		}
	par = strtok(str, " ");
	while (par != NULL)
	{
		while (par[j])
		{
			if (par[j] == '\n')
				par[j] = '\0';
			j++;
		}
		ars[a] = par;
		a++;
		j = 0;
		ars = strtok(NULL, " ");
	}
	ars[a] = NULL;
	return (ars);
}
