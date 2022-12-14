#ifndef LAB_4_MAGICTRAP_H
#define LAB_4_MAGICTRAP_H

#include "Tower.h"


class MagicTrap: public Tower {

private:
    Specification specification = {5, 1, 0, 30};
    Effect effect = {1,0,1};

public:
    explicit MagicTrap(Effect t) {
        effect = t+effect;
        specification.cost += effect.weakening + effect.slowdown + effect.poisoning -2;
    }

    int type() final {return 12;}
    Specification get_specification() final { return specification;}
    Effect get_effect() override {return effect;}
    void set_Effect(Effect tmp) {effect = effect + tmp;}

};


#endif //LAB_4_MAGICTRAP_H
