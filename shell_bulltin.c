#include "alxshell.h"
/**
 * exit_bul - Exit statue of shell.
 * @cmd: Parsed cmd.
 * @input: User Input.
 * @argv:Argument Name.
 * @c: Count.
 * Return: Void.
 */
void  exit_bul(char **cmd, char *input, char **argv, int c)
{
	int stat, n = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][n])
	{
		if (_isalpha(cmd[1][n++]) != 0)
		{
			_prerror(argv, c, cmd);
			break;
		}
		else
		{
			stat = _atoi(cmd[1]);
			free(input);
			free(cmd);
			exit(stat);
		}
	}
}


/**
 * changeDir - Change Dirctory.
 * @cmd: Command.
 * @h: Statue of the last command excuted.
 * Return: 0 Succes and 1 Failed (For Old Pwd Always 0 Case No Old PWD).
 */
int changeDir(char **cmd, __attribute__((unused))int h)
{
	int val = -1;
	char cd[PATH_MAX];

	if (cmd[1] == NULL)
		val = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		val = chdir(getenv("OLDPWD"));
	}
	else
		val = chdir(cmd[1]);

	if (val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (val != -1)
	{
		getcwd(cd, sizeof(cd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cd, 1);
	}
	return (0);
}
/**
 * disEnv - Display enviroment Var.
 * @cmd:cmd
 * @h: Last command excuted.
 * Return:Always 0
 */
int disEnv(__attribute__((unused)) char **cmd, __attribute__((unused)) int h)
{
size_t n;
	int l;

	for (n = 0; env[n] != NULL; n++)
	{
		l = _strlen(env[n]);
		write(1, environ[n], l);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * displayHelp - Displaying help for builtin.
 * @cmd: Command
 * @h: last Command Excuted.
 * Return: 0 Succes and -1 Fail
 */
int displayHelp(char **cmd, __attribute__((unused))int h)
{
	int fd, fs, fu = 1;
	char c;

	fd = open(cmd[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (fu > 0)
	{
		fu = read(fd, &c, 1);
		fs = write(STDOUT_FILENO, &c, fu);
		if (fs < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echoBuiltin - Excute echo.
 * @h:Statue Of Last Command Excuted.
 * @cmd: Parsed Command.
 * Return: Always 0 Or Excute Normal Echo.
 */
int echoBuiltin(char **cmd, int h)
{
	char *pat;
	unsigned int  pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		printNumbeIn(h);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		printNumber(pid);
		PRINTER("\n");

	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		pat = getenv_("PATH");
		PRINTER(pat);
		PRINTER("\n");
		free(pat);

	}
	else
		return (print_echo(cmd));

	return (1);
}
