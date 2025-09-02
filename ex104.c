/*
 * Exercise 1-4. Write a program that prints the corresponding Celsius
 * to Fahrenheit table.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	int lower, upper, step;
	float fahr, celsius;	

	lower = -20;
	upper = 50.0;
	step = 5;

	printf("Celsius-Fahrenheit conversion table:\n");

	celsius = lower;
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * celsius + 32.0;
		printf("%6.1f %6.1f\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}
