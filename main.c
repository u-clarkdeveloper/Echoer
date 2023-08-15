#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char *ESCSTR = "\033[0;3";

enum Color {
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	None
};

enum Color argColor(char *colorstr) {
	enum Color rtcolor;
	if (strcmp(colorstr, "BLACK")) {
		rtcolor = BLACK;
	} else 
	return rtcolor;
}

void echo(char input[],enum Color color,bool newline) {
	char *crlf = (newline) ? "\n": "";
	char escstr[100];

	snprintf(escstr, 100, "%s%d%s", ESCSTR, color, "m");
	char *prefix = (color == None) ? "" : escstr;
	
	printf("%s%s\033[0m%s",prefix, input, crlf);
}


int main(int argc, char **argv) {
	enum Color argcolor = argColor(argv[2]);
	echo(argv[1], argcolor, argv[3]);
	return 0;
}

