#include <iostream>
#include <cmath>
#include "../line.h"
#include "gtest/gtest.h"


TEST(test_get, get_x_test) {
    Line line(10);
    ASSERT_DOUBLE_EQ(10, line.get_x());
}

TEST(test_get_negative, get_x_test) {
    Line line(-1.5);
    ASSERT_DOUBLE_EQ(-1.5, line.get_x());
}

TEST(test_func, get_y_dependence_on_x) {
    Line line(10);
    double y =  sqrt((10.0 + 1.0) / (10.0 - 1.0));
    ASSERT_DOUBLE_EQ(y, line.y_dependence_on_x(1));
}

TEST(test_r_on_phi, get_r_dependence_on_phi) {
    Line line(10);
    double r = -(10*cos(2)/cos(1));
    ASSERT_DOUBLE_EQ(r, line.r_dependence_on_phi(1));
}

TEST(test_r_on_phi_cos_zero, get_r_dependence_on_phi) {
    Line line(10);
    double r = -(10*cos(2)/cos(1));
    ASSERT_DOUBLE_EQ(r, line.r_dependence_on_phi(1));
}

TEST(test_r_on_phi_negative, get_r_dependence_on_phi) {
    Line line(10);
    double r = -(10*cos(1)/cos(0.5));
    ASSERT_DOUBLE_EQ(r, line.r_dependence_on_phi(0.5));
}

TEST(test_func, get_curvature_radius) {
    Line line(10);
    double r = 10.0*sqrt(2);
    ASSERT_DOUBLE_EQ(r, line.curvature_radius());
}

TEST(test_func_radius_negative, get_curvature_radius) {
    Line line(-10);
    double r = 10.0*sqrt(2);
    ASSERT_DOUBLE_EQ(r, line.curvature_radius());
}

TEST(test_func, get_loop_area) {
    Line line(10);
    double s = 2.0*10.0*10.0 - 0.5*M_PI*10.0*10.0;
    ASSERT_DOUBLE_EQ(s, line.loop_area());
}

TEST(test_area, get_volume_x) {
    Line line(10);
    double v = M_PI*10.0*10.0*10.0*(2*log(2) - 4.0/3.0);
    ASSERT_DOUBLE_EQ(v, line.volume_x());
}

TEST(test_area_negative, get_volume_x) {
    Line line(-10);
    double v = M_PI*10.0*10.0*10.0*(2*log(2) - 4.0/3.0);
    ASSERT_DOUBLE_EQ(v, line.volume_x());
}

TEST(test_volume, get_volume) {
    Line line(10);
    double v = 2*10.0*10.0 + 0.5*M_PI*10.0*10.0;
    ASSERT_DOUBLE_EQ(v, line.volume());
}

TEST(test_volume_negative, get_volume) {
    Line line(-17.5);
    double v = 2*17.5*17.5 + 0.5*M_PI*17.5*17.5;
    ASSERT_DOUBLE_EQ(v, line.volume());
}

TEST(exception_test, divizion_by_zero) {
    Line line(1);
    try {
        line.y_dependence_on_x(1);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("Division by zero. X can't equal a!"));
    }
}


TEST(exception_test, sqrt_from_negative) {
    Line line(1);
    try {
        line.y_dependence_on_x(2);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(), std::string("sqrt received negative argument!"));
    }
}

GTEST_API_ int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}