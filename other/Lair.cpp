#include <stdexcept>
#include "Lair.h"

void Lair::add_enemy(Object *t) {
    for (auto & i : queue) {
        if (i->get_time() == t->get_time())
            throw std::invalid_argument("This time all rade have!");
    }
    t->x = x;
    t->y = y;

    queue.push_back(t);
}

void Lair::refresh(Landscape &tmp, int &flag, std::mutex &g_mutex) {
    int k = -1;
    for (int i=0; i < queue.size(); ++i) {
        if (queue[i]->get_time() == tmp.tik) {
            g_mutex.lock(); // lock mutex
            tmp.build(queue[i]);
            g_mutex.unlock();
            k = i;
            break;
        }
    }
    if (k != -1)
        queue.erase(queue.begin() + k);
    flag = 1;
}