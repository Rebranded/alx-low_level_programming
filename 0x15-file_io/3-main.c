#include "main.h"

/**
 * The Entry point of the program.
 *
 * This function is the starting point of the program execution.
 * It validates command-line arguments, calls the copy_file function,
 * and returns an appropriate exit code.
 *
 * @param argc number of command-line arguments.
 * @param argv array of command-line argument strings.
 * @return Exit code: 0 on success, 97 for incorrect arguments,
 *         98 for read error, 99 for write error, 100 for close error.
 */


const char *file_from;
const char *file_to;
int result;

int main(int argc, char *argv[]) 
{
	if (argc != 3) 
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	file_from = argv[1];
	file_to = argv[2];

	result = copy_file(file_from, file_to);
	return (result);
}
