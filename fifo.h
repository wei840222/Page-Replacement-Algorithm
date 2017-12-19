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
    bool isPageFault() const { return (_frameStatus.find(_accessSequence[_accessNumber]) == string::npos) ? true : false;}
    string victimPage() const
    {
      string ret = "";
        if(isPageFault())
        {
          ret += to_string(_fifoIndex) + ", ";
          if(_frameStatus.empty() || _frameStatus.size() < _fifoIndex)
            ret += "NULL";
          else
            ret += _frameStatus[_fifoIndex];
          ret += " -> " + _accessSequence[_accessNumber];
        }
        return ret;
    }

  private:
    string _accessSequence;
    int _accessNumber;
    string _frameStatus;
    const int _frameSize;
    int _fifoIndex;
};

#endif