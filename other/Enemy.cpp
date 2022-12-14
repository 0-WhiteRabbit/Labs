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
    for (auto & object : tmp.objects) {
        if (object->type() == 1) {
            tmp1 = object;
        }
    }

    if (tmp1->x == x && tmp1->y == y) {
        if (tmp1->bit(hill) <= 0) {
            return 0;
        }
        return 2;
    }
    return 1;
}

int Enemy::bit(int bit_hit) {
    hill -= bit_hit*effects.weakening;
    return hill;
}

int Enemy::get_speed() {
    return 2*effects.slowdown;
}

void Enemy::add_effects(Effect _effects) {
    effects = effects + _effects;
}

int Enemy::path_dfs(int x, int y, const Object& castle, int** have_been, int limit, Landscape &tmp) {
    have_been[x][y] = tmp.n*tmp.m+10;
    ++limit;
    if (limit > tmp.n*tmp.m) {
        return 0;
    }
    if (x == castle.x && castle.y == y) {
        have_been[x][y] = limit+1;
        return 1;
    }

    int flag = 0;
    if (x+1 < tmp.n && tmp.fields[x+1][y]->can_go() && !have_been[x+1][y]) {
        flag = path_dfs(x+1, y, castle, have_been, limit, tmp);
    }
    if (y+1 < tmp.m && tmp.fields[x][y+1]->can_go() && !have_been[x][y+1]) {
        flag = path_dfs(x, y+1, castle, have_been, limit, tmp);
    }
    if (x-1 >= 0 && tmp.fields[x-1][y]->can_go() && !have_been[x-1][y]) {
        flag = path_dfs(x-1, y, castle, have_been, limit, tmp);
    }
    if (y > 0 && tmp.fields[x][y-1]->can_go() && !have_been[x][y-1]) {
        flag = path_dfs(x, y-1, castle, have_been, limit, tmp);
    }

    if (flag == 1)
        have_been[x][y] = limit+1;
    return flag;
}


const int *Enemy::get_next_pos(Landscape &tmp) {
    int *pos = new int[2];
    int **have_been = new int*[tmp.n];
    Object *tmp1;
    for (int i=0; i < tmp.objects.size(); ++i) {
        if (tmp.objects[i]->type() == 1) {
            tmp1 = tmp.objects[i];
        }
    }

    for (int i=0; i < tmp.n; ++i) {
        have_been[i] = new int[tmp.m];
        for (int j=0; j < tmp.m; ++j) {
            have_been[i][j] = 0;
        }
    }

    path_dfs(x, y, *tmp1, have_been, 0, tmp);

    int min_l = tmp.n*tmp.m+10;
    pos[0] = x;
    pos[1] = y;

    if (x+1 < tmp.n && tmp.fields[x+1][y]->can_go()) {
        min_l = have_been[x+1][y];
        pos[0] = x+1;
        pos[1] = y;
    }
    if (y+1 < tmp.m && tmp.fields[x][y+1]->can_go() && min_l > have_been[x][y+1]) {
        min_l = have_been[x][y+1];
        pos[0] = x;
        pos[1] = y+1;
    }
    if (x-1 >= 0 && tmp.fields[x-1][y]->can_go() && min_l > have_been[x-1][y]) {
        min_l = have_been[x-1][y];
        pos[0] = x-1;
        pos[1] = y;
    }
    if (y-1 >= 0 && tmp.fields[x][y-1]->can_go() && min_l > have_been[x][y-1]) {
        min_l = have_been[x][y-1];
        pos[0] = x;
        pos[1] = y-1;
    }

    for (int i=0; i < tmp.n; ++i) {
        delete[] have_been[i];
    }
    delete[] have_been;

    return pos;
}

int Enemy::get_time() {
    return time;
}

void Enemy::set_time(int t) {
    time = t;
}
