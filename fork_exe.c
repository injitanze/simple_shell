#include"simshell.h"

/**
* forkexe - System execution with fork.
* @arstr: Array of strings gotten from line command.
* @envp: Environment variables from the parent.
* Return: Void
*/
void forkexe(char **arstr, char *envp[])
{
	pid_t child_pid;
	int stats;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error: Fork issue");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(arstr, envp) == -1)
			perror("./shell: No such file or directory\n");
	}

	else
	{
		wait(&stats);
	}
}
