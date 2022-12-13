#ifndef LAB_4_MAGICTRAP_H
#define LAB_4_MAGICTRAP_H

#include "Tower.h"


class MagicTrap: public Tower {

private:
    Specification specification = {5, 1, 0, 30};

public:
    int type() final {return 12;}
    Specification get_specification() final { return specification;}

};


#endif //LAB_4_MAGICTRAP_H
