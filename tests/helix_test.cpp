#include <helix.h>
#include <point.h>
#include <gtest/gtest.h>
#define _USE_MATH_DEFINES
#include <cmath>

TEST(HelixTest, ZeroRadius) {
    Helix h(0, 0);
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(0));
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(M_PI_2));
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(M_PI));
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(3 * M_PI_2));
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(2 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(7 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(99 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), h.GetPoint(100 * M_PI));
}

TEST(HelixTest, NoneZerosRadius) {
    Helix h(2, 10);
    EXPECT_EQ(Point(2, 0, 0), h.GetPoint(0));
    EXPECT_EQ(Point(0, 2, 2.5), h.GetPoint(M_PI_2));
    EXPECT_EQ(Point(-2, 0, 5), h.GetPoint(M_PI));
    EXPECT_EQ(Point(0, -2, 7.5), h.GetPoint(3 * M_PI_2));
    EXPECT_EQ(Point(2, 0, 10), h.GetPoint(2 * M_PI));
    EXPECT_EQ(Point(-2, 0, 35), h.GetPoint(7 * M_PI));
    EXPECT_EQ(Point(-2, 0, 495), h.GetPoint(99 * M_PI));
    EXPECT_EQ(Point(2, 0, 500), h.GetPoint(100 * M_PI));
}

TEST(HelixTest, NoneZerosRadiusDerivative) {
    Helix h(2, M_PI);
    EXPECT_EQ(Point(0, 2, 0.5), h.GetDerivative(0));
    EXPECT_EQ(Point(-2, 0, 0.5), h.GetDerivative(M_PI_2));
    EXPECT_EQ(Point(0, -2, 0.5), h.GetDerivative(M_PI));
    EXPECT_EQ(Point(2, 0, 0.5), h.GetDerivative(3 * M_PI_2));
    EXPECT_EQ(Point(0, 2, 0.5), h.GetDerivative(2 * M_PI));
    EXPECT_EQ(Point(0, -2, 0.5), h.GetDerivative(7 * M_PI));
    EXPECT_EQ(Point(0, -2, 0.5), h.GetDerivative(99 * M_PI));
    EXPECT_EQ(Point(0, 2, 0.5), h.GetDerivative(100 * M_PI));
}
