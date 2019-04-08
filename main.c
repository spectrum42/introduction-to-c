// See also: https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char* line = NULL;
    size_t buffer_size = 0;
    ssize_t count;

    printf("What is your name?\n");
    count = getline(&line, &buffer_size, stdin);
    printf("Allocated %zu characters.\n", buffer_size);
    printf("Read %zu characters.\n", count);
    line[count-1] = '\0';
    printf("Hello, %s!\n", line);
    free(line);

    return 0;
}
