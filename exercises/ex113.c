/*
 * Exercise 1-13. Write a program to print a histogram of the lengths 
 * of words in its input. It is esy to draw the histogram with the bars 
 * horizontal; a vertical orientation is more challenghing.
 *
 * Compile with:
 * 	gcc -Ilib exercises/ex113.c lib/histogram.c -o build/ex113
 */

#include <stdio.h>
#include <histogram.h>

#define IN 1
#define OUT 0

int char_isws(char c)
{
	return c == ' ' || c == '\t' || c == '\n';
}

int main(int argc, char** argv)
{
	int i, c, state, len;

	char* labels[11] = {
		"1", "2", "3", "4", "5",
		"6", "7", "8", "9", "10",
		"10+"
	};

	double values[] = {
		0.0, 0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0, 0.0,
		0.0
	};

	len = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (state == IN && char_isws(c)) {
			state = OUT;
			if (len <= 10)
				++values[len - 1];
			else
				++values[10];
			len = 0;
		}
		if (state == OUT && !char_isws(c))
			state = IN;
		if (state == IN)
			++len;
	}

	hhist(labels, values, 11, 72);
	putchar('\n');

	vhist(values, 11);
	putchar('\n');

	return 0;
}

