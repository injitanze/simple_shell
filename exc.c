#include "alxshell.h"

/**
 * handleBuiltin - Handle builtin cmd.
 * @cmd: Parsed Command.
 * @h:statue of last excute.
 * Return: -1 Fail and 0 sucess.
 */

int handleBuiltin(char **cmd, int h)
{
	 bul_t bit[] = {
		{"cd", changeDir},
		{"env", disEnv},
		{"help", displayHelp},
		{"echo", echoBuiltin},
		{"history", histoDis},
		{NULL, NULL}
	};
	int n = 0;

	while ((bit + n)->command)
	{
		if (_strcmp(cmd[0], (bit + n)->command) == 0)
		{
			return ((bit + n)->func(cmd, h));
		}
		n++;
	}
	return (-1);
}
/**
 * check_cmd - Excute Simple Shell Command (Fork,Wait,Excute).
 *
 * @tokens:Parsed cmd.
 * @ln: User input.
 * @co:Shell excution time case of command not found.
 * @argv:Program Name.
 * Return: 1 Case Command Null, -1 Wrong Command and 0 Command Excuted.
 */
int check_cmd(char **tokens, char *ln, int co, char **argv)
{
	int sta;
	pid_t pid;

	if (*tokens == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*tokens, "./", 2) != 0 && _strncmp(*tokens, "/", 1) != 0)
		{
			path_cmd(tokens);
		}

		if (execve(*tokens, tokens, environ) == -1)
		{
			printError(tokens[0], co, argv);
			free(ln);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&sta);
	return (0);
}
/**
 * signa - Handle ^C.
 * @sign:Captured Signal.
 * Return: Void.
 */
void signa(int sign)
{
	if (sign == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
