#include "anya_shell.h"

/**
 * main - a custom shell program.
 * @ac: command line argument count.
 * @av: commmand line argument vector.
 * @env: environment variables.
 * Return: always 0 on success.
*/
int main(int ac, char **av, char **env)
{
	const char *path_var = "PATH";
	char *path = NULL;

	if (ac > 1)
	{
		printf("anya_shell$: %s: No such file or directory\n", av[ac - 1]);
		return (-1);
	}
	path = _getenv(env, path_var);
	execute_command(env, path);
	return (0);
}
