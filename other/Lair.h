#ifndef LAB_4_LAIR_H
#define LAB_4_LAIR_H

#include <vector>
#include "Enemy.h"
#include "Object.h"


class Lair: Object {

private:
    std::vector <Enemy> queue;

public:
    int type=3;
    int can_build_tower=1;

    void add_enemy(const Enemy& t);
    void* lair_refresh(int tik) final;
};


#endif //LAB_4_LAIR_H
