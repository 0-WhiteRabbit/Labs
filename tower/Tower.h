#ifndef LAB_4_TOWER_H
#define LAB_4_TOWER_H

#include "../other/Object.h"

struct Specification {
    int cost;
    int radius;
    int hit;
    int speed;
};

class Tower {

public:
    int type=0;
    int strategy=0;
    int level=1;
    Specification specification = {10, 1, 1, 1};
    Effect effect = {0,0,0};
    int x=-1, y=-1;

    void level_up() {
        specification.cost += 5;
        specification.radius += 1;
    }
};


#endif //LAB_4_TOWER_H
