#include <string.h>
/**
 * rm_nline - Removes the command
 * @line: command line
 * Return: input without newline
 */
char *rm_nline(char *line)
{
char *tmp;
tmp= line;
tmp = strtok(tmp, "\n");
return (tmp);
}
