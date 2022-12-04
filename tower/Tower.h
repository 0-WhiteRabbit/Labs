#ifndef LAB_4_TOWER_H
#define LAB_4_TOWER_H

#include "../other/Object.h"

struct Specification {
    int cost;
    int radius;
    int hit;
    int speed;
};

class Tower: virtual Object {

public:
    int type=10;
    int strategy=0;
    int level=1;
    Specification specification = {10, 1, 1, 1};
    Effect effect = {0,0,0};
    int x=-1, y=-1;

    void level_up() {
        specification.cost += 5;
        specification.radius += 1;
    }

    int refresh(Landscape &tmp);

    int strategy_comparator(Object& a1, Object& a2, int tower_x, int tower_y) const;
};


#endif //LAB_4_TOWER_H
