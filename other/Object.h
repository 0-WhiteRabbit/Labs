#ifndef LAB_4_OBJECT_H
#define LAB_4_OBJECT_H

class Landscape;

#include "../Landscape.h"

//! Структура для описания эффектов
/*!
 *  slowdown - замежление, всегда >1, по умолчанию 1.
 *  poisoning - отравление, всегда >0 по умолчанию 0.
 *  weakening - ослабление, всегда >1 по умолчанию 1.
 */
struct Effect {
    int slowdown; ///< множитель используется при расчёте скорости врагов
    int poisoning; ///< каждый ход у врага отнимается такое количество жизней, какой на нём poisoning
    int weakening; ///< Урон получаемый врагом умножается на значение weakening

    //! Складывается уже имеющийся эффект врага и нанесённый башней
    Effect operator+(const Effect& a) const {
        return {a.slowdown + slowdown, a.poisoning + poisoning, a.weakening + weakening};
    }
};

//! Класс радитель для всех объектов
/*!
 *  Является родителем для Castle, Enemy, Lair, Tower
 */
class Object {
public:
    int x=0, y=0; ///< Координаты объекта

    //! Возвращает тип объекта, переопределяется в наследниках
    virtual int type() {return 0;}

    //! Функция для обновления состояния объекта, переопределяется в наследниках
    virtual int refresh(Landscape &tmp) {return 1;}

    //! Функция для добавления эффектов врагу, переопределяется в Enemy
    virtual void add_effects(Effect _effects) {}

    //! Функция для получения скорости врага, переопределяется в Enemy
    virtual int get_speed() {return 0;}

    //! Функция для получения урона, переопределяется в Enemy, Castle
    virtual int bit(int hit) {return 0;}

    //! Получение здоровья врага, переопределяется в Enemy
    virtual int get_hill() {return 0;}

    //! Добавление врага в логово, переопределяется в Lair
    virtual void add_enemy(Object *t) {}

    //! Получение времени, когда следует выпускать врага, переопределяется в Enemy
    virtual int get_time() {return -1;}

    //! Получение золота, которое несёт враг, переопределяется в Enemy
    virtual int get_gold() {return 0;}
};

#endif //LAB_4_OBJECT_H
