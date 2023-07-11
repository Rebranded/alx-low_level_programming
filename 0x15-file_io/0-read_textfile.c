#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file1 print to STDOUT.
 * @filename: text file being read
 * @letters: the number of letters to be read
 * Return: w- actual number of bytes read and printed successfully
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t ffd;
	ssize_t w;
	ssize_t t;

	ffd = open(filename, O_RDONLY);
	if (ffd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(ffd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(ffd);
	return (w);
}
