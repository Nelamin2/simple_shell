#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * parse_line - tokenizes input into command and arguments
 * @line: input command
 * @arguments: array to store command and arguments
 * Return: input
 */
char **parse_line( char *line)
{
int counter = 0;
char **sep_tok;
char *tmp;
char *token;
sep_tok = malloc(sizeof(char *) * _strlen(line));
if (!sep_tok)
{
screen("allocation error\n");
exit(EXIT_FAILURE);
}
tmp = strdup(line);
token = strtok((char *)tmp, " ");
for (i = 0; token; i++)
{
sep_tok[i] = strdup(token);
sep_tok = strtok(NULL, " ");
}
sep_tok[i] = NULL;
free(temp);
return (sep_tok);
}
