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
/**
 * main - entry point for code
 *@argv: input from user
 *@argc: number of arguments
 *Return: 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
int x;
char *sep_tok;
char *line;
int (*builtin)(char **, int, char *);
x = 0;
while (1)
{
prompt_always_on();
line = read_line();
if (*line == '\n' || *line == '\0')
{}
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
return (0);
}
