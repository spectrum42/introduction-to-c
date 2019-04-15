#ifndef _PLAYER_H
#define _PLAYER_H

struct player
{
    char* name;
    int level;
    int health;
    int max_health;
};

struct player* player_new(char* name);
void player_free(struct player* player);
void player_print(struct player* player);

#endif // _PLAYER_H
