#ifndef REPALG_H
#define REPALG_H

#include <algorithm>
#include <string>
using namespace std;

class RepALG
{
public:
  virtual string accessSequence() const { return _accessSequence; }
  virtual int accessNumber() const { return _accessNumber; }
  virtual string frameStatus() const { return _frameStatus; }
  virtual int frameSize() const { return _frameSize; }
  virtual bool isFinish() const { return !(_accessNumber < _accessSequence.size()); }
  virtual bool isPageFault() const { return (_frameStatus.find(_accessSequence[_accessNumber]) == string::npos) ? true : false; }
  virtual string victimPage() const
  {
    string ret = "";
    if (isPageFault())
    {
      ret += to_string(_repIndex) + ", ";
      if (_frameStatus.size() < _frameSize)
        ret += "NULL";
      else
        ret += _frameStatus[_repIndex];
      ret += " -> ";
      ret += _accessSequence[_accessNumber];
    }
    return ret;
  }
  virtual void next() = 0;

protected:
  RepALG(string s = "", int i = 1)
      : _accessSequence(s), _accessNumber(0), _frameStatus(""), _frameSize(i), _repIndex(0) {}
  string _accessSequence;
  int _accessNumber;
  string _frameStatus;
  const int _frameSize;
  int _repIndex;
};

#endif