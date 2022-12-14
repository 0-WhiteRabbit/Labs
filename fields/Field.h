#ifndef LAB_4_FIELD_H
#define LAB_4_FIELD_H

//! Класс, описывающий ячейку игрового поля
class Field {
public:
    //! Возвращает тип ячейки
    virtual int type()=0;
    //! Возвращает 1, если башня может быть построена (стоит на поле), 0 - нельзя строить
    virtual int can_build_tower() {return 0;}
    //! Возвращает 1, если можно ходить, 0 - нельзя ходить. Для врагов.
    virtual int can_go() {return 0;}
    virtual ~Field() = default;

};


#endif //LAB_4_FIELD_H
