#ifndef LAB_4_ENEMY_H
#define LAB_4_ENEMY_H


#include "Object.h"

//! Класс с реализации логики врага
class Enemy: virtual public Object {
private:
    Effect effects = {1, 0, 1}; ///< Эффекты наложенные на врага

    //! Нахождения пути до замка
    int path_dfs(int x, int y, const Object& castle, int** have_been, int limit, Landscape &tmp);
    int hill=0;

public:
    int time=0; ///< Время, когда появляется враг
    int gold=0; ///< золото, которое он несёт

    //! Конструктор, который следует использовать по умолчанию
    Enemy(int init_gold, int init_time, int init_hill): gold(init_gold), time(init_time), hill(init_hill) {}

    //! Получение следующих координат врага
    const int *get_next_pos(Landscape &tmp);

    int type() final {return 2;}

    int refresh(Landscape &tmp) override;
    int bit(int bit_hit) override;
    int get_speed() override;
    void add_effects(Effect _effects) override;
    int get_hill() override {return hill;}
    int get_time() override;
    int get_gold() override {return gold;}
};


#endif //LAB_4_ENEMY_H
