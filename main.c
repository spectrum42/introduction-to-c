#include <stdio.h>
#include <stdlib.h>

#include "input.h"

int main(int argc, char* argv[])
{
    char* line;

    printf("What is your name?\n");
    line = input_getline();
    printf("Hello, %s!\n", line);
    free(line);

    return 0;
}
