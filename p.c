#include "alxshell.h"

/**
 * parse_cmd - Parse Line Of Input.
 * @input: input to perse.
 * Return: Array Of Char (Parsed):Simple Shell.
 */
char **parse_cmd(char *input)
{
	char **toks;
	char *tok;
	int n, buff_size = BUFSIZE;

	if (input == NULL)
		return (NULL);
	toks  = malloc(sizeof(char *) * buff_size);
	if (!toks)
	{
		perror("hsh");
		return (NULL);
	}

	tok  = str_tok(input, "\n ");
	for (n = 0; tok; n++)
	{
		toks[n] = tok;
		tok = str_tok(NULL, "\n ");
	}
	toks[n] = NULL;

	return (toks);
}
