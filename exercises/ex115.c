/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section
 * 1-2 to use a function for conversion.
 *
 * Usaga exemple:
 * 	./ex115 12.43 C
 * 	./ex115 -43.3 F
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

float ctof(float tc); 		/* Celsius to Fahrenheit */
float ftoc(float tf);		/* Fahrenheit to Celsius */

int main(int argc, char** argv)
{
	float temp;
	char unity;
	char* end;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s TEMP UNITY\n", argv[0]);
		return 1;
	}

	errno = 0;
	temp = strtof(argv[1], &end);
	if (end == argv[1] || *end != '\0' || errno == ERANGE) {
		fprintf(
			stderr, 
			"Couldn`t convert \"%s\" to a valid temperature.\n",
			argv[1]
		);
		return 1;
	}
	
	unity = argv[2][0];
	if (unity != 'c' && unity != 'C' && unity != 'f' && unity != 'F') {
		fprintf(stderr, "Unknown unity %c\n", unity);
		return 1;
	}

	switch (unity) {
	case 'c':
	case 'C':
		printf("%f°F\n", ctof(temp));
		break;
	case 'f':
	case 'F':
		printf("%f°C\n", ftoc(temp));
		break;
	}

	return 0;
}

float ctof(float tc)
{
	return (9.0 / 5.0) * tc + 32.0;
}

float ftoc(float tf)
{
	return (5.0 / 9.0) * (tf - 32.0);
}

