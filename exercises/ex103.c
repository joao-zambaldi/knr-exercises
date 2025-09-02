/*
 * Exercise 1-3. Modify the temperature conversion program to print a 
 * heading above the table.
 */

#include <stdio.h>

int main(int argc, char** argv)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fahrenheit-Celsius Conversion Table:\n");

	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%5.1f %6.1f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}

