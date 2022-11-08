#ifndef LAB_4_LAIR_H
#define LAB_4_LAIR_H

#include <vector>
#include "Field.h"
#include "../Enemie.h"


class Lair: Field {

private:
    std::vector <Enemie> queue;

public:
    int type=3;
    int can_build_tower=1;

    void add_enemie(Enemie t);
    Enemie refresh();
    Enemie get_next_enemie();
};


#endif //LAB_4_LAIR_H
