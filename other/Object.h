#ifndef LAB_4_OBJECT_H
#define LAB_4_OBJECT_H


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

    virtual int refresh(int tik) {return 0;}
    virtual void* lair_refresh(int tik) {return nullptr;}
    virtual int get_speed() {return 0;}
    virtual int bit(int bit_hit) {return 0;}
    virtual void add_effects(Effect _effects) {}
};

#endif //LAB_4_OBJECT_H
