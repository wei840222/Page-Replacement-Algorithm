#ifndef FIFO_H
#define FIFO_H

#include "repALG.h"

class FIFO : public RepALG
{
public:
  FIFO(string s = "", int i = 1) : RepALG(s, i), _fifoIndex(0) {}
  string victimPage() const
  {
    string ret = "";
    if (isPageFault())
    {
      ret += to_string(_fifoIndex) + ", ";
      if (_frameStatus.empty() || _frameStatus.size() < _fifoIndex || _frameStatus[_fifoIndex] == '\0')
        ret += "NULL";
      else
        ret += _frameStatus[_fifoIndex];
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
          _frameStatus[_fifoIndex] = _accessSequence[_accessNumber];
        _fifoIndex++;
        _fifoIndex %= _frameSize;
      }
      _accessNumber++;
    }
  }

private:
  int _fifoIndex;
};

#endif