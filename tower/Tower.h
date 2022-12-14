#ifndef LAB_4_TOWER_H
#define LAB_4_TOWER_H

#include "../other/Object.h"

//! Структура, описывающая параметры башни: стоимость постройки, радиус действия, наносимый врагу урон, скорость стрельбы
struct Specification {
    int cost;
    int radius;
    int hit;
    int speed;
};

//! Класс, описывающий башню
class Tower: virtual public Object {

private:
    Specification specification = {10, 1, 1, 1}; ///< Параметры башни по умолчанию
    Effect effect = {0,0,0}; ///< Эффекты башни, постоянное значение

public:
    int strategy=0; ///< Стратегия башни
    int level=1; ///< Уровень башни

    //! Повышение уровня: увеличение радиуса на 1, стоимости на 5
    void level_up() {
        specification.cost += 5;
        specification.radius += 1;
    }

    //! Возвращает параметры башни
    virtual Specification get_specification() { return specification;}
    int type() override {return 10;}
    int refresh(Landscape &tmp) final;
    //! Выбирает стратегию башни
    int strategy_comparator(Object& a1, Object& a2, int tower_x, int tower_y) const;
    //! Возвращает эффекты башни
    virtual Effect get_effect() {return effect;}
};


#endif //LAB_4_TOWER_H
