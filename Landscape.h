#ifndef LAB_4_LANDSCAPE_H
#define LAB_4_LANDSCAPE_H

#include "fields/Field.h"
#include "Enemie.h"
#include "tower/Tower.h"


class Landscape{

private:
    Enemie *enemies;
    Field *fields;

public:
    int n, m;

    ~Landscape();
    Landscape(int init_n, int init_m): n(init_n), m(init_m) {}

    void refresh();
    void build(Tower t, int x, int y);
    void set_field(int n, int m, Field);
    void check_correct();

};


#endif //LAB_4_LANDSCAPE_H
