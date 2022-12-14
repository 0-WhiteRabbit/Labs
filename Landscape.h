#ifndef LAB_4_LANDSCAPE_H
#define LAB_4_LANDSCAPE_H

class Object;

#include "fields/Field.h"
#include "fields/Forest.h"
#include "other/Object.h"
#include "vector/Vector.h"

//! Класс с реализации игрового поля
/*!
 *  Здесь реализована основная логика этапа редактирования поля и строительство башен
 */
class Landscape {
public:
    Vector<Object*> objects; ///< Вектор с объектами на поле
    Vector<Vector<Field*>> fields; ///< Двумерный вектор размером n на m с типом полей
    int n, m;
    int tik=1;
    int gold=100;
    ~Landscape();

    Landscape(int init_n, int init_m);

    //! Функция, обновляющая все объекты на поле, если возвращает 0, то игра окончена
    int refresh();
    void build(Object* t);
    void set_field(int x, int y, Field* f);

    //! Функция проверки поля на корректность
    int check_correct();
};


#endif //LAB_4_LANDSCAPE_H
