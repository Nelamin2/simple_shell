#include <stdio.h>
#include <unistd.h>
#include <ucontext.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include "smpshell.h"
#include <sys/wait.h>
#include "builtin.h"
#include "env.h"
/**
 * main - entry point for code
 *@line: input from user
 *Return: 0
 */

int main(void)
{
int x;
char *arguments[80];
char *command;
char *cmd[] = {"ls", "-l", NULL};
while (1)
{
prompt_always_on();
command = read_line(command);
if (strcmp(command, "exit\n") == 0)
{
perform_exit(0);
}
parse_line(command, arguments);
run_command((const char *)cmd);
path_tracker(command);
}
if (strcmp(command, "env\n") == 0)
{
x = benv();
if (x != -1)
{
screen("[INFO] Successfully printed environment variables.");
}
else
{
screen( "[ERROR] Failed to print environment variables.");
}
printf("[INFO] Program finished.");
}
return(0);
}
