#ifndef LAB_4_LANDSCAPE_H
#define LAB_4_LANDSCAPE_H

class Object;

#include "fields/Field.h"
#include "fields/Forest.h"
#include "other/Object.h"
#include <vector>


class Landscape{

public:
    std::vector<Object> objects;
    int n, m;
    int tik=1;

    ~Landscape();
    Landscape(int init_n, int init_m);

    int refresh(); // 0 - if game over
    void build(const Object& t);
    void set_field(int n, int m, Field f);
    int check_correct();

    std::vector<std::vector<Field>> fields;
};


#endif //LAB_4_LANDSCAPE_H
