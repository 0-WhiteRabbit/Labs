#ifndef LAB_4_MAGICTOWER_H
#define LAB_4_MAGICTOWER_H

#include "Tower.h"

//! Класс, описывающий магическую башню
class MagicTower: public Tower {

private:
    Specification specification = {15, 1, 5, 1}; ///< Параметры для магической башни по умолчанию
    Effect effect = {1,0,1}; ///< Эффекты магической башни по умолчанию

public:
    explicit MagicTower(Effect t) {
        effect = t+effect;
        specification.cost += effect.weakening + effect.slowdown + effect.poisoning -2;
    }

    int type() final {return 13;}
    //! Возвращает параметры магической башни
    Specification get_specification() final { return specification;}
    //! Возвращает эффекты магической башни
    Effect get_effect() override {return effect;}
    //! Устанавливает эффекты магической башни
    void set_Effect(Effect tmp) {effect = effect + tmp;}
};


#endif //LAB_4_MAGICTOWER_H
