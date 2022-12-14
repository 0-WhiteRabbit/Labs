#ifndef LAB_4_MAGICTOWER_H
#define LAB_4_MAGICTOWER_H

#include "Tower.h"


class MagicTower: public Tower {

private:
    Specification specification = {15, 1, 5, 1};
    Effect effect = {1,0,1};

public:
    explicit MagicTower(Effect t) {
        effect = t+effect;
        specification.cost += effect.weakening + effect.slowdown + effect.poisoning -2;
    }

    int type() final {return 13;}
    Specification get_specification() final { return specification;}
    Effect get_effect() override {return effect;}
    void set_Effect(Effect tmp) override {effect = effect + tmp;}
};


#endif //LAB_4_MAGICTOWER_H
