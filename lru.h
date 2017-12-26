#ifndef LRU_H
#define LRU_H

#include "repALG.h"

class LRU : public RepALG
{
  public:
    LRU(string s = "", int i = 1) : RepALG(s, i) {}
    void next()
    {
        if (!isFinish())
        {
            if (isPageFault())
            {
                if (_frameStatus.size() < _frameSize)
                {
                    _frameStatus += _accessSequence[_accessNumber];
                    _repIndex++;
                    _repIndex %= _frameSize;
                }
                else
                {
                    findLRU();
                    _frameStatus[_repIndex] = _accessSequence[_accessNumber];
                }
            }
            if (_frameStatus.size() >= _frameSize)
                findLRU();
        }
        _accessNumber++;
    }

  private:
    void findLRU()
    {
        _repIndex = 0;
        int minIndex = _accessSequence.rfind(_frameStatus[0], _accessNumber);
        for (int i = 1; i < _frameSize; i++)
            if (_accessSequence.rfind(_frameStatus[i], _accessNumber) < minIndex)
            {
                minIndex = _accessSequence.rfind(_frameStatus[i], _accessNumber);
                _repIndex = i;
            }
    }
};

#endif