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
    EXPECT_EQ("000", secondChance->_chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, NULL -> E", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(1, secondChance->accessNumber());
    EXPECT_EQ("E", secondChance->frameStatus());
    EXPECT_EQ("100", secondChance->_chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("1, NULL -> F", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(2, secondChance->accessNumber());
    EXPECT_EQ("EF", secondChance->frameStatus());
    EXPECT_EQ("110", secondChance->_chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("2, NULL -> A", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(3, secondChance->accessNumber());
    EXPECT_EQ("EFA", secondChance->frameStatus());
    EXPECT_EQ("111", secondChance->_chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, E -> B", secondChance->victimPage());
}

TEST(SecondChance, 4st_5st_6st)
{
    SecondChance *secondChance = new SecondChance("EFABFCFDBCFCBAB", 3);
    secondChance->next();
    secondChance->next();
    secondChance->next();
    secondChance->next();
    EXPECT_EQ(4, secondChance->accessNumber());
    EXPECT_EQ("BFA", secondChance->frameStatus());
    EXPECT_EQ("100", secondChance->_chanceTable);
    EXPECT_FALSE(secondChance->isPageFault());
    secondChance->next();
    EXPECT_EQ(5, secondChance->accessNumber());
    EXPECT_EQ("BFA", secondChance->frameStatus());
    EXPECT_EQ("110", secondChance->_chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("2, A -> C", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(6, secondChance->accessNumber());
    EXPECT_EQ("BFC", secondChance->frameStatus());
    EXPECT_EQ("101", secondChance->_chanceTable);
    EXPECT_EQ(0, secondChance->_repIndex);
    EXPECT_FALSE(secondChance->isPageFault());
}

TEST(SecondChance, 7st_8st_9st)
{
    SecondChance *secondChance = new SecondChance("EFABFCFDBCFCBAB", 3);
    secondChance->next();
    secondChance->next();
    secondChance->next();
    secondChance->next();
    secondChance->next();
    secondChance->next();
    secondChance->next();
    EXPECT_EQ(7, secondChance->accessNumber());
    EXPECT_EQ("BFC", secondChance->frameStatus());
    EXPECT_EQ("111", secondChance->_chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, B -> D", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(8, secondChance->accessNumber());
    EXPECT_EQ("DFC", secondChance->frameStatus());
    EXPECT_EQ("100", secondChance->_chanceTable);
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("1, F -> B", secondChance->victimPage());
    secondChance->next();
    EXPECT_EQ(9, secondChance->accessNumber());
    EXPECT_EQ("DBC", secondChance->frameStatus());
    EXPECT_EQ("110", secondChance->_chanceTable);
    EXPECT_FALSE(secondChance->isPageFault());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}