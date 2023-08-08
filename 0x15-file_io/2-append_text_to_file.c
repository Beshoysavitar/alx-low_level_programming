#include "main.h"
/**
 * append_text_to_file - ***
 * @filename: ***
 * @text_content: ***
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t n_written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		n_written = write(fd, text_content, _strlen(text_content));
		if (n_written == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
size_t _strlen(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
