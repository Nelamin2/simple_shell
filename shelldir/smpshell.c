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
 *@argv: input from user
 *@argc: number of arguments
 *Return: 0
 */
int main(int argc, char *argv[])
{
int x;
char **sep_tok;
char *line;
while (1)
{
prompt_always_on();
line = read_line();
if (*line == '\n' || *line == '\0')
{}
line = rm_newline(line);
if (strcmp(line, "exit\n") == 0)
{
perform_exit(0);
}
sep_tok = parse_line(line);
if (!sep_tok || !sep_tok[0])
continue;
run_command(sep_tok, argv[0]);
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
memory_free2(tokens);
return (0);
}
