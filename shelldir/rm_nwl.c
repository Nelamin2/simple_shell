#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * remove_newline - read user's input
 *@line: input string
 * Return: input without new linw
 *
 */void remove_newline(char *line) {
size_t size = strlen(line);
if (size > 0 && line[size - 1] == '\n')
{
line[size - 1] = '\0';
}
