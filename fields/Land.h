#ifndef LAB_4_LAND_H
#define LAB_4_LAND_H

#include "Field.h"


class Land: public Field {

public:
    int type() override {return 4;}
    int can_build_tower() override {return 1;}
    int can_go() override {return 0;}

};


#endif //LAB_4_LAND_H
