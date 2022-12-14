#ifndef LAB_4_CASTLE_H
#define LAB_4_CASTLE_H

#include "Object.h"


class Castle: public Object {

public:
    int max_stability = 0;
    int current_stability = 0;
    int gold=0;

    Castle(int new_max_stability): max_stability(new_max_stability), current_stability(new_max_stability) {}

    int bit(int hit) override;
    int type() final {return 1;}
    int refresh(Landscape &tmp) final;
};


#endif //LAB_4_CASTLE_H
