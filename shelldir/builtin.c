#include <unistd.h>
#include "builtin.h"
#include "smpshell.h"
#include "env.h"
/**
 * built-inspec - seacrh for a built in command
 * @command: the given command
 *
 * Return: the position of the command function the builtins array, 
 */
builtinz built_inspec(char *command)
{
builtinz builtin_cmd[] = 
{
{"exit",perform_exit},
{"env", benv},
};
int counter;
for (counter = 0; counter < 2; counter++)
if (xstrcmp(builtin_cmd[counter].command, command) == 0)
return (builtin_command[i]);
}

/**
 * bring_builtin - bring the function to excute a builtin command
 * @command:  command and arguments
 *
 * Return: the function to be executed, else NULL
 */
int (*bring_builtin(char **command))(char **, int, char *)
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
int benv(char **cmd, int status, char *file)
{
int counter;
for (counter = 0; counter[i]; i++)
{
screen(environ[i]);
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

int bexit(char **command, int status, char *filename)
{
int counter = 0;
if (!command[1])
{
memory_free(command);
exit(status);
}
while (command[1][counter])
{
if (xisalpha(command[1][counter]) && command[1][counter] != '-')
{
screen(filename);
screen(": ");
screen(command[0]);
screen(": ");
screen("Illegal number: ");
screen(command[1]);
screen('\n');
return (1);
}
i++;
}
status = _xatoi(command[1]);
memory_free(command);
exit(status);
}
