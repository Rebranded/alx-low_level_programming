#include <stdio.h>

/**
 * main - Lists all the natural numbers below 1024 (excluded)
 *        that are multiples of 3 or 5.
 *
 * Return: Always 0.
 */
int main(void)
{
	int h, sum = 0;

	for (h = 0; h < 1024; h++)
	{
		if ((h % 3) == 0 || (h % 5) == 0)
			sum += h;
	}

	printf("%d\n", sum);

	return (0);
}
