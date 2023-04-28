#include "alxshell.h"

/**
 * path_cmd -  Search In $PATH for excutable command.
 * @ln: Parsed Input.
 * Return: 1  Failure and  0  Success.
 */
int path_cmd(char **ln)
{
	char *path, *val, *cmd_path;
	struct stat buf;

	path = getenv_("PATH");
	val = str_tok(path, ":");
	while (val != NULL)
	{
		cmd_path = build(*ln, val);
		if (stat(cmd_path, &buf) == 0)
		{
			*ln = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		val = str_tok(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * build - Build command.
 * @token: Excutable command.
 * @value: Dirctory conatining command.
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *build(char *token, char *value)
{
	char *cm;
	size_t ln;

	ln = _strlen(value) + _strlen(token) + 2;
	cm = malloc(sizeof(char) * ln);
	if (cm == NULL)
	{
		return (NULL);
	}

	memset(cm, 0, ln);

	cm = _strcat(cm, value);
	cm = _strcat(cm, "/");
	cm = _strcat(cm, token);

	return (cm);
}
/**
 * getenv_ - Gets value Of enviroment var by name
 * @name: Environment variable name
 * Return: The value of the environment variable, else NULL.
 */
char *getenv_(char *name)
{
	size_t ab, ac;
	char *value;
	int n, y, z;

	ab = _strlen(name);
	for (n = 0 ; environ[n]; n++)
	{
		if (_strncmp(name, environ[n], ab) == 0)
		{
			ac = _strlen(environ[n]) - ab;
			value = malloc(sizeof(char) * ac);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			z = 0;
			for (y = ab + 1; environ[n][y]; y++, z++)
			{
				value[z] = environ[n][y];
			}
			value[z] = '\0';

			return (value);
		}
	}

	return (NULL);
}
