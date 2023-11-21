#ifndef ANYA_SHELL_H
#define ANYA_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
int anya_prompt(void);
char *read_command(void);
char **_argv(char *com);
int argv_len(char **command);
int _execve(char *pathname, char **argv, char **env);
int execute_command(char **env, char *path_var);
int process(char *c, char **av, char **env);
char *get_full_path(char *command, char *var);
ssize_t anya_getline(char **buffer, size_t *n, FILE *stream);
char *_getenv(char **env, const char *var);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *first, char *sec);


#endif
