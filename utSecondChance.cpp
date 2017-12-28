#include <gtest/gtest.h>
#include "secondChance.h"

TEST(SecondChance, ctor)
{
    SecondChance *secondChance = new SecondChance("ADRASDGEEAEGSS", 3);
    EXPECT_EQ("ADRASDGEEAEGSS", secondChance->accessSequence());
    EXPECT_EQ(3, secondChance->frameSize());
    EXPECT_EQ(0, secondChance->accessNumber());
    EXPECT_EQ("", secondChance->frameStatus());
    EXPECT_TRUE(secondChance->isPageFault());
    EXPECT_EQ("0, NULL -> A", secondChance->victimPage());
}

TEST(SecondChance, chanceTable)
{
    SecondChance *secondChance = new SecondChance("ADRASDGEEAEGSS", 3);
    EXPECT_EQ("000", secondChance->chanceTable);
    secondChance->next();
    secondChance->next();
    secondChance->next();
    secondChance->next();
    EXPECT_EQ(4, secondChance->accessNumber());
    EXPECT_EQ("ADR", secondChance->frameStatus());
    EXPECT_EQ("100", secondChance->chanceTable);
    secondChance->next();
    EXPECT_EQ(5, secondChance->accessNumber());
    EXPECT_EQ("ASR", secondChance->frameStatus());
    EXPECT_EQ("000", secondChance->chanceTable);
    secondChance->next();
    EXPECT_EQ(6, secondChance->accessNumber());
    EXPECT_EQ("ASD", secondChance->frameStatus());
    EXPECT_EQ("000", secondChance->chanceTable);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}