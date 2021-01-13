#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// refarctor and revise the code a bit
// stop printing histogram after reaching the last non-zero value in the array

static void printLine(const int len) {
	for (int i = 0; i < len; ++i)
		printf("#");
}

void printHisto(const int *d) {
	for (int i = 1; i < 20; ++i) {
		printf("%4i: ", i);
		printLine(d[i]);
		printf("\n");
	}
}

void printVertHisto(const int *d) {

	int max = d[0];

	for (int i = 1; i < 20; ++i) {
		if (d[i] > max)
			max = d[i];
	}

	for (int i = 0; i <= max; ++i) {
		for (int j = 1; j < 20; ++j) {
			if (i == max) {
				printf("%3i", j);
				continue;
			}
			if (d[j] >= (max - i))
				printf("  #");
			else
				printf("   ");
		}
		printf("\n");
	}
}

// stdin white space counter program
int main (void)
{
	int len[20] = {0};

	int out = 1;
	int c;
	int l = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			if (out == 0) {
				len[l]++;
				l = 0;
			}
			out = 1;
		}
		else {
			l++;
			out = 0;
		}
	}

	printHisto(len);
	printf("\n");
	printVertHisto(len);

	return 0;
}

