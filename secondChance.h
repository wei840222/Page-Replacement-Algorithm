#ifndef SECONDCHANCE_H
#define SECONDCHANCE_H

#include <iostream>
using namespace std;
#include <gtest/gtest.h>
#include "repALG.h"

class SecondChance : public RepALG
{
public:
  SecondChance(string s = "", int i = 1) : RepALG(s, i)
  {
    _chanceTable = "";
    for (int i = 0; i < frameSize(); i++)
      _chanceTable += '0';
  }
  string victimPage() const
  {
    string ret = "";
    int i = _repIndex;
    if (_chanceTable.find('0') != string::npos)
    {
      while (_chanceTable[i] == '1')
      {
        i++;
        i %= _frameSize;
      }
    }
    if (isPageFault())
    {
      ret += to_string(i) + ", ";
      if (_frameStatus.size() < _frameSize)
        ret += "NULL";
      else
        ret += _frameStatus[i];
      ret += " -> ";
      ret += _accessSequence[_accessNumber];
    }
    return ret;
  }
  void next()
  {
    if (!isFinish())
    {
      if (isPageFault())
      {
        if (_frameStatus.size() < _frameSize)
        {
          _chanceTable[_repIndex] = '1';
          _frameStatus += _accessSequence[_accessNumber];
        }
        else
        {
          if (_chanceTable.find('0') == string::npos)
          {
            _chanceTable = "";
            for (int i = 0; i < frameSize(); i++)
              _chanceTable += '0';
          }
          else
          {
            while (_chanceTable[_repIndex] == '1')
            {
              _chanceTable[_repIndex] = '0';
              _repIndex++;
            }
          }
          _chanceTable[_repIndex] = '1';
          _frameStatus[_repIndex] = _accessSequence[_accessNumber];
        }
        _repIndex++;
        _repIndex %= _frameSize;
      }
      else
        _chanceTable[_repIndex] = '1';
      _accessNumber++;
    }
  }

private:
  string _chanceTable;

  FRIEND_TEST(SecondChance, 1st_2st_3st);
  FRIEND_TEST(SecondChance, 4st_5st_6st);
};

#endif