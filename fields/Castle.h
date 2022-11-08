#ifndef LAB_4_CASTLE_H
#define LAB_4_CASTLE_H


class Castle {

public:
    char *name;
    int max_stability = 0;
    int curent_stability = 0;
    int gold = 0;

    Castle(char *init_name, int new_max_stability): name(init_name), max_stability(new_max_stability), curent_stability(new_max_stability) {}

    int hit_castle(int hit);
};


#endif //LAB_4_CASTLE_H
