#include <iostream>
#include <cmath>
#include "../train.h"
#include "gtest/gtest.h"


TEST(test_create_empty_train, get_number_of_passenger) {
    Train train;
    ASSERT_DOUBLE_EQ(0, train.number_of_passenger());
}

TEST(test_add_carriage, number_of_passenger) {
    Train train;
    Carriage tmp = {10, 2};
    train.add_carriage(tmp);
    ASSERT_DOUBLE_EQ(2, train.number_of_passenger());
}

TEST(test_add_carriage, wrong_number_of_passenger) {
    Train train;
    Carriage tmp = {10, 2};
    train.add_carriage(tmp);
    try {
        train.reserved_seat(1, 11);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("Exceeded the limit of seats"));
    }
}

TEST(test_reserved_seats, reserved_seats_passenger) {
    Train train;
    Carriage tmp = {10, 2};
    train.add_carriage(tmp);
    train.reserved_seat(1, 5);
    ASSERT_DOUBLE_EQ(7, train.number_of_passenger());
}

TEST(test_del_carriage, del_number_of_passenger) {
    Train train;
    Carriage tmp = {10, 2};
    train.add_carriage(tmp);
    int buf[1] = {0};
    train.change_train(1, buf);
    ASSERT_DOUBLE_EQ(0, train.number_of_passenger());
}

TEST(test_del_carriage, number_of_reserved_seats) {
    Train train;
    Carriage tmp = {10, 2};
    train.add_carriage(tmp);
    int buf[1] = {0};
    train.change_train(1, buf);
    try {
        train.number_of_reserved_seats(1);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("Exceeded the limit of seats"));
    }
}

TEST(test_del_carriage, number_of_reserved_seats_2) {
    Train train;
    Carriage tmp = {10, 2}, tmp1 = {1, 0}, tmp2 = {100, 2};
    train.add_carriage(tmp);
    train.add_carriage(tmp1);
    train.add_carriage(tmp2);
    int buf[2] = {0, 1};
    train.change_train(2, buf);
    ASSERT_DOUBLE_EQ(0, train.number_of_passenger());
}

TEST(exception_test, invalid_seat) {
    Train train;
    try {
        train.reserved_seat(1, 1);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("Exceeded the limit of seats"));
    }
}

GTEST_API_ int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}