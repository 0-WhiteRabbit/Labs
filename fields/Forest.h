#ifndef LAB_4_FOREST_H
#define LAB_4_FOREST_H

#include "Field.h"

//! Класс, описывающий лес
class Forest: virtual public Field {

public:
    //! Возвращает тип ячейки = 3
    int type() override {return 3;}
};


#endif //LAB_4_FOREST_H
