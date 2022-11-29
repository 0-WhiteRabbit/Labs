#include <cmath>
#include "Landscape.h"

Landscape::~Landscape() {
    objects.clear();
    fields.clear();
}

int Landscape::refresh() {
    ++tik;
    for (auto & i: objects) {
        if (i.type == 1 || i.type == 2) {
            i.refresh(tik);
        } else if (i.type == 3) {
            auto tmp = (Object *) i.lair_refresh(tik);
            if (tmp != nullptr) {
                objects.push_back(*tmp);
            }
        }
    }

    for (auto & i: towers) {
        int target = -1;
        for (int j=0; j < objects.size(); ++j) {
            if (objects[j].type == 2) {
                int dx = i.x - objects[j].x;
                int dy = i.y - objects[j].y;
                double dl = sqrt(dx*dx + dy*dy);
                if (dl <= i.specification.radius) {
                    if (target == -1 || strategy_comparator(objects[j], objects[target], i)) {
                        target = j;
                    }
                }
            }
        }
        if (objects[target].bit(i.specification.hit) <= 0) {
            objects.erase(objects.begin()+target);
        } else {
            objects[target].add_effects(i.effect);
        }
    }

    for (auto & i: objects) {
        if (i.type == 2) {
            if (tik % i.get_speed() == 0) {
                const int *t = get_next_pos(i);
                i.x = t[0];
                i.y = t[1];
                delete[] t;
            }

            Object *tmp;
            for (auto & j: objects) {
                if (j.type == 1) {
                    tmp = &j;
                }
            }

            if (tmp->x == i.x && tmp->y == i.y) {
                if (tmp->bit(i.hill) <= 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void Landscape::build(Tower t) {
    towers.push_back(t);
}

void Landscape::set_field(int x, int y, Field tmp) {
    fields[x][y] = tmp;
}

int Landscape::check_correct() {
    int num_of_castle=0;
    for (auto & object : objects) {
        if (object.type == 1) {
            ++num_of_castle;
        }
    }

    if (num_of_castle != 1) {
        return 0;
    }

    return 1;
}

Landscape::Landscape(int init_n, int init_m): n(init_n), m(init_m) {
    fields.reserve(n);
    for (int i=0; i < n; ++i) {
        std::vector<Field> tmp;
        tmp.reserve(m);
        for (int j=0; j < m; ++j) {
            tmp.push_back({});
        }
        fields.push_back(tmp);
    }
}

int Landscape::strategy_comparator(Object& a1, Object& a2, Tower tmp) {
    switch (tmp.strategy) {
        case 0: { // ближайший к башне
            int dx1 = a1.x - tmp.x;
            int dy1 = a1.y - tmp.y;
            int dx2 = a2.x - tmp.x;
            int dy2 = a2.y - tmp.y;
            if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) {
                return 1;
            }
            return 0;
        }
        case 1: { // ближайший к замку
            const int *tower_pos = get_x_y_of_tower();
            int dx1 = a1.x - tower_pos[0];
            int dy1 = a1.y - tower_pos[1];
            int dx2 = a2.x - tower_pos[0];
            int dy2 = a2.y - tower_pos[1];
            delete[] tower_pos;
            if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) {
                return 1;
            }
            return 0;
        }
        case 2: { // наиболее слабый
            if (a1.hill < a2.hill) {
                return 1;
            }
            return 0;
        }
        case 3: { // наиболее сильный
            if (a1.hill > a2.hill) {
                return 1;
            }
            return 0;
        }
        case 4: { // наиболее быстрый
            if (a1.get_speed() < a2.get_speed()) {
                return 1;
            }
            return 0;
        }
        default:
            return 0;
    }
}

const int *Landscape::get_x_y_of_tower() {
    int *pos = new int[2];
    for (auto & i: objects) {
        if (i.type == 1) {
            pos[0] = i.x;
            pos[1] = i.y;
            return pos;
        }
    }
    return pos;
}

int Landscape::path_dfs(int x, int y, const Object& castle, int** have_been, int limit) {
    have_been[x][y] = 1;
    ++limit;
    if (limit > n*m) {
        return 0;
    }
    if (x == castle.x && castle.y == y) {
        return 1;
    }

    int flag = 0;
    if (x+1 < n && fields[x+1][y].can_go && !have_been[x+1][y]) {
        flag = path_dfs(x+1, y, castle, have_been, limit);
    }
    if (y < m && fields[x][y+1].can_go && !have_been[x][y+1]) {
        flag = path_dfs(x, y+1, castle, have_been, limit);
    }
    if (x-1 >= 0 && fields[x-1][y].can_go && !have_been[x-1][y]) {
        flag = path_dfs(x-1, y, castle, have_been, limit);
    }
    if (y >= 0 && fields[x][y-1].can_go && !have_been[x][y-1]) {
        flag = path_dfs(x, y-1, castle, have_been, limit);
    }

    return flag;
}

const int *Landscape::get_next_pos(const Object &t) {
    int *pos = new int[2];
    int **have_been = new int*[n];
    Object *tmp;
    for (auto & i: objects) {
        if (i.type == 1) {
            tmp = &i;
        }
    }
    for (int i=0; i < n; ++i) {
        have_been[i] = new int[m];
        for (int j=0; j < m; ++j) {
            have_been[i][j] = 0;
        }
    }

    path_dfs(t.x, t.y, *tmp, have_been, 0);

    return pos;
}


