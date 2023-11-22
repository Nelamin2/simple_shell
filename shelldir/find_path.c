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
 * @path: the path to track
 *@str: strinf to be duplicated
 *Return: NULL.
 */
char *xstrdup(char *str);
int *path_tracker(const char **path)
{
char *direction;
char *cpdirection;
const char *delimiter = ":";
char *path;
char final_path;
struct stat buffer;
char *ph;
path = NULL;
direction = getenv("PATH");
if (direction == NULL)
{
screen("PATH environment variable not found\n");
return (NULL);
}
cpdirection = xstrdup(direction);
if (cpdirection == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
ph = strtok(cpdirection, delimiter);
while (ph != NULL)
{
final_path = compose_path(*path, ph);
if (stat(final_path, &buf) == 0)
{
*path = xstrdup(final_path);
free(final_path);
return (0);
}
free(final_path);
ph = strtok(NULL, ":");
free(direction);
free(cpdirection);
}
return (1);
}
