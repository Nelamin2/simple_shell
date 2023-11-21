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
 * compose_path - create the poth for a given command
 * @token: the given command
 * @ph: the path to build for @token
 *
 * Return: @value/@token - the path of command
 */

char *compose_path(char *token, char *ph)
{
char *path;
size_t length;
length = strlen(path);
path = malloc(strlen(ph) + strlen(command) + 2);
if (path == NULL)
{
return (NULL);
memset(path, 0, length);
path = strcat(path, ph);
path = strcat(path, "/");
path = strcat(path, token);
return (path);
}
