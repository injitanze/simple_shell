#include "alxshell.h"
/**
 * readFile - Read cmd from file.
 * @fname:Filename.
 * @argv:Program Name.
 * Return: -1 or  0.
 */

void readFile(char *fname, char **argv)
{
	FILE *fp;
	char *ln = NULL;
	size_t l = 0;
	int counter = 0;

	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&ln, &l, fp)) != -1)
	{
		counter++;
		treatFile(ln, counter, fp, argv);

	}
	if (ln)
		free(ln);
	fclose(fp);
	exit(0);
}
/**
 * treatFile - PARSE Check Command Fork Wait Excute in Line of File.
 * @ln: line from file.
 * @counter:Error counter.
 * @fp:File Descriptor.
 * @argv:Program Name.
 * Return : Excute  line void.
 */
void treatFile(char *ln, int counter, FILE *fp, char **argv)
{
	char **cm;
	int s = 0;

	cm = parse_cmd(ln);

		if (_strncmp(cm[0], "exit", 4) == 0)
		{
			exit_bull(cm, ln, fp);
		}
		else if (checkBuiltin(cm) == 0)
		{
			s = handleBuiltin(cm, s);
			free(cm);
		}
		else
		{
			s = check_cmd(cm, ln, counter, argv);
			free(cm);
		}
}
/**
 * exit_bull - Exit Shell Case Of File.
 * @ln: Line from file.
 * @cmd: Parsed Command.
 * @fd:File Descriptor.
 * Return : Case Of exit in A file line.
 */
void exit_bull(char **cmd, char *ln, FILE *fd)
{
	int statue, n = 0;

	if (cmd[1] == NULL)
	{
		free(ln);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][n])
	{
		if (_isalpha(cmd[1][n++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(ln);
	free(cmd);
	fclose(fd);
	exit(statue);



}
