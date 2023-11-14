#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/stat.h>
/**
 * path_tracker- find teh corrct directory
 * @ine: the comand to ftnd the poath for
 * Return: NULL.
 */
 char *path_tracker(const char *command)
{
char *direction; 
char *cpdirection;
const char *delimiter = ":";
char *path;
struct stat buffer;
char *token;
path = NULL;
direction = getenv("PATH");
if (direction == NULL) {
screen("PATH environment variable not found\n");
return NULL;
}
cpdirection = strdup(direction);
if (cpdirection == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
token = strtok(cpdirection, delimiter);
while (token != NULL)
{
path = malloc(strlen(token) + strlen(command) + 2);
if (path == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
strcpy((char *)path, token);
strcat((char *)path, "/");
strcat((char *)path, command);
if (stat(path, &buffer) == 0)
{
free(cpdirection);
return (path);
}
else
{
free(path);
token = strtok(NULL, delimiter);
}
}
free(cpdirection);
return (NULL);
}
