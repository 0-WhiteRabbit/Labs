#ifndef LAB_4_ROAD_H
#define LAB_4_ROAD_H


#include "Field.h"


class Road: virtual public Field {

public:
    int type() override {return 1;}
    int can_build_tower() override {return 0;}
    int can_go() override {return 1;}
    ~Road() = default;
};


#endif //LAB_4_ROAD_H
