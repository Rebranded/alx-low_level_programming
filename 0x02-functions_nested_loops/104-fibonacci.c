#include <stdio.h>

/**
 * main - fibonacci <3
 *
 * Purpose - no hardcode
 *
 * Return:  (Success)
 */

int main(void)
{
	unsigned long int q;
	unsigned long int bef = 1;
	unsigned long int aft = 2;
	unsigned long int l = 1000000000;
	unsigned long int bef1;
	unsigned long int bef2;
	unsigned long int aft1;
	unsigned long int aft2;

	printf("%lu", bef);

	for (q = 1; q < 91; q++)
	{
		printf(", %lu", aft);
		aft += bef;
		bef = aft - bef;
	}

	bef1 = (bef / l);
	bef2 = (bef % l);
	aft1 = (aft / l);
	aft2 = (aft % l);

	for (q = 92; q < 99; ++q)
	{
		printf(", %lu", aft1 + (aft2 / l));
		printf("%lu", aft2 % l);
		aft1 = aft1 + bef1;
		bef1 = aft1 - bef1;
		aft2 = aft2 + bef2;
		bef2 = aft2 - bef2;
	}
	printf("\n");
	return (0);
}
