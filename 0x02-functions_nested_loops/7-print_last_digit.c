#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @q: the int to extract the last digit from
 * Return: value of the last digit
 */
int print_last_digit(int q)
{
	int a;

	if (q < 0)
	q = -q;

	a = q % 10;

	if (a < 0)
		a = -a;

	_putchar(a + '0');

	return (a);
}
