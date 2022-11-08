#ifndef LAB_4_ENEMIE_H
#define LAB_4_ENEMIE_H


class Enemie {

private:
    int hill=0;
    int effects[3] = {0, 0, 0};

public:
    int time;
    int gold=0;

    Enemie(int init_gold, int init_time, int init_hill): gold(init_gold), time(init_time), hill(init_hill) {}

    int refresh();
    int bit();
};


#endif //LAB_4_ENEMIE_H
