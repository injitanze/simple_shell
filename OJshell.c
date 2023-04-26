#include "simshell.h"
/**
* Main -Simple command shell.
* @argc: Arguments of number.
* @argv: Arguments of array.
* @envp: Environment variables of array.
* Return: Always 0.
*/
int main(int argc, char *argv[], char *envp[])
{
	char **str;
	size_t m = 10, inbuilt = 0, pt = 4;
	ssize_t numba_char;
	char *ptr, *mc;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$");
		ptr = malloc(size of(char) * m);
		numba_char = getline(&ptr, &m, (stdin);
		if (numba_char == -1)
		{
			free(ptr);
			exit(EXIT_FAILURE);
		}

		if (*ptr != '\n')
		{
			str = fhstrstok(ptr);
			if (strcmp("exist", str[0]) == 0)
				break;
			inbuilt = checkinbuilt(str[0]);
			mc = filecheck(str[0]);
			if (inbuilt == 0 && mc != NULL)
				str[0] = mc;
			pt = pathcheck(str[0]);
			if (pt == 1)
				forkexe(str, envp);
			if (mc == NULL && pt == 0 && inbuilt == 0)
				printf("./shell: No such file or directory \n");
		}
	}
	free(mc);
	free(ptr);
	free(str);
}
