#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

void execmd(char **argv){
    char *command = NULL, *actual_command = NULL;
    pid_t child_pid;

    if (argv){
        command = argv[0];

        actual_command = find_path(command);

        if (actual_command == NULL) {
            printf("Command not found: %s\n", command);
            return;
        }
    
        child_pid = fork();

        if (child_pid < 0) {
          
            perror("Error:");
            return;
        }
        else if (child_pid == 0) {
           
            if (execve(actual_command, argv, NULL) == -1){
                perror("Error:");
            }
        }
        else {
           
            int status;
            wait(&status);
        }
    }
}
