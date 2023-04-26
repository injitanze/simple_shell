#include "alxshell.h"

/**
 * histoDis - Display the history Of User input
 * @cmd: Command
 * @h:Statue Of the last excute
 * Return: 0 Succes -1 Fail
 */
int histoDis(__attribute__((unused))char **cmd, __attribute__((unused)) int h)
{
	char *filename = ".simple_shell_history";
	FILE *fp;
	char *ln = NULL;
	size_t l = 0;
	int counter = 0;
	char *t;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&ln, &l, fp)) != -1)
	{
		counter++;
		t = _itoa(counter);
		PRINTER(t);
		free(t);
		PRINTER(" ");
		PRINTER(ln);

	}
	if (ln)
		free(ln);
	fclose(fp);
	return (0);
}
/**
 * print_echo - Excute echo
 * @cmd: Command
 * Return: 0 Succes and  -1 Fail.
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int s;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, env) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &s, WUNTRACED);
		} while (!WIFEXITED(s) && !WIFSIGNALED(s));
	}
	return (1);
}
