#ifndef LAB_4_LAIR_H
#define LAB_4_LAIR_H


#include <vector>
#include "../Landscape.h"
#include "Object.h"


class Lair: public Object {
private:
    Vector<Object*> queue; ///< Очередь на появление из врагов

public:
    Lair() = default;

    ~Lair() {
        for (auto & i : queue) {
            delete i;
            i = nullptr;
        }

        queue.clear();
    }

    int type() override {return 3;}

    //! Добавление врага в очередь
    void add_enemy(Object *t) override;
    int refresh(Landscape &tmp) override;
};


#endif //LAB_4_LAIR_H
