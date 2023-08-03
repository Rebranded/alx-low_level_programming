#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal
 * @n: number to print in binary
 */


void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int flagTrack = 0;

	while (mask)
	{
		if (n & mask)
			flagTrack = 1;

		if (flagTrack)
			_putchar((n & mask) ? '1' : '0');

		mask >>= 1;
	}

	if (!flagTrack)
		_putchar('0');

	_putchar('\n');
}
