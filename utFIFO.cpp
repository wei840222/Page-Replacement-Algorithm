#include "fifo.h"
#include <gtest/gtest.h>

TEST(FIFO, ctor)
{
    FIFO *fifo = new FIFO("A,D,R,S,A,D,G,E,E,A,E,G,S,S", 3);
    EXPECT_EQ("A, D, R, S, A, D, G, E, E, A, E, G, S, S", fifo->accessSequence());
    EXPECT_EQ(3, fifo->frameSize());
    EXPECT_EQ(0, fifo->accessNumber());
    EXPECT_TRUE(fifo->frameStatus()->empty());
    EXPECT_TRUE(fifo->isPageFault());
    EXPECT_EQ("0, NULL -> A", fifo->victimPage());
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}