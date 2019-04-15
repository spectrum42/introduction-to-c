#include <stdio.h>
#include <stdlib.h>

#include "player.h"

struct player* player_new(char* name) {
    struct player* player = NULL;

    player = calloc(1, sizeof(struct player));
    if(player == NULL) {
        perror(__func__);
        exit(1);
    }
    player->name = name;
    player->level = 1;
    player->health = 10;
    player->max_health = 10;

    return player;
}

void player_free(struct player* player) {
    free(player->name);
    free(player);
}

void player_print(struct player* player) {
    printf("Player name: %s\n", player->name);
    printf("Level: %d\n", player->level);
    printf("Health points: %d/%d\n", player->health, player->max_health);
}
