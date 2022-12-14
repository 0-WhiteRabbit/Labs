#ifndef LAB_4_LAIR_H
#define LAB_4_LAIR_H


#include <vector>
#include "../Landscape.h"
#include "Object.h"


class Lair: public Object {

private:
    Vector<Object*> queue;

public:
    Lair() = default;

    ~Lair() {
        for (int i=0; i<queue.size(); ++i) {
            delete queue[i];
            queue[i] = NULL;
        }

        queue.clear();
    }

    int type() override {return 3;}
    void add_enemy(Object *t) override;
    int refresh(Landscape &tmp) override;
};


#endif //LAB_4_LAIR_H
