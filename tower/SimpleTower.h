#ifndef LAB_4_SIMPLETOWER_H
#define LAB_4_SIMPLETOWER_H

#include "Tower.h"

class SimpleTower: virtual public Tower {

private:
    Specification specification = {10, 1, 10, 1}; // specification: 0 - cost, 1 - radius, 2 - hit, 3 - speed

public:
    int type() final {return 11;}
    Specification get_specification() final { return specification;}
};


#endif //LAB_4_SIMPLETOWER_H
