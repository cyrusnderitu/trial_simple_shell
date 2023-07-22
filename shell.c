#include "shell.h"

/**
 * main - Main function to initiate shell
 * Return: 0 on success
*/

int main(void)
{
	char *commands = NULL, *input_list[100];
	char *token;
	int status = 0, i = 0;

	do
	{
		commands = _getline();
		fflush(stdout);

		if (commands)
		{
			status = 1;
			token = _strtok(commands, " ");
			while (token != NULL)
			{
				input_list[i] = token;
				i++;
				token = _strtok(NULL, " ");
			}
			input_list[i] = NULL;
			if ((_strcmp(input_list[0], "exit")) && input_list[1] == NULL)
			{
				free(commands);
				break;
			}
			else if (_strcmp(input_list[0], "cd") == 0) 
			{
            	if (input_list[1] != NULL) 
				{
                 	if (chdir(input_list[1]) == -1)
					{
                        perror("cd");
                    }
                }
                continue;
            }
			if(status)
			{
                pid_t pid = fork();
                if (pid == 0)
				{
                	_execute(input_list);
                	exit(EXIT_SUCCESS);
                } else if (pid > 0)
				{
					wait(NULL);
				}else
				{
            	  	_execute(input_list);
            	}
			}
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(1);
		}
		free(commands);
	} while(1);
	return (0);
}