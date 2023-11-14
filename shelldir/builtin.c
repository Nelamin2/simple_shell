#include <unistd.h>
#include "builtin.h"
#include "smpshell.h"
#include "env.h"
int benv(void)
{
int counter;
char *var;
char *value;
char **env_var;
env_var = environ;
if (env_var == NULL)
{
screen("[ERROR] Failed to retrieve environment variables.");
return -1;
}
for (counter= 0; env_var[counter] != NULL; counter++)
{
var = strtok(env_var[counter], "=");
value = strtok(NULL, "=");
printf("%s=%s\n", var, value);
}
return (0);
}        
