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
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_LENGTH 1024
int main(void)
{
int x;
char *arguments[80];
char *line;
char *cmd[] = {"ls", "-l", NULL};
while (1)
{
prompt_always_on();
line = read_line();
line = rm_newline(line);
if (strcmp(line, "exit\n") == 0)
{
perform_exit(0);
}
parse_line(command, arguments);
path_tracker(command);
run_command((const char *)cmd);
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
screen("[ERROR] Failed to print environment variables.");
}
}
screen("[INFO] Program finished.");
handle_path("add", "/new/directory");
handle_path("remove", "/old/directory");
handle_path("search", "executable");
return (0);
}
