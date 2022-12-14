#include "Tower.h"
#include <cmath>

int Tower::strategy_comparator(Object& a1, Object& a2, int tower_x, int tower_y) const {
    switch (strategy) {
        case 0: { // ближайший к башне
            int dx1 = abs(a1.x - x);
            int dy1 = abs(a1.y - y);
            int dx2 = abs(a2.x - x);
            int dy2 = abs(a2.y - y);
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
            if (abs((dx1 * dx1 + dy1 * dy1)) < abs((dx2 * dx2 + dy2 * dy2))) {
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
    if (tmp.tik % specification.speed != 0) {
        return 1;
    }

    int target = -1;
    for (int j = 0; j < tmp.objects.size(); ++j) {
        if (tmp.objects[j]->type() == 2) {
            int dx = abs(x - tmp.objects[j]->x);
            int dy = abs(y - tmp.objects[j]->y);
            double dl = sqrt(dx * dx + dy * dy);
            if (dl <= specification.radius) {
                if (target == -1 || strategy_comparator(*tmp.objects[j], *tmp.objects[target], x, y)) {
                    target = j;
                }
            }
        }
    }

    if (target != -1 && tmp.objects[target]->bit(specification.hit) <= 0) {
        tmp.gold += tmp.objects[target]->get_gold();
        tmp.objects.erase(tmp.objects.begin() + target);
    } else if (target != -1) {
        tmp.objects[target]->add_effects(get_effect());
    }
    return 1;
}
