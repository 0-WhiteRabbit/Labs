#include "Tower.h"
#include <cmath>

int Tower::strategy_comparator(Object& a1, Object& a2, int tower_x, int tower_y) const {
    switch (strategy) {
        case 0: { // ближайший к башне
            int dx1 = a1.x - x;
            int dy1 = a1.y - y;
            int dx2 = a2.x - x;
            int dy2 = a2.y - y;
            if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) {
                return 1;
            }
            return 0;
        }
        case 1: { // ближайший к замку
            int dx1 = a1.x - tower_x;
            int dy1 = a1.y - tower_y;
            int dx2 = a2.x - tower_x;
            int dy2 = a2.y - tower_y;
            if ((dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2)) {
                return 1;
            }
            return 0;
        }
        case 2: { // наиболее слабый
            if (a1.get_hill() < a2.get_hill()) {
                return 1;
            }
            return 0;
        }
        case 3: { // наиболее сильный
            if (a1.get_hill() > a2.get_hill()) {
                return 1;
            }
            return 0;
        }
        case 4: { // наиболее быстрый
            if (a1.get_speed() < a2.get_speed()) {
                return 1;
            }
            return 0;
        }
        default:
            return 0;
    }
}

int Tower::refresh(Landscape &tmp) {
    int target = -1;
    for (int j = 0; j < tmp.objects.size(); ++j) {
        if (tmp.objects[j]->type() == 2) {
            int dx = x - tmp.objects[j]->x;
            int dy = y - tmp.objects[j]->y;
            double dl = sqrt(dx * dx + dy * dy);
            if (dl <= specification.radius) {
                if (target == -1 || strategy_comparator(*tmp.objects[j], *tmp.objects[target], x, y)) {
                    target = j;
                }
            }
        }
    }

    if (tmp.objects[target]->bit(specification.hit) <= 0) {
        tmp.objects.erase(tmp.objects.begin() + target);
    } else {
        tmp.objects[target]->add_effects(effect);
    }
    return 1;
}
