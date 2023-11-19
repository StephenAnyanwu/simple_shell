#include "anya_shell.h"

/**
  * get_full_path - get the full path of the a command from
  * the PATH environment variable.
  * @command: argument vector.
  * @var: environment variable.
  * Return: the full path of the command if it exist, NULL if not.
*/
char *get_full_path(char *command, char *var)
{
	int command_len = _strlen(command);
	char *environ_var = NULL;
	char *tok = NULL;
	char *full_path = NULL;
	struct stat statbuf;
	int stat_RV;

	stat_RV = stat(command, &statbuf);
	if (stat_RV == 0)
	{
		full_path = malloc(sizeof(char) * _strlen(command) + 2);
		if (full_path == NULL)
			exit(EXIT_FAILURE);
		_strcpy(full_path, command);
		return (full_path);
	}
	environ_var = malloc(sizeof(char) * _strlen(var) + 2);
	if (environ_var == NULL)
		exit(EXIT_FAILURE);
	_strcpy(environ_var, var);
	tok = strtok(environ_var, ":");
	while (tok != NULL)
	{
		full_path = malloc(sizeof(char) * _strlen(tok) + command_len + 3);
		if (full_path == NULL)
		{
			free(environ_var);
			exit(EXIT_FAILURE);
		}
		_strcpy(full_path, tok);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		stat_RV = stat(full_path, &statbuf);
		/* chaeck if the file path exist */
		if (stat_RV == 0)
		{
			free(environ_var);
			return (full_path);
		}
		tok = strtok(NULL, ":");
	}
	free(full_path);
	free(environ_var);
	return (NULL);
}
