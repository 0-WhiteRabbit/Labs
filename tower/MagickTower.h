#ifndef LAB_4_MAGICKTOWER_H
#define LAB_4_MAGICKTOWER_H

#include "Tower.h"


class MagickTower: Tower {

public:
    int type = 2;

    void level_up() final {}

};


#endif //LAB_4_MAGICKTOWER_H
