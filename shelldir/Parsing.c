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
 * @input: input command
 * @arguments: array to store command and arguments
 */

void parse_line(const char *line, char *arguments[])
{
int counter = 0;
char *token = strtok((char *)line, " ");
while (token != NULL)
{
arguments[counter++] = token;
token = strtok(NULL, " ");
}
arguments[counter] = NULL;
}

