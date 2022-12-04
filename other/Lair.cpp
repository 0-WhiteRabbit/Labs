#include "Lair.h"

void Lair::add_enemy(const Enemy& t) {
    queue.push_back(t);
}

void Lair::lair_refresh(Landscape &tmp) {
    for (auto & i : queue) {
        if (i.time == tmp.tik) {

        }
    }
}
