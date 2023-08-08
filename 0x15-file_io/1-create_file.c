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
	int op, wr, l;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}
	op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(op, text_content, l);

	if (op == -1 || wr == -1)
		return (-1);

	close(op);

	return (1);
}
