#include "alxshell.h"

/**
 * main - Simple shell
 * @argc: Argument count
 * @argv:Argument vector
 * Return: Exit value by status.
 */

int main(__attribute__((unused))int argc, char **argv)
{
	char *input, **cmd;
	int cot = 0, sta = 1, st = 0;

	if (argv[1] != NULL)
		readFile(argv[1], argv);
	signal(SIGINT, signa);
	while (sta)
	{
		cot++;
		if (isatty(STDIN_FILENO))
			shell_prompt();
		input = getline_();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, cot);
		}
		else if (checkBuiltin(cmd) == 0)
		{
			st = handleBuiltin(cmd, st);
			freeAll(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, cot, argv);

		}
		freeAll(cmd, input);
	}
	return (sta);
}
/**
 * checkBuiltin - check the builtin
 *
 * @cmd:command to be  check
 * Return: 0 when succesfull and  -1  when fail
 */
int checkBuiltin(char **cmd)
{
	bul_t func[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int n = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((func + n)->command)
	{
		if (_strcmp(cmd[0], (func + n)->command) == 0)
			return (0);
		n++;
	}
	return (-1);
}
/**
 * creatEnvi - Creat an array of enviroment variable
 * @envi: Array of enviroment Var
 * Return: Void
 */
void creatEnvi(char **envi)
{
	int n;

	for (n = 0; env[n]; n++)
		envi[n] = _strdup(env[n]);
	envi[n] = NULL;
}
