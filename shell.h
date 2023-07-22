#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void print_error(char *msg);
char *_getline(void);
char *_strtok(char *str, const char *delim);
char *_strcpy(char *dest, char *src);
int  _strcmp(char *str1, char *str2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strtok(char *str, const char *delim);
char *_strdup(const char *str);
#endif
