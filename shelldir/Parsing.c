#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "smpshell.h"
/**
 * parse_line - tokenizes command and arguments
 * @line: input command
 * Return: user input
 */

char **parse_line(char *line)
{
int counter;
char **sep_tok;
char *tmp;
char *token;
int x;
counter = 0;
x = xstrlen(line);
sep_tok = (char **) malloc(sizeof(char *) * x);
if (!sep_tok)
{
screen("allocation error\n");
exit(EXIT_FAILURE);
}
tmp = xstrdup(line);
token = strtok((char *)tmp, " ");
while (token)
{
sep_tok[counter++] = xstrdup(token);
token = strtok(NULL, " ");
}
sep_tok[counter] = NULL;
free(tmp);
return (sep_tok);
}
