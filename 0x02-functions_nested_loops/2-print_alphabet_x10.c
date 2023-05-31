#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase,
 * followed by a new line
 */
void print_alphabet_x10(void)
{
	char st;
	int j;

	j = 0;

	while (j < 10)
	{
		st = 'a';
		while (st <= 'z')
		{
			_putchar(st);
			st++;
		}
		_putchar('\n');
		j++;
	}
}
