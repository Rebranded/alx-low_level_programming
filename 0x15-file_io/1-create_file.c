#include "main.h"

/**
 * create_file - Creates a new file.
 * @filename: A pointer to the name of the file to  be created.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails  display - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int ffd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	ffd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(ffd, text_content, len);

	if (ffd == -1 || w == -1)
		return (-1);

	close(ffd);

	return (1);
}
