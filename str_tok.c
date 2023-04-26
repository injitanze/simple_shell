#includ "alxshell.h"
/**
 * checkDelim - Checks if a Char match any Char *
 * @a: Char to check.
 * @st: String to check.
 * Return: 1 Succes,and 0 Failed.
 */
unsigned int checkDelim(char a, const char *st)
{
	unsigned int n;

	for (n = 0; st[n] != '\0'; n++)
	{
		if (a == st[n])
			return (1);
	}
	return (0);
}

/**
 * str_tok - Token to string into token
 * @st: String
 * @to: Delimiter.
 * Return: Pointer to the next token Or NULL.
 */
char *str_tok(char *st, const char *to)
{
	static char *s;
	static char *ss;
	unsigned int n;

	if (st != NULL)
		ss = st;
	s = ss;
	if (s == NULL)
		return (NULL);
	for (n = 0; s[n] != '\0'; n++)
	{
		if (checkDelim(s[n], to) == 0)
			break;
	}
	if (ss[n] == '\0' || ss[n] == '#')
	{
		ss = NULL;
		return (NULL);
	}
	s = ss + n;
	ss = s;
	for (n = 0; ss[n] != '\0'; n++)
	{
		if (checkDelim(ss[n], to) == 1)
			break;
	}
	if (ss[n] == '\0')
		ss = NULL;
	else
	{
		ss[n] = '\0';
		ss = ss + n + 1;
		if (*ss == '\0')
			ss = NULL;
	}
	return (s);
}
