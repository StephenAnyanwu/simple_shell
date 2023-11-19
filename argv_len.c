#include "anya_shell.h"

/**
 * argv_len - calculates the length of a null-terminated
 * array of strings (argv) excluding the null character.
 * @command: null terminated arrya of strings.
 * Return: the calculated length.
*/
int argv_len(char **command)
{
	int i = 0;

	while (command[i] != NULL)
		i++;
	return (i);
}
