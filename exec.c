#include "anya_shell.h"

/**
 * _execve - executes the program referred to by pathname.
 * It replace the calling process with the new program.
 * @pathname: the path to the program to be executed, It is
 * either a binary executable or a script.
 * @argv: a null-terminated array of strings with the first item
 * equals pathname and other items are command linee arguments.
 * @env: a null-terminated array of strings which are the envinment of
 * the program to be executed.
 * Return: nothing on success , -1 on failure.
*/

int _execve(char *pathname, char **argv, char **env)
{
	int execve_RV;

	execve_RV = execve(pathname, argv, env);
	if (execve_RV == -1)
	{
		perror("Error");
		return (-1);
	}
	return (0);
}
