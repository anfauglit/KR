#include <stdio.h>
#define MAXLINE 80 /* maximum input line length */
// remove empty lines and trailing white characters

int Getline(char line[], const int maxline);
void copy(char to[], const char from[]);

int main() {
	int len; /* current line length */
	int max; /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */
	char longest[MAXLINE]; /* longest line saved here */
	max = 0;

	while ((len = Getline(line, MAXLINE)) > 0)
		if (len > 1)
			printf("%s", line);
//	printf("Max str length: %i\n", max);
	return 0;
}

/* Getline: read a line into s, return length */
int Getline(char s[], const int lim) {
	int c, i;
	int lastC = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if (i < lim - 1) {
			if (c != '\t' && c != ' ')
				lastC = i;
			s[i] = c;
		}

	if (c == '\n') {
		++lastC;
		s[lastC] = c;
	}

	if (i < lim - 1)
		s[lastC + 1] = '\0';
	else
		s[lim - 1] = '\0';

	return lastC;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], const char from[]) {
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
