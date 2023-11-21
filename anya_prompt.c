#include "anya_shell.h"
/**
* anya_prompt - prints the command prompt on the terminal.
* Return: 1 on success, on error, -1 is returned, and errno
* is set appropriately.
*/
int anya_prompt(void)
{
	char *prompt = "anya_shell$ ";

	return (write(STDOUT_FILENO, prompt, _strlen(prompt)));
}
