#ifndef LAB_4_OBJECT_H
#define LAB_4_OBJECT_H

class Landscape;

#include "../Landscape.h"

struct Effect {
    int slowdown;
    int poisoning;
    int weakening;

    Effect operator+(const Effect& a) const {
        return {a.slowdown + slowdown, a.poisoning + poisoning, a.weakening + weakening};
    }
};

class Object {

public:
    int x=0, y=0;
    int type=0;
    int hill=0;

    virtual int refresh(Landscape &tmp) {return 1;}
    virtual void lair_refresh(Landscape &tmp) {}
    virtual void add_effects(Effect _effects) {}
    virtual int get_speed() {return 0;}
    virtual int bit(int hit) {return 0;}
};

#endif //LAB_4_OBJECT_H
