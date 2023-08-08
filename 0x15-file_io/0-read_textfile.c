#include "main.h"
/**
 * read_textfile - ***
 * @filename: ***
 * @letters: ***
 * Return: ***
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t n_r, n_w;
	int f;
	char *buf;

	if (filename == NULL)
		return (0);

	f = open(filename, O_RDONLY);

	if (f == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
		return (0);

	n_r = read(f, buf, letters);

	if (n_r == -1)
		return (0);

	n_w = write(STDOUT_FILENO, buf, n_r);

	if (n_w == -1 || n_w != n_r)
		return (0);

	free(buf);
	close(f);
	return (n_w);
}
