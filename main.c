#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "input.h"
#include "player.h"
#include "room.h"

int main(int argc, char* argv[])
{
    char* line;
    struct player* player = NULL;
    struct room rooms[] = {
        {.title = "Cave Entrance"},
        {"Dark Passageway", 15},
        {"Dragon's Lair", 30},
        {"Treasure Room", 50},
    };
    bool playing = true;

    int current_room = 0;
    int num_rooms = sizeof(rooms) / sizeof(struct room);
    int gold = 0;

    printf("What is your name?\n");
    printf("> ");
    line = input_getline();
    player = player_new(line);
    printf(
        "Welcome to the tutorial dungeon! There are %d rooms to explore.\n",
        num_rooms);
    player_print(player);
    while(playing) {
        printf("> ");
        line = input_getline();
        if(strcasecmp("quit", line) == 0) {
            playing = false;
        } else if(strcasecmp("go", line) == 0) {
            current_room++;
            if(current_room >= num_rooms) {
                printf("Dungeon complete! You collected %d gold.\n", gold);
                playing = false;
            } else {
                printf(" ** %s **\n", rooms[current_room].title);
                printf("Collected %d gold.\n", rooms[current_room].gold);
                gold += rooms[current_room].gold;
            }
        } else if(strcasecmp("status", line) == 0) {
            player_print(player);
        } else if(strcasecmp("help", line) == 0) {
            printf("Available commands:\n");
            printf("    status - Show player status.\n");
            printf("    help   - Show this help screen.\n");
            printf("    go     - Go to the next room.\n");
            printf("    quit   - Exit the program.\n");
        } else {
            printf("Unknown command. Type \"help\" for help, \"quit\" to exit the program.\n");
        }
        free(line);
    }
    player_free(player);

    return 0;
}
