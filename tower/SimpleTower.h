#ifndef LAB_4_SIMPLETOWER_H
#define LAB_4_SIMPLETOWER_H

#include "Tower.h"

class SimpleTower: Tower {

public:
    int type = 1;
    Specification specification = {10, 1, 10, 60}; // specification: 0 - cost, 1 - radius, 2 - hit, 3 - speed
};


#endif //LAB_4_SIMPLETOWER_H
