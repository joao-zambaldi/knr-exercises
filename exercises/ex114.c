/*
 * Eercise 1-14. Write a program to print a histogram of the frequencies
 * of different characters in its input.
 *
 * Compile with:
 * 	gcc -Ilib exercises/ex114.c lib/histogram.c -o build/ex114
 *
 * Note: This solution will print the frequence of chars between
 * 32 and 126 if they have non-zero frequency.
 */

#include <stdio.h>
#include <histogram.h>

int main(int argc, char** argv)
{
	int i, c, count;
	double freqarr[95];
	double values[95];
	char labels[95][2];
	char* label_ptrs[95];

	/* Build all the labels */
	for (i = 0; i < 95; ++i) {
		freqarr[i] = 0;
		labels[i][0] = i + 32;
		labels[i][1] = 0;
	}

	/* 
	 * Counts the frequence of chars between 32 and 126 (inclusive)
	 * in the input.
	 */
	while ((c = getchar()) != EOF)
		if (c >= 32 && c <= 126)
			++freqarr[c - 32];

	/*
	 * We only want to print a row for a character in the histogram 
	 * if its frequence is not zero. So we go over the frequency
	 * array to find the chars with non-zero frequency. Those are 
	 * added to values and its label to labels_ptrs.
	 */
	count = 0;
	for (i = 0; i < 95; ++i)
		if (freqarr[i] != 0) {
			values[count] = freqarr[i];
			label_ptrs[count] = labels[i];
			++count;
		}


	hhist(label_ptrs, values, count, 72);

	return 0;
}

