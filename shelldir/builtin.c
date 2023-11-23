#include <unistd.h>
#include "builtin.h"
#include "smpshell.h"
/**
 * built-inspec - seacrh for a built in command
 * @command: the given command
 *
 * Return: the position of the command function the builtins array, 
 */
builtinz built_inspec(char *command)
{
builtinz builtin_command[] = 
{
{"exit",bexit},
{"env", benv},
};
int counter;
for (counter = 0; counter < 2; counter++)
if (xstrcmp(builtin_command[counter].command, command) == 0)
return (builtin_command[counter]);
}

/**
 * bring_builtin - bring the function to excute a builtin command
 * @command:  command and arguments
 *
 * Return: the function to be executed, else NULL
 */
int (*bring_builtin(char **command))(char **args, int status, char *filename)
{
builtinz x = built_inspec(command[0]);
if (x.command)
return (x.p);
return (NULL);
}

/**
 * benv_cmd - prints the env variables
 * @command: unused
 * @status: status 
 * @filename: unused
 * Return: Always 0
 */
int benv(char **command, int status, char *file)
{
int counter;
(void) command;
(void) status;
(void) file;
for (counter = 0; environ[counter]; counter++)
{
screen(environ[counter]);
xputchar('\n');
}
return (0);
}

/**
 * bexit- builtin Implementation of exit command
 * @commandd: command
 * @status: the status code
 * Return: exit with the status or
 *  current execution status
 */

int bexit(char **command, int status, char *file)
{
int counter = 0;
if (!command[1])
{
memory_free2(command);
exit(status);
}
while (command[1][counter])
{
if (xisalpha(command[1][counter]) && command[1][counter] != '-')
{
screen(file);
screen(": ");
screen(command[0]);
screen(": ");
screen("Illegal number: ");
screen(command[1]);
xputchar('\n');
return (1);
}
counter++;
}
status = xatoi(command[1]);
memory_free2(command);
exit(status);
}
