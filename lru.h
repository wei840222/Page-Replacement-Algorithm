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
    void next() {}

  private:
    int _lruIndex;
};

#endif