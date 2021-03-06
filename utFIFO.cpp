#include <gtest/gtest.h>
#include "fifo.h"

TEST(FIFO, ctor)
{
  FIFO *fifo = new FIFO("ADRSADGEEAEGSS", 3);
  EXPECT_EQ("ADRSADGEEAEGSS", fifo->accessSequence());
  EXPECT_EQ(3, fifo->frameSize());
  EXPECT_EQ(0, fifo->accessNumber());
  EXPECT_EQ("", fifo->frameStatus());
  EXPECT_TRUE(fifo->isPageFault());
  EXPECT_EQ("0, NULL -> A", fifo->victimPage());
}

TEST(FIFO, 2nd_element)
{
  FIFO *fifo = new FIFO("ADRSADGEEAEGSS", 3);
  EXPECT_EQ("ADRSADGEEAEGSS", fifo->accessSequence());
  EXPECT_EQ(3, fifo->frameSize());
  EXPECT_EQ(0, fifo->accessNumber());
  fifo->next();
  EXPECT_EQ(1, fifo->accessNumber());
  EXPECT_EQ("A", fifo->frameStatus());
  EXPECT_TRUE(fifo->isPageFault());
  EXPECT_EQ("1, NULL -> D", fifo->victimPage());
}

TEST(FIFO, 3456th_element)
{
  FIFO *fifo = new FIFO("ADRSADGEEAEGSS", 3);
  fifo->next();
  fifo->next();
  EXPECT_EQ(2, fifo->accessNumber());
  EXPECT_EQ("AD", fifo->frameStatus());
  EXPECT_TRUE(fifo->isPageFault());
  EXPECT_EQ("2, NULL -> R", fifo->victimPage());
  fifo->next();
  EXPECT_EQ(3, fifo->accessNumber());
  EXPECT_EQ("ADR", fifo->frameStatus());
  EXPECT_TRUE(fifo->isPageFault());
  EXPECT_EQ("0, A -> S", fifo->victimPage());
  fifo->next();
  EXPECT_EQ(4, fifo->accessNumber());
  EXPECT_EQ("SDR", fifo->frameStatus());
  EXPECT_TRUE(fifo->isPageFault());
  EXPECT_EQ("1, D -> A", fifo->victimPage());
  fifo->next();
  EXPECT_EQ("SAR", fifo->frameStatus());
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}