#include <gtest/gtest.h>
#include "lru.h"

TEST(LRU, ctor)
{
    LRU *lru = new LRU("ADRSADGEEAEGSS", 3);
    EXPECT_EQ("ADRSADGEEAEGSS", lru->accessSequence());
    EXPECT_EQ(3, lru->frameSize());
    EXPECT_EQ(0, lru->accessNumber());
    EXPECT_EQ("", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("0, NULL -> A", lru->victimPage());
}

TEST(LRU, 2nd_3rd_element)
{
    LRU *lru = new LRU("ADRSADGEEAEGSS", 3);
    EXPECT_EQ("ADRSADGEEAEGSS", lru->accessSequence());
    EXPECT_EQ(3, lru->frameSize());
    EXPECT_EQ(0, lru->accessNumber());
    lru->next();
    EXPECT_EQ(1, lru->accessNumber());
    EXPECT_EQ("A", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("1, NULL -> D", lru->victimPage());
    lru->next();
    EXPECT_EQ(2, lru->accessNumber());
    EXPECT_EQ("AD", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("2, NULL -> R", lru->victimPage());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}