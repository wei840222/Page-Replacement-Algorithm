#include <gtest/gtest.h>
#include "secondChance.h"

TEST(SecondChance, ctor)
{
    SecondChance *secondChance = new SecondChance("ADRSADGEEAEGSS", 3);
    EXPECT_EQ("ADRSADGEEAEGSS", secondChance->accessSequence());
    EXPECT_EQ(3, secondChance->frameSize());
    EXPECT_EQ(0, secondChance->accessNumber());
    EXPECT_EQ("", secondChance->frameStatus());
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, NULL -> A", secondChance->victimPage());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}