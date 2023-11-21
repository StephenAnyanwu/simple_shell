#include "anya_shell.h"

/**
 * process - runs process.
 * @c: command pathname.
 * @av: a null-terminated array of string with the first
 * items equal c while other items are command arguments.
 * @env: environment.
 * Return: 0 on success, -1 on failure.
*/
int process(char *c, char **av, char **env)
{
	pid_t fork_RV;
	int wstatus;

	fork_RV = fork();
	if (fork_RV == -1)
	{
		perror("Error");
		return (-1);
	}
	if (fork_RV == 0)
		_execve(c, av, env);
	else
		wait(&wstatus);
	return (0);
}
