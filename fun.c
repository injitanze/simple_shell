#include "alxshell.h"

/**
 * _putchar - Write character to stdout.
 * @c: character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strncpy - Copie a string.
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_strncpy(char *dest, char *src, int n)
{
int t;

t = 0;
	while (t < n && *(src + t))
	{
	*(dest + t) = *(src + t);
	t++;
	}
	while (t < n)
	{
	*(dest + t) = '\0';
	t++;
	}
	return (dest);
}

/**
 * _strlen - Lenght of string.
 * @s:char
 * Return:int
 */

int _strlen(char *s)
{
	int t;

		for (t = 0; s[t] != '\0'; t++)
		{
			continue;
		}
return (t);
}

/**
 * _atoi - Convert to a int
 * @s:string
 * Return:int
 */
int _atoi(char *s)
{
int n, t, y, z;

	n = y = 0;
	z = 1;
	while ((s[n] < '0' || s[n] > '9') && (s[n] != '\0'))
	{
		if (s[n] == '-')
			z *= -1;
		n++;
	}
	t = n;
	while ((s[t] >= '0') && (s[t] <= '9'))
	{
		y = (y * 10) + z * ((s[t]) - '0');
		t++;
	}
	return (y);
}
/**
 * _puts - print a string.
 * @st:pointer char
 * return:void
 */
void _puts(char *st)
{
	int n;

	for (n = 0; st[n] != '\0'; n++)
	{
		_putchar(st[n]);
	}
_putchar('\n');
return;
}
