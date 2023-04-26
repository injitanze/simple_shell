#include "alxshell.h"
/**
 *  _prerror - To print custome error
 * @argv:Argument Name
 * @c:Error count
 * @cmd:Command
 * Return: Void.
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *h = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(h);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(h);
}
