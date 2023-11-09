#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * path_tracker- find teh corrct directory
 * @line: the comand to ftnd the poath for
 * Return: NULL.
 */
char *path_tracker(char *line)
{
char *direction;
char *cpdirection;
direction = getenv("PATH");
const char *delimiter = ":";
char *token, *full_path;
struct stat buffer;
cpdirection = strdup(direction);
if (cpdirection == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
token = strtok(cpdirection, delimiter);
while (token != NULL)
{
path = malloc(strlen(token) + strlen(line) + 2);
if (path == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
strcpy(path, token);
strcat(path, "/");
strcat(path, line);
if (stat(direction, &buffer) == 0)
{
free(cpdirection);
return (direction);
}
free(path);
token = strtok(NULL, delimiter);
}
free(cpdirection);
return (NULL);
}
