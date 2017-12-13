#ifndef FIFO_H
#define FIFO_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class FIFO
{
  public:
    FIFO(string s = "", int j = 1) : _accessSequence(s), _accessNumber(0), _frameStatus(""), _frameSize(j), _fifoIndex(0) {}
    string accessSequence() const { return _accessSequence; }
    int accessNumber() const { return _accessNumber; }
    string frameStatus() const { return _frameStatus; }
    int frameSize() const { return _frameSize; }

    bool isPageFault()
    {
        for (int i = 0; i < _frameStatus.length(); i+=2)
            if (_frameSize[i] == _accessSequence[_accessNumber])
                return true;
        return false;
    }
    string victimPage() const
    {
        return "";
    }

  private:
    string _accessSequence;
    int _accessNumber;
    string _frameStatus;
    const int _frameSize;
    int _fifoIndex;
};

#endif