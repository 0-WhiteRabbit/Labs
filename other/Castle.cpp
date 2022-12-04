#include "Castle.h"

int Castle::bit(int hit) {
    current_stability -= hit;
    return current_stability;
}

int Castle::refresh(Landscape &tmp) {
    if (tmp.tik % 10 == 0 && current_stability < max_stability)
        current_stability += 1;
    return 1;
}
