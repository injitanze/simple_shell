#include "alxshell.h"
/**
 * printNumber -Print nnsigned int putchar.
 * @n: unisigned integer to print.
 * Return: Void.
 */
void printNumber(unsigned int n)
{
	unsigned int num = n;

	if ((num / 10) > 0)
		printNumber(num / 10);

	_putchar(num % 10 + '0');
}
/**
 * printNumberIn -Print Number Putchar.
 * @n:Integer number.
 * Return: void.
 */
void printNumberIn(int n)
{
	unsigned int num  = n;

	if (n < 0)
	{
		_putchar('-');
		num  = -num;
	}
	if ((num / 10) > 0)
		printNumber(num / 10);

	_putchar(num % 10 + '0');
}
