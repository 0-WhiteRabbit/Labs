#include "Enemy.h"

int Enemy::refresh(Landscape &tmp) {
    if (tmp.tik % 10 == 0)
        hill -= effects.poisoning;

    if (tmp.tik % get_speed() == 0) {
        const int *t = get_next_pos(tmp);
        x = t[0];
        y = t[1];
        delete[] t;
    }

    Object *tmp1;
    for (auto & j: tmp.objects) {
        if (j.type == 1) {
            tmp1 = &j;
        }
    }

    if (tmp1->x == x && tmp1->y == y) {
        if (tmp1->bit(hill) <= 0) {
            return 0;
        }
    }
    return 1;
}

int Enemy::bit(int bit_hit) {
    hill -= bit_hit;
    return hill;
}

int Enemy::get_speed() {
    return 60 * effects.slowdown;
}

void Enemy::add_effects(Effect _effects) {
    effects = effects + _effects;
}

int Enemy::path_dfs(int x, int y, const Object& castle, int** have_been, int limit, Landscape &tmp) {
    have_been[x][y] = 1;
    ++limit;
    if (limit > tmp.n*tmp.m) {
        return 0;
    }
    if (x == castle.x && castle.y == y) {
        return 1;
    }

    int flag = 0;
    if (x+1 < tmp.n && tmp.fields[x+1][y].can_go && !have_been[x+1][y]) {
        flag = path_dfs(x+1, y, castle, have_been, limit, tmp);
    }
    if (y < tmp.m && tmp.fields[x][y+1].can_go && !have_been[x][y+1]) {
        flag = path_dfs(x, y+1, castle, have_been, limit, tmp);
    }
    if (x-1 >= 0 && tmp.fields[x-1][y].can_go && !have_been[x-1][y]) {
        flag = path_dfs(x-1, y, castle, have_been, limit, tmp);
    }
    if (y >= 0 && tmp.fields[x][y-1].can_go && !have_been[x][y-1]) {
        flag = path_dfs(x, y-1, castle, have_been, limit, tmp);
    }

    return flag;
}

const int *Enemy::get_next_pos(Landscape &tmp) {
    int *pos = new int[2];
    int **have_been = new int*[tmp.n];
    Object *tmp1;
    for (auto & i: tmp.objects) {
        if (i.type == 1) {
            tmp1 = &i;
        }
    }
    for (int i=0; i < tmp.n; ++i) {
        have_been[i] = new int[tmp.m];
        for (int j=0; j < tmp.m; ++j) {
            have_been[i][j] = 0;
        }
    }

    path_dfs(x, y, *tmp1, have_been, 0, tmp);

    return pos;
}
