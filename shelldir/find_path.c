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
 * @command: the path to track
 *@str: strinf to be duplicated
 *Return: 0 or 1
 */
char *xstrdup(char *str);
int path_tracker( char **command)
{
char *direction;
struct stat buf;
char *cpdirection;
const char *delimiter = ":";
char *final_path;
char *ph;
char final_path[MAX_PATH_LENGTH];
direction = getenv("PATH");
cpdirection = xstrdup(direction);
if (cpdirection == NULL)
{
perror("Memory allocation error");
exit(EXIT_FAILURE);
}
ph = strtok(cpdirection, delimiter);
while (ph != NULL)
{
final_path = compose_path(*command, ph);
if (stat(final_path, &buf) == 0)
{
sep_tok = parse_line(final_path);
while (sep_tok[token_count] != NULL)
{
token_count++;
}
free(*command);
*command = xstrdup(final_path);
free(final_path);
free(cpdirection);
return (0);
}
free(final_path);
ph = strtok(NULL, ":");
}
free(direction);
free(cpdirection);
return (1);
}
