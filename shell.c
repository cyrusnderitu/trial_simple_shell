#include "shell.h"

/**
 * main - Main function to initiate shell
 * Return: 0 on success
*/

int main(void)
{
	char *commands = NULL, **input_list;
	char PATH[100] = "/bin/";
	int status;

	while (1)
	{
		commands = _getline();
		if (commands)
		{
			input_list = _strtok(commands, " ");
			if (!input_list)
			{
				free(commands);
				continue;
			}
			if ((!_strcmp(input_list[0], "exit")) && input_list[1] == NULL)
			{
				free(input_list);
				break;
			}
			else
			{
				_strcat(PATH, input_list[0])
				if (stat(PATH, &st) != 0)
					perror("Could not find file");
				else
				{
					input_list[0] = PATH;
					child = fork();
				}
				if (pid == 0)
				{
					execve(input_list[0], input_list, NULL);
					exit(1);
				}
				else if (pid > 0)
				{
					wait(&status);
				}
				else
				{
					print_error("fork failed");
					exit(1);
				}
			}
			free(input_list);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(1);
		}
		free(commands);
	}
	return (0);
}
