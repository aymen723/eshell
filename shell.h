#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

void execmd(char **argv);
char *get_location(char *command);
void trim(char *str);
char *find_path(const char *command);
void print_environment();