#include "smpshell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void run_command(const char *line) {
    char *path;
    char *arguments[20];
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        parse_line(line, arguments);

        if (setenv("MY_VARIABLE", "Hello, World!", 1) != 0) {
            perror("Error setting environment variable");
            exit(EXIT_FAILURE);
        }
        path = path_tracker(arguments[0]); 
       execve(path, arguments[0], NULL);
        perror("Error in execve");
        exit(EXIT_FAILURE);
    } else {
        int status;
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not exit normally\n");
        }
    }
}

