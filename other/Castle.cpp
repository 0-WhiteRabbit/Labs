#include "Castle.h"

int Castle::hit_castle(int hit) {
    current_stability -= hit;
    return current_stability;
}

int Castle::refresh(int tik) {
    if (tik % 10 == 0)
        current_stability += 1;
    return 0;
}
