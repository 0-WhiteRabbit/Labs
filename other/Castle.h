#ifndef LAB_4_CASTLE_H
#define LAB_4_CASTLE_H

#include "Object.h"


class Castle: virtual Object {

public:
    char *name;
    int max_stability = 0;
    int current_stability = 0;
    int gold=0;
    int type=1;

    Castle(char *init_name, int new_max_stability): name(init_name), max_stability(new_max_stability), current_stability(new_max_stability) {}

    int bit(int hit);
    int refresh(Landscape &tmp) final;
};


#endif //LAB_4_CASTLE_H
