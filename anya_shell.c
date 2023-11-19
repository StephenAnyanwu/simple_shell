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

	printf("alx");	
	if ( ac > 1)
	{
		perror("Error");
		return (-1);
	}
	path = _getenv(env, path_var);
	exec_com(path);
	return (0);
}
