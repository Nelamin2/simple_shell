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
path = malloc(xstrlen(ph) + xstrlen(token) + 2);
length = xstrlen(path);
if (path == NULL)
{
return (NULL);
memset(path, 0, length);
}
path = xstrcat(path, ph);
path = xstrcat(path, "/");
path = xstrcat(path, token);
return (path);
}
