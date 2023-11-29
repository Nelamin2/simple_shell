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
#include <ctype.h>

/**
 * is_whitespace- check if the input a whitespace
 *@str: input string
 *Return: 0 incase there's a whitspace
 *else 1
 */

int is_whitespace(const char *str)
{
while (*str)
{
if (!isspace(*str))
return (0);
str++;
}
return (1);
}

/**
 * main - entry point for code
 *@argv: input from user
 *@argc: number of arguments
 *Return: 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
int x;
char **sep_tok;
char *line;
int (*builtin)(char **, int, char *);
x = 0;
while (1)
{
prompt_always_on();
line = read_line();
if (*line == '\n' || *line == '\0' || is_whitespace(line))
{
memory_free(line);
continue;
}
line = rm_nline(line);
sep_tok = parse_line(line);
if (!sep_tok || !sep_tok[0])
continue;
builtin = bring_builtin(sep_tok);
if (builtin)
{
x = builtin(sep_tok, x, argv[0]);
memory_free2(sep_tok);
continue;
}
else
x = run_command(sep_tok, argv[0]);
memory_free2(sep_tok);
}
return (0);
}
