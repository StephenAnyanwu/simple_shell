#include "anya_shell.h"

/**
 * _argv - reads command (and arguments) from
 * the terminal and stores them in null-terminated array.
 * @com: command to be read.
 * Return: a null-terminated array of strings.
*/

char **_argv(char *com)
{
	char **command = NULL;
	int argc = 0;
	char *tok, delim[] = {' ', '\n', '\t'};

	command = malloc(sizeof(char *) * _strlen(com));
	if (command == NULL)
	{
		exit(EXIT_FAILURE);
	}
	tok = strtok(com, delim);
	while (tok != NULL)
	{
		command[argc++] = tok;
		tok = strtok(NULL, delim);
	}
	command[argc] = NULL;
	return (command);
}
