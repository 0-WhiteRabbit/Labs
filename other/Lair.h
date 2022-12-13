#ifndef LAB_4_LAIR_H
#define LAB_4_LAIR_H

#include <vector>
#include "../Landscape.h"
#include "Enemy.h"
#include "Object.h"


class Lair: virtual public Object {

private:
    Vector<Enemy*> queue;

public:
    int can_build_tower=1;

    virtual int type() {return 3;}
    void add_enemy(Enemy *t);
    int refresh(Landscape &tmp) override;
};


#endif //LAB_4_LAIR_H
