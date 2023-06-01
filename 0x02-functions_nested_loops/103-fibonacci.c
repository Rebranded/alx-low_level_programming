#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a;
	unsigned long int j, k, nextnum, sum;

	j = 1;
	k = 2;
	sum = 0;

	for (a = 1; a <= 33; ++a)
	{
		if (j < 4000000 && (j % 2) == 0)
		{
			sum = sum + j;
		}
		nextnum = j + k;
		j = k;
		k = nextnum;
	}

	printf("%lu\n", sum);

	return (0);
}
