#include "Enemy.h"

int Enemy::refresh(int tik) {
    if (tik % 10 == 0)
        hill -= effects.poisoning;
    return 0;
}

int Enemy::bit(int bit_hit) {
    hill -= bit_hit;
    return hill;
}

int Enemy::get_speed() {
    return 60 * effects.slowdown;
}

void Enemy::add_effects(Effect _effects) {
    effects = effects + _effects;
}
