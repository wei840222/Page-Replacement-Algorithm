#ifndef FIFO_H
#define FIFO_H

#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class FIFO
{
  public:
    FIFO(string s = "", int i = 1) : _frameSize(i), _accessNumber(0), _frameStatus({}), _fifoIndex(0)
    {
        if (s == "")
            _accessSequence = {};
        else
        {
            string token;
            while (istringstream(s), token, ',')
                _accessSequence.push_back(token);
        }
    }
    string accessSequence() const
    {
        stringstream ss;
        ss << _accessSequence[0];
        for (int i = 1; i < _accessSequence.size(); i++)
            ss << ", " << _accessSequence[i];
        return ss.str();
    }
    int frameSize() const { return _frameSize; }
    int accessNumber() const { return _accessNumber; }
    vector<string> frameStatus() const { _frameStatus; }
    bool isPageFault() const { return find(_frameStatus.begin(), _frameStatus.end(), _accessSequence[_accessNumber]) == _frameStatus.end(); }
    string victimPage()
    {
        stringstream ss;
        if (_frameStatus.size() < _frameSize)
            ss << _frameStatus.size() << ", NULL -> " << _accessSequence[_accessNumber];
        else if (isPageFault())
            ss << _fifoIndex << ", " << _frameStatus[_fifoIndex] << " -> " << _accessSequence[_accessNumber];
        return ss.str();
    }

  private:
    vector<string> _accessSequence;
    const int _frameSize;
    int _accessNumber;
    vector<string> _frameStatus;
    int _fifoIndex;
};

#endif