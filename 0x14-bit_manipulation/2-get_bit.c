#include "main.h"

/**
 * get_bit - will returns the value of a bit at an index in a decimal number
 * @n: number to search for.
 * @index: index of the bit
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int myBit_val;

	if (index > 63)
		return (-1);

	myBit_val = (n >> index) & 1;

	return (myBit_val);
}
