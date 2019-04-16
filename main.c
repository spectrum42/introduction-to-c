#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "input.h"
#include "player.h"

int main(int argc, char* argv[])
{
    char* line;
    struct player* player = NULL;
    bool playing = true;

    printf("What is your name?\n");
    printf("> ");
    line = input_getline();
    player = player_new(line);
    player_print(player);
    while(playing) {
        printf("> ");
        line = input_getline();
        if(strcasecmp("quit", line) == 0) {
            playing = false;
        } else {
            printf("Unknown command. Type \"quit\" to exit the program.\n");
        }
    }
    player_free(player);

    return 0;
}
