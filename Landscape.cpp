#include <stdexcept>
#include <iostream>
#include "Landscape.h"

Landscape::~Landscape() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            delete fields[i][j];
        }
        fields[i].clear();
    }

    fields.clear();
    objects.clear();
}

int Landscape::refresh() {
    ++tik;
    int flag = 1;
    for (int i=0; i < objects.size(); ++i) { // refresh
        flag = objects[i]->refresh(*this);
        if (flag == 0) {
            return 0;
        } else if (flag == 2) {
            objects.erase(objects.begin() + i);
        }
    }
    return 1;
}

void Landscape::build(Object* t) {
    if (t->x > n || t->y > m || t->x < 0 || t->y < 0)
        throw std::invalid_argument("Wrong x, y!");
    if ((t->type() == 1 || t->type() == 3) && fields[t->x][t->y]->type() != 1)
        throw std::invalid_argument("You can build castle or lair only on road!");
    if (t->type() > 9 && fields[t->x][t->y]->type() != 2)
        throw std::invalid_argument("You can build tower only on land!");
    if (t->type() == 2 && fields[t->x][t->y]->type() != 1)
        throw std::invalid_argument("You can build enemy only on road!");

    if (t->type() == 1 || t->type() == 3 || t->type() > 9) {
        for (auto & object : objects) {
            if (object->x == t->x && object->y == t->y) {
                throw std::invalid_argument("This space not empty!");
            }
        }
    }

    objects.push_back(t);
}

void Landscape::set_field(int x, int y, Field* tmp) {
    if (x > n || y > m || x < 0 || y < 0) {
        throw std::invalid_argument("Wrong x, y!");
    }
    delete fields[x][y];
    fields[x][y] = tmp;
}

int Landscape::check_correct() {
    int num_of_castle=0;
    for (auto & object : objects) {
        if (object->type() == 1) {
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
        fields.push_back({});
        fields[i].reserve(m);
        for (int j=0; j < m; ++j) {
            Field *tmp2 = new Forest;
            fields[i].push_back(tmp2);
        }
    }
}
