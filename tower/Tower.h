#ifndef LAB_4_TOWER_H
#define LAB_4_TOWER_H


class Tower {

public:
    int type=0;
    int strategy=0;
    int level=1;
    int specification[4] = {0, 0, 0, 0};
    int effect = 0;

    virtual void level_up(){};
};


#endif //LAB_4_TOWER_H
