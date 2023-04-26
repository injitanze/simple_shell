#include "alxshell.h"

/**
 **realloc_ -  Reallocates A Memory.
 *@p: Pointer.
 *@oldSize: Previous Size Of The Pointer.
 *@newSize: New Size Of The Pointer.
 *Return: Void Pointer Rellocated Memory.
 */
void *realloc_(void *p, unsigned int oldSize, unsigned int newSize)
{
	void *res;

	if (newSize == oldSize)
		return (p);
	if (newSize == 0 && p)
	{
		free(p);
		return (NULL);
	}
	res = malloc(newSize);
	if (res == NULL)
		return (NULL);
	if (p == NULL)
	{
		fill_an_array(res, '\0', newSize);
		free(p);
	}
	else
	{
		_memcpy(res, p, oldSize);
		free(p);
	}
	return (res);

}
/**
 * freeAll - Free Array Of Char Pointer And Char Pointer.
 * @input:Array pointer.
 * @ln:Char Pointer.
 * Return: Void.
 */
void freeAll(char **input, char *ln)
{
	free(input);
	free(ln);
	input = NULL;
	ln = NULL;
}

/**
 * _memcpy - Copy Byte from source To destination.
 * @dest: Destination Pointer.
 * @src: Source Pointer.
 * @n: Size (
 *Return: Void Pointer.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int t;

	for (t = 0; t < n; t++)
	{
		dest[t] = src[t];
	}
	return (dest);
}
/**
 * fill_an_array - Fill An Array By Constant Byte.
 * @ab:Void Pointer.
 * @ad: int.
 * @len:length Int.
 *Return: Void Pointer.
 */
void *fill_an_array(void *ab, int ad, unsigned int len)
{
	char *pr = ab;
	unsigned int n = 0;

	while (n < len)
	{
		*pr = ad;
		pr++;
		n++;
	}
	return (ab);
}
/**
 * calloc_ -  allocates Memory for an array with Malloc.
 * @size: Size.
 * Return: Void Pointer.
 */
void *calloc_(unsigned int size)
{
	char *e;
	unsigned int i;

	if (size == 0)
	return (NULL);
	e = malloc(size);
	if (e == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		e[i] = '\0';
	}
	return (e);
}
