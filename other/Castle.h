#ifndef LAB_4_CASTLE_H
#define LAB_4_CASTLE_H

#include "Object.h"

//! Класс с реализации логики замка
class Castle: public Object {
public:
    int max_stability = 0; ///< Максимальное здоровье
    int current_stability = 0; ///< Текущее здоровье

    //! Конструктор по умолчанию
    explicit Castle(int new_max_stability): max_stability(new_max_stability), current_stability(new_max_stability) {}

    int bit(int hit) override;
    int type() final {return 1;}
    int refresh(Landscape &tmp) final;
};


#endif //LAB_4_CASTLE_H
