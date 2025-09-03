#include <stdio.h>
#include <stdlib.h>

double arrmax(double* values, int count)
{
	double max;
	int i;

	for (i = 0; i < count; ++i)
		if (values[i] > max)
			max = values[i];

	return max;
}

void print_hhist_line(char* label, double value, int histlen, int fill_len)
{
	int j;
	
	printf("%-10s [", label);

	for (j = 0; j < histlen; ++j)
		putchar(j < fill_len ? '#' : ' ');

	printf("] %6.1lf\n", value);
}

void hhist(char** labels, double* values, int count, int term_w)
{
	int i, fill_len, hist_len;
	double max;

	hist_len = term_w - 20;
	max = arrmax(values, count);
	for (i = 0; i < count; ++i) {
		fill_len = (values[i] / max) * hist_len;
		print_hhist_line(labels[i], values[i], hist_len, fill_len);
	}
}

void vhist(double* values, int count)
{
	int i, j, hist_height;
	int *hs;
	double max;

	hs = malloc(count * sizeof(int));	
	max = arrmax(values, count);
	hist_height = 10;
	
	/* calculate heights for each columsn */	
	for (i = 0; i < count; ++i)
		hs[i] = (values[i] / max) * hist_height;

	/* print histogram */
	for (i = hist_height + 1; i > 0; --i) {
		for (j = 0; j < count; ++j)
			putchar(i > hs[j] ? ' ' : '#');
		putchar('\n');
	}

	free(hs);
}

