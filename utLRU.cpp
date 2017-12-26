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

TEST(LRU, 4nd_5th_6th_element)
{
    LRU *lru = new LRU("ADRSADGEEAEGSS", 3);
    lru->next();
    lru->next();
    lru->next();
    EXPECT_EQ(3, lru->accessNumber());
    EXPECT_EQ("ADR", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("0, A -> S", lru->victimPage());
    lru->next();
    EXPECT_EQ(4, lru->accessNumber());
    EXPECT_EQ("SDR", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("1, D -> A", lru->victimPage());
    lru->next();
    EXPECT_EQ(5, lru->accessNumber());
    EXPECT_EQ("SAR", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("2, R -> D", lru->victimPage());
    lru->next();
    EXPECT_EQ(6, lru->accessNumber());
    EXPECT_EQ("SAD", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("0, S -> G", lru->victimPage());
}

TEST(LRU, 7nd_8th_9th_element)
{
    LRU *lru = new LRU("ADRSADGEEAEGSS", 3);
    lru->next();
    lru->next();
    lru->next();
    lru->next();
    lru->next();
    lru->next();
    lru->next();
    EXPECT_EQ(7, lru->accessNumber());
    EXPECT_EQ("GAD", lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("1, A -> E", lru->victimPage());
    lru->next();
    EXPECT_EQ(8,lru->accessNumber());
    EXPECT_EQ("GED",lru->frameStatus());
    EXPECT_FALSE(lru->isPageFault());
    lru->next();
    EXPECT_EQ(9,lru->accessNumber());
    EXPECT_EQ("GED",lru->frameStatus());
    EXPECT_TRUE(lru->isPageFault());
    EXPECT_EQ("2, D -> A", lru->victimPage());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}