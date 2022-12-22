#include "Castle.h"

int Castle::bit(int hit) {
    current_stability -= hit;
    return current_stability;
}

void Castle::refresh(Landscape &tmp, int &flag, std::mutex &g_mutex) {
    if (tmp.tik % 10 == 0 && current_stability < max_stability)
        current_stability += 1;
    flag = 1;
}
