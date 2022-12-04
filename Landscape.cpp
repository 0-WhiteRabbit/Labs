#include "Landscape.h"

Landscape::~Landscape() {
    objects.clear();
    fields.clear();
}

int Landscape::refresh() {
    ++tik;
    int flag = 1;
    for (auto & i: objects) { // refresh
        flag = i.refresh(*this);
        if (flag == 0) {
            return 0;
        }
    }
    return 1;
}

void Landscape::build(const Object& t) {
    objects.push_back(t);
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
