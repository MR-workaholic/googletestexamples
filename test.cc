#include <gtest/gtest.h>
#include <iostream>


int test_fun(int a) {
  return a + 1;
}

TEST(FunTest, HandlesZeroInput) {
  EXPECT_EQ(1, test_fun(0));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
