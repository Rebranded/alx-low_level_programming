#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Return: ALways 0 (Success)
 */
int main(void)
{
	int a, m;

	for (a = 48; a <= 56; a++)
	{
		for (m = 49; m <= 57; m++)
		{
			if (m > a)
			{
				putchar(a);
				putchar(m);
				if (a != 56 || m != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
