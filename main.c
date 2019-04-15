#include <stdio.h>
#include <stdlib.h>

#include "input.h"
#include "player.h"

int main(int argc, char* argv[])
{
    char* line;
    struct player* player = NULL;

    printf("What is your name?\n");
    printf("> ");
    line = input_getline();
    player = player_new(line);
    player_print(player);
    player_free(player);

    return 0;
}
