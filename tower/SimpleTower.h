#ifndef LAB_4_SIMPLETOWER_H
#define LAB_4_SIMPLETOWER_H

#include "Tower.h"

class SimpleTower: Tower {

public:
    int type = 1;

    void level_up() final {}
};


#endif //LAB_4_SIMPLETOWER_H
