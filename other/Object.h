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

private:
    int hill=0;

public:
    int x=0, y=0;

    virtual int type() {return 0;}
    virtual int refresh(Landscape &tmp) {return 1;}
    virtual void add_effects(Effect _effects) {}
    virtual int get_speed() {return 0;}
    virtual int bit(int hit) {return 0;}
    virtual int get_hill() {return hill;}
    virtual void add_enemy(Object *t) {}
    virtual int get_time() {return -1;}
    virtual void set_time(int t) {}
    virtual int get_gold() {return 0;}
};

#endif //LAB_4_OBJECT_H
