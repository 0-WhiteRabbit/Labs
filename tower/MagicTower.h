#ifndef LAB_4_MAGICTOWER_H
#define LAB_4_MAGICTOWER_H

#include "Tower.h"


class MagicTower: public Tower {

private:
    Specification specification = {15, 1, 5, 1};

public:
    int type() final {return 13;}
    Specification get_specification() final { return specification;}

};


#endif //LAB_4_MAGICTOWER_H
