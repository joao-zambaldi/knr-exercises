#include <stdio.h>

int power(int base, int p);

int main(int argc, char** argv)
{
	int i;

	for (i = 0; i <= 10; ++i)
		printf("%3d\t%5d\t%6d\n", i, power(2, i), power(-3, i));

	return 0;
}

int power(int base, int p)
{
	int i, res;

	res = 1;
	for (i = 1; i <= p; ++i)
		res *= base;

	return res;
}


