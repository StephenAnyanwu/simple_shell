#include "anya_shell.h"

/**
* _getenv - searches the environment list to find the environment variable.
* @env: environment list.
* @var: name of the environment variable.
* Return: pointer to the environment variable.
*/

char *_getenv(char **env, const char *var)
{
	int idx = 0;
	char *tok = NULL;

	while (env[idx])
	{
		/* get the environment variable name */
		tok = strtok(env[idx], "=");
		/* compare environment variable name with the given variable name (var). */
		if (strcmp(tok, var) == 0)
		{
			/* return the environment variable value. */
			return (strtok(NULL, "="));
		}
		idx++;
	}
	return (NULL);
}
