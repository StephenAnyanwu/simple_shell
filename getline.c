#include "anya_shell.h"

/**
  * anya_getline - reads a line from the terminal and stores it in a buffer.
  * It append a newline character at the end of the read line.
  * See man getline for more information.
  * @buffer: Pointer to the buffer where the line will be stored
  * @stream: Pointer to the stream where the line will be read from.
  * @n: Size of the buffer
  * Return: The number of characters read not including the null byte,
  * -1 on failure.
*/
ssize_t anya_getline(char **buffer, size_t *n, FILE *stream)
{
	int cha, position = 0;
	int  buf_size = 128;

	if (!buffer || !n || !stream)
		return (-1);
	/* initialized buffer size */
	/* allocate memory for buffer */
	*buffer = malloc(sizeof(char) * buf_size);
	if (*buffer == NULL)
		return (-1);
	/* Read characters from the stream and store in the buffer */
	while ((cha = fgetc(stream)) != EOF && cha != '\n')
	{
		(*buffer)[position++] = (char)cha;
		/* reallocate buffer with a larger size if it is full */
		if (position == buf_size - 1)
		{
			buf_size *= 2;
			*buffer = realloc(*buffer, buf_size);
		}
		/* if reallocation fails */
		if (*buffer == NULL)
			return (-1);
	}
	(*buffer)[position] = '\n';
	position++;
	(*buffer)[position] = '\0';
	*n = buf_size;
	/* return the number of characters read */
	return (position);
}
