#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smpshell.h"

void perform_exit(int status)
{
screen("Exiting the shell...\n");
exit(status);
}
