#ifndef LAB_4_LANDSCAPE_H
#define LAB_4_LANDSCAPE_H

class Object;

#include "fields/Field.h"
#include "fields/Forest.h"
#include "other/Object.h"
#include "vector/Vector.h"


class Landscape{

public:
    Vector<Object*> objects;
    Vector<Vector<Field*>> fields;
    int n, m;
    int tik=1;
    int gold=100;
    ~Landscape();

    Landscape(int init_n, int init_m);
    int refresh(); // 0 - if game over
    void build(Object* t);
    void set_field(int x, int y, Field* f);

    int check_correct();
};


#endif //LAB_4_LANDSCAPE_H
