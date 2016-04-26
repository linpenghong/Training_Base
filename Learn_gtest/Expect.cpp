#include <gtest/gtest.h>

int main()
{
    double x = 10;
    double y = 20;

    EXPECT_EQ(x, y) << "x and y are not equal";

    EXPECT_TRUE(x == 5) << "x and y are not equal";

    EXPECT_FALSE(x == 10) << "x and y are equal";

    return 0;
}
