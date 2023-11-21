#include "anya_shell.h"
/**
 * execute_command - executes a command pass in the terminal.
 * @env: environment.
 * @path_var: PATH environment variable.
 * Return: 0 on success, other value if error.
 */
int execute_command(char **env, char *path_var)
{
	unsigned long int prompt_count = 1;
	char *command, **argv = NULL, **argv_formatted = NULL;
	char *command_fullpath = NULL, *shell = "anya_shell";
	int i, non_iteractive = 0, isatty_RV;

	while (1 && !non_iteractive)
	{
		isatty_RV = isatty(STDIN_FILENO);
		if (isatty_RV == 0)
			non_iteractive = 1;
		else
			anya_prompt();
		command = read_command();
		argv = malloc(sizeof(char *) * _strlen(command) + 2);
		argv = _argv(command);
		command_fullpath = get_full_path(argv[0], path_var);
		if (command_fullpath == NULL)
		{
			printf("%s: %lu: %s: not found\n", shell, prompt_count, argv[0]);
			prompt_count++;
			continue;
		}
		else
		{
			argv_formatted = malloc(sizeof(char *) * argv_len(argv) + 2);
			argv_formatted[0] = command_fullpath;
			for (i = 1; i <= argv_len(argv); i++)
				argv_formatted[i] = argv[i];
		}
		process(argv_formatted[0], argv_formatted, env);
		prompt_count++;
	}
	free(command);
	free(argv);
	free(argv_formatted);
	free(command_fullpath);
	return (0);
}
