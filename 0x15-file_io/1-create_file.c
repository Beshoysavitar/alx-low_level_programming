#include "main.h"
/**
 * create_file - ***
 *
 * @text_content: ***
 * @filename: ***
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int open = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	int write = write(o, text_content, len);
	int l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	if (open == -1 || write == -1)
		return (-1);

	close(open);

	return (1);
}
