#ifndef LRU_H
#define LRU_H

#include "repALG.h"
#include <iostream>
using namespace std;

class LRU : public RepALG
{
  public:
    LRU(string s = "", int i = 1) : RepALG(s, i), _lruIndex(0) {}
    string victimPage() const
    {
        string ret = "";
        if (isPageFault())
        {
            ret += to_string(_lruIndex) + ", ";
            if (_frameStatus.size() < _frameSize)
                ret += "NULL";
            else
                ret += _frameStatus[_lruIndex];
            ret += " -> ";
            ret += _accessSequence[_accessNumber];
        }
        return ret;
    }
    void next()
    {
        if (!isFinish() && isPageFault())
        {
            if (_frameStatus.size() < _frameSize)
            {
                _frameStatus += _accessSequence[_accessNumber];
                _lruIndex++;
                _lruIndex %= _frameSize;
            }
            else
            {
                _frameStatus[_lruIndex] = _accessSequence[_accessNumber];
                _lruIndex = 0;
                int minIndex = _accessSequence.rfind(_frameStatus[0], _accessNumber);
                for (int i = 1; i < _frameSize; i++)
                    if (_accessSequence.rfind(_frameStatus[i], _accessNumber) < minIndex)
                    {
                        minIndex = _accessSequence.rfind(_frameStatus[i], _accessNumber);
                        _lruIndex = i;
                    }
            }
        }
        _accessNumber++;
    }

  private:
    int _lruIndex;
};

#endif