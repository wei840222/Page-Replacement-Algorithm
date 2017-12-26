#ifndef FIFO_H
#define FIFO_H

#include "repALG.h"

class FIFO : public RepALG
{
public:
  FIFO(string s = "", int i = 1) : RepALG(s, i) {}
  void next()
  {
    if (!isFinish())
    {
      if (isPageFault())
      {
        if (_frameStatus.size() < _frameSize)
          _frameStatus += _accessSequence[_accessNumber];
        else
          _frameStatus[_repIndex] = _accessSequence[_accessNumber];
        _repIndex++;
        _repIndex %= _frameSize;
      }
      _accessNumber++;
    }
  }
};

#endif