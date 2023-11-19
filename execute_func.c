#include "anya_shell.h"

/**
 * exec_com - executes a command pass in the terminal.
 * @path_var: PATH environment variable.
 * Return : 0 on success, other value if error.
 */
int exec_com(char *path_var)
{
	/* counts how any times we run command on the p */
	unsigned long int prompt_count = 1;
	int non_iteractive = 0;
	char *command;
	/* a null_terminated array of strings/poineters */
	char **argv = NULL, **argv_formatted = NULL;
	int i;
	int wstatus, execve_RV;
	char *command_fullpath = NULL;
	pid_t fork_RV;
	int isatty_RV;

	while (1 && !non_iteractive)
	{
		/* check if we are in non-interactive mode */
		isatty_RV = isatty(STDIN_FILENO);
		if (isatty_RV == 0)
			non_iteractive = 1;
		/* display my custom shell prompt */
		anya_prompt();
		/* read command entered by the user */
		command = read_com();
		argv = malloc(sizeof(char *) * _strlen(command) + 2);
		/* null terminaed array of strings */
		argv = _argv(command);
		command_fullpath = get_full_path(argv[0], path_var);
		if (command_fullpath == NULL)
		{
			printf("anya_shell$: %lu: %s: not found\n", prompt_count, argv[0]);
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
		/* child process */
		fork_RV = fork();
		if (fork_RV == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (fork_RV == 0)
		{
			execve_RV = execve(argv_formatted[0], argv_formatted, NULL);
			if (execve_RV == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&wstatus);
			prompt_count++;
		}
	}
	return (0);
}
