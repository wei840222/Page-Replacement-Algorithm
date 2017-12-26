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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}