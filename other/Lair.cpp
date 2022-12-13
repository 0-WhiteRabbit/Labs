#include "Lair.h"

void Lair::add_enemy(Enemy *t) {
    queue.push_back(t);
}

int Lair::refresh(Landscape &tmp) {
    int k = -1;
    for (int i=0; i < queue.size(); ++i) {
        if (queue[i]->time == tmp.tik) {
            tmp.build(queue[i]);
            k = i;
            break;
        }
    }
    if (k != -1)
        queue.erase(queue.begin() + k);
    return 1;
}
