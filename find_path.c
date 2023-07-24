#include "shell.h"

char *find_path(const char *command) {
    char *path = getenv("PATH");
    char *path_copy = strdup(path);

    char *dir = strtok(path_copy, ":");
    while (dir != NULL) {
        char *full_path = malloc(strlen(dir) + strlen(command) + 2);
        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
