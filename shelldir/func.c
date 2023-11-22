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
 * memory_free - Free a pointer
 *
 * @p: Pointer to free
 **/
void memory_free(char *p)
{
if (p != NULL)
{
free(p);
p = NULL;
}
p = NULL;
}


/**
 * memory_free2 - Free a double pointer
 *@p: Double pointer to free
 **/
void memory_free2(char **p)
{
char **tmp;
tmo = p;
for (; *tmp != NULL; tmp++)
memory_free(*tmp);
free(p);
}


/**
 * xatoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int xatoi(char *s)
{
int sign = 1, i = 0;
unsigned int res = 0;
while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
i++;
}
while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
{
res = (res * 10) + (s[i] - '0');
i++;
}
res *= sign;
return (res);
}

/**
 * xisalpha - checks for alphabetic character
 * @c: the character to be checked
 * Return: 1 if c is a letter, 0 otherwise
 */
int xisalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
