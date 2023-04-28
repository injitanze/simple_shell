#include "alxshell.h"
/**
 * _strcpy - src to destination char.
 * @dest:Destination.
 * @src:src
 * Return: Copies Of char *
 */
char *_strcpy(char *dest, char *src)
{
int n = 0;
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
dest[n] = '\0';
return (dest);
}
/**
 * _strcat - To concatinate  two string.
 * @dest: First Str.
 * @src: Second Str.
 * Return: concatination strings.
 */
char *_strcat(char *dest, char *src)
{
	char *sc = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (sc);
}
/**
 * _strchr - Locate Char In String.
 * @s:String Search In.
 * @c:Char To Search For.
 * Return: Pointer To Char*
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}
/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @ss: str.
 * @ss1: str.
 * @n: amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0.
 */
int _strncmp(const char *ss, const char *ss1, size_t n)
{
	size_t ar;

	if (ss == NULL)
		return (-1);
	for (ar = 0; ar < n && ss1[ar]; ar++)
	{
		if (ss[ar] != ss1[ar])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - String duplication.
 * @st:str
 * Return: String duplication.
 */
char *_strdup(char *st)
{
	size_t l, n;
	char *str;

	len = _strlen(st);
	str  = malloc(sizeof(char) * (l + 1));
	if (!str)
	{
		return (NULL);
	}

	for (n  = 0; n <= l; n++)
	{
		str[n] = st[n];
	}

	return (str);
}
