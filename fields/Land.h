#ifndef LAB_4_LAND_H
#define LAB_4_LAND_H

#include "Field.h"


class Land: virtual public Field {

public:
    int type() final {return 2;}
    int can_build_tower() override {return 1;}
    int can_go() override {return 0;}
    ~Land() = default;

};


#endif //LAB_4_LAND_H
