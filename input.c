// See also: https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

char* input_getline()
{
    char* line = NULL;
    size_t buffer_size = 0;
    ssize_t result;

    result = getline(&line, &buffer_size, stdin);
    if(result < 0)
    {
        perror(__func__);
        exit(1);
    } else if (result > 0) {
        // Remove trailing line break.
        line[result-1] = '\0';
    } 

    return line;
}
