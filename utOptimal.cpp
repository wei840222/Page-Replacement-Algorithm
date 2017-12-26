#include <gtest/gtest.h>
#include "optimal.h"

TEST(Optimal, ctor)
{
  Optimal *optimal = new Optimal("ADRSADGEEAEGSS", 3);
  EXPECT_EQ("ADRSADGEEAEGSS", optimal->accessSequence());
  EXPECT_EQ(3, optimal->frameSize());
  EXPECT_EQ(0, optimal->accessNumber());
  EXPECT_EQ("", optimal->frameStatus());
  EXPECT_TRUE(optimal->isPageFault());
  EXPECT_EQ("0, NULL -> A", optimal->victimPage());
}

TEST(Optimal, 2nd_element)
{
  Optimal *optimal = new Optimal("ADRSADGEEAEGSS", 3);
  EXPECT_EQ("ADRSADGEEAEGSS", optimal->accessSequence());
  EXPECT_EQ(3, optimal->frameSize());
  EXPECT_EQ(0, optimal->accessNumber());
  optimal->next();
  EXPECT_EQ(1, optimal->accessNumber());
  EXPECT_EQ("A", optimal->frameStatus());
  EXPECT_TRUE(optimal->isPageFault());
  EXPECT_EQ("1, NULL -> D", optimal->victimPage());
}

TEST(Optimal, 3456th_element)
{
  Optimal *optimal = new Optimal("ADRSADGEEAEGSS", 3);
  optimal->next();
  optimal->next();
  EXPECT_EQ(2, optimal->accessNumber());
  EXPECT_EQ("AD", optimal->frameStatus());
  EXPECT_TRUE(optimal->isPageFault());
  EXPECT_EQ("2, NULL -> R", optimal->victimPage());
  optimal->next();
  EXPECT_EQ(3, optimal->accessNumber());
  EXPECT_EQ("ADR", optimal->frameStatus());
  EXPECT_TRUE(optimal->isPageFault());
  EXPECT_EQ("2, R -> S", optimal->victimPage());
  optimal->next();
  EXPECT_EQ(4, optimal->accessNumber());
  EXPECT_EQ("ADS", optimal->frameStatus());
  EXPECT_FALSE(optimal->isPageFault());
  optimal->next();
  EXPECT_EQ("ADS", optimal->frameStatus());
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}