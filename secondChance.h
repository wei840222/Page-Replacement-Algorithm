#ifndef SECONDCHANCE_H
#define SECONDCHANCE_H

#include <gtest/gtest.h>
#include "repALG.h"

class SecondChance : public RepALG
{
public:
  SecondChance(string s = "", int i = 1) : RepALG(s, i)
  {
    chanceTable = "";
    for (int i = 0; i < frameSize(); i++)
      chanceTable += '0';
  }
  void next()
  {
    if (!isFinish())
    {
      if (isPageFault())
      {
        if (_frameStatus.size() < _frameSize)
          _frameStatus += _accessSequence[_accessNumber];
        else
        {
          while (chanceTable[_repIndex] != '0')
          {
            chanceTable[_repIndex] = '0';
            _repIndex++;
            _repIndex %= _frameSize;
          }
          _frameStatus[_repIndex] = _accessSequence[_accessNumber];
          _repIndex++;
          _repIndex %= _frameSize;
        }
      }
      else
        chanceTable[_frameStatus.find(_accessSequence[_accessNumber])] = '1';
      _accessNumber++;
    }
  }

private:
  string chanceTable;

  FRIEND_TEST(SecondChance, chanceTable);
};

#endif