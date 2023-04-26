#include "alxshell.h"

/**
 * _strcmp - compering two string
 * @ss:first string
 * @ss1:first string
 * Return: 0 if identical Otherwise how much diffrent
 */
int _strcmp(char *ss, char *ss1)
{
int cmp = 0, n, l1, l2;
l1 = _strlen(ss);
l2 = _strlen(ss1);

	if (ss == NULL || ss1 == NULL)
		return (1);
	if (l1 != l2)
		return (1);
	for (n = 0; ss[n]; n++)
	{
		if (ss[n] != ss1[n])
		{
			cmp = ss[n] - ss1[n];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _isalpha - checking the alphabelt
 *@d: Character to check
 * Return: 1 If true and 0 if not
 */
int _isalpha(int d)
{
if (((d >= 97) && (d <= 122)) || ((d >= 65) && (d <= 90)))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _itoa - Convertion of integer to string
 * @t: Int to convert
 * Return: char pointer
 */
char *_itoa(unsigned int t)
{
	int l = 0, n = 0;
	char *st;

	l = intlen(t);
	st = malloc(l + 1);
	if (!st)
		return (NULL);
	*st = '\0';
	while (t / 10)
	{
		st[n] = (t % 10) + '0';
		t /= 10;
		n++;
	}
	s[n] = (t % 10) + '0';
	array_rev(st, l);
	st[n + 1] = '\0';
	return (st);
}
/**
 *  arrayRet - reverse array
 * @arr:array to reverse
 * @len:length Of array
 * Return: Void(reverse array)
 */
void arrayRet(char *arr, int len)
{
	int m;
	char temp;

	for (m = 0; m < (len / 2); m++)
	{
		temp = arr[i];
		arr[m] = arr[(len - 1) - m];
		arr[(len - 1) - m] = temp;
	}
}
/**
 * int_len - to determine the length Of Int
 * @num: Given Int
 * Return: length Of Int
 */
int int_len(int num)
{
	int l = 0;

	while (num != 0)
	{
		l++;
		num /= 10;
	}
	return (l);
}
