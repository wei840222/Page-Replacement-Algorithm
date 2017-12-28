#include <gtest/gtest.h>
#include "secondChance.h"

TEST(SecondChance, ctor)
{
    SecondChance *secondChance = new SecondChance("EFABFCFDBCFCBAB", 3);
    EXPECT_EQ("EFABFCFDBCFCBAB", secondChance->accessSequence());
    EXPECT_EQ(3, secondChance->frameSize());
    EXPECT_EQ(0, secondChance->accessNumber());
    EXPECT_EQ("", secondChance->frameStatus());
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, NULL -> E", secondChance->victimPage());
}

TEST(SecondChance, 1st_2st_3st)
{
    SecondChance *secondChance = new SecondChance("EFABFCFDBCFCBAB", 3);
    EXPECT_EQ(0, secondChance->accessNumber());
    EXPECT_EQ("", secondChance->frameStatus());
    EXPECT_EQ("000", secondChance->chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, NULL -> E", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(1, secondChance->accessNumber());
    EXPECT_EQ("E", secondChance->frameStatus());
    EXPECT_EQ("100", secondChance->chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("1, NULL -> F", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(2, secondChance->accessNumber());
    EXPECT_EQ("EF", secondChance->frameStatus());
    EXPECT_EQ("110", secondChance->chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("2, NULL -> A", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(3, secondChance->accessNumber());
    EXPECT_EQ("EFA", secondChance->frameStatus());
    EXPECT_EQ("111", secondChance->chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, E -> B", secondChance->victimPage());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}