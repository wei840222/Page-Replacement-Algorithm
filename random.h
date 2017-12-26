#ifndef RANDOM_H
#define RANDOM_H

#include "repALG.h"
#include <cstdlib>
#include <ctime>

class Random : public RepALG
{
public:
  Random(string s = ""){
    srand( time(NULL) );
  }
  string victimPage() const{
    string ret = "";
    if (isPageFault()){
      ret += to_string(_fifoIndex) + ", ";
      if (_frameStatus.empty() || _frameStatus.size() < _fifoIndex || _frameStatus[_fifoIndex] == '\0')
        ret += "NULL";
      else{
        _randomIndex = rand();
      }
      ret += " -> ";
      ret += _accessSequence[_accessNumber];
    }
    return ret;
  }
  void next()
  {
	  if(!isFinish()){
	    if(isPageFault()){

	    }
	  }    
  }

private:
  int _fault
  int _randomIndex;
};
#endif
