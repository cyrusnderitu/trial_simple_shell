#include "shell.h"

/**
 * _getline - Fetch input from user by getline
 * Return: Input info.
 */
char *_getline(void)
{
	char *lineptr = NULL;
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#S-shell$ ", 10);

	if (getline(&lineptr, &len, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
