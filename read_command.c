#include "anya_shell.h"

/**
 * read_com - reads a command from the terminal.
 * Return: a pointer to the read command (string).
*/
char *read_com(void)
{
	char *buf = NULL;
	size_t n = 0;
	int getline_RV;

	getline_RV = anya_getline(&buf, &n, stdin);
	if (getline_RV == -1)
	{
		free(buf);
		exit(EXIT_FAILURE);
	}
	return (buf);
}
