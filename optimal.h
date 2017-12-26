#ifndef OPTIMAL_H
#define OPTIMAL_H

#include "repALG.h"

class Optimal : public RepALG
{
public:
  Optimal(string s = ""){}
  string victimPage() const
  {
    string ret = "";
    if (isPageFault()){
      ret += to_string(_optimalIndex) + ", ";
      if (_frameStatus.empty() || _frameStatus.size() < _optimalIndex || _frameStatus[_optimalIndex] == '\0')
        ret += "NULL";
      else{
        //
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
  int _optimalIndex;
  
};
#endif