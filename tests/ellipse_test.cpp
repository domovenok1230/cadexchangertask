#include <ellipse.h>
#include <point.h>
#include <gtest/gtest.h>
#define _USE_MATH_DEFINES
#include <cmath>

TEST(EllipsTest, ZeroRadius1_2) {
    Ellipse e(0, 0);
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(0));
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(M_PI_2));
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(M_PI));
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(3 * M_PI_2));
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(2 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(7 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(99 * M_PI));
    EXPECT_EQ(Point(0, 0, 0), e.GetPoint(100 * M_PI));
}

TEST(EllipsTest, NoneZerosRadius) {
    Ellipse e(1, 2);
    EXPECT_EQ(Point(1, 0, 0), e.GetPoint(0));
    EXPECT_EQ(Point(0, 2, 0), e.GetPoint(M_PI_2));
    EXPECT_EQ(Point(-1, 0, 0), e.GetPoint(M_PI));
    EXPECT_EQ(Point(0, -2, 0), e.GetPoint(3 * M_PI_2));
    EXPECT_EQ(Point(1, 0, 0), e.GetPoint(2 * M_PI));
    EXPECT_EQ(Point(-1, 0, 0), e.GetPoint(7 * M_PI));
    EXPECT_EQ(Point(-1, 0, 0), e.GetPoint(99 * M_PI));
    EXPECT_EQ(Point(1, 0, 0), e.GetPoint(100 * M_PI));
}

TEST(EllipsTest, NoneZerosRadiusDerivative) {
    Ellipse e(1, 2);
    EXPECT_EQ(Point(0, 2, 0), e.GetDerivative(0));
    EXPECT_EQ(Point(-1, 0, 0), e.GetDerivative(M_PI_2));
    EXPECT_EQ(Point(0, -2, 0), e.GetDerivative(M_PI));
    EXPECT_EQ(Point(1, 0, 0), e.GetDerivative(3 * M_PI_2));
    EXPECT_EQ(Point(0, 2, 0), e.GetDerivative(2 * M_PI));
    EXPECT_EQ(Point(0, -2, 0), e.GetDerivative(7 * M_PI));
    EXPECT_EQ(Point(0, -2, 0), e.GetDerivative(99 * M_PI));
    EXPECT_EQ(Point(0, 2, 0), e.GetDerivative(100 * M_PI));
}
