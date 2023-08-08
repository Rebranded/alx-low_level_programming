#include "main.h"


/**
 * Copy the content of one file to another file.
 *
 * @param file_from Source file name.
 * @param file_to Destination file name.
 * @return 0 on success, 97 for incorrect arguments, 98 for read error,
 *         99 for write error, 100 for close error.
 */

int copy_file(const char *file_from, const char *file_to)
{
	int fd_from;
	int fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	ssize_t bytes_written;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return 98;
	}


	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1) {
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		return 99;
	}



	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) 
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1) {
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			return 99;
		}
	}

	if (bytes_read == -1) {
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		return 98;
	}

	if (close(fd_from) == -1 || close(fd_to) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		return 100;
	}

	return 0;
}
