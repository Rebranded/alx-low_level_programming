#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n:the number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, countNum = 0;
	unsigned long int currentNum;

	for (i = 63; i >= 0; i--)
	{
		currentNum = n >> i;

		if (currentNum & 1)
		{
			_putchar('1');
			countNum++;
		}
		else if (countNum)
			_putchar('0');
	}
	if (!countNum)
		_putchar('0');
}
