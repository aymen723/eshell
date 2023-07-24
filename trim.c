#include "shell.h" 

void trim(char *str) {
    int start = 0;
    int end = strlen(str) - 1;
    int index = 0;
    int i;

    while (isspace(str[start])) {
        start++;
    }

    while (end >= 0 && isspace(str[end])) {
        end--;
    }

    
    for (i = start; i <= end; i++)
    {
        str[index++] = str[i];
    }

    str[index] = '\0';
}
