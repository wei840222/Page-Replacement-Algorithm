#ifndef LRU_H
#define LRU_H

#include "repALG.h"

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
        if (!isFinish())
        {
            if (isPageFault())
            {
                if (_frameStatus.size() < _frameSize)
                    _frameStatus += _accessSequence[_accessNumber];
                else
                    _frameStatus[_lruIndex] = _accessSequence[_accessNumber];
                _lruIndex++;
                _lruIndex %= _frameSize;
            }
            _accessNumber++;
        }
    }

  private:
    int _lruIndex;
};

#endif