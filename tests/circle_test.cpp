#include <circle.h>
#include <point.h>
#include <gtest/gtest.h>
#define _USE_MATH_DEFINES
#include <cmath>

TEST(CircileTest, ZeroRadiusPoint) {
    Circle c(0);
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(0));
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(M_PI_2));
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(M_PI));
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(3 * M_PI_2));
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(2 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(7 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(99 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), c.GetPoint(100 * M_PI));
}


TEST(CircileTest, NonZeroRadius) {
    Circle c(2);
    EXPECT_EQ(Point(2, 0, 0), c.GetPoint(0));
    EXPECT_EQ(Point(0, 2, 0), c.GetPoint(M_PI_2));
    EXPECT_EQ(Point(-2, 0, 0), c.GetPoint(M_PI));
    EXPECT_EQ(Point(0, -2, 0), c.GetPoint(3 * M_PI_2));
    EXPECT_EQ(Point(2, 0, 0), c.GetPoint(2 * M_PI));
    EXPECT_EQ(Point(-2, 0, 0), c.GetPoint(7 * M_PI));
    EXPECT_EQ(Point(-2, 0, 0), c.GetPoint(99 * M_PI));
    EXPECT_EQ(Point(2, 0, 0), c.GetPoint(100 * M_PI));
}

TEST(CircileTest, NonZeroRadiusDerivative) {
    Circle c(2);
    EXPECT_EQ(Point(0, 2, 0), c.GetDerivative(0));
    EXPECT_EQ(Point(-2, 0, 0), c.GetDerivative(M_PI_2));
    EXPECT_EQ(Point(0, -2, 0), c.GetDerivative(M_PI));
    EXPECT_EQ(Point(2, 0, 0), c.GetDerivative(3 * M_PI_2));
    EXPECT_EQ(Point(0, 2, 0), c.GetDerivative(2 * M_PI));
    EXPECT_EQ(Point(0, -2, 0), c.GetDerivative(7 * M_PI));
    EXPECT_EQ(Point(0, -2, 0), c.GetDerivative(99 * M_PI));
    EXPECT_EQ(Point(0, 2, 0), c.GetDerivative(100 * M_PI));
}

