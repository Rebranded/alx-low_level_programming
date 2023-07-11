#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int ffd);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file that buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer_1;

	buffer_1 = malloc(sizeof(char) * 1024);

	if (buffer_1 == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer_1);
}

/**
 * close_file - Closes file descriptors.
 * @ffd: The file descriptor to be closed.
 */
void close_file(int ffd)
{
	int c;

	c = close(ffd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close ffd %d\n", ffd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a cartain file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If the file_from does not exist or cannot be read - exit code 98.
 * If the file_to cannot be created or written to - exit code 99.
 * If the file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer_1;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer_1 = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer_1, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer_1);
			exit(98);
		}

		w = write(to, buffer_1, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer_1);
			exit(99);
		}

		r = read(from, buffer_1, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer_1);
	close_file(from);
	close_file(to);

	return (0);
}
