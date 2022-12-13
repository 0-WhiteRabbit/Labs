#include <stdexcept>
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
        }
    }
    return 1;
}

void Landscape::build(Object* t) {
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
    for (int i=0; i < objects.size(); ++i) {
        if (objects[i]->type() == 1) {
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
