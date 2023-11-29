#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smpshell.h"

/**
 * perform_exit- act as exit function
 * @status: exit status
**/
void perform_exit(int status)
{
screen("Exiting the shell...\n");
exit(status);
}
