#ifndef LAB_4_ROAD_H
#define LAB_4_ROAD_H


#include "Field.h"

//! Класс, описывающий дорогу
class Road: virtual public Field {
public:
    //! Возвращает тип ячейки = 1
    int type() override {return 1;}
    //! Сообщает, что враг может двигаться
    int can_go() override {return 1;}
};


#endif //LAB_4_ROAD_H
