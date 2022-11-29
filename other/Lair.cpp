#include "Lair.h"

void Lair::add_enemy(const Enemy& t) {
    queue.push_back(t);
}

void* Lair::lair_refresh(int tik) {
    for (auto & i : queue) {
        if (i.time == tik) {
            return &i;
        }
    }

    return nullptr;
}
