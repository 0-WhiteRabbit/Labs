#ifndef LAB_4_FIELD_H
#define LAB_4_FIELD_H


class Field {
public:
    virtual int type() {return 0;}
    virtual int can_build_tower() {return 0;}
    virtual int can_go() {return 0;}

};


#endif //LAB_4_FIELD_H
