#ifndef OPTIMAL_H
#define OPTIMAL_H

#include "repALG.h"

class Optimal : public RepALG
{
public:
  Optimal(string s = "", int i = 1):RepALG(s, i){}
  
  void next()
  {
    if(!isFinish()){
	    if(isPageFault()){
        if (_frameStatus.size() < _frameSize)
          _frameStatus += _accessSequence[_accessNumber];
        else{
          findVictim();

        }
	    }
	  }    
  }

private:
  void findVictim(){
    _repIndex = 0;
    for(int i = 0; i < frameSize(); i++){
      for(int i = _accessNumber; i < _accessSequence.size(); ++i){
        
      }
    }
  }
  
};
#endif