#include "shell.h"

/**
 * _execute - Excutes commands contained
 *            in the args list
 * @args: List conataining tokenized user input
*/
void _execute(char* args[]) 
{
    pid_t child;
    child = fork();
    if (pid == 0) {
        if (execve(args[0], args) == -1) {
            perror("Command execution failed");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Fork error");
    } else {
        wait(NULL);
    }
}