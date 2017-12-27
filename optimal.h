#ifndef OPTIMAL_H
#define OPTIMAL_H

#include <iostream>

#include <vector>
#include <limits>
#include "repALG.h"

using namespace std;

class Optimal : public RepALG
{
public:
  Optimal(string s = "", int i = 1):RepALG(s, i){}
  
  void next()
  {
    if(!isFinish()){
	    if(isPageFault()){
        if (_frameStatus.size() < _frameSize){
          _frameStatus += _accessSequence[_accessNumber];
          _repIndex++;
          _repIndex %= _frameSize;
        }
        else{
          findVictim();
          _frameStatus[_repIndex] = _accessSequence[_accessNumber];
        }
	    }
	  }
    _accessNumber++;
  }

private:
  void findVictim(){
    vector<int> _position;
    for(int i = 0; i < frameSize(); i++){
      _position.push_back(infinity);
    }
    for(int i = 0; i < frameSize(); i++){
      int j = _accessNumber;
      while(j < _accessSequence.size()){
        if(_frameStatus[i] == _accessSequence[j]){
          _position[i] = j;
          break;
        }
        ++j;
      }
    }
    for(int i = 0; i < frameSize(); i++){
      int _tmpPosition = 0;
      if(_position[i] > _tmpPosition){
        _tmpPosition = _position[i];
        _repIndex = i;
      }
    }
  }

  int const infinity = std::numeric_limits<int>::max();
  
};
#endif