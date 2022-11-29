#ifndef LAB_4_LANDSCAPE_H
#define LAB_4_LANDSCAPE_H

#include "fields/Field.h"
#include "fields/Forest.h"
#include "tower/Tower.h"
#include "other/Enemy.h"
#include "other/Object.h"
#include <vector>


class Landscape{

private:
    std::vector<Tower> towers;
    std::vector<Object> objects;
    std::vector<std::vector<Field>> fields;

    const int* get_x_y_of_tower();
    int strategy_comparator(Object& a1, Object& a2, Tower tmp);
    int path_dfs(int x, int y, const Object& castle, int** have_been,  int limit);
    const int *get_next_pos(const Object &t);

public:
    int n, m;
    int tik=1;

    ~Landscape();
    Landscape(int init_n, int init_m);

    int refresh(); // 0 - if game over
    void build(Tower t);
    void set_field(int n, int m, Field f);
    int check_correct();
};


#endif //LAB_4_LANDSCAPE_H
