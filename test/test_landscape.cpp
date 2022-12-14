#include <iostream>

#include "CastleTest.h"
#include "../tower/SimpleTower.h"


//Landscape tests
TEST(set_fields, test_Field) {
    Landscape t(10, 10);
    const Land *tmp1 = new Land();
    t.set_field(0, 0, (Field *) tmp1);
    ASSERT_EQ(1, t.fields[0][0]->can_build_tower());
}

TEST(set_wrong_fields, test_Field) {
    Landscape t(10, 10);
    const Land *tmp1 = new Land();
    try {
        t.set_field(110, 0, (Field *) tmp1);
    }
    catch (std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("Wrong x, y!"));
    }
    delete tmp1;
}

TEST(check_correct_field, test_Field) {
    Landscape t(5, 5);
    Field *tmp1 = new Road();
    t.set_field(0, 0, (Field *) tmp1);
    auto castle = Castle(10);
    castle.x = 0;
    castle.y = 0;
    t.build((Object *) &castle);
    ASSERT_EQ(t.check_correct(), 1);
}

//Enemy test
TEST(check_type, test_Enemy) {
    Enemy tmp = Enemy(10, 0, 10);
    ASSERT_EQ(tmp.type(), 2);
}

TEST(kill_enemy, test_Enemy) {
    Enemy tmp = Enemy(10, 0, 11);
    ASSERT_EQ(tmp.bit(11), 0);
}

TEST(add_affect, test_Enemy) {
    Enemy tmp = Enemy(10, 0, 11);
    tmp.add_effects({10,0,0});
    ASSERT_EQ(tmp.get_speed(), 22);
}

//test refresh
TEST_F(CastleTest, test_refrash) {
    ASSERT_EQ(1, landscape.refresh());
}

//test lair
TEST_F(CastleTest, test_spawn) {
    auto *t = new Enemy(10, 10, 10);
    lair->add_enemy(t);
    for (int i=0; i<10; ++i) {
        landscape.refresh();
    }
    int k = landscape.objects[2]->type();
    delete t;
    ASSERT_EQ(2, k);
}

TEST_F(CastleTest, test_find_path) {
    auto *t = new Enemy(10, 10, 10);
    landscape.build(t);
    const int *xy = t->get_next_pos(landscape);
    int x = xy[0];
    int y = xy[1];
    delete[] xy;
    delete t;
    ASSERT_EQ(0, x);
    ASSERT_EQ(1, y);
}

TEST_F(CastleTest, test_shoot) {
    auto *t = new Enemy(10, 10, 20);
    t->x = 0;
    t->y = 1;
    auto *tower = new SimpleTower();
    tower->x = 1;
    tower->y = 1;
    landscape.build(tower);
    landscape.build(t);
    landscape.refresh();
    landscape.refresh();
    int k = t->get_hill();
    delete t;
    delete tower;
    ASSERT_EQ(19, k);
}


GTEST_API_ int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}