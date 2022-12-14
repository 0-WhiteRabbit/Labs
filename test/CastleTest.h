#ifndef LAB_4_CASTLETEST_H
#define LAB_4_CASTLETEST_H

#include "gtest/gtest.h"
#include "../Landscape.h"
#include "../fields/Forest.h"
#include "../fields/Land.h"
#include "../fields/Road.h"
#include "../other/Enemy.h"
#include "../other/Castle.h"
#include "../other/Lair.h"


class CastleTest : public ::testing::Test {
public:
    Castle *castle;
    Lair *lair;
    Landscape landscape;

protected:
    CastleTest(): landscape(4, 4) {
        castle = new Castle(10);
        lair = new Lair();

        const Road *tmp0_0 = new Road();
        landscape.set_field(0, 0, (Field *) tmp0_0);
        const Road *tmp0_1 = new Road();
        landscape.set_field(0, 1, (Field *) tmp0_1);
        const Road *tmp0_2 = new Road();
        landscape.set_field(0, 2, (Field *) tmp0_2);
        const Road *tmp1_2 = new Road();
        landscape.set_field(1, 2, (Field *) tmp1_2);
        const Road *tmp2_2 = new Road();
        landscape.set_field(2, 2, (Field *) tmp2_2);
        const Road *tmp3_2 = new Road();
        landscape.set_field(3, 2, (Field *) tmp3_2);
        const Land *tmp0_3 = new Land();
        landscape.set_field(0, 3, (Field *) tmp0_3);
        const Land *tmp1_3 = new Land();
        landscape.set_field(1, 3, (Field *) tmp1_3);
        const Land *tmp2_3 = new Land();
        landscape.set_field(2, 3, (Field *) tmp2_3);
        const Land *tmp3_3 = new Land();
        landscape.set_field(1, 1, (Field *) tmp3_3);

        castle->x = 3;
        castle->y = 2;
        landscape.build((Object *) castle);

        lair->x = 0;
        lair->y = 0;
        landscape.build((Object *) lair);
    }

    ~CastleTest() {
        delete castle;
        delete lair;
    }

    void SetUp() override {

    }
};


#endif //LAB_4_CASTLETEST_H
