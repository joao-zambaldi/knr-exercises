#include <stdio.h>

void print_hhist_line(char* label, double value, int histlen, int filllen)
{
	int j;
	
	printf("%-10s [", label);

	for (j = 0; j < histlen; ++j)
		if (j < filllen)
			putchar('#');
		else
			putchar(' ');

	printf("] %6.1lf\n", value);
}

void hhist(char** labels, double* values, int count, int term_w)
{
	int i, fill_len, hist_len;
	double max;

	hist_len = term_w - 20;

	max = 0;
	for (i = 0; i < count; ++i)
		if (values[i] > max)
			max = values[i];

	for (i = 0; i < count; ++i) {
		fill_len = (values[i] / max) * hist_len;
		print_hhist_line(
			labels[i], 
			values[i], 
			hist_len, 
			fill_len
		);
	}

}

