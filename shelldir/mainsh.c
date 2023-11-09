#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * main - entry point for code
 *@line: input from user
 *Return: 0
 */

int main(void)
{
char *arguments[80];
char line[256];
const char *cmd[] = {"ls", "-l", NULL};
while (1)
{
prompt_always_on();
read_line(line);
parse_line(line, arguments);
run_command(cmd);
path_tracker(line);
}
return (0);
}
