#ifndef LAB_4_LAND_H
#define LAB_4_LAND_H

#include "Field.h"

//! Класс, описывающий поле
class Land: virtual public Field {

public:
    //! Возвращает тип ячейки = 2
    int type() final {return 2;}
    //! Сообщает, что можно строить башню в данной клетке
    int can_build_tower() override {return 1;}

};


#endif //LAB_4_LAND_H
