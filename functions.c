#include "anya_shell.h"
/**
 * _strlen - a function that returns the length of a string.
 * @s: a pointer to the string.
 * Return: returns integer (string length).
*/
int _strlen(char *s)
{
	int str_len = 0;

	while (*s)
	{
		s++;
		str_len++;
	}
	return (str_len);
}

/**
 * anya_print - prints a string on the stdout.
 *@str: the string to be printed.
*/
int anya_print(char *str)
{
	int len = _strlen(str);

	return (write(STDIN_FILENO, str, len));
}

/**
 * _strcpy - copies a string.
 * @dest:destination.
 * @src: source.
 * Return: the pointer to dest.
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - a function that concatenates two strings.
 * @first: the first string.
 * @sec: the second string.
 * Return: returns the concatenated strings.
*/
char *_strcat(char *first, char *sec)
{
	int first_len = 0, sec_len = 0, i;

	for (i = 0; first[i]; i++)
		first_len++;
	for (i = 0; sec[i]; i++)
		sec_len++;
	for (i = 0; i <= sec_len; i++)
		first[first_len + i] = sec[i];
	return (first);
}

