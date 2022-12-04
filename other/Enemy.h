#ifndef LAB_4_ENEMY_H
#define LAB_4_ENEMY_H

#include "Object.h"


class Enemy: virtual Object {

private:
    Effect effects = {0, 0, 0};
    int path_dfs(int x, int y, const Object& castle, int** have_been, int limit, Landscape &tmp);
    const int *get_next_pos(Landscape &tmp);

public:
    int time=0;
    int gold=0;
    int type=2;
    int hill=0;

    Enemy(int init_gold, int init_time, int init_hill): gold(init_gold), time(init_time), hill(init_hill) {}

    int refresh(Landscape &tmp);
    int bit(int bit_hit);
    int get_speed();
    void add_effects(Effect _effects);
};


#endif //LAB_4_ENEMY_H
