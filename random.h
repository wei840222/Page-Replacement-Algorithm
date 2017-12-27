#ifndef RANDOM_H
#define RANDOM_H

#include "repALG.h"
#include <cstdlib>
#include <ctime>

class Random : public RepALG
{
public:
  Random(string s = "", int i = 1) : RepALG(s, i) {
    srand( time(NULL) );
  }
  void next()
  {
	  if(!isFinish()){
	    if(isPageFault()){
        if(_frameStatus.size() < _frameSize){
          _frameStatus += _accessSequence[_accessNumber];
          _repIndex++;
          _repIndex%=frameSize();
        }
        else{
          findRandom();
          _frameStatus[_repIndex] = _accessSequence[_accessNumber];
        }
	    }
	  }
    _accessNumber++;  
  }

private:
  void findRandom(){
    _repIndex = rand()%frameSize();
  }
};
#endif
