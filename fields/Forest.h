#ifndef LAB_4_FOREST_H
#define LAB_4_FOREST_H

#include "Field.h"


class Forest: virtual public Field {

public:
    int type() override {return 3;}
    int can_build_tower() override {return 0;}
    int can_go() override {return 0;}
    ~Forest() = default;;

};


#endif //LAB_4_FOREST_H
