#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char *ESCSTR = "\033[0;3";

enum Color
{
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

enum Color argColor(char *colorstr)
{
	enum Color rtcolor;
	if (strcmp(colorstr, "BLACK") == 0)
	{
		rtcolor = BLACK;
	}
	else if (strcmp(colorstr, "RED") == 0)
	{
		rtcolor = RED;
	}
	else if (strcmp(colorstr, "GREEN") == 0)
	{
		rtcolor = GREEN;
	}
	else if (strcmp(colorstr, "YELLOW") == 0)
	{
		rtcolor = YELLOW;
	}
	else if (strcmp(colorstr, "BLUE") == 0)
	{
		rtcolor = BLUE;
	}
	else if (strcmp(colorstr, "MAGENTA") == 0)
	{
		rtcolor = MAGENTA;
	}
	else if (strcmp(colorstr, "CYAN") == 0)
	{
		rtcolor = CYAN;
	}
	else if (strcmp(colorstr, "WHITE") == 0)
	{
		rtcolor = WHITE;
	}
	else if (strcmp(colorstr, "None") == 0)
	{
		rtcolor = None;
	}
	else
	{
		rtcolor = None;
	}
	return rtcolor;
}

void echo(char input[], enum Color color, bool newline)
{
	char *crlf = (newline) ? "\n" : "";
	char escstr[100];

	snprintf(escstr, 100, "%s%d%s", ESCSTR, color, "m");
	char *prefix = (color == None) ? "" : escstr;

	printf("%s%s\033[0m%s", prefix, input, crlf);
}

int parseArgs(int numArgs, char **argv)
{
	if (numArgs == 0)
	{
		printf("Usage: echo <string> <color> <inline>\n");
		return 1;
	}
	else if (numArgs == 1)
	{
		echo(argv[1], None, true);
	}
	else if (numArgs == 2)
	{
		echo(argv[1], argColor(argv[2]), true);
	}
	else if (numArgs == 3)
	{
		echo(argv[1], argColor(argv[2]), false);
	}
	else
	{
		printf("Usage: echo <string> <color> <inline>\n");
		return 1;
	}
	return 0;
}

int main(int argc, char **argv)
{
	int numArgs = argc - 1;
	return parseArgs(numArgs, argv);
}
