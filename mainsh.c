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
char line[256];
while (1)
{
prompt_always_on();
read_line(line);
run_command(line);
}
return (0);
}
